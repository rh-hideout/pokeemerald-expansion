"""
Parser module for extracting Pokemon data from pokeemerald-expansion codebase.
"""
import re
import json
from typing import Dict, List, Tuple, Optional
from pathlib import Path


class PokemonDataParser:
    """Parses Pokemon data from the codebase."""

    def __init__(self, repo_root: Path):
        self.repo_root = Path(repo_root)
        self.species_info_path = self.repo_root / "src" / "data" / "pokemon" / "species_info"
        self.learnsets_path = self.repo_root / "src" / "data" / "pokemon" / "level_up_learnsets"
        self.teachable_path = self.repo_root / "src" / "data" / "pokemon" / "teachable_learnsets.h"
        self.egg_moves_path = self.repo_root / "src" / "data" / "pokemon" / "egg_moves.h"
        self.tms_hms_path = self.repo_root / "include" / "constants" / "tms_hms.h"
        self.species_enabled_path = self.repo_root / "include" / "config" / "species_enabled.h"
        self.pokedex_h_path = self.repo_root / "include" / "constants" / "pokedex.h"
        self._tm_hm_moves = None  # Cache for TM/HM moves
        self._natdex_numbers = None  # Cache for natdex name -> number mapping

    def parse_natdex_numbers(self) -> Dict[str, int]:
        """Parse NATIONAL_DEX_X enum from pokedex.h to get name -> number mapping."""
        if self._natdex_numbers is not None:
            return self._natdex_numbers

        numbers = {}
        if not self.pokedex_h_path.exists():
            self._natdex_numbers = numbers
            return numbers

        content = self.pokedex_h_path.read_text(errors='ignore')

        # Extract just the enum block
        enum_match = re.search(r'enum\s+NationalDexOrder\s*\{(.+?)\};', content, re.DOTALL)
        if not enum_match:
            self._natdex_numbers = numbers
            return numbers

        enum_body = enum_match.group(1)
        idx = 0
        for m in re.finditer(r'NATIONAL_DEX_(\w+)', enum_body):
            name = m.group(1)
            if name == 'NONE':
                idx = 0
            else:
                idx += 1
                numbers[name] = idx

        self._natdex_numbers = numbers
        return numbers

    @staticmethod
    def _resolve_stat_value(expr: str, macros: Dict[str, int]) -> Optional[int]:
        """Resolve a stat value expression to an integer.

        Handles:
        - Plain integers: "65"
        - Ternary with P_UPDATED_STATS: "P_UPDATED_STATS >= GEN_6 ? 90 : 80" -> 90 (latest)
        - Macro references: "BEEDRILL_ATTACK" -> lookup
        - Macro + offset: "BEEDRILL_ATTACK + 60" -> lookup + 60
        """
        expr = expr.strip().rstrip(',')

        # Plain integer
        if re.fullmatch(r'\d+', expr):
            return int(expr)

        # Ternary: take the first (latest gen) value
        ternary = re.search(r'\?\s*(\d+)\s*:', expr)
        if ternary:
            return int(ternary.group(1))

        # Macro + offset: MACRO_NAME + N or MACRO_NAME - N
        arith = re.match(r'([A-Z_]\w+)\s*([+-])\s*(\d+)', expr)
        if arith:
            macro_val = macros.get(arith.group(1))
            if macro_val is not None:
                op = arith.group(2)
                offset = int(arith.group(3))
                return macro_val + offset if op == '+' else macro_val - offset

        # Plain macro reference
        macro_val = macros.get(expr)
        if macro_val is not None:
            return macro_val

        return None

    @staticmethod
    def _parse_stat_macros(content: str) -> Dict[str, int]:
        """Extract #define MACRO_NAME (ternary or value) stat macros from file content."""
        macros = {}
        for m in re.finditer(r'#define\s+([A-Z_]\w+)\s+\(P_UPDATED_STATS\s*>=\s*\w+\s*\?\s*(\d+)\s*:\s*(\d+)\)', content):
            macros[m.group(1)] = int(m.group(2))  # latest gen value
        # Also match simple numeric #defines that look like stat macros
        for m in re.finditer(r'#define\s+([A-Z][A-Z_0-9]*(?:_(?:ATTACK|DEFENSE|SPEED|HP|SP_ATTACK|SP_DEFENSE))?)\s+(\d+)\s*$', content, re.MULTILINE):
            macros[m.group(1)] = int(m.group(2))
        return macros

    @staticmethod
    def _parse_type_macros(content: str) -> Dict[str, tuple]:
        """Extract type-related macros from file content.

        Handles:
        - #define X_TYPES { TYPE_A, TYPE_B } or MON_TYPES(TYPE_A, TYPE_B)
        - #define X_TYPE2 (P_UPDATED_TYPES >= GEN_X ? TYPE_A : TYPE_B) -> TYPE_A (latest)

        For conditional #if blocks, takes the first (latest gen) definition.
        Returns dict mapping macro name -> (type1, type2_or_None) for _TYPES macros,
        or macro name -> (type, None) for single-type macros.
        """
        type_macros = {}
        # Pattern 1: #define X_TYPES { TYPE_A, TYPE_B } or MON_TYPES(TYPE_A, TYPE_B)
        for m in re.finditer(
            r'#define\s+(\w+_TYPES)\s+'
            r'(?:\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}|MON_TYPES\(TYPE_(\w+)(?:,\s*TYPE_(\w+))?\))',
            content
        ):
            name = m.group(1)
            if name in type_macros:
                continue  # Keep first definition (latest gen in #if blocks)
            t1 = m.group(2) or m.group(4)
            t2 = m.group(3) or m.group(5)
            type_macros[name] = (t1, t2 if t2 and t2 != t1 else None)

        # Pattern 2: #define X_TYPE2 (P_UPDATED_TYPES >= GEN_X ? TYPE_A : TYPE_B)
        for m in re.finditer(
            r'#define\s+(\w+_TYPE\d?)\s+\(P_UPDATED_TYPES\s*>=\s*\w+\s*\?\s*TYPE_(\w+)\s*:\s*TYPE_(\w+)\)',
            content
        ):
            name = m.group(1)
            if name not in type_macros:
                type_macros[name] = (m.group(2), None)  # Latest gen value

        return type_macros

    @staticmethod
    def _parse_info_macros(content: str) -> Dict[str, str]:
        """Extract multi-line #define macros that contain species info (.base*, .types, .abilities).

        Returns a dict mapping macro name (without params) to the expanded body text.
        Handles backslash-continued lines. Also captures macros that invoke other info macros.
        """
        all_macros = {}
        # Match #define MACRO_NAME(params) followed by backslash-continued lines
        pattern = r'#define\s+(\w+)\([^)]*\)\s*\\?\n((?:.*\\\n)*.*?\n)'
        for m in re.finditer(pattern, content):
            macro_name = m.group(1)
            macro_body = m.group(2).replace('\\\n', '\n')
            all_macros[macro_name] = macro_body

        # First pass: identify macros with direct species data fields
        info_macros = {}
        for name, body in all_macros.items():
            if '.base' in body or '.types' in body or '.abilities' in body:
                info_macros[name] = body

        # Second pass: include macros that invoke known info macros
        changed = True
        while changed:
            changed = False
            for name, body in all_macros.items():
                if name in info_macros:
                    continue
                for info_name in list(info_macros.keys()):
                    if info_name + '(' in body:
                        info_macros[name] = body
                        changed = True
                        break

        return info_macros

    def _extract_species_fields(self, text: str, stat_macros: Dict[str, int],
                               type_macros: Dict[str, tuple] = None) -> Dict:
        """Extract stats, types, abilities, evolutions from a text block."""
        result = {}

        # Extract base stats + track editability
        stats = {}
        stats_editable = True  # all 6 must be plain ints
        for stat in ['HP', 'Attack', 'Defense', 'Speed', 'SpAttack', 'SpDefense']:
            stat_match = re.search(rf'\.base{stat}\s*=\s*(.+?)(?:,|\s*\\?\n)', text)
            if stat_match:
                raw = stat_match.group(1).strip().rstrip(',')
                resolved = self._resolve_stat_value(raw, stat_macros)
                if resolved is not None:
                    stats[stat] = resolved
                if not re.fullmatch(r'\d+', raw):
                    stats_editable = False
        result['stats'] = stats
        result['_stats_editable'] = stats_editable

        # Extract types - try multiple patterns
        type1, type2 = None, None
        types_editable = False  # only True for direct MON_TYPES(TYPE_X, TYPE_Y)

        # Pattern 1: MON_TYPES(TYPE_X) or MON_TYPES(TYPE_X, TYPE_Y)
        types_match = re.search(r'\.types\s*=\s*MON_TYPES\(TYPE_(\w+)(?:,\s*TYPE_(\w+))?\)', text)
        if types_match:
            type1 = types_match.group(1)
            type2 = types_match.group(2)
            types_editable = True
        else:
            # Pattern 2: MON_TYPES(TYPE_X, MACRO_REF) - second arg is a macro
            types_match = re.search(r'\.types\s*=\s*MON_TYPES\(TYPE_(\w+),\s*(\w+)\)', text)
            if types_match:
                type1 = types_match.group(1)
                macro_ref = types_match.group(2)
                # Resolve the macro from type_macros (handles ternary P_UPDATED_TYPES macros)
                if type_macros and macro_ref in type_macros:
                    type2 = type_macros[macro_ref][0]  # First element is the resolved type
                else:
                    type2 = None

        if not type1:
            # Pattern 2b: MON_TYPES(MACRO_REF) or MON_TYPES(MACRO_REF, TYPE_X)
            types_match2 = re.search(r'\.types\s*=\s*MON_TYPES\((\w+)(?:,\s*TYPE_(\w+))?\)', text)
            if types_match2 and not types_match2.group(1).startswith('TYPE_'):
                macro_ref = types_match2.group(1)
                if type_macros and macro_ref in type_macros:
                    type1 = type_macros[macro_ref][0]
                type2 = types_match2.group(2) if types_match2.group(2) else None

        if not type1:
            # Pattern 3: { TYPE_X, TYPE_Y }
            types_match = re.search(r'\.types\s*=\s*\{\s*TYPE_(\w+)\s*,\s*TYPE_(\w+)\s*\}', text)
            if types_match:
                type1 = types_match.group(1)
                type2 = types_match.group(2)

        if not type1:
            # Pattern 4: .types = SOME_FAMILY_TYPES (whole-type macro)
            type_macro_match = re.search(r'\.types\s*=\s*([A-Z_]\w+_TYPES)\b', text)
            if type_macro_match and type_macros and type_macro_match.group(1) in type_macros:
                type1, type2 = type_macros[type_macro_match.group(1)]

        # Normalize: if type2 == type1, it's single-typed
        if type2 and type2 == type1:
            type2 = None

        result['type1'] = type1
        result['type2'] = type2
        result['_types_editable'] = types_editable

        # Extract abilities
        abilities = []
        abilities_editable = False
        abilities_match = re.search(r'\.abilities\s*=\s*\{\s*ABILITY_(\w+)(?:,\s*ABILITY_(\w+))?(?:,\s*ABILITY_(\w+))?\s*\}', text)
        if abilities_match:
            abilities_editable = True
            for i in range(1, 4):
                if abilities_match.group(i) and abilities_match.group(i) != 'NONE':
                    abilities.append(abilities_match.group(i))
        result['abilities'] = abilities
        result['_abilities_editable'] = abilities_editable

        # Extract national dex number
        natdex_match = re.search(r'\.natDexNum\s*=\s*NATIONAL_DEX_(\w+)', text)
        result['natdex'] = natdex_match.group(1) if natdex_match else None

        # Extract evolutions
        evolutions = []
        evolutions_match = re.search(r'\.evolutions\s*=\s*EVOLUTION\((.+?)\)\s*[,\\]', text, re.DOTALL)
        if evolutions_match:
            evo_entries = re.finditer(r'\{(\w+),\s*(.+?),\s*SPECIES_(\w+)', evolutions_match.group(1))
            for evo in evo_entries:
                evolutions.append({
                    'method': evo.group(1),
                    'condition': evo.group(2).strip(),
                    'target': evo.group(3)
                })
        result['evolutions'] = evolutions

        return result

    def _fill_from_info_macros(self, fields: Dict, text: str,
                              info_macros: Dict[str, str], stat_macros: Dict[str, int],
                              type_macros: Dict[str, tuple] = None,
                              visited: set = None):
        """Recursively fill missing fields from info macros found in text."""
        if visited is None:
            visited = set()

        for macro_name, macro_body in info_macros.items():
            if macro_name in visited:
                continue
            if macro_name + '(' not in text:
                continue

            visited.add(macro_name)
            macro_fields = self._extract_species_fields(macro_body, stat_macros, type_macros)

            # Fill in missing fields
            for stat_key, stat_val in macro_fields['stats'].items():
                if stat_key not in fields['stats']:
                    fields['stats'][stat_key] = stat_val
            if not fields['type1'] and macro_fields['type1']:
                fields['type1'] = macro_fields['type1']
                fields['type2'] = macro_fields['type2']
            if not fields['abilities'] and macro_fields['abilities']:
                fields['abilities'] = macro_fields['abilities']
            if not fields['evolutions'] and macro_fields['evolutions']:
                fields['evolutions'] = macro_fields['evolutions']
            if not fields['natdex'] and macro_fields['natdex']:
                fields['natdex'] = macro_fields['natdex']

            # Recurse: this macro's body might reference other info macros
            if len(fields['stats']) < 6 or not fields['type1'] or not fields['abilities']:
                self._fill_from_info_macros(fields, macro_body, info_macros, stat_macros, type_macros, visited)

    def parse_species_info(self) -> Dict[str, Dict]:
        """Parse all species info from gen_X_families.h files."""
        pokemon_data = {}
        natdex_numbers = self.parse_natdex_numbers()

        for gen_file in sorted(self.species_info_path.glob("gen_*_families.h")):
            gen_match = re.search(r'gen_(\d+)', gen_file.name)
            if not gen_match:
                continue
            gen_num = int(gen_match.group(1))

            content = gen_file.read_text(errors='ignore')

            # Collect stat macros, type macros, and info macros defined in this file
            stat_macros = self._parse_stat_macros(content)
            type_macros = self._parse_type_macros(content)
            info_macros = self._parse_info_macros(content)

            # Find family definitions
            family_pattern = r'#if\s+(P_FAMILY_\w+)'
            current_family = None

            # Find all pokemon entries with explicit struct bodies
            # Match from [SPECIES_X] = { to the next [SPECIES_ or preprocessor directive
            pattern = r'\[SPECIES_(\w+)\]\s*=\s*\{(.+?)(?=\n    \[SPECIES_|\n#(?:if|endif|else|elif)|\Z)'
            matches = list(re.finditer(pattern, content, re.DOTALL))

            # Also find one-line macro species: [SPECIES_X] = MACRO_NAME(args),
            oneliner_pattern = r'\[SPECIES_(\w+)\]\s*=\s*(\w+)\(([^)]*)\)\s*[,;]'
            oneliner_matches = list(re.finditer(oneliner_pattern, content))

            # Process explicit struct species
            for match in matches:
                species_name = match.group(1)
                species_block = match.group(2)

                # Find the family for this species by looking backwards
                pos = match.start()
                preceding_text = content[:pos]
                family_matches = list(re.finditer(family_pattern, preceding_text))
                if family_matches:
                    current_family = family_matches[-1].group(1)

                # Extract fields directly from the species block
                fields = self._extract_species_fields(species_block, stat_macros, type_macros)

                # If stats/types/abilities are missing, check for info macro invocations
                # Follow macro chains (e.g. FLOETTE_NORMAL_INFO -> FLOETTE_MISC_INFO)
                self._fill_from_info_macros(fields, species_block, info_macros, stat_macros, type_macros)

                natdex_name = fields['natdex'] or species_name
                natdex_num = natdex_numbers.get(natdex_name, 0)
                stats = fields['stats']
                bst = sum(stats.values()) if stats else 0

                pokemon_data[species_name] = {
                    'name': species_name.title().replace('_', ' '),
                    'species_const': f'SPECIES_{species_name}',
                    'generation': gen_num,
                    'natdex': natdex_num,
                    'stats': stats,
                    'bst': bst,
                    'type1': fields['type1'],
                    'type2': fields['type2'],
                    'abilities': fields['abilities'],
                    'evolutions': fields['evolutions'],
                    'family': current_family,
                    'editable': {
                        'stats': fields.get('_stats_editable', False),
                        'types': fields.get('_types_editable', False),
                        'abilities': fields.get('_abilities_editable', False),
                        'level_up_moves': True,
                        'egg_moves': True,
                    }
                }

            # Process one-line macro species (e.g. Alcremie forms, Arceus forms)
            for match in oneliner_matches:
                species_name = match.group(1)
                macro_name = match.group(2)

                # Skip if already parsed via struct pattern
                if species_name in pokemon_data:
                    continue

                # Find the family for this species
                pos = match.start()
                preceding_text = content[:pos]
                family_matches_list = list(re.finditer(family_pattern, preceding_text))
                if family_matches_list:
                    current_family = family_matches_list[-1].group(1)

                # Resolve fields by following the macro chain using the same helper
                combined_fields = {'stats': {}, 'type1': None, 'type2': None,
                                   'abilities': [], 'evolutions': [], 'natdex': None}
                # Create a synthetic text with the macro invocation so chain-following works
                synthetic_text = f'{macro_name}()'
                self._fill_from_info_macros(combined_fields, synthetic_text, info_macros, stat_macros, type_macros)

                # For species where type comes from macro arguments (e.g. Arceus, Silvally),
                # try to extract TYPE_X from the call arguments
                if not combined_fields['type1']:
                    macro_args = match.group(3)  # The arguments in MACRO(args)
                    type_arg = re.search(r'TYPE_(\w+)', macro_args)
                    if type_arg:
                        combined_fields['type1'] = type_arg.group(1)

                # Skip species where we couldn't resolve any stats
                if not combined_fields['stats']:
                    continue

                natdex_name = combined_fields['natdex'] or species_name
                natdex_num = natdex_numbers.get(natdex_name, 0)
                stats = combined_fields['stats']
                bst = sum(stats.values()) if stats else 0

                pokemon_data[species_name] = {
                    'name': species_name.title().replace('_', ' '),
                    'species_const': f'SPECIES_{species_name}',
                    'generation': gen_num,
                    'natdex': natdex_num,
                    'stats': stats,
                    'bst': bst,
                    'type1': combined_fields['type1'],
                    'type2': combined_fields['type2'],
                    'abilities': combined_fields['abilities'],
                    'evolutions': combined_fields['evolutions'],
                    'family': current_family,
                    'editable': {
                        'stats': False,
                        'types': False,
                        'abilities': False,
                        'level_up_moves': True,
                        'egg_moves': True,
                    }
                }

        return pokemon_data

    def get_pokedex_database(self) -> Dict[str, Dict]:
        """Get Pokemon database for pokedex manager (no learnsets, includes enabled status)."""
        print("Parsing species info for pokedex...")
        pokemon_data = self.parse_species_info()

        print("Parsing family definitions...")
        family_defs = self.parse_family_definitions()
        enabled_families = self.get_enabled_families(family_defs)

        for species_name, data in pokemon_data.items():
            family = data.get('family')
            data['enabled'] = family in enabled_families if family else False

        return pokemon_data, family_defs

    def parse_family_definitions(self) -> Dict[str, str]:
        """Parse P_FAMILY_X definitions from species_enabled.h."""
        family_defs = {}

        if not self.species_enabled_path.exists():
            return family_defs

        content = self.species_enabled_path.read_text(errors='ignore')

        # Parse family definitions
        pattern = r'#define\s+P_FAMILY_(\w+)\s+(.+?)(?://|$)'
        matches = re.finditer(pattern, content, re.MULTILINE)

        for match in matches:
            family_name = match.group(1)
            family_value = match.group(2).strip()
            family_defs[f'P_FAMILY_{family_name}'] = family_value

        return family_defs

    def get_enabled_families(self, family_defs: Dict[str, str]) -> set:
        """Determine which families are enabled based on definitions."""
        enabled = set()

        # Parse generation definitions
        gen_pattern = r'#define\s+P_GEN_(\d+)_POKEMON\s+(TRUE|FALSE)'
        if self.species_enabled_path.exists():
            content = self.species_enabled_path.read_text(errors='ignore')
            gen_matches = re.finditer(gen_pattern, content, re.MULTILINE)

            gen_enabled = {}
            for match in gen_matches:
                gen_num = int(match.group(1))
                is_enabled = match.group(2) == 'TRUE'
                gen_enabled[f'P_GEN_{gen_num}_POKEMON'] = is_enabled
        else:
            # Default all to enabled if file doesn't exist
            gen_enabled = {f'P_GEN_{i}_POKEMON': True for i in range(1, 10)}

        for family_name, family_value in family_defs.items():
            # Check if it's directly TRUE/FALSE
            if family_value == 'TRUE':
                enabled.add(family_name)
            elif family_value == 'FALSE':
                continue
            # Check if it references a generation
            elif family_value in gen_enabled:
                if gen_enabled[family_value]:
                    enabled.add(family_name)
            else:
                # It might reference another define, for simplicity assume enabled if not FALSE
                enabled.add(family_name)

        return enabled

    def parse_level_up_learnsets(self) -> Dict[str, Dict[int, List[Tuple[int, str]]]]:
        """Parse level up learnsets from gen_X.h files.

        Returns a dict mapping species names to dicts of {generation: [(level, move), ...]}
        """
        learnsets = {}

        for gen_file in sorted(self.learnsets_path.glob("gen_*.h")):
            # Extract generation number from filename
            gen_match = re.search(r'gen_(\d+)', gen_file.name)
            if not gen_match:
                continue
            gen_num = int(gen_match.group(1))

            content = gen_file.read_text(errors='ignore')

            # Find all learnset arrays
            pattern = r'static const struct LevelUpMove s(\w+)LevelUpLearnset\[\]\s*=\s*\{([^}]+)\}'
            matches = re.finditer(pattern, content, re.DOTALL)

            for match in matches:
                species_name = match.group(1).upper()
                learnset_block = match.group(2)

                # Extract moves
                moves = []
                move_pattern = r'LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*MOVE_(\w+)\s*\)'
                move_matches = re.finditer(move_pattern, learnset_block)

                for move_match in move_matches:
                    level = int(move_match.group(1))
                    move = move_match.group(2)
                    moves.append((level, move))

                # Store by generation
                if species_name not in learnsets:
                    learnsets[species_name] = {}
                learnsets[species_name][gen_num] = moves

        return learnsets

    def parse_tm_hm_moves(self) -> set:
        """Parse the list of TM/HM moves from tms_hms.h."""
        if self._tm_hm_moves is not None:
            return self._tm_hm_moves

        tm_hm_moves = set()

        if not self.tms_hms_path.exists():
            self._tm_hm_moves = tm_hm_moves
            return tm_hm_moves

        content = self.tms_hms_path.read_text(errors='ignore')

        # Find all moves in FOREACH_TM and FOREACH_HM macros
        # Pattern matches multiline macros with backslash continuation
        for macro in ['FOREACH_TM', 'FOREACH_HM']:
            pattern = rf'#define {macro}\(F\)[^\n]*\n((?:.*?F\([^)]+\)[^\n]*\n)+)'
            match = re.search(pattern, content, re.MULTILINE)
            if match:
                moves_block = match.group(1)
                # Extract move names from F(MOVE_NAME) format
                move_pattern = r'F\((\w+)\)'
                for move_match in re.finditer(move_pattern, moves_block):
                    tm_hm_moves.add(move_match.group(1))

        self._tm_hm_moves = tm_hm_moves
        return tm_hm_moves

    def parse_teachable_learnsets(self) -> Dict[str, List[Dict[str, str]]]:
        """Parse teachable learnsets (TM/HM/Tutor) from teachable_learnsets.h with source info."""
        learnsets = {}

        if not self.teachable_path.exists():
            return learnsets

        content = self.teachable_path.read_text(errors='ignore')
        tm_hm_moves = self.parse_tm_hm_moves()

        # Find all teachable learnset arrays
        pattern = r'static const u16 s(\w+)TeachableLearnset\[\]\s*=\s*\{([^}]+)\}'
        matches = re.finditer(pattern, content, re.DOTALL)

        for match in matches:
            species_name = match.group(1).upper()
            learnset_block = match.group(2)

            # Extract moves with source
            moves = []
            move_pattern = r'MOVE_(\w+)'
            move_matches = re.finditer(move_pattern, learnset_block)

            for move_match in move_matches:
                move = move_match.group(1)
                if move != 'UNAVAILABLE' and move != 'NONE':
                    # Determine if TM/HM or Tutor
                    source = 'TM/HM' if move in tm_hm_moves else 'TUTOR'
                    moves.append({'move': move, 'source': source})

            learnsets[species_name] = moves

        return learnsets

    def parse_egg_moves(self) -> Dict[str, List[str]]:
        """Parse egg moves from egg_moves.h."""
        egg_moves = {}

        if not self.egg_moves_path.exists():
            return egg_moves

        content = self.egg_moves_path.read_text(errors='ignore')

        # Find all egg move arrays
        pattern = r'static const u16 s(\w+)EggMoveLearnset\[\]\s*=\s*\{([^}]+)\}'
        matches = re.finditer(pattern, content, re.DOTALL)

        for match in matches:
            species_name = match.group(1).upper()
            learnset_block = match.group(2)

            # Extract moves
            moves = []
            move_pattern = r'MOVE_(\w+)'
            move_matches = re.finditer(move_pattern, learnset_block)

            for move_match in move_matches:
                move = move_match.group(1)
                if move != 'UNAVAILABLE' and move != 'NONE':
                    moves.append(move)

            egg_moves[species_name] = moves

        return egg_moves

    @staticmethod
    def _get_base_species_name(species_name: str) -> str:
        """Get base species name by removing common form suffixes.

        For example: EISCUE_ICE -> EISCUE, LYCANROC_MIDDAY -> LYCANROC
        """
        # Common form suffixes used in pokeemerald-expansion
        form_suffixes = [
            'ICE', 'NOICE', 'MIDDAY', 'MIDNIGHT', 'DUSK',
            'ALOLA', 'GALAR', 'HISUI', 'PALDEA',
            'MEGA', 'MEGA_X', 'MEGA_Y', 'PRIMAL', 'ORIGIN', 'SKY', 'LAND', 'SEA',
            'THERIAN', 'INCARNATE', 'ARIA', 'PIROUETTE',
            'STANDARD', 'ZEN', 'ORDINARY', 'RESOLUTE',
            'WHITE', 'BLACK', 'SHIELD', 'BLADE',
            'AVERAGE', 'SMALL', 'LARGE', 'SUPER',
            'ATTACK', 'DEFENSE', 'SPEED',
            'PLANT', 'SANDY', 'TRASH', 'FROST', 'FAN', 'MOW', 'WASH', 'HEAT', 'SPIN', 'CUT',
            'BLUE', 'RED', 'YELLOW', 'GREEN', 'ORANGE', 'PURPLE', 'PINK',
            'METEOR', 'SUNSHINE',
            'EAST', 'WEST', 'NORTH', 'SOUTH',
            'SOLO', 'SCHOOL',
            'BATTLE', 'BAILE', 'POM_POM', 'PAU', 'SENSU',
            'DISGUISED', 'BUSTED', 'TOTEM', 'ULTRA', 'ORIGINAL',
            'HANGRY', 'FULL_BELLY', 'LOW_KEY', 'AMPED',
            'SINGLE_STRIKE', 'RAPID_STRIKE', 'DADA',
            'ICE_RIDER', 'SHADOW_RIDER', 'HERO', 'FAMILY',
            'DROOPY', 'STRETCHY', 'ROAMING', 'COMPLETE', 'BLOODMOON',
            'OWN_TEMPO', 'NORMAL'
        ]

        # Try to match and remove a suffix
        for suffix in form_suffixes:
            if species_name.endswith(f'_{suffix}'):
                return species_name[:-len(suffix)-1]

        return species_name

    def get_full_pokemon_database(self, filter_by_enabled: bool = False) -> Dict[str, Dict]:
        """Get complete Pokemon database with all data."""
        print("Parsing species info...")
        pokemon_data = self.parse_species_info()

        print("Parsing level up learnsets...")
        level_up_learnsets = self.parse_level_up_learnsets()

        print("Parsing teachable learnsets...")
        teachable_learnsets = self.parse_teachable_learnsets()

        print("Parsing egg moves...")
        egg_moves = self.parse_egg_moves()

        # Always parse enabled status
        print("Parsing family definitions...")
        family_defs = self.parse_family_definitions()
        enabled_families = self.get_enabled_families(family_defs)

        # Combine all data
        for species_name, data in pokemon_data.items():
            # Add learnsets - try multiple lookup strategies
            # 1. Exact match
            data['level_up_moves'] = level_up_learnsets.get(species_name, [])
            if not data['level_up_moves']:
                # 2. Try base name (remove form suffix with underscore)
                base_name = self._get_base_species_name(species_name)
                data['level_up_moves'] = level_up_learnsets.get(base_name, [])
            if not data['level_up_moves']:
                # 3. Try without underscores (for camelCase learnsets like LYCANROCMIDDAY)
                no_underscore = species_name.replace('_', '')
                data['level_up_moves'] = level_up_learnsets.get(no_underscore, [])

            data['teachable_moves'] = teachable_learnsets.get(species_name, [])
            if not data['teachable_moves']:
                base_name = self._get_base_species_name(species_name)
                data['teachable_moves'] = teachable_learnsets.get(base_name, [])
            if not data['teachable_moves']:
                no_underscore = species_name.replace('_', '')
                data['teachable_moves'] = teachable_learnsets.get(no_underscore, [])

            data['egg_moves'] = egg_moves.get(species_name, [])
            if not data['egg_moves']:
                base_name = self._get_base_species_name(species_name)
                data['egg_moves'] = egg_moves.get(base_name, [])
            if not data['egg_moves']:
                no_underscore = species_name.replace('_', '')
                data['egg_moves'] = egg_moves.get(no_underscore, [])

            # Always tag enabled status
            family = data.get('family')
            data['enabled'] = family in enabled_families if family else False

        # Filter out disabled Pokemon if requested
        if filter_by_enabled:
            pokemon_data = {k: v for k, v in pokemon_data.items() if v.get('enabled', False)}

        return pokemon_data


