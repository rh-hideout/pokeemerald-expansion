# Famille Kralamoure

> Dans Dofus, le Kralamoure est une ressource de pêche emblématique (et le
> Dévoreur de Kralamoure, id 735, le monstre qui surgit quand on en pêche un).
> Le **Kralamoure Géant** (id DofusDB **423**, race « Monstres des Tourbières »)
> est le boss de l'Antre du Kralamoure Géant, dans la Tourbière Nauséabonde
> (Otomaï), et le gardien du Dofus Ocre. Sorts : *Kracheau immobilisant* (vol
> de vie Feu, −6 PM), *Kraken* (son humeur change selon l'élément des dégâts
> reçus ; +200 PV), *Tourbe écrasante* (immobilise le terrain), un bouclier de
> +900 % de résistances partout, et l'invocation de quatre Tentacules.
> — Évolutions : Kralamoure → Kralamoure Géant (niv. 20).

**État** : validée et intégrée.

Constantes : `SPECIES_KRALAMOURE` (1746) et `SPECIES_KRALAMOURE_GEANT` (1747),
créées pour l'occasion après Tourthon (dex National et Hoenn : après Tourthon).
Nom en jeu du stade final : **Kralagéant** (« Kralamoure Géant » dépasse les
12 caractères d'un nom d'espèce).

## Intention

Archétype : **monstre à élever** (Kralamoure) puis **tank offensif physique**
(Kralamoure Géant) · Références : Magicarpe → Léviator (la prise ridicule qui
devient un monstre marin redoutable), Léviator pour le profil final ·
Pourquoi : le « Magicarpe » d'Osatopia, la prise la plus commune à la Canne.
Kralamoure ne sait rien faire ; on le paie en expérience (croissance lente,
comme Magicarpe) pour obtenir un Géant lent, massif et qui frappe fort.

**Eau pur** aux deux stades. Les sorts du boss sont Feu dans Dofus, mais
un poulpe Eau/Feu n'a pas de sens dans Osatopia.

Les trois talents reprennent le boss :
- **Homochromie** : *Kraken*, l'humeur qui change selon l'élément reçu ;
- **Multiécaille** : le bouclier de +900 %, brisé au premier coup ;
- **Ocre** (caché) : le Dofus Ocre et son PA en plus, soit une action offerte
  avant l'adversaire.

Kracheau et Ocre vont ensemble : le Géant draine et ralentit avant que la
cible ne joue, puis la double grâce au ralentissement malgré ses 55 de
Vitesse.

Faiblesses (Eau) : Plante, Électrik. Couverture contre Électrik par CT
(Séisme, Tunnel) ; aucune couverture Plante (incohérente pour un poulpe).

## Stades

| | Kralamoure | Kralamoure Géant |
|---|---|---|
| Constante | `SPECIES_KRALAMOURE` | `SPECIES_KRALAMOURE_GEANT` |
| Nom en jeu | Kralamoure | Kralagéant |
| Types | Eau | Eau |
| PV / Att / Déf / AtqSpé / DéfSpé / Vit | 30 / 15 / 60 / 15 / 30 / 60 | 110 / 130 / 80 / 50 / 100 / 55 |
| Total | 210 | 525 |
| Talents | Homochromie (Color Change) / Multiécaille (Multiscale) / caché : **Ocre** (custom) | idem |
| Capture / Exp. | 255 / 40 | 45 / 189 |
| EV | 1 Vit | 2 Att, 1 PV |
| Évolution | niv. 20 | – |

Stats sacrifiées : la Vitesse et l'AtqSpé du Géant (un poulpe massif et
purement physique). Kralamoure garde le profil de Magicarpe, un peu plus
solide et plus lent.

Comparaisons (`similaires`) :

| Monstre | PV / Att / Déf / AtqSpé / DéfSpé / Vit | Total |
|---|---|---|
| **Kralamoure Géant** | 110 / 130 / 80 / 50 / 100 / 55 | 525 |
| Léviator | 95 / 125 / 79 / 60 / 100 / 81 | 540 |
| Grenn (Osatopia, Eau/Combat) | 95 / 115 / 90 / 70 / 85 / 75 | 530 |
| Vigie Pirate (Osatopia, Spectre) | 100 / 120 / 80 / 50 / 90 / 55 | 495 |
| **Kralamoure** | 30 / 15 / 60 / 15 / 30 / 60 | 210 |
| Magicarpe | 20 / 10 / 55 / 15 / 20 / 80 | 200 |

Autres champs : 50 % femelle, bonheur standard (valeurs Bitouf) ; 5 cycles
d'œuf et groupes Aquatique 2 / Dragon (comme Magicarpe) ; croissance
`GROWTH_SLOW` (comme Magicarpe et Léviator) ; couleur violette.
Pokédex : Kralamoure 0,4 m / 6 kg (« Octopus »), Kralamoure Géant 7 m /
400 kg (« Kraken »).

