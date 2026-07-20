# Hoenn Habitat balance table

## Grove capacity and crop identity

| Rule | Value | Notes |
|---|---:|---|
| Residents out at once | 6 | `HABITAT_GROVE_OUT_CAP` is global because the Grove is one map, not a per-plot allowance. |
| Workers per plot | 2 | The second worker supports the established crop and never changes its berry identity. |
| Crop on last worker leaving | retained | Growth pauses and the next matching first worker resumes its stage and progress. |
| Changed first worker | reset | A different berry resets the plot's berry, stage, and progress to zero. |
