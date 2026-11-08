# Rom hack de Pokémon Esmeralda — Documento de diseño

**Estado:** solo idea, sin código todavía. Nombre del proyecto por definir.

**Base técnica sugerida:** `pokeemerald-expansion` (ya trae muchas mecánicas hechas, como Mega Evolución) + Porymap para mapas.

## Visión

Un Esmeralda donde el combate es un juego de **tempo y riesgo**: cada KO te da ventaja, puedes encadenar movimientos, pero todo cuesta stamina y el rival tiene las mismas herramientas. Si te confías, te barren el equipo. Encima, Pokémon especiales (alpha, super, enraged y Omega) que valen la pena cazar, un post-game durísimo y legendarios que vuelven en versión Omega.

---

## 1. Núcleo de combate

### Stamina
- Es una stat más del Pokémon. Su máximo sube con el **nivel, los EVs y los IVs**.
- Cada movimiento gasta stamina según su **potencia**.
- Al agotarse, hay que esperar a que se recargue; mientras tanto no se puede hacer nada, ni siquiera Struggle.

### Movimientos encadenados (compuestos)
- Se pueden usar **varios movimientos no repetibles en un mismo turno**, a cambio de que el rival obtenga más turnos.
- Los movimientos de protección, o los que anulan un ataque del rival por un turno (tipo Protect), **no se pueden encadenar** con otros.

### Habilidades de snowball
- **Moxie reworkeado:** al noquear a un Pokémon, restaura al instante un porcentaje de stamina, además de subir el ataque. Así los atacantes de mucho daño (Haxorus y similares) se vuelven requeridos.
- Más habilidades de este tipo: encadenar KOs, destrucción.
- **Contrapeso:** debuffs que quitan stamina y movimientos que reducen el gasto de stamina.
- El rival también puede encadenar: hay que pensar cada jugada, o te barren el equipo completo.

---

## 2. Pokémon especiales

- Rangos: **alpha, super, enraged, omega** (ideas propias).
- Tienen stats base muy altas y se **buffean al inicio del combate**, al estilo de los alpha de Legends Arceus. Tanquear hasta que una ball funcione es inviable.
- **Omega:** en el lore son super anomalías genéticas. Son Pokémon salvajes, no jefes. Ejemplo de idea: un Treecko Omega con **+50% de stats base** respecto a uno normal.
- **Rareza:** los Omega son ligeramente más raros que un shiny.
- **Dónde aparecen:** encuentros aleatorios, zonas con más probabilidad (por ejemplo la cueva de Groudon) y mini bosses fijos tipo Heatran.
- *Idea descartada por ahora:* Omega con más probabilidad en huevos.

---

## 3. Poké Balls

| Ball | Notas |
|---|---|
| **Overdrive Ball** | Reemplaza a la "Hyper Ball" (que es el nombre japonés de la Ultra Ball). |
| **Alpha Ball** | Idea propia; efecto por definir. |
| **Omega Ball** | Puede capturar Omegas, pero **no está garantizado**. |
| **Infinity Ball** | Captura a cualquier Pokémon, incluidos los especiales. Equivalente post-game de la Master Ball. No se compra en tienda; es de post-game (recompensa de la Super Liga) o de cheat codes. |

- La **Master Ball deja de ser 100%** con los especiales: tiene como máximo un 70% de probabilidad contra los super, y baja con cada tier hasta ser prácticamente inviable contra los Omega.
- Como capturar un Omega exige una ball de end game, encontrarse uno a mitad del juego no sirve de nada intentarlo.

---

## 4. Gears

- Un slot **aparte de los objetos equipados**, que da buffs y características nuevas.
- Habrá **pocos**.
- Ejemplo: **Colmillo de Rayquaza** — +10% de stats a los tipos Volador/Dragón. Se consigue **derrotando** a Rayquaza (no capturándolo).

---

## 5. Post-game

- Para llegar hay que ser **campeón de Hoenn**. La **Super Liga** viene después de la liga normal, no la reemplaza.
- Antes de ella el jugador ya puede tener Pokémon especiales y con gears.
- En la Super Liga, los líderes llevan **entre 1 y 4 Omegas** en su equipo. Dificultad extrema: "reza para ganar".
- Ganarla da la **Infinity Ball**.
- Después de la liga, los **legendarios derrotados reaparecen en su versión Omega**, inspirados en la pelea final contra Ultra Necrozma de Sol y Luna: muerte y destrucción para el jugador.

### Rayquaza
- Al bajar a **75% de vida o menos, mega evoluciona** durante el combate.
- Es una **trampa a propósito**: la idea es que el jugador se confíe antes del giro.

---

## Notas técnicas y puntos abiertos
*(Sugerencias surgidas al hablarlo, no decisiones.)*

**Técnico**
- En Esmeralda **no hay espacio para una séptima stat** en la estructura del Pokémon guardado. Opciones: derivar la stamina de stats existentes (la más fácil para empezar), reutilizar campos poco usados (como los de concursos) o ampliar la estructura.
- Stamina, gear, y el estado Omega necesitan **bits en el guardado**: planearlos desde el principio.
- Los stats base caben en un byte (máx. 255). El bonus Omega conviene aplicarlo como **multiplicador en el cálculo de stats con un flag**, no tocando los datos de cada especie.
- La **UI** (barra de stamina, ver la del rival) es de las partes que más trabajo dan.
- Los entrenadores necesitan **IA con reglas simples** para usar la stamina con sentido.

**Balance**
- +50% a las stats base es enorme: un Sceptile (530) pasaría a unos 795, más que un Mega Rayquaza (780). Valorar un multiplicador por tier (por ejemplo alpha +15%, super +30%, omega +50%) o bajar el Omega.
- Riesgo de ventaja del que pega primero (el primer KO decide el combate). Los drenajes deben ser baratos y con buena prioridad.
- Decidir: qué pasa si dos Pokémon se quedan sin stamina a la vez, si los movimientos de estado gastan stamina, y si cambiar de Pokémon cuesta stamina.
- Hyper Beam, Giga Impact y similares ya tienen recarga: sustituir por costo de stamina alto.
- Los gears deben cambiar cómo juegas (con ventajas y desventajas), no ser solo "más stats". Los entrenadores fuertes deberían usarlos también.
- Los Omega de entrenador quizá no deberían tener el mismo buff que los salvajes.

**Encuentros y pelea contra Rayquaza**
- Omega salvajes: aura o señal visible antes del combate, poder huir siempre, y algo que ayude a cazarlos en post-game.
- Rayquaza: pistas sutiles antes del giro, punto de guardado antes de la pelea. La versión Omega no debe repetir el mismo truco.
- Considerar si derrotar a Rayquaza hace que no se pueda capturar en ese momento (el dilema gear vs. Pokémon) y avisarlo antes del combate.

---

## Orden de implementación sugerido

1. Stamina (derivada de stats existentes).
2. Habilidades de snowball.
3. Movimientos encadenados.
4. Balls y sistema de captura por tiers.
5. Gears.
6. Pokémon especiales, Omega, Super Liga y legendarios Omega.

Antes de programar: simular a mano en papel combates con 5 o 6 Pokémon, con sus costos de stamina, para ver si el snowball se descontrola.