def merge_twop_data(pokemon_data: Dict[str, Dict], twop_path: Path):
    """Merge twop_pokemon_data.json fields (region, habitat, overview) into species data."""
    if not twop_path.exists():
        print(f"  twop data not found at {twop_path}, skipping")
        return

    with open(twop_path) as f:
        twop = json.load(f)

    matched = 0
    for species_key, data in pokemon_data.items():
        twop_entry = twop.get(species_key)
        if twop_entry:
            data['region'] = twop_entry.get('region')
            data['habitat'] = twop_entry.get('habitat')
            data['overview'] = twop_entry.get('overview')
            matched += 1

    print(f"  Merged twop data for {matched}/{len(pokemon_data)} species")


def build_form_groups(pokemon_data: Dict[str, Dict]) -> Dict[int, Dict]:
    """Group species by natdex number. Returns {natdex: {base: key, forms: [keys]}}."""
    # Known form suffixes that indicate a non-base form
    FORM_SUFFIXES = {
        'MEGA', 'MEGA_X', 'MEGA_Y', 'PRIMAL', 'GMAX', 'GIGANTAMAX', 'TOTEM',
        'ALOLA', 'GALAR', 'HISUI', 'PALDEA',
        'ORIGIN', 'SKY', 'LAND', 'SEA', 'THERIAN', 'INCARNATE',
        'ATTACK', 'DEFENSE', 'SPEED', 'NORMAL',
        'COSPLAY', 'ROCK_STAR', 'BELLE', 'POP_STAR', 'PHD', 'LIBRE',
        'ORIGINAL', 'HOENN', 'SINNOH', 'UNOVA', 'KALOS', 'PARTNER', 'WORLD',
        'STARTER', 'SPIKY_EARED',
        'SUNNY', 'SUNSHINE', 'RAINY', 'SNOWY',
        'SANDY', 'TRASH', 'FROST', 'FAN', 'MOW', 'WASH', 'HEAT', 'SPIN', 'CUT',
        'WHITE', 'BLACK', 'SHIELD', 'BLADE',
        'ARIA', 'PIROUETTE', 'ZEN', 'RESOLUTE',
        'MIDDAY', 'MIDNIGHT', 'DUSK', 'OWN_TEMPO',
        'SCHOOL', 'SOLO', 'METEOR', 'CORE',
        'BAILE', 'POM_POM', 'PAU', 'SENSU',
        'DISGUISED', 'BUSTED', 'ULTRA',
        'HANGRY', 'FULL_BELLY', 'LOW_KEY', 'AMPED', 'DADA',
        'SINGLE_STRIKE', 'RAPID_STRIKE',
        'ICE_RIDER', 'SHADOW_RIDER', 'HERO',
        'DROOPY', 'STRETCHY', 'ROAMING', 'COMPLETE', 'BLOODMOON',
        'ICE', 'NOICE', 'CROWNED', 'ETERNAMAX',
        'TEAL', 'WELLSPRING', 'HEARTHFLAME', 'CORNERSTONE',
        'TEAL_TERA', 'WELLSPRING_TERA', 'HEARTHFLAME_TERA', 'CORNERSTONE_TERA',
        'FAMILY',
        # Type-based forms (Arceus, Silvally)
        'BUG', 'DARK', 'DRAGON', 'ELECTRIC', 'FAIRY', 'FIGHTING', 'FIRE',
        'FLYING', 'GHOST', 'GRASS', 'GROUND', 'ICE', 'POISON', 'PSYCHIC',
        'ROCK', 'STEEL', 'WATER', 'STELLAR',
    }

    # Suffixes that suggest a "default" form when no plain base exists
    DEFAULT_FORM_SUFFIXES = {'NORMAL', 'STANDARD', 'AVERAGE', 'NATURAL', 'INCARNATE',
                             'DISGUISED', 'FULL_BELLY', 'AMPED', 'SOLO', 'ARIA',
                             'PLANT', 'RED', 'SPRING', 'MIDDAY', 'ORDINARY'}

    def base_form_score(key):
        """Lower score = more likely to be the base form.

        Strategy: among a natdex group, the base form is the one
        with no form suffix, or the "default" variant if all have suffixes.
        """
        # Check if key ends with any known form suffix
        matched_suffix = None
        for suffix in sorted(FORM_SUFFIXES, key=len, reverse=True):
            if key.endswith('_' + suffix):
                matched_suffix = suffix
                break

        if matched_suffix is None:
            # No suffix = true base form (e.g. CHARIZARD, PIKACHU)
            return (0, len(key), key)
        elif matched_suffix in DEFAULT_FORM_SUFFIXES:
            # Default-ish form (e.g. DEOXYS_NORMAL, WORMADAM_PLANT)
            return (1, len(key), key)
        else:
            # Alternate form
            return (3, len(key), key)

    by_natdex = {}
    for key, data in pokemon_data.items():
        ndex = data.get('natdex', 0)
        if ndex not in by_natdex:
            by_natdex[ndex] = []
        by_natdex[ndex].append(key)

    groups = {}
    for ndex, members in by_natdex.items():
        if ndex == 0:
            continue
        members.sort(key=base_form_score)
        base = members[0]
        forms = members[1:]
        groups[ndex] = {'base': base, 'forms': forms}

    return groups


