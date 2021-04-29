# Gamearino

Elektronisches Spielgerät mit 
* Gameboy Tastenlayout
* OLED-Display mit 128x64 Pixel
* Controller: ESP8266EX (Modul ESP-12F)

# OLED
wurde getestet mit dem Arduino Nano mit der Adafruit-Lib. Weil wir keinen Reset-Pin haben, 
muss das Display etwas anders initialisiert werden: 
''display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false);''

Die I2C-Adresse jedenfalls ist 0x3c anstatt 0x3d (Default aus Example Code). 

# Arduino IDE
* ESP8266 installieren: 
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
* Adafruit SSD1306 Lib: 
  Achtung: I2C-Adresse auf 0x3c:
  #define SCREEN_ADDRESS 0x3c

  I2C-Schnittstelle auf GPIO2 und GPIO14 festlegen:
  Wire.begin(2,14); // SDA, SCL


# Links
* Arduino ES8266 Core Dokumentation: https://arduino-esp8266.readthedocs.io/en/latest/
* Wikipedia: https://en.wikipedia.org/wiki/ESP8266
* OLED I2C vs. SPI on Youtube: https://www.youtube.com/watch?v=Wz6Fzo3rsLM
* https://www.heise.de/ct/artikel/Arduino-IDE-installieren-und-fit-machen-fuer-ESP8266-und-ESP32-4130814.html
* http://stefanfrings.de/esp8266/

