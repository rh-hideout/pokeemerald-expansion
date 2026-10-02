import os
import re
import subprocess
import sys

def check_repo_status():
    result = subprocess.run(["git", "status", "--porcelain", "--untracked-files=no"], capture_output=True, text=True)
    if not result.stdout:
        return
    print("Expansion can't be updated when you still have uncommited files")
    exit()

def split_migration_commits(message):
    result = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], capture_output=True, text=True)
    starting_branch = result.stdout.strip()
    result = subprocess.run(["git", "checkout", "FETCH_HEAD"], capture_output=True)
    result = subprocess.run(["git", "checkout", "-b", "temporary_migration_branch_clean"], capture_output=True)
    if result.returncode:
        print("Error: temporary_migration_branch_clean already exists. Aborting")
        exit()
    result = subprocess.run(["git", "checkout", "-b", "temporary_migration_branch_split"])
    print("Splitting migration commit into multiple commits")
    result = subprocess.run(["git", "show", "--pretty=format:%b", "-s", "HEAD"], capture_output=True, text=True)
    lines = result.stdout.splitlines()

    result = subprocess.run(["git", "reset", "HEAD~1"], capture_output=True)

    script = "migration_scripts/" + lines.pop(0).strip()
    subprocess.run(["git", "add", script])
    commit_message = f"Commit automated by auto_migration.py: Add migration script for {message}"
    subprocess.run(["git", "commit", "--quiet", "-m", commit_message])

    migrated_files = []
    for line in lines:
        migrated_files.append(line.strip())
    result = subprocess.run(["git", "diff", "--name-only", "temporary_migration_branch_clean", "HEAD"], capture_output=True, text=True)
    modified_files = result.stdout.splitlines()
    for modified_file in modified_files:
        if modified_file not in migrated_files:
            subprocess.run(["git", "add", modified_file])

    commit_message = f"Commit automated by auto_migration.py: Add code changes for {message}"
    subprocess.run(["git", "commit", "--quiet", "-m", commit_message])

    for migrated_file in migrated_files:
        subprocess.run(["git", "add", migrated_file])
    commit_message = f"Commit automated by auto_migration.py: Unused migrated files from expansion (do not merge into your working branches)"
    subprocess.run(["git", "commit", "--quiet", "--allow-empty", "-m", commit_message])

    result = subprocess.run(["git", "checkout", starting_branch])


def merge_commits_if_no_conflict(commit, message):
    result = subprocess.run(["git", "merge", "--no-commit", "--no-ff", commit], capture_output=True)
    if result.returncode:
        subprocess.run(["git", "merge", "--abort"])
        print(f"Could not merge without creating conflicts\nPlease manually run\ngit merge {commit}")
        exit()
    commit_message = f"Merge commit automated by auto_migration.py: {message}"
    result = subprocess.run(["git", "commit", "-m", commit_message])

def run_migration(message):
    result = subprocess.run(["git", "show", "--pretty=format:%b", "-s", "temporary_migration_branch_clean"], capture_output=True, text=True)
    lines = result.stdout.splitlines()
    script = "migration_scripts/" + lines.pop(0).strip()
    print(f"Launching migration script: {script}")
    result = subprocess.run(["python3", script])
    if result.returncode:
        print("Error when running migration file. Removing temporary branches and aborting")
        result = subprocess.run(["git", "branch", "-D", "temporary_migration_branch_clean"])
        result = subprocess.run(["git", "branch", "-D", "temporary_migration_branch_split"])
        exit()
    subprocess.run(["touch", "migration_scripts/auto_migration_tag_data_was_migrated"])
    print(f"Migration succesful, commiting changes")
    for line in lines:
        subprocess.run(["git", "add", line.strip()])
    commit_message = f"Commit automated by auto_migration.py: Add migrated data for {message}"
    subprocess.run(["git", "commit", "--allow-empty", "-m", commit_message])

def cleanup_after_migration():
    result = subprocess.run(["git", "log", "--oneline", "-1", "temporary_migration_branch_clean"], capture_output=True, text=True)
    match = re.search(r'([a-f0-9]+) \[migration\](.+)', result.stdout)
    if match:
        migration_name = match.group(2).strip()
    else:
        migration_name = "unknown migration"
    print(f"Cleaning up remote data and removing temporary branches")
    commit_message = f"Merge commit automated by auto_migration.py: ignore remote data for `{migration_name}`"
    result = subprocess.run(["git", "merge", "-m", commit_message, "-s", "ours", "temporary_migration_branch_clean"])
    subprocess.run(["rm", "migration_scripts/auto_migration_tag_data_was_migrated"])
    result = subprocess.run(["git", "branch", "-D", "temporary_migration_branch_clean"])
    result = subprocess.run(["git", "branch", "-D", "temporary_migration_branch_split"])

def continue_in_progress_migration():
    result = subprocess.run(["git", "log", "--oneline", "-1", "temporary_migration_branch_clean"], capture_output=True, text=True)
    match = re.search(r'([a-f0-9]+) \[migration\](.+)', result.stdout)
    if match:
        migration_name = match.group(2).strip()
    else:
        migration_name = "unknown migration"
    run_migration(migration_name)
    print(f"Trying to merge expansion changes")
    merge_commits_if_no_conflict("temporary_migration_branch_split~1", f"merging expansion changes for `{migration_name}`")
    cleanup_after_migration()

check_repo_status()
remote = "https://github.com/rh-hideout/pokeemerald-expansion.git"
main_branch = sys.argv[1]

result = subprocess.run(["git", "show-ref", "--quiet", "temporary_migration_branch_split"])
if not result.returncode:
    result = subprocess.run(["git", "log", "--oneline", "--reverse", "temporary_migration_branch_split", "^HEAD"], capture_output=True, text=True);
    remaining_commits = len(result.stdout.splitlines())
    if remaining_commits == 3:
        print("Can't continue automatic migration. You need to do some manual merging.")
        print("Please run the following command")
        print("git merge temporary_migration_branch_split~2")
        exit()
    elif remaining_commits == 2:
        if os.path.exists("migration_scripts/auto_migration_tag_data_was_migrated"):
            print("Can't continue automatic migration. You need to do some manual merging.")
            print("Please run the following command")
            print("git merge temporary_migration_branch_split~1")
            exit()
        else:
            continue_in_progress_migration()
    elif remaining_commits == 1:
        cleanup_after_migration()

subprocess.run(["git", "fetch", remote, main_branch]);
result = subprocess.run(["git", "log", "--oneline", "--reverse", "FETCH_HEAD", "^HEAD"], capture_output=True, text=True);
non_migration_commits = 0
for line in result.stdout.splitlines():
    match = re.search(r'([a-f0-9]+) \[migration\](.+)', line)
    if match:
        migration_hash =  match.group(1)
        migration_name =  match.group(2)
        print(f"Migration needed: Creating temporary branch")
        split_migration_commits(migration_name)
        print(f"Trying to merge all commits until beginning of migration")
        merge_commits_if_no_conflict("temporary_migration_branch_split~2", f"merging until beginning of migration for `{migration_name}`")
        continue_in_progress_migration()
        non_migration_commits = 0
    else:
        non_migration_commits += 1

if non_migration_commits > 0:
    print(f"No more migration needed: merging all remaining commits")
    merge_commits_if_no_conflict("FETCH_HEAD", f"merging until HEAD of {remote}/{main_branch}")
