#!/usr/bin/env python3

"""Migrate the configured generation-specific level-up learnset header."""

import subprocess
import sys
import zipfile
from pathlib import Path


GENERATION_COUNT = 9
IGNORE_ENTRY = b"src/data/pokemon/level_up_learnsets.h"
LEGACY_BACKUP = Path("level_up_learnsets_legacy_backup.zip")
LEGACY_DIRECTORY = Path("src/data/pokemon/level_up_learnsets")
OUTPUT_FILE = Path("src/data/pokemon/level_up_learnsets.h")


class MigrationError(Exception):
    """A problem that prevents the migration from completing safely."""


def run_cpp(command: list[str], source: str) -> str:
    try:
        result = subprocess.run(
            [*command, "-P"],
            input=source,
            text=True,
            capture_output=True,
            check=False,
        )
    except OSError as error:
        raise MigrationError(
            f"Could not run C preprocessor {command[0]}: {error}"
        ) from error

    if result.returncode != 0:
        raise MigrationError(
            f"C preprocessor failed: {' '.join(command)}\n{result.stderr}"
        )

    return result.stdout


def configured_generation(command: list[str]) -> int:
    branches = [
        "#ifndef P_LVL_UP_LEARNSETS",
        '#error "P_LVL_UP_LEARNSETS is not defined"',
        "#endif",
        "#if P_LVL_UP_LEARNSETS <= GEN_1",
        "1",
    ]

    for generation in range(2, GENERATION_COUNT):
        branches.extend(
            (
                f"#elif P_LVL_UP_LEARNSETS == GEN_{generation}",
                str(generation),
            )
        )

    branches.extend(
        (
            "#else",
            str(GENERATION_COUNT),
            "#endif",
            "",
        )
    )

    output = run_cpp(command, "\n".join(branches)).strip()
    if not output.isdecimal():
        raise MigrationError(
            "Unable to determine the configured level-up learnset generation"
        )

    return int(output)


def run_git(
    project_root: Path,
    arguments: list[str],
) -> subprocess.CompletedProcess:
    try:
        return subprocess.run(
            ["git", *arguments],
            cwd=project_root,
            capture_output=True,
            check=False,
        )
    except OSError as error:
        raise MigrationError(f"Could not run Git: {error}") from error


def read_git_blob(
    project_root: Path,
    object_name: str,
) -> bytes | None:
    result = run_git(project_root, ["show", object_name])
    if result.returncode != 0:
        return None

    return result.stdout


def revisions_for_path(
    project_root: Path,
    relative_path: str,
    *,
    first_parent: bool,
) -> list[str]:
    arguments = ["rev-list"]
    if first_parent:
        arguments.append("--first-parent")

    arguments.extend(("HEAD", "--", relative_path))
    result = run_git(project_root, arguments)
    if result.returncode != 0:
        return []

    return result.stdout.decode("ascii").splitlines()


def find_legacy_contents(
    project_root: Path,
    legacy_file: Path,
) -> tuple[bytes, str]:
    if legacy_file.is_file():
        return legacy_file.read_bytes(), str(legacy_file)

    relative_path = legacy_file.relative_to(project_root).as_posix()

    for stage in (2, 3):
        contents = read_git_blob(
            project_root,
            f":{stage}:{relative_path}",
        )
        if contents is not None:
            return contents, f"the Git index (stage {stage})"

    contents = read_git_blob(
        project_root,
        f"ORIG_HEAD:{relative_path}",
    )
    if contents is not None:
        return contents, "the pre-update ORIG_HEAD revision"

    # Prefer the project's first-parent history. The full reachable history is
    # only a fallback for customizations introduced through a merged branch.
    checked_revisions: set[str] = set()
    revision_groups = (
        revisions_for_path(
            project_root,
            relative_path,
            first_parent=True,
        ),
        revisions_for_path(
            project_root,
            relative_path,
            first_parent=False,
        ),
    )

    for revisions in revision_groups:
        for revision in revisions:
            if revision in checked_revisions:
                continue

            checked_revisions.add(revision)
            contents = read_git_blob(
                project_root,
                f"{revision}:{relative_path}",
            )
            if contents is not None:
                return contents, f"Git commit {revision[:10]}"

    raise MigrationError(
        f"Could not find {relative_path} in the working tree, "
        "the Git index, or reachable Git history. If the file was stashed, "
        "restore it and run the migration again."
    )


