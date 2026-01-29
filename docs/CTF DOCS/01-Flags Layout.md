## Theme
Pokemon Rom hack:

### Story:
- Ganzer Tag Komisch
- Glitches als Gateway --> durch flagge geöffnet
### Flag 0 (Tutorial Flag)
- Links die flag in Rot13 und rechts jemand der erzählt wie toll Rot13 ist.
	- Flagname {I_Like_Rot_13}	  
### Story: 
- Herr Bauer sagt wir haben extra auf sie gewartet:
	- text Pokemon Starten

### Flag1
- Team Rocket hat eine Galerie verunstaltet, Bilder zuordnen Jahreszahlen

### Flag2
- HalterWower Theo 1 --> Glitch du hast Matrikelnummer vergessen
- Flashback ins Sekretariat --> Trainernnr + Name xor oder änhliches 
	- Flagname {Iam_XXXXXXX}
### Flag3
- Fällt in ein Glitchloch (Keller/Werkstatt)
	- Items linux befehle für terminal (TM sprite)
- Rätsel durch linux Befehle zb. CD... zurück CD Ebene1

- Ein Exit point braucht flagge -->
	- {Linux_is_cool}

### Flag4
- Story hinted auf Savegame
- Obfuskation von Flagge in savegame
- Flaggename: {is_it_save?}

### Flag5: 
- NPC ein System zeigt nur noch eine Zahl an und reagiert nicht auf eingaben.
- Bildschirme zeigen beispiele für eine leichte Hashfunktion.
- Diese muss reverse engineered werden mit den beispielen.
- „LegacyHash v0.3 – Token required.“ 
	- NPC: „Ich kenne den Code nicht. Aber hier liegen noch Log-Ausdrucke mit ein paar alten Einträgen. Wenn du das Muster knackbarst, kommst du durch.“
- Hashfunktion wie Token = (Summe * 300 + 223) mod 2000 kann auch randomized sein müsste man sich überlegen
- Irgendwo sind beispiele verteilt
	- Zeigt Flag bei Reparatur {Reverse_it}
### Flag6:
- Music Flag 
- Story kommt noch
- Flag in Soundtrack morse code 
  
### Flag 7 – _“The Code Beneath the World”_

**Schwierigkeit:** hoch  
**Technischer Fokus:** Decompiling / Reverse Engineering / GBA-Binary  
**Flagname:** `{I_See_The_Code}` _(Vorschlag)_
## Story-Einbettung

- Nach Flag 6 beginnt das Spiel **stärker zu glitchten**:
    
    - NPCs frieren ein
        
    - Texte erscheinen fragmentiert
        
    - Tiles fehlen oder zeigen Debug-Sprites
        
- Ein NPC sagt sinngemäß:
    

> „Die Welt läuft nicht mehr richtig.  
> Früher war alles klar – jetzt ist nur noch **Code** übrig.  
> Wenn du verstehen willst, musst du **unter die Oberfläche schauen**.“

- Der Spieler betritt einen Bereich wie:
    
    - „Debug Room“
        
    - „Abandoned Dev Lab“
        
    - „Memory Core“
        

---

## Kernidee (CTF-Mechanik)

Die Flag ist **nicht direkt im Spiel lösbar**, sondern **im ROM selbst versteckt** – allerdings **nicht als Klartext**, sondern:

- als **obfuskierter String**
    
- oder **zusammengesetzt aus mehreren Konstanten**
    
- oder **nur über eine Funktion erreichbar**, die im Spiel nie normal ausgeführt wird
    

→ **Spieler müssen die ROM dekompilieren oder disassemblieren.**

Technische Umsetzung (realistisch & machbar)

#### Variante A – Flag im C-Code (pokeemerald-expansion ideal)

Da ihr `pokeemerald-expansion` nutzt:

1. Die Flag liegt **nicht als String literal** vor:
    
    `static const u8 flagData[] = {0x12, 0x3F, 0x29, 0x01, ...};`
    
2. Eine Funktion dekodiert sie:
    
    `void DecodeFlag(u8* out) {     for (int i = 0; i < LEN; i++)         out[i] = flagData[i] ^ 0x55; }`
    
