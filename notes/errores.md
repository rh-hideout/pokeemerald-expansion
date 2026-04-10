# Errores

Registra errores encontrados y cómo se resolvieron.

## Fecha: 2026-04-09

- **Error de compilación en Windows con `make`**: al ejecutar el build desde PowerShell/Chocolatey aparecieron errores como `uname` no reconocido, `"{" no se reconoce como un comando` y fallos de rutas (`"C:" no se reconoce como un comando`).
  - **Solución verificada**: compilar desde **WSL** en lugar de hacerlo directamente con `make.exe` de Windows.

- **Bloqueo actual en WSL**: el build avanza, pero el toolchain de GBA no está instalado; `arm-none-eabi-gcc` devuelve `command not found`.
  - **Solución aplicada**: se instalaron las dependencias indicadas en `docs/install/windows/WSL.md` y ahora `arm-none-eabi-gcc` ya responde correctamente en WSL.

- **Cuello de botella actual**: la compilación sigue siendo muy lenta y silenciosa al ejecutarse en **WSL2 sobre `/mnt/c`**, incluso después de instalar el toolchain.
  - **Contexto**: esto coincide con la documentación del proyecto, que recomienda usar el sistema de archivos Linux de WSL2 (`~/...`) o WSL1 si el repo se mantiene en `C:`.
  - **Siguiente paso**: seguir compilando desde un entorno WSL más adecuado o asumir tiempos de build bastante más largos mientras se continúa depurando.

- **Error real de compilación en `src/region_map.c`**: el build fallaba con `error: expected expression at end of input` al compilar `region_map.o`.
  - **Causa raíz verificada**: faltaban los tilemaps `graphics/pokedex/region_map_johto.bin.smolTM` y `graphics/pokenav/region_map/map_johto.bin.smolTM`, aunque sí existían los `.png`, `.gbapal` y `.8bpp.smol` de Johto.
  - **Solución aplicada**: se restauraron ambos archivos como placeholders funcionales copiando temporalmente los equivalentes de Kanto, lo que permitió volver a generar `build/emerald/src/region_map.o`.

- **Error de enlace final (`pokeemerald.elf`)**: `arm-none-eabi-ld: final link failed: Input/output error`.
  - **Causa raíz verificada**: el proyecto se estaba compilando en `/mnt/c/...` y la unidad de Windows estaba completamente llena (`df -h /mnt/c` mostró `119G usados`, `0 disponibles`, `100%`).
  - **Siguiente paso**: compilar desde el sistema de archivos de Ubuntu/WSL (por ejemplo `~/...`) o liberar espacio en `C:` antes de volver a enlazar.

[[index]] | [[Avances]] | [[Soluciones]]