def resolve_sprite_paths(pokemon_data: Dict[str, Dict], repo_root: Path):
    """Add sprite path to each species entry."""
    gfx = repo_root / "graphics" / "pokemon"
    found = 0

    for species_key, data in pokemon_data.items():
        key = species_key.lower()
        sprite = None

        # Try direct directory match
        base_dir = gfx / key
        if base_dir.exists():
            for fn in ['anim_front.png', 'front.png']:
                if (base_dir / fn).exists():
                    sprite = f"graphics/pokemon/{key}/{fn}"
                    break

        # Try form subdirectory: split at each _ to find base/form
        if not sprite:
            parts = key.split('_')
            for i in range(len(parts) - 1, 0, -1):
                base = '_'.join(parts[:i])
                form = '_'.join(parts[i:])
                form_dir = gfx / base / form
                if form_dir.exists():
                    for fn in ['anim_front.png', 'front.png']:
                        if (form_dir / fn).exists():
                            sprite = f"graphics/pokemon/{base}/{form}/{fn}"
                            break
                if sprite:
                    break

        # Default forms (CASTFORM_NORMAL, DEOXYS_NORMAL) -> use base dir sprite
        if not sprite:
            parts = key.split('_')
            for i in range(len(parts) - 1, 0, -1):
                base = '_'.join(parts[:i])
                base_dir = gfx / base
                if base_dir.exists():
                    for fn in ['anim_front.png', 'front.png']:
                        if (base_dir / fn).exists():
                            sprite = f"graphics/pokemon/{base}/{fn}"
                            break
                if sprite:
                    break

        if sprite:
            data['sprite'] = sprite
            found += 1

    print(f"  Resolved sprites for {found}/{len(pokemon_data)} species")


