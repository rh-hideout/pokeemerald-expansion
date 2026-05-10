"""
Write-back module for editing Pokemon data in pokeemerald-expansion source files.

Only edits fields that use plain, regex-safe patterns (no ternaries, no macros).
The parser's 'editable' flags indicate which fields are safe to write.
"""
import re
from pathlib import Path
from typing import Dict, List, Optional, Tuple


def _find_species_file(repo_root: Path, species_key: str, subdir: str) -> Optional[Path]:
    """Find which gen file contains a species key."""
    search_dir = repo_root / subdir
    for f in sorted(search_dir.glob("gen_*.h")):
        content = f.read_text(errors='ignore')
        if f'SPECIES_{species_key}' in content or f's{species_key.title().replace("_", "")}' in content:
            return f
    return None


def _find_species_info_file(repo_root: Path, species_key: str) -> Optional[Path]:
    return _find_species_file(repo_root, species_key, "src/data/pokemon/species_info")


def _find_learnset_file(repo_root: Path, species_key: str) -> Optional[Path]:
    return _find_species_file(repo_root, species_key, "src/data/pokemon/level_up_learnsets")


# ── Stats ──────────────────────────────────────────────────────────

STAT_FIELD_MAP = {
    'HP': 'baseHP',
    'Attack': 'baseAttack',
    'Defense': 'baseDefense',
    'Speed': 'baseSpeed',
    'SpAttack': 'baseSpAttack',
    'SpDefense': 'baseSpDefense',
}


def write_stats(repo_root: Path, species_key: str, stats: Dict[str, int]) -> Dict:
    """Write base stats for a species. Only works for plain integer stats."""
    f = _find_species_info_file(repo_root, species_key)
    if not f:
        return {'ok': False, 'error': f'Could not find file for {species_key}'}

    content = f.read_text(errors='ignore')

    # Find the species block
    block_pattern = rf'(\[SPECIES_{species_key}\]\s*=\s*\{{.+?)(?=\n    \[SPECIES_|\n#(?:if|endif|else|elif)|\Z)'
    block_match = re.search(block_pattern, content, re.DOTALL)
    if not block_match:
        return {'ok': False, 'error': f'Could not find [SPECIES_{species_key}] block'}

    block = block_match.group(1)
    new_block = block

    for stat_name, new_val in stats.items():
        field = STAT_FIELD_MAP.get(stat_name)
        if not field:
            return {'ok': False, 'error': f'Unknown stat: {stat_name}'}

        # Only replace plain integer values
        pattern = rf'(\.{field}\s*=\s*)(\d+)(,)'
        if not re.search(pattern, new_block):
            return {'ok': False, 'error': f'{field} is not a plain integer for {species_key}'}

        new_block = re.sub(pattern, rf'\g<1>{int(new_val)}\3', new_block)

    content = content.replace(block, new_block)
    f.write_text(content)
    return {'ok': True, 'file': str(f.relative_to(repo_root))}


# ── Types ──────────────────────────────────────────────────────────

def write_types(repo_root: Path, species_key: str, type1: str, type2: Optional[str]) -> Dict:
    """Write types for a species. Only works for direct MON_TYPES() pattern."""
    f = _find_species_info_file(repo_root, species_key)
    if not f:
        return {'ok': False, 'error': f'Could not find file for {species_key}'}

    content = f.read_text(errors='ignore')

    block_pattern = rf'(\[SPECIES_{species_key}\]\s*=\s*\{{.+?)(?=\n    \[SPECIES_|\n#(?:if|endif|else|elif)|\Z)'
    block_match = re.search(block_pattern, content, re.DOTALL)
    if not block_match:
        return {'ok': False, 'error': f'Could not find [SPECIES_{species_key}] block'}

    block = block_match.group(1)

    # Only replace direct MON_TYPES patterns
    pattern = r'(\.types\s*=\s*)MON_TYPES\(TYPE_\w+(?:,\s*TYPE_\w+)?\)'
    if not re.search(pattern, block):
        return {'ok': False, 'error': 'Types use macros — not editable'}

    if type2 and type2 != type1:
        replacement = rf'\1MON_TYPES(TYPE_{type1}, TYPE_{type2})'
    else:
        replacement = rf'\1MON_TYPES(TYPE_{type1}, TYPE_{type1})'

    new_block = re.sub(pattern, replacement, block)
    content = content.replace(block, new_block)
    f.write_text(content)
    return {'ok': True, 'file': str(f.relative_to(repo_root))}


# ── Abilities ──────────────────────────────────────────────────────

