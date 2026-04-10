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

### 2026-04-09 - Diagnóstico del error de enlace final por disco lleno
- **Tipo**: Build / entorno
- **Descripción**: El build avanzó hasta el enlace de `pokeemerald.elf`, pero `arm-none-eabi-ld` falló con `Input/output error`. Se verificó con `df -h /mnt/c` que la unidad `C:` estaba al `100%` de uso (`0` espacio disponible).
- **Archivos Afectados**: salida del build, `notes/errores.md`
- **Motivo**: Aislar la causa real del fallo final del enlace.
- **Resultado**: Quedó confirmado que el siguiente paso es compilar desde el sistema de archivos de Ubuntu/WSL o liberar espacio en `C:`.

### 2026-04-09 - Corrección del build en `region_map.c` por assets Johto faltantes
- **Tipo**: Build / gráficos
- **Descripción**: La compilación fallaba en `src/region_map.c` al intentar cargar assets de Johto. Se detectó que faltaban `graphics/pokedex/region_map_johto.bin.smolTM` y `graphics/pokenav/region_map/map_johto.bin.smolTM`.
- **Archivos Afectados**: `graphics/pokedex/region_map/region_map_johto.bin.smolTM`, `graphics/pokenav/region_map/map_johto.bin.smolTM`
- **Motivo**: Desbloquear `build/emerald/src/region_map.o` y permitir que el build avance al siguiente error real.
- **Resultado**: `region_map.o` volvió a generarse correctamente tras restaurar placeholders temporales.

### 2026-04-09 - Toolchain ARM instalado y validado en WSL
- **Tipo**: Build / entorno
- **Descripción**: Se verificó que `arm-none-eabi-gcc` ya está disponible en WSL (`/usr/bin/arm-none-eabi-gcc`, versión `13.2.1 20231009`). También se validó con `mapjson` que los mapas nuevos `RegionFerry`, `KantoPort`, `JohtoPort` y `HoennPort` son correctos.
- **Archivos Afectados**: `notes/registro_cambios.md`, `notes/errores.md`
- **Motivo**: Continuar el proceso de compilación y aislar el siguiente bloqueo real del proyecto.
- **Resultado**: El bloqueo dejó de ser la falta del compilador; el cuello de botella actual es la lentitud del build al trabajar en WSL2 sobre `/mnt/c`.

### 2026-04-09 - Diagnóstico del entorno de compilación en Windows/WSL
- **Tipo**: Build / entorno
- **Descripción**: Se verificó que el proyecto no debe compilarse con `make.exe` de Windows, porque falla con errores de `uname` y rutas. Desde WSL, el build sí arranca y genera dependencias, pero el siguiente bloqueo real es que falta `arm-none-eabi-gcc`.
- **Archivos Afectados**: `notes/errores.md`, `docs/install/windows/WSL.md`
- **Motivo**: Identificar el primer error real antes de seguir corrigiendo el proyecto.
- **Resultado**: Quedó confirmado que el siguiente paso necesario es instalar el toolchain de GBA en WSL.

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

