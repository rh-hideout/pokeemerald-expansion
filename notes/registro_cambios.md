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
- **Archivos Afectados**: include/region_map.h, src/region_map.c, include/constants/region_map_sections.h, include/regions.h
- **Motivo**: Implementar mapas de región para Kanto y Johto como parte del mundo semiabierto.
- **Resultado**: Código base listo; faltan archivos de gráficos y layout de mapa para Johto.