## Kit final

| Rôle | Attaque |
|---|---|
| STAB fort | Aquatacle (Wave Crash) · Eau · phys. · 120 |
| Signature | **Kracheau** (Inkspit) · Eau · phys. · 75 |
| Couverture | Mâchouille (Crunch) · Ténèbres · phys. · 80 |
| Boost | Gonflette (Bulk Up) |

## Talent custom : Ocre

- Effet : pendant son premier tour sur le terrain (en début de combat ou après
  être entré), toutes ses attaques ont +1 en priorité.
- Description : « Moves first on 1st turn. »
- Code : `ABILITY_OCRE`. Condition dans `GetBattleMovePriority`
  (`battle_main.c`), après Prioguérison, sur
  `gDisableStructs[battler].isFirstTurn` (le même indicateur que Bluff).
  L'IA en tient compte puisqu'elle passe par ce calcul.
- Test : `test/battle/ability/ocre.c`.

## Capacités custom

### Kracheau (Inkspit)

D'après *Kracheau immobilisant* (vol de vie, −6 PM).

| Champ | Valeur |
|---|---|
| Type / catégorie | Eau / Physique |
| Puissance / Précision / PP | 75 / 100 / 10 |
| Effet | récupère 50 % des dégâts infligés ; Vitesse −1 de la cible (100 %) |
| Modèle | Vampi-Poing (`EFFECT_ABSORB`, `absorbPercentage = 50`) + `MOVE_EFFECT_SPD_MINUS_1` |
| Animation | celle d'Octazooka (jet d'encre) |
| Description | « Spits draining ink. Heals / and lowers foe's Speed. » |

Ajoutée à `IsMoveSheerForceBoosted` (`test/battle/ability/sheer_force.c`).

## Learnsets

**Kralamoure**

| Niv. | Attaque | Type | Cat. | Puiss. |
|---|---|---|---|---|
| 1 | Trempette (Splash) | Normal | Statut | – |
| 15 | Ligotage (Wrap) | Normal | Phys. | 15 |
| 25 | Gigotage (Flail) | Normal | Phys. | – |

**Kralamoure Géant**

| Niv. | Attaque | Type | Cat. | Puiss. |
|---|---|---|---|---|
| Évo | **Kracheau** (Inkspit) | Eau | Phys. | 75 |
| 1 | Trempette (Splash) | Normal | Statut | – |
| 15 | Ligotage (Wrap) | Normal | Phys. | 15 |
| 22 | Brouillard (Smokescreen) | Normal | Statut | – |
| 25 | Gigotage (Flail) | Normal | Phys. | – |
| 26 | Morsure (Bite) | Ténèbres | Phys. | 60 |
| 29 | Anneau Hydro (Aqua Ring) | Eau | Statut | – |
| 32 | Cascade (Waterfall) | Eau | Phys. | 80 |
| 35 | Octoprise (Octolock) | Combat | Statut | – |
| 38 | Gonflette (Bulk Up) | Combat | Statut | – |
| 41 | Mâchouille (Crunch) | Ténèbres | Phys. | 80 |
| 45 | Aqua-Brèche (Liquidation) | Eau | Phys. | 85 |
| 52 | Aquatacle (Wave Crash) | Eau | Phys. | 120 |

13 attaques. Rien à 90+ avant le niveau 52.

## CT, CS et tuteurs

**Kralamoure** : aucune (comme Magicarpe), seulement les attaques universelles.

**Kralamoure Géant**

| Catégorie | Attaques |
|---|---|
| Statut | Toxik, Abri, Danse Pluie, Repos, Reflet, Attraction, Ténacité, Blabla Dodo, Ronflement, Vantardise, Provoc, Tourmente, Hurlement |
| Boost | Gonflette |
| Eau | Surf, Cascade, Plongée, Vibraqua |
| Normal | Façade, Plaquage, Damoclès, Force |
| Couverture | Séisme, Tunnel, Éboulement, Tomberoche, Larcin, Vent Glace, Éclate-Roc |

Exclusions volontaires : coups de poing et Casse-Brique (pas de poings) ; Vol,
Aéropique, Aile d'Acier (pas d'ailes) ; Queue de Fer (pas de queue) ; Danse
Lames (Gonflette reste son seul boost) ; Laser Glace, Blizzard, Ultralaser
(AtqSpé 50, il reste purement physique) ; toute couverture Plante.

## Sprites

Sprites de combat faits à part (PR #107) : Kralamoure à partir de l'icône de
la ressource, Kralamoure Géant recomposé (`kralamoure_geant_pose`, taille
« enorme »). Palettes d'icône appliquées avec `icon_palettes.py`.

## Rencontre

Prise la plus commune à la Canne, en mer et en eau douce, comme Magicarpe.
