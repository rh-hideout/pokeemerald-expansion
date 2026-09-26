import re
import subprocess

def get_branch_to_fetch():
    return ("origin", "pull/10834/head")

def check_repo_status():
    result = subprocess.run(["git", "status", "--porcelain", "--untracked-files=no"], capture_output=True, text=True)
    if not result.stdout:
        return
    print("Expansion can't be updated when you still have uncommited files")
    exit()

def merge_commits_if_no_conflict(commit, message):
    result = subprocess.run(["git", "merge", "--no-commit", "--no-ff", commit], capture_output=True)
    if result.returncode:
        subprocess.run(["git", "merge", "--abort"])
        print(f"Could not merge without creating conflicts\nPlease manually run\ngit merge {commit}")
        exit()
    commit_message = f"Merge commit automated by auto_migration.py: {message}"
    result = subprocess.run(["git", "commit", "-m", commit_message])
    print(f"Merge succesful")

def run_migration(commit, message):
    result = subprocess.run(["git", "show", "--pretty=format:%b", "-s", commit], capture_output=True, text=True)
    lines = result.stdout.splitlines()
    script = "migration_scripts/" + lines.pop(0).strip()
    print(f"Launching migration script: {script}")
    result = subprocess.run(["python3", script])
    print(f"Migration succesful, commiting changes")
    for line in lines:
        subprocess.run(["git", "add", line.strip()])
    commit_message = f"Commit automated by auto_migration.py: Add migrated data for {message}"
    subprocess.run(["git", "commit", "--allow-empty", "-m", commit_message])
    print(f"Cleaning up remote data")
    commit_message = f"Merge commit automated by auto_migration.py: ignore remote data for {message}"
    result = subprocess.run(["git", "merge", "-s", "ours", commit], text=True)

check_repo_status()
to_fetch = get_branch_to_fetch()
subprocess.run(["git", "fetch", to_fetch[0], to_fetch[1]]);
result = subprocess.run(["git", "log", "--no-merges", "--oneline", "--reverse", "FETCH_HEAD", "^HEAD"], capture_output=True, text=True);
non_migration_commits = 0
for line in result.stdout.splitlines():
    match = re.search(r'([a-f0-9]+) \[(migration-\w+)\](.+)', line)
    if match:
        type = match.group(2)
        if type == "migration-script":
            print(f"Migration needed: only merging until migration step")
            message = "merging until beginning of migration for" + match.group(3)
            merge_commits_if_no_conflict(match.group(1), message)
        elif type == "migration-data":
            run_migration(match.group(1), match.group(3))
        elif type == "migration-changes":
            message = "merging expansion changes for" + match.group(3)
            merge_commits_if_no_conflict(match.group(1), message)
            non_migration_commits = 0
    else:
        non_migration_commits += 1
if non_migration_commits > 0:
    print(f"No more migration needed: merging all remaining commits")
    merge_commits_if_no_conflict("FETCH_HEAD", "merging until HEAD of PR 10834")
