# Localization

Translations and localized graphics for `make LANG=<es|pt|fr>`.

* `text/`: one CSV per source file, generated and updated by `make loc-extract`
* `assets.csv`: text drawn into graphics, used by `graphics.json`
* `graphics.json`: reserved tilemap areas redrawn with localized text
* `locales/<lang>/`: whole-image overrides, mirroring the original paths
* `rules.json`: languages, sources, width and buffer limits

Full guide: [docs/tutorials/how_to_localization.md](../docs/tutorials/how_to_localization.md)
