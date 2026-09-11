"""Regression coverage for project-owned teachable overrides."""

import unittest
from unittest.mock import patch

from apply_learnset_overrides import apply_overrides
from make_learnset_overrides import make_overrides
from make_teachables import prepare_output


class LearnsetOverridesTests(unittest.TestCase):
    def render_moves(self, teaching_type, overrides, literacy=True):
        special = {
            "universalMoves": ["MOVE_SUBSTITUTE"],
            "signatureTeachables": ["MOVE_VOLT_TACKLE"],
        }
        official = {"MEW": ["MOVE_TOXIC", "MOVE_SUBSTITUTE"]}
        effective = apply_overrides(official, overrides)
        with patch("make_teachables.extract_tm_litteracy_config", return_value=literacy):
            return prepare_output(
                effective,
                ["MOVE_SUBSTITUTE", "MOVE_TOXIC", "MOVE_VOLT_TACKLE"],
                ["MOVE_TOXIC"],
                special,
                ["#if P_MEW\n", {"name": "Mew", "teaching_type": teaching_type}, "#endif\n"],
                "",
                overrides,
            )

    def test_removals_override_universal_and_all_teachables(self):
        for teaching_type in ("DEFAULT_LEARNING", "ALL_TEACHABLES", "TM_ILLITERATE"):
            with self.subTest(teaching_type=teaching_type):
                output = self.render_moves(teaching_type, {
                    "MEW": {"remove": ["MOVE_SUBSTITUTE", "MOVE_TOXIC"]},
                })
                self.assertNotIn("MOVE_SUBSTITUTE", output)
                self.assertNotIn("MOVE_TOXIC", output)
                self.assertIn("MOVE_UNAVAILABLE", output)
                self.assertIn("#if P_MEW", output)
                self.assertIn("#endif", output)

    def test_additions_override_signature_exclusion_but_need_availability(self):
        output = self.render_moves("ALL_TEACHABLES", {
            "MEW": {"add": ["MOVE_VOLT_TACKLE", "MOVE_POUND"]},
        })
        self.assertIn("MOVE_VOLT_TACKLE", output)
        self.assertNotIn("MOVE_POUND", output)
        self.assertEqual(output.count("MOVE_TOXIC"), 1)

    def test_remove_wins_over_add(self):
        output = self.render_moves("DEFAULT_LEARNING", {
            "MEW": {"add": ["MOVE_TOXIC"], "remove": ["MOVE_TOXIC"]},
        })
        self.assertNotIn("MOVE_TOXIC", output)

    def test_tm_illiterate_membership_is_reusable(self):
        output = self.render_moves("TM_ILLITERATE", {}, literacy=False)
        self.assertIn("MOVE_TOXIC", output)
        self.assertNotIn("MOVE_SUBSTITUTE", output)

    def test_proposal_preserves_custom_species_and_differences(self):
        current = {"MEW": {"MOVE_TOXIC"}, "CUSTOM": {"MOVE_POUND"}}
        official = {"MEW": {"MOVE_SUBSTITUTE"}}
        proposal = make_overrides(current, official)
        effective = apply_overrides(
            {species: sorted(moves) for species, moves in official.items()},
            proposal,
        )
        self.assertEqual(effective, {"CUSTOM": ["MOVE_POUND"], "MEW": ["MOVE_TOXIC"]})
        self.assertEqual(current["MEW"], {"MOVE_TOXIC"})


if __name__ == "__main__":
    unittest.main()
