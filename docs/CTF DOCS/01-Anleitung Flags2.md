# Schritt-für-Schritt: Flag-Eingabe in einer Map + Events danach (pokeemerald-expansion, Map-Scripts.inc)

Ziel (Test-Setup):
1) Du startest in der Map "InsideOfTruck".
2) Dort steht ein Terminal (NPC/Objekt).
3) Du gibst die erste Flag (z. B. "sleep") ein (Groß/Klein egal).
4) Danach erscheint in derselben Map ein Teleporter.
5) Der Teleporter warpt dich ins Player House (je nach Geschlecht).

Diese Anleitung nutzt bewusst den “klassischen” Weg:
- Scripts pro Map in: data/maps/<MapName>/scripts.inc
- Objekte/Events setzt du in Porymap.
- Poryscript (.pory) ist optional und wird hier nicht vorausgesetzt.

────────────────────────────────────────────────────────────

## 0) Voraussetzungen (einmalig)

### 0.1 Case-insensitive Flag-Prüfung ist im Projekt vorhanden
Du hast bereits:
- src/ctf_flags.c (case-insensitive Vergleich)
- src/ctf_flag_terminal.c (callnative Ctf_FlagTerminal, öffnet Naming Screen)
- include/ctf_flags.h

Wichtig: Die “Flag-Library” (Wörter) wird in src/ctf_flags.c gepflegt.
Beispiel: Gym 1 = "SLEEP" (Groß/Klein später egal).

### 0.2 Ctf_FlagTerminal ist als Native registriert
Damit im Script "callnative Ctf_FlagTerminal" klappt, muss Ctf_FlagTerminal in der Native-Liste stehen.

Wie prüfen?
- Suche im Repo nach "gScriptNativeFuncs" oder "NativeFunc".
- Wenn du schon einmal erfolgreich gebaut hast und callnative nicht meckert, passt es.

Typischer Eintrag sieht sinngemäß so aus (nur zur Orientierung):
    Ctf_FlagTerminal,

Wenn callnative später nicht funktioniert: das ist der erste Punkt, den du checken musst.

────────────────────────────────────────────────────────────

## 1) Save-Flag anlegen, das den Teleporter sichtbar macht

Warum?
- Porymap-Objekte können ein “Appearance Flag” haben.
- Solange Flag NICHT gesetzt: Objekt unsichtbar.
- Sobald Flag gesetzt: Objekt sichtbar.

Wichtig: SaveFlags müssen im gültigen Bereich liegen.
Benutze deshalb ein vorhandenes FLAG_UNUSED_0x… als Basis (so wie ihr es schon gemacht habt).

### 1.1 In include/constants/flags.h hinzufügen
Füge irgendwo bei euren CTF-Defines hinzu:

    #define FLAG_CTF_TRUCK_TELEPORT  FLAG_UNUSED_0x038

Hinweis:
- Wenn 0x038 schon vergeben ist, nimm den nächsten freien UNUSED Slot.
- Verwende später überall nur FLAG_CTF_TRUCK_TELEPORT (nicht FLAG_UNUSED_0x038 direkt).

────────────────────────────────────────────────────────────

## 2) Flag-Wort für Gym 1 festlegen (was der Spieler eintippen muss)

In src/ctf_flags.c steht eure Tabelle, z. B.:

    static const u8 sGymFlagWords[CTF_GYM_COUNT][PLAYER_NAME_LENGTH + 1] =
    {
        _("SLEEP"),   // Gym 1
        ...
    };

Für den Test:
- Lass Gym 1 = SLEEP (oder ändere es, wenn du willst).
- Durch case-insensitive Normalisierung funktionieren dann: sleep, SLEEP, SlEeP, etc.

Wichtig:
- Der Vanilla Naming Screen ist kurz (typisch 7 Zeichen).
- Nimm für den Test kurze Wörter (SLEEP passt).

────────────────────────────────────────────────────────────

## 3) Map-Scripts: InsideOfTruck um Terminal + Teleporter ergänzen

Du arbeitest direkt in:
- data/maps/InsideOfTruck/scripts.inc

### 3.1 Terminal-Script (Flag eingeben → bei Erfolg Flag setzen)
Füge in scripts.inc zwei neue Script-Labels hinzu.

