#!/usr/bin/env python3
"""Behavior tests for the fail-closed Habitat memory budget checker."""

from __future__ import annotations

import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
CHECKER = ROOT / "tools/habitat/check_memory.py"


class CheckMemoryTests(unittest.TestCase):
    def run_checker(self, budget: dict[str, object]) -> subprocess.CompletedProcess[str]:
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "budget.json"
            path.write_text(json.dumps(budget), encoding="utf-8")
            return subprocess.run(
                ["python3", str(CHECKER), "--budget", str(path)],
                text=True,
                capture_output=True,
                check=False,
            )

    def test_accepts_measurements_at_or_below_each_ceiling(self) -> None:
        result = self.run_checker({
            "metrics": {
                "ewram": {"used": 235929, "capacity": 262144, "ceiling_percent": 90},
                "iwram": {"used": 29491, "capacity": 32768, "ceiling_percent": 90},
                "rom": {"used": 28521267, "capacity": 33554432, "ceiling_percent": 85},
                "saveblock3": {"used": 1624, "capacity": 1624, "ceiling_bytes": 1624},
            }
        })
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("memory budgets pass", result.stdout)

    def test_rejects_measurement_above_ceiling(self) -> None:
        result = self.run_checker({
            "metrics": {
                "ewram": {"used": 235930, "capacity": 262144, "ceiling_percent": 90},
                "iwram": {"used": 29491, "capacity": 32768, "ceiling_percent": 90},
                "rom": {"used": 28521267, "capacity": 33554432, "ceiling_percent": 85},
                "saveblock3": {"used": 1624, "capacity": 1624, "ceiling_bytes": 1624},
            }
        })
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("ewram", result.stderr)

    def test_fails_closed_when_a_required_metric_is_missing(self) -> None:
        result = self.run_checker({"metrics": {}})
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("missing required metric", result.stderr)


if __name__ == "__main__":
    unittest.main()
