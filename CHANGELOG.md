Changelog Gamearino
===================


# Elektronik
## V0.0.1 - CNC-Prototyp
* Grundbeschaltung des ESP8266 ESP-12F:
  * 10k auf GPIO15 gegen GND
  * 10k auf Enable gegen 3V3
* Programmierschaltung mit Transistoren auf Steckbrett getestet
  Arduino-IDE, Standardeinstellung für NodeMCU 1.0
* OLED-Beschaltung auf Steckbrett getestet
* 3D-Design der Taster und des Steuerkreuzes
* Die 8 Taster werden über eine 3x3-Tastermatrix ausgewertet
* Autoreset: unterer Transistor gespiegelt. Beide sind NPN. 
* Pinbelegungsliste als .ods-Datei
* Bemaßungen der Taster
* TODOs aktualisiert: ESP mit OLED erfolgreich getestet
* OLED Demoprogramm
* Tastenanordnung Start/Select und A/B wie beim Original Gameboy (TM)
* USB-Footprint optimiert, inkl. Pin in Paste
* Layout für CNC-Fertigung (ca. 60 Vias!)

# 3D-Druck
* Steuerkreuz: Unterkante von 1.8mm auf Niveau +1.6mm abgesenkt, Haltering bleibt oben +2.8mm
* Gehäuseboden gestaltet
* Dummy-PCB
* Gehäusedeckel probegedruckt
* Deckel-Boden-Paarung: mit 0.2mm-Nut, und identischen Konturen passt es perfekt zusammen
* 3D-Druckteile auf 0.2mm Schichthöhe optimiert (außer Steuerkreuz)
## TODOs
* Gehäuse dokumentieren


# Spiele
## Snake
* Grundsätzliche Funktion vorhanden
* TODO: Highscore
* TODO: Asynchrones Warten und Tasten einlesen