def write_abilities(repo_root: Path, species_key: str, abilities: List[str]) -> Dict:
    """Write abilities for a species. Expects 1-3 ability names (without ABILITY_ prefix)."""
    f = _find_species_info_file(repo_root, species_key)
    if not f:
        return {'ok': False, 'error': f'Could not find file for {species_key}'}

    content = f.read_text(errors='ignore')

    block_pattern = rf'(\[SPECIES_{species_key}\]\s*=\s*\{{.+?)(?=\n    \[SPECIES_|\n#(?:if|endif|else|elif)|\Z)'
    block_match = re.search(block_pattern, content, re.DOTALL)
    if not block_match:
        return {'ok': False, 'error': f'Could not find [SPECIES_{species_key}] block'}

    block = block_match.group(1)

    pattern = r'(\.abilities\s*=\s*)\{[^}]+\}'
    if not re.search(pattern, block):
        return {'ok': False, 'error': 'Abilities pattern not found'}

    # Pad to 3 entries
    while len(abilities) < 3:
        abilities.append('NONE')
    ab_str = ', '.join(f'ABILITY_{a}' for a in abilities[:3])
    new_block = re.sub(pattern, rf'\1{{ {ab_str} }}', block)

    content = content.replace(block, new_block)
    f.write_text(content)
    return {'ok': True, 'file': str(f.relative_to(repo_root))}


# ── Level-Up Moves ─────────────────────────────────────────────────

def _learnset_var_name(species_key: str) -> str:
    """Convert SPECIES_KEY to learnset variable name: BULBASAUR -> sBulbasaurLevelUpLearnset"""
    return 's' + species_key.title().replace('_', '') + 'LevelUpLearnset'


def write_level_up_moves(repo_root: Path, species_key: str,
                         moves: List[Tuple[int, str]]) -> Dict:
    """Write level-up learnset. moves is [(level, 'MOVE_NAME'), ...]."""
    # Find correct gen file — learnset arrays use camelCase names
    learnset_dir = repo_root / "src" / "data" / "pokemon" / "level_up_learnsets"
    var_name = _learnset_var_name(species_key)

    target_file = None
    for f in sorted(learnset_dir.glob("gen_*.h")):
        if var_name in f.read_text(errors='ignore'):
            target_file = f
            break

    # Also try without underscores for form species
    if not target_file:
        alt_name = 's' + species_key.replace('_', '').title() + 'LevelUpLearnset'
        for f in sorted(learnset_dir.glob("gen_*.h")):
            if alt_name in f.read_text(errors='ignore'):
                target_file = f
                var_name = alt_name
                break

    if not target_file:
        return {'ok': False, 'error': f'Could not find learnset for {species_key}'}

    content = target_file.read_text(errors='ignore')

    # Find the array
    pattern = rf'(static const struct LevelUpMove {var_name}\[\]\s*=\s*\{{)\s*\n(.+?)(LEVEL_UP_END\s*\}};)'
    match = re.search(pattern, content, re.DOTALL)
    if not match:
        return {'ok': False, 'error': f'Could not find {var_name} array'}

    # Build new move entries
    lines = []
    for level, move in moves:
        move_const = move if move.startswith('MOVE_') else f'MOVE_{move}'
        lines.append(f'    LEVEL_UP_MOVE({level:2d}, {move_const}),')
    lines.append(f'    LEVEL_UP_END')

    new_body = match.group(1) + '\n' + '\n'.join(lines) + '\n};'
    content = content[:match.start()] + new_body + content[match.end():]

    target_file.write_text(content)
    return {'ok': True, 'file': str(target_file.relative_to(repo_root))}


# ── Egg Moves ──────────────────────────────────────────────────────

def _egg_move_var_name(species_key: str) -> str:
    return 's' + species_key.title().replace('_', '') + 'EggMoveLearnset'


def write_egg_moves(repo_root: Path, species_key: str, moves: List[str]) -> Dict:
    """Write egg moves. moves is ['MOVE_NAME', ...]."""
    egg_path = repo_root / "src" / "data" / "pokemon" / "egg_moves.h"
    if not egg_path.exists():
        return {'ok': False, 'error': 'egg_moves.h not found'}

    content = egg_path.read_text(errors='ignore')
    var_name = _egg_move_var_name(species_key)

    pattern = rf'(static const u16 {var_name}\[\]\s*=\s*\{{)\s*\n(.+?)(MOVE_UNAVAILABLE\s*,?\s*\}};)'
    match = re.search(pattern, content, re.DOTALL)
    if not match:
        return {'ok': False, 'error': f'Could not find {var_name} array'}

    lines = []
    for move in moves:
        move_const = move if move.startswith('MOVE_') else f'MOVE_{move}'
        lines.append(f'    {move_const},')
    lines.append(f'    MOVE_UNAVAILABLE,')

    new_body = match.group(1) + '\n' + '\n'.join(lines) + '\n};'
    content = content[:match.start()] + new_body + content[match.end():]

    egg_path.write_text(content)
    return {'ok': True, 'file': 'src/data/pokemon/egg_moves.h'}


# ── Dispatch ───────────────────────────────────────────────────────

def apply_edit(repo_root: Path, edit: Dict) -> Dict:
    """Apply a single edit. edit has keys: species, field, value."""
    species = edit['species']
    field = edit['field']
    value = edit['value']

    if field == 'stats':
        return write_stats(repo_root, species, value)
    elif field == 'types':
        return write_types(repo_root, species, value.get('type1', ''), value.get('type2'))
    elif field == 'abilities':
        return write_abilities(repo_root, species, value)
    elif field == 'level_up_moves':
        return write_level_up_moves(repo_root, species, value)
    elif field == 'egg_moves':
        return write_egg_moves(repo_root, species, value)
    else:
        return {'ok': False, 'error': f'Unknown field: {field}'}