def inherit_form_data(pokemon_data: Dict[str, Dict], form_groups: Dict[int, Dict]):
    """Share learnset/twop data within form groups.

    If the base is missing data, pull from the first form that has it.
    Then propagate from the base to all forms that are missing data.
    """
    inherited = 0
    fields_learnset = ['level_up_moves', 'teachable_moves', 'egg_moves']
    fields_twop = ['overview', 'region', 'habitat']

    for ndex, group in form_groups.items():
        all_keys = [group['base']] + group['forms']
        all_data = [pokemon_data.get(k) for k in all_keys]
        if not all(all_data):
            continue

        # Find a donor for each field type — prefer base, then first form that has it
        donor = {}
        for field in fields_learnset + fields_twop:
            for d in all_data:
                if d.get(field):
                    donor[field] = d[field]
                    break

        # Apply to all members that lack data
        for d in all_data:
            changed = False
            for field in fields_learnset:
                if not d.get(field) and field in donor:
                    d[field] = donor[field]
                    changed = True
            for field in fields_twop:
                if not d.get(field) and field in donor:
                    d[field] = donor[field]
                    changed = True
            if changed:
                inherited += 1

    print(f"  Inherited data for {inherited} forms/bases within form groups")


def generate_pokemon_data(repo_root: Path, output_path: Path,
                          filter_by_enabled: bool = False, twop_path: Path = None):
    """Generate Pokemon data as an embeddable JS file or JSON."""
    parser = PokemonDataParser(repo_root)
    pokemon_data = parser.get_full_pokemon_database(filter_by_enabled)

    if twop_path:
        print("Merging twop data...")
        merge_twop_data(pokemon_data, twop_path)

    print("Building form groups...")
    form_groups = build_form_groups(pokemon_data)
    print(f"  {len(form_groups)} base species, {sum(len(g['forms']) for g in form_groups.values())} alternate forms")

    print("Inheriting form data...")
    inherit_form_data(pokemon_data, form_groups)

    print("Resolving sprites...")
    resolve_sprite_paths(pokemon_data, repo_root)

    if output_path.suffix == '.js':
        with open(output_path, 'w') as f:
            f.write(f"const POKEMON_DATA = {json.dumps(pokemon_data, separators=(',', ':'))};\n")
            f.write(f"const FORM_GROUPS = {json.dumps(form_groups, separators=(',', ':'))};\n")
    else:
        with open(output_path, 'w') as f:
            json.dump({'pokemon': pokemon_data, 'form_groups': form_groups}, f, indent=2)

    print(f"Generated Pokemon database with {len(pokemon_data)} species at {output_path}")


