#!/usr/bin/env python3

"""Generate the configured level-up learnsets from the porymoves JSON data."""

import json
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


REFERENCE_PATTERN = re.compile(r"\.levelUpLearnset\s*=\s*(s\w+LevelUpLearnset)")
DIRECTIVE_PATTERN = re.compile(
    r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$"
)

PRE_GENERATION_EIGHT_GAMES = (
    "y",
    "c",
    "rse",
    "hgss",
    "b2w2",
    "oras",
    "usum",
)

LevelUpMove = tuple[int, str]
Learnset = list[LevelUpMove]
Learnsets = dict[str, Learnset]
ConditionContext = tuple[str, ...]
SymbolReference = tuple[str, ConditionContext]
ConditionalSymbol = tuple[str, str | None]


@dataclass
class ConditionalBlock:
    tests: list[str]
    current: str


def make_symbol(species: str) -> str:
    parts = re.findall(r"[A-Za-z0-9]+", species)
    name = "".join(part[:1].upper() + part[1:].lower() for part in parts)
    return f"s{name}LevelUpLearnset"


def load_game(path: Path) -> Learnsets:
    with path.open("r", encoding="utf-8") as file:
        source = json.load(file)

    result = {}

    for species, learnsets in source.items():
        if not learnsets["LevelMoves"]:
            continue

        symbol = make_symbol(species)
        if symbol in result:
            raise ValueError(f"{path} contains multiple entries for {symbol}")

        moves = []
        for entry in learnsets["LevelMoves"]:
            level = int(entry["Level"])
            if not 0 <= level <= 100:
                raise ValueError(
                    f"{path} contains invalid level {level} for {species}"
                )

            moves.append((level, entry["Move"]))

        result[symbol] = sorted(moves, key=lambda move: move[0])

    return result


def load_generations(inputs_dir: Path) -> list[Learnsets]:
    generations = [
        load_game(inputs_dir / f"{game}.json")
        for game in PRE_GENERATION_EIGHT_GAMES
    ]

    sword_and_shield = load_game(inputs_dir / "swsh.json")
    brilliant_diamond_and_shining_pearl = load_game(inputs_dir / "bdsp.json")
    legends_arceus = load_game(inputs_dir / "la.json")

    species_known_before_legends_arceus = set().union(
        *(generation.keys() for generation in generations),
        sword_and_shield.keys(),
        brilliant_diamond_and_shining_pearl.keys(),
    )

    # Sword and Shield provide the default Generation 8 data. Legends: Arceus
    # adds its new species, while BDSP takes precedence for species it contains.
    generation_eight = generations[-1].copy()
    generation_eight.update(sword_and_shield)
    generation_eight.update(
        {
            symbol: moves
            for symbol, moves in legends_arceus.items()
            if symbol not in species_known_before_legends_arceus
        }
    )
    generation_eight.update(brilliant_diamond_and_shining_pearl)
    generations.append(generation_eight)

    # Scarlet and Violet override Generation 8. Legends: Z-A only supplies
    # species which still have no learnset at that point.
    generation_nine = generation_eight.copy()
    generation_nine.update(load_game(inputs_dir / "sv.json"))

    legends_za = load_game(inputs_dir / "za.json")
    generation_nine.update(
        {
            symbol: moves
            for symbol, moves in legends_za.items()
            if symbol not in generation_nine
        }
    )
    generations.append(generation_nine)

    return generations


def select_learnsets(
    generations: list[Learnsets],
    generation: int,
) -> Learnsets:
    all_symbols = set().union(
        *(learnsets.keys() for learnsets in generations)
    )
    selected = {}

    for symbol in all_symbols:
        introduction = next(
            index
            for index, learnsets in enumerate(generations)
            if symbol in learnsets
        )

        if generation < introduction:
            selected_generation = introduction
        else:
            selected_generation = max(
                index
                for index in range(introduction, generation + 1)
                if symbol in generations[index]
            )

        selected[symbol] = generations[selected_generation][symbol]

    return selected


def branch_expression(kind: str, value: str) -> str:
    value = value.split("//", 1)[0].strip()

    if kind == "ifdef":
        return f"defined({value})"
    if kind == "ifndef":
        return f"!defined({value})"

    return value


def previous_branch_expression(tests: list[str]) -> str:
    return " || ".join(f"({test})" for test in tests)


def collect_references(path: Path) -> list[SymbolReference]:
    references = []
    stack: list[ConditionalBlock] = []

    with path.open("r", encoding="utf-8") as file:
        for line in file:
            directive = DIRECTIVE_PATTERN.match(line)

            if directive is not None:
                kind, value = directive.groups()

                if kind in ("if", "ifdef", "ifndef"):
                    expression = branch_expression(kind, value)
                    stack.append(
                        ConditionalBlock(
                            tests=[expression],
                            current=expression,
                        )
                    )
                elif kind == "elif":
                    expression = branch_expression(kind, value)
                    block = stack[-1]
                    previous = previous_branch_expression(block.tests)
                    block.current = f"!({previous}) && ({expression})"
                    block.tests.append(expression)
                elif kind == "else":
                    block = stack[-1]
                    previous = previous_branch_expression(block.tests)
                    block.current = f"!({previous})"
                else:
                    stack.pop()

                continue

            context = tuple(block.current for block in stack)
            references.extend(
                (match.group(1), context)
                for match in REFERENCE_PATTERN.finditer(line)
            )

    if stack:
        raise ValueError(f"Unclosed preprocessor condition in {path}")

    return references


