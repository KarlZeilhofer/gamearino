* Bei der Bestückung wurden soll 10k mit ist 12k bestückt, weil keine 10k vorhanden waren. 
* Statt der BAV99 wurde ein NPN-Transistor verwendet für den OLED-Reset. 

* Kurzschluss beim USB-C - Pin in Paste noch suboptimal?
  Pastenauftrag war leicht verschmiert. 

* Die Autoreset-Transistoren sind falsch belegt. 
  Wurde durch drehen um 120° und mit Drahtbrücke gelöst. 
  --> MCU Ist nun programmierbar. 

* OLED Beschaltung optimiert, siehe Screenshot:
  * R17 überbrückt
  * Kathode der Diode auf 3.3V gehängt. 

* Fehler in OLED-Pin-Reihenfolge wurde durch Kupferlackdraht und Skalpell behoben

* SDA und SCL sind im Schaltplan falsch am OLED-Display angeschlossen: 
  IST: 19+20=SCL, 18=SDA
  SOLL: 18 = SCL, 19+20 = SDA

* SCL und SDA wurde in Software ausgetauscht:
  Richtig ist nun: Wire.begin(14, 2) // SDA, SCL



