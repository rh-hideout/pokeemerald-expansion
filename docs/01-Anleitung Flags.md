# CTF-Romhack (pokeemerald-expansion): Flags → Events → Arena-Kampf (Spickzettel)

Diese Anleitung ist ein Nachschlagewerk, wie du für jede Arena/Badge den Flow baust und später schnell anpassen kannst:

Flag eingeben → Event (Tür/Blocker/Warp) → Arenaleiter-Kampf → Badge/Teleporter/weitere Events

Voraussetzung: Du hast bereits
- ctf_flags.c (case-insensitive) im Projekt
- ctf_flag_terminal.c (Naming-Screen Eingabe via callnative Ctf_FlagTerminal)
- ctf_flags.h

---

## 1) Grundprinzip: Welche Bausteine gibt es?

### 1.1 Flag eingeben
Ort: Terminal/PC/NPC-Objekt in einer Map  
Technik: Poryscript ruft callnative Ctf_FlagTerminal auf  
Eingabe: Naming Screen (wie Charakter-Name) → liefert String  
Prüfung: Ctf_IsGymFlagCorrect(gymId, input) → setzt VAR_RESULT

Wichtig:
- gymId wird im Script über VAR_0x8000 übergeben.
- Ergebnis steht nach waitstate in VAR_RESULT (1 = korrekt, 0 = falsch).

---

## 2) Wo ändere ich was? (die 5 Stellschrauben)

### 2.1 Flag-Wörter (die Lösungen)
Datei: src/ctf_flags.c  
Stelle: Tabelle sGymFlagWords

Beispiel (C):
    static const u8 sGymFlagWords[CTF_GYM_COUNT][PLAYER_NAME_LENGTH + 1] =
    {
        _("SLEEP"),   // Gym 1
        _("DOZE"),    // Gym 2
        // ...
    };

Regeln:
- Wörter kurz halten (typisch ≤ 7 Zeichen wegen Naming Screen).
- Groß-/klein egal (case-insensitive Normalisierung ist drin).
- Wenn du ein Wort änderst, ist nur diese Stelle nötig.

---

### 2.2 Welche Arena wird geprüft? (gymId)
Datei: dein Poryscript (Arena-Terminal Script)  
Stelle: setvar VAR_0x8000 <N>

Beispiel (Gym 1):
    setvar VAR_0x8000 1
    callnative Ctf_FlagTerminal
    waitstate
    compare VAR_RESULT 1

Gym 2 wäre 2, … Gym 8 wäre 8.

---

### 2.3 Welche Events passieren nach korrekt?
Nach compare VAR_RESULT 1 kannst du alles auslösen:

- Flag setzen (setflag FLAG_...)
- Blocker verschwinden lassen (via Flag am Objekt)
- Tür-Metatiles ändern (setmetatile)
- Warp aktivieren (via Flag am Warp/Objekt)
- NPC Dialoge ändern (via Flag-Abfragen)
- Item geben, Sound spielen, Cutscene starten, etc.

---

### 2.4 Arenaleiter-Battle ändern
Datei: Poryscript (Leader-Script)  
Stelle: trainerbattle ... TRAINER_...

Beispiel:
    trainerbattle SINGLE TRAINER_CTF_GYM1_LEADER 0 "..." "..." 0

Du änderst entweder:
1) die Trainer-ID-Konstante (z. B. TRAINER_CTF_GYM1_LEADER)  
oder
2) die Daten dieses Trainers (Party, Level, AI, Texte) in den Trainer-Daten.

---

### 2.5 Map-Events (Porymap): Objekt/Flag-Verknüpfung
Viele Tür auf / Block weg / Teleporter erscheint Effekte gehen ohne Metatile-Änderungen, nur über Porymap-Objektflags:

- Blocker-Objekt hat Flag = FLAG_GYM_ACCESS  
  Flag false → Blocker sichtbar  
  Flag true → Blocker unsichtbar (Weg frei)

- Teleporter-Objekt hat Flag = FLAG_GYM_TELEPORT  
  erscheint erst nach Sieg

---

## 3) Standard-Template pro Gym (copy/paste)

### 3.1 Terminal (Flag-Eingabe)
Poryscript:
    script CtfGymN_Terminal {
      lock
      faceplayer
      msgbox "Gib das Codewort ein." MSGBOX_DEFAULT

      setvar VAR_0x8000 N
      callnative Ctf_FlagTerminal
      waitstate

      compare VAR_RESULT 1
      if eq goto .ok

      msgbox "Falsch." MSGBOX_DEFAULT
      release
      end

    .ok:
      // Hier kommen deine nach Flag korrekt Events rein
      // Beispiel: Zugang freischalten
      setflag FLAG_CTF_GYMN_ACCESS
      msgbox "Korrekt. Zugang freigeschaltet." MSGBOX_DEFAULT
      release
      end
    }

Was du pro Gym änderst:
- N (1..8)
- FLAG_CTF_GYMN_ACCESS
- Texte

---

### 3.2 Blocker (Tür/Barrier-Effekt über Objekt-Flag)
In Porymap:
- Lege ein Objekt vor den Durchgang (z. B. NPC/Statue/Laser).
- Setze im Objekt: Flag = FLAG_CTF_GYMN_ACCESS
- Optional Script: "Verschlossen."

Ergebnis:
- Vor Eingabe: Blocker steht da
- Nach korrekter Flag: Blocker verschwindet automatisch

Vorteile gegenüber Metatiles:
- sehr robust
- keine Koordinaten-/Tile-ID-Pflege
- kein Map-Refresh nötig

---