Achte darauf:
- Nutze dieselbe “Script-Syntax”, die in der Datei bereits verwendet wird.
- Wenn die Datei schon msgbox/warp Beispiele enthält, kopiere deren Stil.

Beispiel (typischer Stil, den du einfügen kannst):

    CtfTruck_Terminal::
        lock
        faceplayer
        msgbox CtfTruck_Text_Prompt, MSGBOX_DEFAULT

        setvar VAR_0x8000, 1
        callnative Ctf_FlagTerminal
        waitstate

        compare VAR_RESULT, 1
        goto_if_eq CtfTruck_Terminal_Ok

        msgbox CtfTruck_Text_Wrong, MSGBOX_DEFAULT
        release
        end

    CtfTruck_Terminal_Ok::
        setflag FLAG_CTF_TRUCK_TELEPORT
        msgbox CtfTruck_Text_Ok, MSGBOX_DEFAULT
        release
        end

Dazu passende Texte (ebenfalls in scripts.inc):

    CtfTruck_Text_Prompt::
        .string "CTF-Terminal: Gib die erste Flag ein.@"

    CtfTruck_Text_Wrong::
        .string "Falsch.@"

    CtfTruck_Text_Ok::
        .string "Korrekt! Ein Teleporter ist erschienen.@"

Hinweise:
- setvar VAR_0x8000, 1 bedeutet “prüfe Gym 1”.
- VAR_RESULT wird nach waitstate gesetzt (1=korrekt, 0=falsch).
- Bei Erfolg setzen wir FLAG_CTF_TRUCK_TELEPORT → damit wird das Teleporter-Objekt sichtbar.

### 3.2 Teleporter-Script (Warp ins Player House)
Du willst ins Player House. In Emerald gibt es zwei Varianten:
- Brendans House 1F
- Mays House 1F

Wir machen es abhängig vom Geschlecht.

Beispiel:

    CtfTruck_Teleporter::
        lock
        checkplayergender
        compare VAR_RESULT, FEMALE
        goto_if_eq CtfTruck_Teleporter_May

        warp MAP_GROUP(LITTLEROOT_TOWN_BRENDANS_HOUSE_1F), MAP_NUM(LITTLEROOT_TOWN_BRENDANS_HOUSE_1F), 0, 6, 7
        release
        end

    CtfTruck_Teleporter_May::
        warp MAP_GROUP(LITTLEROOT_TOWN_MAYS_HOUSE_1F), MAP_NUM(LITTLEROOT_TOWN_MAYS_HOUSE_1F), 0, 6, 7
        release
        end

Wichtiger Hinweis zur Warp-Syntax:
- Manche Projekte nutzen statt MAP_GROUP/MAP_NUM eine kürzere Form.
- Wenn dein Build bei warp meckert: suche in derselben scripts.inc nach einem existierenden “warp …” und übernimm exakt dessen Format.

Koordinaten (6,7) sind nur Beispiel:
- Öffne in Porymap die Ziel-Map (Brendan/Mays House 1F).
- Wähle eine sichere Boden-Koordinate (x,y) und ersetze 6,7 entsprechend.

────────────────────────────────────────────────────────────

## 4) Porymap: Objekte in InsideOfTruck setzen

Jetzt verknüpfst du die Scripts mit echten Objekten in der Map.

### 4.1 Terminal-Objekt platzieren
1) Porymap öffnen
2) Map: InsideOfTruck
3) Object Event hinzufügen (z. B. als NPC, Schild, PC – egal)
4) Script/Script Pointer: CtfTruck_Terminal
5) Stelle das Objekt so, dass du es erreichen kannst.

### 4.2 Teleporter-Objekt platzieren (unsichtbar bis Flag gesetzt)
1) Noch ein Object Event hinzufügen
2) Script: CtfTruck_Teleporter
3) Appearance Flag / Flag Feld setzen auf: FLAG_CTF_TRUCK_TELEPORT
4) Position: irgendwo frei im Truck, nicht auf dem Spawnfeld.

Ergebnis:
- Vor korrekter Flag: Teleporter ist nicht sichtbar.
- Nach korrekter Flag: Teleporter erscheint.

────────────────────────────────────────────────────────────

## 5) Stolperstein: Intro-/Cutscene im Truck

