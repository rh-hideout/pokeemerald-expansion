# Famille Tourthon

> Lotte des abysses de Dofus (race « Trithons », niv. 200–212, id DofusDB
> **4439**) : humanoïde massif à peau orange et grise, une lanterne verte au
> bout d'une antenne. Sorts : *Attraction Lumineuse* (Feu, à distance, attire
> la cible de 4 cases et lui retire 4 PA) et *Enlacement* (Neutre au corps à
> corps, rend la cible Pacifiste). 6600 PV au grade 5, Tacle +40.
> Résistances Air +40, Eau +25, Feu +20, Terre +5, Neutre −10. Zones :
> Domaine, Faille et Tréfonds des Trithons, Palais de Dantinéa (Abysses de
> Sufokia). — Sans évolution.

**État** : validée et intégrée.

Constante : `SPECIES_TOURTHON` (1745, créée pour l'occasion, après
Crabe Yoloniste ; dex National et Hoenn : après Gélikan).

## Intention

Archétype : **tank offensif** (mixte, lent) + **piégeur** · Références :
Lanturn (le poisson-lanterne, Lumiattirance, Absorbe-Eau), Crapustule et
Laggron (profil massif mixte d'un Eau de fin de jeu) ·
Pourquoi : prise rare de la Méga Canne en fin de jeu, l'équivalent de Barpau,
Corayon ou Lovdisc. Ce doit être une prise convoitée, d'où un total élevé pour
un monstre sans évolution (515).

Le prédateur à l'affût : il attire sa proie avec sa lanterne, la retient
(Regard Noir, Croque Fort, Marque Ombre en talent caché) puis l'étreint
(Enlacement). Il frappe d'abord avec Coup Bas pour compenser sa lenteur.

C'est l'opposé de **Raul Mops**, l'autre Eau/Ténèbres (nettoyeur physique
rapide, 80/125/70/55/65/120). Tourthon est lent, encaisse et attaque des deux
côtés. Pas d'attaque Feu, même si le leurre est Feu dans Dofus : ce serait
incohérent pour une créature des abysses dans Osatopia. Pas d'Électrik non
plus, pour ne pas doubler Tilamproie et Mantaze : sa lanterne sert de leurre,
pas d'arme.

Faiblesses Eau/Ténèbres : Plante, Électrik, Combat, Insecte, Fée.
Résistances : Feu, Eau, Glace, Acier, Spectre, Ténèbres ; immunité Psy.

## Stades

| | Tourthon |
|---|---|
| Constante | `SPECIES_TOURTHON` |
| Types | Eau / Ténèbres |
| PV / Att / Déf / AtqSpé / DéfSpé / Vit | 110 / 100 / 85 / 90 / 80 / 50 |
| Total | 515 |
| Talents | Lumiattirance (Illuminate) / Absorbe-Eau (Water Absorb) / caché : Marque Ombre (Shadow Tag) |
| Capture / Exp. | 30 / 195 |
| EV | 2 PV, 1 Att |
| Évolution | – |

Stats sacrifiées : la Vitesse (une lotte massive qui attend sa proie ; Coup
Bas compense) et un peu la DéfSpé.

Comparaisons (`similaires`) :

| Monstre | PV / Att / Déf / AtqSpé / DéfSpé / Vit | Total |
|---|---|---|
| **Tourthon** | 110 / 100 / 85 / 90 / 80 / 50 | 515 |
| Coudlangue | 110 / 85 / 95 / 80 / 95 / 50 | 515 |
| Crapustule | 105 / 95 / 75 / 85 / 75 / 74 | 509 |
| Laggron | 100 / 110 / 90 / 85 / 90 / 60 | 535 |
| Lanturn | 125 / 58 / 58 / 76 / 76 / 67 | 460 |
| Raul Mops (custom) | 80 / 125 / 70 / 55 / 65 / 120 | 515 |
| Dracochon (custom) | 105 / 108 / 90 / 62 / 90 / 60 | 515 |
| Grenn (custom) | 95 / 115 / 90 / 70 / 85 / 75 | 530 |

Autres valeurs : 50 % femelle, 20 cycles d'œuf, `STANDARD_FRIENDSHIP`,
`GROWTH_SLOW` (comme Lanturn, Relicanth : rare de fin de jeu), groupe d'œuf
Eau 2 (poissons, comme Lanturn), `BODY_COLOR_BROWN`. Taille 2,0 m
(`.height = 20`), poids 160 kg (`.weight = 1600`), catégorie Pokédex
« Angler ».

Pokédex (en jeu) :
> It lurks in abyssal trenches, its green
> lantern swaying in the dark. Prey drawn
> to the light is crushed in its embrace
> before it ever sees the jaws behind.

## Talents

| Emplacement | Talent | Intérêt |
|---|---|---|
| 1 | **Lumiattirance** (Illuminate) | la lanterne : sa Précision ne peut pas baisser ; hors combat, plus de rencontres sauvages |
| 2 | **Absorbe-Eau** (Water Absorb) | comme Lanturn et Crapustule : il se nourrit des attaques Eau |
| Caché | **Marque Ombre** (Shadow Tag) | la proie attirée ne peut plus repartir |

## Kit final (niv. 40–50)