def make_output_trackable(project_root: Path) -> bool:
    gitignore = project_root / ".gitignore"
    lines = gitignore.read_bytes().splitlines(keepends=True)
    filtered_lines = [line for line in lines if line.strip() != IGNORE_ENTRY]

    if filtered_lines == lines:
        return False

    gitignore.write_bytes(b"".join(filtered_lines))
    return True


def back_up_non_selected_files(
    project_root: Path,
    legacy_directory: Path,
    selected_file: Path,
) -> tuple[Path | None, int]:
    legacy_files = [
        legacy_directory / f"gen_{generation}.h"
        for generation in range(1, GENERATION_COUNT + 1)
    ]
    files_to_back_up = [
        path
        for path in legacy_files
        if path != selected_file and path.is_file()
    ]

    if not files_to_back_up:
        return None, 0

    backup_file = project_root / LEGACY_BACKUP
    if backup_file.exists():
        raise MigrationError(
            f"{LEGACY_BACKUP} already exists. Move or remove it before "
            "running the migration again so it is not overwritten."
        )

    try:
        with zipfile.ZipFile(
            backup_file,
            mode="x",
            compression=zipfile.ZIP_DEFLATED,
        ) as archive:
            for path in files_to_back_up:
                archive.write(path, path.relative_to(project_root))
    except (OSError, zipfile.BadZipFile) as error:
        raise MigrationError(
            f"Could not create {LEGACY_BACKUP}: {error}"
        ) from error

    return backup_file, len(files_to_back_up)


def remove_legacy_files(legacy_directory: Path) -> int:
    removed = 0

    for generation in range(1, GENERATION_COUNT + 1):
        legacy_file = legacy_directory / f"gen_{generation}.h"
        if not legacy_file.is_file():
            continue

        legacy_file.unlink()
        removed += 1

    if legacy_directory.is_dir():
        try:
            legacy_directory.rmdir()
        except OSError:
            pass

    return removed


def migrate(cpp_command: list[str]) -> None:
    project_root = Path.cwd().resolve()
    if not (project_root / "Makefile").is_file():
        raise MigrationError("Run this migration from the project root")

    generation = configured_generation(cpp_command)
    legacy_directory = project_root / LEGACY_DIRECTORY
    legacy_file = legacy_directory / f"gen_{generation}.h"
    output_file = project_root / OUTPUT_FILE

    contents, source = find_legacy_contents(project_root, legacy_file)

    if output_file.exists():
        if output_file.read_bytes() != contents:
            raise MigrationError(
                f"{OUTPUT_FILE} already exists and differs from the "
                "legacy header. It was not overwritten. Back it up or "
                "remove it before running the migration again."
            )
    backup_file, backup_count = back_up_non_selected_files(
        project_root,
        legacy_directory,
        legacy_file,
    )

    if not output_file.exists():
        output_file.write_bytes(contents)

    changed_gitignore = make_output_trackable(project_root)
    removed_count = remove_legacy_files(legacy_directory)

    print(
        f"Migrated P_LVL_UP_LEARNSETS=GEN_{generation} from {source} "
        f"to {OUTPUT_FILE}."
    )
    if removed_count:
        print(f"Removed {removed_count} legacy level-up learnset file(s).")
    if backup_file is not None:
        print(
            f"Saved {backup_count} non-selected legacy file(s) to "
            f"{backup_file.relative_to(project_root)}."
        )
    if changed_gitignore:
        print(f"Removed {OUTPUT_FILE} from .gitignore so it can be tracked.")

    print("Review the migrated header and Git changes before committing them.")


def main() -> None:
    arguments = sys.argv[1:]

    try:
        separator = arguments.index("--")
    except ValueError as error:
        raise MigrationError(
            f"Usage: {sys.argv[0]} CPP [CPP_ARG ...] --"
        ) from error

    cpp_command = arguments[:separator]
    trailing_arguments = arguments[separator + 1 :]

    if not cpp_command or trailing_arguments:
        raise MigrationError(
            f"Usage: {sys.argv[0]} CPP [CPP_ARG ...] --"
        )

    migrate(cpp_command)


if __name__ == "__main__":
    try:
        main()
    except MigrationError as error:
        raise SystemExit(f"error: {error}") from error
