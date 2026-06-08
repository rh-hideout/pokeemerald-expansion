#!/bin/bash

find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_FLAVOR_BUFFER/{s/[^;]$/&;/;s/PREPARE_FLAVOR_BUFFER/PrepareFlavorBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_STAT_BUFFER/{s/[^;]$/&;/;s/PREPARE_STAT_BUFFER/PrepareStatBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_ABILITY_BUFFER/{s/[^;]$/&;/;s/PREPARE_ABILITY_BUFFER/PrepareAbilityBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_TYPE_BUFFER/{s/[^;]$/&;/;s/PREPARE_TYPE_BUFFER/PrepareTypeBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_BYTE_NUMBER_BUFFER/{s/[^;]$/&;/;s/PREPARE_BYTE_NUMBER_BUFFER/PrepareByteNumberBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_HWORD_NUMBER_BUFFER/{s/[^;]$/&;/;s/PREPARE_HWORD_NUMBER_BUFFER/PrepareHwordNumberBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_WORD_NUMBER_BUFFER/{s/[^;]$/&;/;s/PREPARE_WORD_NUMBER_BUFFER/PrepareWordNumberBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_STRING_BUFFER/{s/[^;]$/&;/;s/PREPARE_STRING_BUFFER/PrepareStringBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_MOVE_BUFFER/{s/[^;]$/&;/;s/PREPARE_MOVE_BUFFER/PrepareMoveBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_ITEM_BUFFER/{s/[^;]$/&;/;s/PREPARE_ITEM_BUFFER/PrepareItemBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_SPECIES_BUFFER/{s/[^;]$/&;/;s/PREPARE_SPECIES_BUFFER/PrepareSpeciesBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_MON_NICK_WITH_PREFIX_BUFFER/{s/[^;]$/&;/;s/PREPARE_MON_NICK_WITH_PREFIX_BUFFER/PrepareMonNickWithPrefixBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER/{s/[^;]$/&;/;s/PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER/PrepareMonNickWithPrefixLowerBuffer/}' {} +
find . \( -name "*.c" -o -name "*.h" \) -exec sed -i '/PREPARE_MON_NICK_BUFFER/{s/[^;]$/&;/;s/PREPARE_MON_NICK_BUFFER/PrepareMonNickBuffer/}' {} +