def simplify_contexts(
    contexts: list[ConditionContext],
) -> list[ConditionContext]:
    unique_contexts = list(dict.fromkeys(contexts))

    return [
        context
        for context in unique_contexts
        if not any(
            other != context and set(other).issubset(context)
            for other in unique_contexts
        )
    ]


def format_condition(contexts: list[ConditionContext]) -> str | None:
    contexts = simplify_contexts(contexts)

    if any(not context for context in contexts):
        return None

    branches = [
        context[0]
        if len(context) == 1
        else " && ".join(f"({expression})" for expression in context)
        for context in contexts
    ]

    if len(branches) == 1:
        return branches[0]

    return " || ".join(f"({branch})" for branch in branches)


def generation_number(path: Path) -> int:
    match = re.search(r"gen_(\d+)", path.name)
    if match is None:
        raise ValueError(f"Unable to determine generation from {path}")

    return int(match.group(1))


def species_files(data_dir: Path) -> list[Path]:
    family_files = sorted(
        (data_dir / "species_info").glob("gen_*_families.h"),
        key=generation_number,
    )

    return family_files + [data_dir / "species_info.h"]


def collect_symbols(data_dir: Path) -> list[ConditionalSymbol]:
    symbol_order = []
    contexts = {}

    for path in species_files(data_dir):
        for symbol, context in collect_references(path):
            if symbol == "sNoneLevelUpLearnset":
                continue

            if symbol not in contexts:
                symbol_order.append(symbol)
                contexts[symbol] = []

            contexts[symbol].append(context)

    return [
        (symbol, format_condition(contexts[symbol]))
        for symbol in symbol_order
    ]


def run_cpp(cpp: str, cpp_args: list[str], source: str) -> str:
    command = [cpp, *cpp_args, "-P"]
    result = subprocess.run(
        command,
        input=source,
        text=True,
        capture_output=True,
        check=False,
    )

    if result.returncode != 0:
        raise RuntimeError(
            f"C preprocessor failed: {' '.join(command)}\n{result.stderr}"
        )

    return result.stdout


def configured_generation(
    cpp: str,
    cpp_args: list[str],
    generation_count: int,
) -> int:
    branches = [
        "#ifndef P_LVL_UP_LEARNSETS",
        '#error "P_LVL_UP_LEARNSETS is not defined"',
        "#endif",
        "#if P_LVL_UP_LEARNSETS <= GEN_1",
        "0",
    ]

    for generation in range(2, generation_count):
        branches.extend(
            (
                f"#elif P_LVL_UP_LEARNSETS == GEN_{generation}",
                str(generation - 1),
            )
        )

    branches.extend(("#else", str(generation_count - 1), "#endif", ""))
    output = run_cpp(cpp, cpp_args, "\n".join(branches)).strip()

    if not output.isdecimal():
        raise ValueError(
            "Unable to determine the configured level-up learnset generation"
        )

    return int(output)


def render_array(symbol: str, moves: Learnset) -> list[str]:
    lines = [f"static const struct LevelUpMove {symbol}[] = {{"]
    lines.extend(
        f"    LEVEL_UP_MOVE({level:2}, {move}),"
        for level, move in moves
    )
    lines.extend(("    LEVEL_UP_END", "};", ""))
    return lines


def render(
    learnsets: Learnsets,
    symbols: list[ConditionalSymbol],
) -> str:
    missing = [symbol for symbol, _ in symbols if symbol not in learnsets]
    if missing:
        raise ValueError(f"No level-up data found for: {', '.join(missing)}")

    lines = [
        "// This file is initialized from official porymoves data.",
        "// Make does not overwrite it after creation; "
        "edit it for project-specific learnsets.",
        "// Run `make regenerate-level-up-learnsets` to replace it "
        "with fresh official data.",
        "",
        "#define LEVEL_UP_MOVE(lvl, moveLearned) "
        "{.move = moveLearned, .level = lvl}",
        "#define LEVEL_UP_END {.move = LEVEL_UP_MOVE_END, .level = 0}",
        "",
        "static const struct LevelUpMove sNoneLevelUpLearnset[] = {",
        "    LEVEL_UP_MOVE(1, MOVE_POUND),",
        "    LEVEL_UP_END",
        "};",
        "",
    ]
    active_condition = None

    for symbol, condition in symbols:
        if condition != active_condition:
            if active_condition is not None:
                lines.extend(("#endif", ""))

            if condition is not None:
                lines.append(f"#if {condition}")

            active_condition = condition

        lines.extend(render_array(symbol, learnsets[symbol]))

    if active_condition is not None:
        lines.append("#endif")

    return "\n".join(lines) + "\n"


def main() -> None:
    try:
        separator = sys.argv.index("--")
    except ValueError:
        separator = 0

    cpp_command = sys.argv[1:separator]
    input_arguments = sys.argv[separator + 1 :]

    if not cpp_command or len(input_arguments) != 3:
        raise SystemExit(
            f"Usage: {sys.argv[0]} CPP [CPP_ARG ...] -- "
            "INPUTS_DIR SPECIES_DATA_DIR OUTPUT_FILE"
        )

    cpp, *cpp_args = cpp_command
    inputs_dir, data_dir, output_file = map(Path, input_arguments)

    generations = load_generations(inputs_dir)
    generation_index = configured_generation(
        cpp,
        cpp_args,
        len(generations),
    )

    learnsets = select_learnsets(generations, generation_index)
    symbols = collect_symbols(data_dir)
    contents = render(learnsets, symbols)

    output_file.write_text(contents, encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