def load_config() -> Dict:
    """Load config.json from the same directory as this script."""
    config_path = Path(__file__).parent / "config.json"
    if config_path.exists():
        with open(config_path) as f:
            return json.load(f)
    return {}


if __name__ == "__main__":
    import sys

    config = load_config()
    script_dir = Path(__file__).parent

    # CLI args override config values
    # Usage: python pokemon_data_parser.py [repo_root] [output_path] [--filter-enabled] [--twop PATH]
    positional = [a for a in sys.argv[1:] if not a.startswith('--')]

    # repo_root: first positional arg > config > default "../.."
    if positional:
        repo_root = Path(positional[0])
    elif config.get("repo_root"):
        repo_root = (script_dir / config["repo_root"]).resolve()
    else:
        repo_root = (script_dir / "../..").resolve()

    # output: second positional arg > config > default "pokemon_data.js"
    if len(positional) > 1:
        output_path = Path(positional[1])
    elif config.get("output"):
        output_path = script_dir / config["output"]
    else:
        output_path = script_dir / "pokemon_data.js"

    # filter_enabled: CLI flag > config
    filter_enabled = "--filter-enabled" in sys.argv or config.get("filter_enabled", False)

    # twop: CLI --twop > config
    twop_path = None
    if "--twop" in sys.argv:
        idx = sys.argv.index("--twop")
        if idx + 1 < len(sys.argv):
            twop_path = Path(sys.argv[idx + 1])
    elif config.get("twop_data"):
        twop_path = (script_dir / config["twop_data"]).resolve()

    print(f"Config: repo={repo_root}, output={output_path}, twop={twop_path or 'none'}")
    generate_pokemon_data(repo_root, output_path, filter_enabled, twop_path)