3. Die Funktion wird **nie im Spiel aufgerufen**.
    

👉 Spieler müssen:

- ROM extrahieren
    
- Code analysieren (ghidra / IDA / pokeemerald source)
    
- XOR rückgängig machen

## Sinnvoller Ansatz für eine „Save/Memory Manipulation“-Flag 8

Du baust **deinen eigenen MissingNo-artigen Glitch** als Story-Element, der absichtlich eine Memory-/Save-Manipulation auslöst – kontrolliert, reproduzierbar und CTF-tauglich.

Damit bekommst du:

- das „MissingNo-Feeling“ (Glitch-Pokémon als Trigger)
    
- aber ohne dich auf instabile, schwer reproduzierbare Engine-Bugs zu verlassen
    

---

# Flag 8 Konzept: „MissingNo as a Write Primitive“

**Ziel:** Spieler müssen über ein Glitch-Pokémon (MissingNo-Analog) eine bestimmte **Save-Variable** verändern, um eine Tür / NPC / Ending freizuschalten.

### Story

Ein NPC sagt:

> „Dieses Pokémon existiert nicht. Es schreibt Dinge um. Wenn du es fütterst… verändert sich die Realität.“

### Mechanik

- Du implementierst ein spezielles Pokémon (z. B. „MISSINGNO“ als Fakemon/Debug-Mon).
    
- Beim Fangen / Level-Up / Item-Use löst es **absichtlich** eine Routine aus, die:
    
    - eine kleine Datenstruktur aus dem Party-/Box-Slot liest
        
    - diese Bytes in einen „Save-Block“ schreibt (oder eine GameVar setzt)
        

Das ist dann ein kontrollierter „Exploit“:

- Spieler müssen herausfinden:
    
    - welche Werte (z. B. Nickname/OT/EVs/IVs/Checksum) wie interpretiert werden
        
    - wie sie MissingNo präparieren müssen
        
- Ergebnis: ein Wert wird gesetzt → Flag erscheint oder Exit öffnet sich.
    

---

## Drei Varianten (nach Schwierigkeitsgrad)

### Variante 1: Einfach – „Nickname als Key“

- MissingNo schreibt den **Nickname** (oder Teile davon) XOR-kodiert in eine SaveVar.
    
- Spieler müssen MissingNo so benennen, dass die SaveVar den Zielwert trifft.
    
- Sehr CTF-tauglich, reproduzierbar.
    

**Beispiel:**

- SaveVar `VAR_GLITCH_KEY` wird aus den ersten 4 Zeichen des Nicknames berechnet.
    
- Tür prüft: `VAR_GLITCH_KEY == 0x1337`.
    

---

### Variante 2: Mittel – „Box-Daten / Checksums“

- MissingNo nutzt Bytes aus dem Pokémon-Datenblock (Growth/Attack/EVs/Misc).
    
- Spieler müssen z. B. mit seltenen Candies/EV-Training/Items Werte einstellen.
    
- Dann triggert ein NPC „Stabilizer“, der die Daten in eine Variable „leakt“.
    

Das ist mehr „puzzle“ als „pure RE“.

---

### Variante 3: Hart – „Write-What-Where light“

- MissingNo implementiert absichtlich eine fehlerhafte Copy-Routine:
    
    - `memcpy(savePtr + offset, src, len)`
        
    - offset/len werden aus Pokémon-Daten abgeleitet
        
- Spieler müssen einen **gezielten Write** erzeugen (aber sicher begrenzt), um:
    
    - ein Flag-Bytearray zu entschlüsseln
        
    - oder eine „DoorUnlocked“-Flag zu setzen
        

Wichtig: begrenzen, damit nichts kaputtgeht:

- offset nur innerhalb eines kleinen „Glitch“-Savebereichs
    
- len capped
    
- Checksums anschließend korrekt neu berechnen (sonst Save bricked)

  
Additions if theres time:
- More Pokemon Elements
- Besondere Pokemon
- MissingNo als Flag