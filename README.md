# Gamearino

Elektronisches Spielgerät mit 
* Gameboy Tastenlayout
* OLED-Display mit 128x64 Pixel
* Controller: ESP8266

# Arduino IDE
* ESP8266 installieren: 
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
* Adafruit SSD1306 Lib: 
  Achtung: I2C-Adresse auf 0x3c:
  #define SCREEN_ADDRESS 0x3c

  I2C-Schnittstelle auf GPIO2 und GPIO14 festlegen:
  Wire.begin(2,14); // SDA, SCL


# Links
* https://www.heise.de/ct/artikel/Arduino-IDE-installieren-und-fit-machen-fuer-ESP8266-und-ESP32-4130814.html
* http://stefanfrings.de/esp8266/

