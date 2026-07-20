#ifndef GUARD_HABITAT_MIGRATION_H
#define GUARD_HABITAT_MIGRATION_H

// Migrates the in-memory HabitatSave after it has been read from sectors.
// Safe to call repeatedly: a current-version save is left byte-identical.
void Habitat_MigrateSave(void);

#endif // GUARD_HABITAT_MIGRATION_H