| Emplacement | Choix | Alternatives |
|---|---|---|
| STAB Eau | **Surf** Eau · Spé · 90 (CS) | Hydrocanon 110, Aqua-Brèche 85 (phys.), Vibraqua 60 |
| STAB Ténèbres | **Croque Fort** (Jaw Lock) Ténèbres · Phys · 80 · aucun des deux ne peut fuir | Vibrobscur 80 (spé.), Mâchouille 80 |
| L'étreinte | **Enlacement** (custom) Normal · Phys · 80 · Att −1 | Bâillement, Regard Noir |
| Priorité | **Coup Bas** (Sucker Punch) Ténèbres · Phys · 70 · prio +1 | Laser Glace 90 (couverture Plante) |

## Capacités custom

**Enlacement** (`MOVE_ENLACEMENT`), inspirée du sort *Enlacement* — en jeu :
**Embrace** (41 px).
- Normal · Physique · puissance 80 · précision 100 · PP 15 · contact ·
  baisse l'Attaque de la cible d'un niveau (100 %).
- Le « Pacifiste » de Dofus devient la baisse d'Attaque : la proie étreinte
  n'a plus la force de riposter.
- Attaque la plus proche : **Furie-Bond** (Lunge, Insecte, `EFFECT_HIT` +
  `MOVE_EFFECT_ATK_MINUS_1` à 100 %). Animation : celle de Ligotage.
- Description : « Crushes the foe in a tight / hug. Lowers its Attack. »
- Difficulté : facile. Effet secondaire à 100 % : à ajouter à
  `IsMoveSheerForceBoosted` dans `test/battle/ability/sheer_force.c`.

Piste écartée : *Attraction Lumineuse* (Feu spécial qui piège) — pas d'attaque
Feu pour Tourthon.

## Learnsets

### Tourthon
| Niv. | Attaque | Type | Cat. | Puiss. | Rôle |
|---|---|---|---|---|---|
| 1 | Ligotage (Wrap) | Normal | Phys. | 15 | l'étreinte de base |
| 1 | Pistolet à O (Water Gun) | Eau | Spé. | 40 | STAB faible |
| 1 | Ultrason (Supersonic) | Normal | Statut | – | la lanterne qui hypnotise (comme Lanturn) |
| 5 | Morsure (Bite) | Ténèbres | Phys. | 60 | STAB faible |
| 9 | Regard Noir (Mean Look) | Normal | Statut | – | le leurre : la proie ne peut plus fuir |
| 13 | Vibraqua (Water Pulse) | Eau | Spé. | 60 | |
| 17 | Bâillement (Yawn) | Normal | Statut | – | |
| 21 | Coup Bas (Sucker Punch) | Ténèbres | Phys. | 70 prio+1 | priorité |
| 25 | Croque Fort (Jaw Lock) | Ténèbres | Phys. | 80 | STAB, piège |
| 29 | **Enlacement** (custom) | Normal | Phys. | 80 | signature |
| 33 | Surf | Eau | Spé. | 90 | STAB fort |
| 37 | Vibrobscur (Dark Pulse) | Ténèbres | Spé. | 80 | STAB spécial |
| 41 | Aqua-Brèche (Liquidation) | Eau | Phys. | 85 | STAB physique |
| 45 | Hydrocanon (Hydro Pump) | Eau | Spé. | 110 | attaque finale |

14 attaques. Il se pêche tard (Méga Canne) : à partir du niveau 33, il arrive
avec Coup Bas, Croque Fort, Enlacement et Surf.

## CT, CS et tuteurs

| Attaque | Source | Tourthon |
|---|---|---|
| Toxik, Provoc, Abri, Danse Pluie, Reflet, Façade, Repos, Attraction, Larcin, Tourmente | CT | ✓ |
| Vibraqua, Laser Glace, Blizzard, Grêle, Ultralaser | CT | ✓ |
| Ball'Ombre, Casse-Brique, Mitra-Poing | CT | ✓ |
| Surf, Cascade, Plongée, Force, Éclate-Roc | CS | ✓ |
| Plaquage, Damoclès, Riposte, Frappe Atlas, Ultimapoing, Poing Glace, Vent Glace | Tuteur | ✓ |
| Ténacité, Blabla Dodo, Ronflement, Vantardise | Tuteur | ✓ |

Exclusions volontaires : toutes les attaques Feu (Lance-Flammes,
Déflagration, Surchauffe, Poing Feu, Zénith), les Électrik (Tonnerre,
Fatal-Foudre, Poing Éclair, Cage Éclair : c'est le domaine de Tilamproie et
Mantaze), les boosts (Gonflette, Plénitude, Danse Lames : c'est un tank, pas
un attaquant à boost), Séisme et Tunnel (marin), Psyko, Bomb-Beurk, les CT
de vol et de lames (Aéropique, Ailes d'Acier, Coupe, Faux-Chage).

## Rencontre

À placer : Méga Canne, fin de jeu, rare. Niveau conseillé : 33 ou plus
(pour qu'il ait Surf et Enlacement). `src/data/wild_encounters.json` n'est pas
modifié ici.

## Sprites

Récupérés depuis Dofus (id 4439, face direction 3, dos direction 7, taille
« grand »). Icône régénérée depuis la face (palette d'icône 0).