### 3.3 Leader (Battle + nach Sieg Events)
Poryscript:
    script CtfGymN_Leader {
      lock
      faceplayer

      checkflag FLAG_CTF_GYMN_ACCESS
      if 0 goto .noaccess

      checkflag FLAG_CTF_GYMN_DEFEATED
      if 1 goto .after

      msgbox "Du hast das Codewort. Kaempfen wir!" MSGBOX_DEFAULT
      trainerbattle SINGLE TRAINER_CTF_GYMN_LEADER 0 "..." "..." 0

      setflag FLAG_CTF_GYMN_DEFEATED
      setflag FLAG_CTF_GYMN_TELEPORT

      msgbox "Sieg! Teleporter aktiviert." MSGBOX_DEFAULT
      release
      end

    .after:
      msgbox "Du hast mich bereits besiegt." MSGBOX_DEFAULT
      release
      end

    .noaccess:
      msgbox "Ohne Codewort kein Kampf." MSGBOX_DEFAULT
      release
      end
    }

Was du pro Gym änderst:
- Flags: ACCESS, DEFEATED, TELEPORT
- Trainer-ID: TRAINER_CTF_GYMN_LEADER
- Texte

---

### 3.4 Teleporter (erscheint erst nach Sieg)
In Porymap:
- Lege ein Teleporter-Objekt (NPC/Tile/Sign) in den Raum.
- Setze Flag = FLAG_CTF_GYMN_TELEPORT
- Script:
    script CtfGymN_Teleporter {
      lock
      // Beispiel: später durch echtes warp ersetzen
      // warp MAP_CTF_HUB 5 6
      msgbox "Teleport!" MSGBOX_DEFAULT
      release
      end
    }

---

## 4) Alle Event-Möglichkeiten nach Flag korrekt

Wenn VAR_RESULT == 1 (Flag korrekt), kannst du z. B.:

### 4.1 Tür auf / Weg frei
A) Blocker verschwindet (empfohlen)
- setze Flag im Script (setflag)
- Blocker hat Flag in Porymap

B) Metatile-Tür öffnen
- setmetatile x y <OPEN_TILE> 0
- special DrawWholeMapView (oder Map-Refresh Special)
- Vorteil: echte Tür-Optik
- Nachteil: Koordinaten-/Tilepflege

C) Warp erst aktivieren
- Warp-Event oder Teleporter-Objekt hat Flag in Porymap
- nach Erfolg setflag FLAG_WARP_ENABLED

---

### 4.2 Neue Inhalte spawnen
- NPC/Item/Objekt in Porymap mit Flag versehen
- per Script setflag setzen

Beispiele:
- NPC erscheint und gibt Hinweis
- Item-Pokéball erscheint
- Terminal schaltet Logfile frei

---

### 4.3 Dialoge ändern
Im NPC-Script mit checkflag verzweigen:
    checkflag FLAG_CTF_GYMN_ACCESS
    if 1 goto .after
    msgbox "Erst die Flag!" MSGBOX_DEFAULT
    end
    .after:
    msgbox "Ah, du hast es geschafft." MSGBOX_DEFAULT
    end

---

### 4.4 Cutscene / Audio / Feedback
- playsong, fanfare
- applymovement (NPC bewegt sich weg)
- giveitem / addmoney / setvar
- fadescreen usw. (je nach Repo)

---

## 5) Wo trage ich die Progress-Flags ein?

### 5.1 Konstanten
Datei: include/constants/flags.h  
Lege pro Gym drei Flags an:
- FLAG_CTF_GYM1_ACCESS
- FLAG_CTF_GYM1_DEFEATED
- FLAG_CTF_GYM1_TELEPORT
… bis Gym 8.

### 5.2 Verwendung
- Terminal setzt ACCESS
- Leader setzt DEFEATED und TELEPORT
- Porymap-Objekte nutzen diese Flags als sichtbar/unsichtbar

---

## 6) Schnell-Guide: Neue Arena duplizieren

Für Gym N:
1) Flag-Wort in src/ctf_flags.c Tabelle eintragen (Index N).
2) In flags.h: ACCESS/DEFEATED/TELEPORT für Gym N definieren.
3) In Poryscript:
   - CtfGymN_Terminal
   - CtfGymN_Leader
   - CtfGymN_Teleporter
4) In Porymap:
   - Terminal-Objekt → Script CtfGymN_Terminal
   - Blocker-Objekt → Flag FLAG_CTF_GYMN_ACCESS
   - Leader-Objekt → Script CtfGymN_Leader
   - Teleporter-Objekt → Flag FLAG_CTF_GYMN_TELEPORT + Script

---

## 7) Debug / Test-Checkliste

- Flag-Wort in unterschiedlicher Schreibweise eingeben:
  sleep, SLEEP, SlEeP → muss immer funktionieren.
- Nach Erfolg:
  - Blocker verschwindet
  - Leader-Battle startet nur mit Access
  - Nach Sieg:
    - Leader ist done (DEFEATED)
    - Teleporter erscheint

---

## 8) Häufige Stolpersteine

1) Naming Screen Eingabe-Limit: Wörter kurz halten.
2) callnative hängt: immer waitstate danach; Native muss registriert sein.
3) Objekt-Flag falsch gesetzt: Blocker/Teleporter erscheinen nicht wie erwartet.

---

## 9) Minimal-Snippets (Spickzettel)

Terminal minimal:
    setvar VAR_0x8000 1
    callnative Ctf_FlagTerminal
    waitstate
    compare VAR_RESULT 1

Zugang freischalten:
    setflag FLAG_CTF_GYM1_ACCESS

Leader Battle:
    trainerbattle SINGLE TRAINER_CTF_GYM1_LEADER 0 "..." "..." 0

Teleporter aktivieren:
    setflag FLAG_CTF_GYM1_TELEPORT
