# Registro de Cambios

Este archivo registra todos los cambios realizados en el proyecto, para facilitar el seguimiento del progreso y la comprensión en futuras sesiones o chats.

## Formato de registro:
- **Fecha y Hora**: [Fecha]
- **Tipo de Cambio**: [Código/Nota/Configuración/etc.]
- **Descripción**: Breve explicación del cambio.
- **Archivos Afectados**: Lista de archivos modificados.
- **Motivo**: Por qué se hizo el cambio.
- **Resultado**: Qué se logró.

---

## Registros

### 2026-04-09 10:25 - Implementación de Eeveeluciones
- **Tipo**: Adición de Pokémon
- **Descripción**: Agregadas las especies de Leafeon, Glaceon y Sylveon manualmente en species_info.h.
- **Archivos Afectados**: src/data/pokemon/species_info.h
- **Motivo**: Incluir las Eeveeluciones adicionales según la información principal.
- **Resultado**: Eeveeluciones disponibles en el juego.

### 2026-04-09 11:00 - Inicio de Adición de Mapas de Región para Kanto y Johto
- **Tipo**: Sistema de Mapas
- **Descripción**: Agregado soporte para mapas de región de Johto en el sistema de region_map. Incluye enum REGION_MAP_JOHTO, constantes de MAPSEC para Johto, actualización de funciones GetRegionMapType y GetRegionForSectionId, y preparación de includes para gráficos (archivos de gráficos pendientes).
- **Archivos Afectados**: include/region_map.h, src/region_map.c, include/constants/region_map_sections.h, include/regions.h, src/data/region_map/region_map_layout_johto.h, src/data/region_map/region_map_entries.h, graphics/pokenav/region_map/map_johto.8bpp.smol, graphics/pokenav/region_map/map_johto.bin.smolTM, graphics/pokenav/region_map/map_johto.gbapal, graphics/pokedex/region_map_johto.8bpp.smol, graphics/pokedex/region_map_johto.bin.smolTM, graphics/pokedex/region_map_johto.gbapal
- **Motivo**: Implementar mapas de región para Kanto y Johto como parte del mundo semiabierto.
- **Resultado**: Código base listo; se agregó un layout placeholder Johto y activos temporales copiados de Kanto para arrancar la integración mientras se crean los mapas reales.

### 2026-04-09 12:10 - Corrección de texto en la intro personalizada de Malak
- **Tipo**: Ajuste de texto/evento
- **Descripción**: Eliminadas cadenas residuales en `LittlerootTown_ProfessorBirchsLab/scripts.inc` que seguían al texto de introducción de Malak y podían causar que el mensaje mostrado fuera demasiado largo o incorrecto.
- **Archivos Afectados**: data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc
- **Motivo**: Asegurar que la intro del juego solo muestre el texto personalizado de Malak y no incluya texto original sobrante.
- **Resultado**: Introducción de Malak limpia y consistente en el evento de entrega de la Pokédex.

### 2026-04-09 23:45 - Registro del special de secuencia de camión y saneamiento del build
- **Tipo**: Corrección de build/eventos
- **Descripción**: Detectado que los mapas nuevos `KantoPort`, `JohtoPort` y `HoennPort` llamaban al special `Special_ExecuteTruckSequence`, pero ese special no estaba registrado en `data/specials.inc`. Además, se confirmó que parte de los errores de link venían de objetos desactualizados, porque tras recompilar `pokemon_storage_system.o` y `pokemon_summary_screen.o` reaparecieron símbolos que el linker reportaba como faltantes.
- **Archivos Afectados**: data/specials.inc
- **Motivo**: Evitar errores de enlace por símbolos `SPECIAL_*` no generados y dejar trazado el diagnóstico real del estado del build.
- **Resultado**: El special del camión queda registrado; el siguiente build debería avanzar más allá de ese punto y mostrar el próximo bloqueo real, si existe.

### 2026-04-09 23:55 - Desactivación temporal del hook de layout Johto en region_map
- **Tipo**: Corrección de build/mapa de región
- **Descripción**: `src/region_map.c` estaba incluyendo y usando `region_map_layout_johto.h`, pero las constantes `MAPSEC_*` de Johto aún no existen en `include/constants/region_map_sections.h`. Eso hacía fallar la compilación de `region_map.o` con identificadores no declarados.
- **Archivos Afectados**: src/region_map.c
- **Motivo**: Desbloquear el build sin borrar los assets ni el layout placeholder de Johto, dejando la integración lista para retomarse cuando se definan correctamente las secciones Johto.
- **Resultado**: El runtime deja de intentar compilar el layout Johto incompleto; el build puede avanzar al siguiente error real.

