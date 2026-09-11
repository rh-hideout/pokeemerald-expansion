"""Tests for level-up-derived TM compatibility; no project data is modified."""

import unittest
from unittest.mock import patch

from make_level_up_tms import collect_compatibility
from make_teachables import prepare_output


class LevelUpTmsTests(unittest.TestCase):
    def test_shared_arrays_union_only_tm_moves(self):
        source = """
        const int levelUpPolicyTms[] = { MOVE_SURF, MOVE_FLY };
        const struct LevelUpMove first[] = {
            {.move = MOVE_SURF, .level = 1},
            {.move = MOVE_SURF, .level = 20},
            {.move = MOVE_POUND, .level = 30},
        };
        const struct LevelUpMove second[] = {{.move = MOVE_FLY, .level = 1}};
        const struct SpeciesInfo gSpeciesInfo[] = {
            [1] = {.stats = {1, 2}, .levelUpLearnset = first,
                   .teachableLearnset = sSharedTeachableLearnset},
            [2] = {.levelUpLearnset = second,
                   .teachableLearnset = sSharedTeachableLearnset},
            [3] = {.levelUpLearnset = second,
                   .teachableLearnset = sOtherTeachableLearnset},
        };
        """
        self.assertEqual(collect_compatibility(source), {
            "Other": ["MOVE_FLY"],
            "Shared": ["MOVE_FLY", "MOVE_SURF"],
        })

    def test_missing_array_is_an_error(self):
        with self.assertRaisesRegex(ValueError, "Missing initializer for missing"):
            collect_compatibility("""
                const int levelUpPolicyTms[] = {MOVE_SURF};
                const int gSpeciesInfo[] = {
                    {.levelUpLearnset = missing,
                     .teachableLearnset = sExampleTeachableLearnset},
                };
            """)

    def test_policy_filters_tutor_only_moves_and_honors_removals(self):
        with patch("make_teachables.extract_tm_litteracy_config", return_value=True):
            result = prepare_output(
                {"EXAMPLE": []},
                ["MOVE_SURF", "MOVE_FLY"],
                ["MOVE_POUND"],
                {"universalMoves": [], "signatureTeachables": []},
                [{"name": "Example", "teaching_type": "DEFAULT_LEARNING"}],
                "",
                {"EXAMPLE": {"remove": ["MOVE_FLY"]}},
                {"Example": ["MOVE_SURF", "MOVE_FLY", "MOVE_POUND"]},
            )
        self.assertIn("MOVE_SURF", result)
        self.assertNotIn("MOVE_FLY", result)
        self.assertNotIn("MOVE_POUND", result)

    def test_disabled_policy_adds_nothing(self):
        with patch("make_teachables.extract_tm_litteracy_config", return_value=True):
            result = prepare_output(
                {"EXAMPLE": []}, ["MOVE_SURF"], [],
                {"universalMoves": [], "signatureTeachables": []},
                [{"name": "Example", "teaching_type": "DEFAULT_LEARNING"}], "",
            )
        self.assertNotIn("MOVE_SURF", result)


if __name__ == "__main__":
    unittest.main()