In der Original-Story läuft im Truck oft eine Cutscene/Scene-Script ab.
Das kann dazu führen:
- Du kannst dich nicht frei bewegen.
- Du kannst das Terminal nicht ansprechen.

Für den Test hast du zwei Optionen:

Option A (einfach): Truck-Scene temporär deaktivieren
- In Porymap Map Properties von InsideOfTruck prüfen:
  - Scene Scripts / Map Scripts / On Load Scripts
- Alles, was automatisch startet, für den Test entfernen oder auf “None” setzen.

Option B (Alternative): Terminal später platzieren
- Wenn du die Story nicht anfassen willst, teste erstmal auf einer Map ohne Intro.

Für “schnell testen” ist Option A meist am besten.

────────────────────────────────────────────────────────────

## 6) Testen

1) Projekt bauen
2) New Game starten
3) Im Truck Terminal ansprechen
4) “sleep” eingeben
5) Erwartung:
   - Bei falscher Eingabe: Text “Falsch.”
   - Bei korrekter Eingabe: Text “Korrekt…” und Teleporter erscheint
6) Teleporter ansprechen → Warp ins Player House

Wenn Teleporter nicht erscheint:
- Prüfe, ob im Terminal-Script wirklich setflag FLAG_CTF_TRUCK_TELEPORT steht.
- Prüfe, ob das Teleporter-Objekt in Porymap wirklich diese Flag als Appearance Flag nutzt.
- Prüfe, ob flags.h FLAG_CTF_TRUCK_TELEPORT korrekt definiert ist.

────────────────────────────────────────────────────────────

## 7) So editierst du später schnell (Checkliste pro “Flag → Event”)

### 7.1 Flag-Wort ändern
- src/ctf_flags.c
- Eintrag in sGymFlagWords ändern (z. B. Gym 1).

### 7.2 Welche Flag geprüft wird (Gym-Index)
- In deinem Terminal-Script: setvar VAR_0x8000, N
- N = 1..8

### 7.3 Welche Events nach korrekter Flag passieren
Nach “compare VAR_RESULT, 1” kannst du beliebig erweitern:

Beispiele:
- Nur Teleporter spawnen:
    setflag FLAG_CTF_TRUCK_TELEPORT

- Blocker entfernen:
    setflag FLAG_CTF_GYM1_ACCESS
  (Blocker-Objekt in Porymap hat Appearance Flag FLAG_CTF_GYM1_ACCESS)

- Mehrere Dinge:
    setflag FLAG_CTF_TRUCK_TELEPORT
    setflag FLAG_SOME_OTHER_THING
    msgbox Text_Whatever, MSGBOX_DEFAULT

- Für Tests resetten (optional):
    clearflag FLAG_CTF_TRUCK_TELEPORT

### 7.4 Warp-Ziel ändern
- Im Teleporter-Script warp auf eine andere Map/Koordinate setzen.
- Koordinaten immer in Porymap nachschauen.

────────────────────────────────────────────────────────────

## 8) Mini-Erweiterung: “Nur einmal gültig”
Wenn du willst, dass das Terminal nach einmal erfolgreicher Eingabe etwas anderes sagt:

Idee:
- Nutze dasselbe Flag als “bereits freigeschaltet”.
- Vor dem Eingabeteil checken:

Beispiel (vor dem msgbox prompt):

    checkflag FLAG_CTF_TRUCK_TELEPORT
    goto_if_eq CtfTruck_AlreadyUnlocked

    ... normale Eingabe ...

    CtfTruck_AlreadyUnlocked::
        msgbox CtfTruck_Text_Already, MSGBOX_DEFAULT
        release
        end

Und Text:
    CtfTruck_Text_Already::
        .string "Teleporter ist bereits aktiv.@"

────────────────────────────────────────────────────────────

## 9) Wenn du danach Gyms/Badges machen willst
Dieses Test-Muster ist genau der Baukasten:

Terminal (prüft Gym N) → setflag FLAG_CTF_GYMN_ACCESS → Blocker verschwindet → Leader-Kampf → setflag FLAG_CTF_GYMN_TELEPORT

Du musst pro Map nur:
- scripts.inc ergänzen
- Objekte in Porymap setzen
- passende SaveFlags definieren
