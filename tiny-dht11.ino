
#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>
#include "DHT.h"

#define DHTPIN 1     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

SSD1306_Mini oled;

void setup() {
  oled.init(0x3c);

  oled.clear();
  oled.startScreen();
  oled.cursorTo(48, 1);
  oled.printString( "ATTiny");

  oled.cursorTo(0, 4);
  oled.printString("Temp: ");
  oled.cursorTo(0, 6);
  oled.printString("Humidity: ");
  
  dht.begin();
}


void loop() {
  delay(1000);
    
  char temp[16];
  oled.cursorTo(115, 4);
  itoa((int)dht.readTemperature(), temp, 10);
  oled.printString(temp);
  
  char hum[16];
  oled.cursorTo(115, 6);
  itoa((int)dht.readHumidity(), hum, 10);
  oled.printString(hum);

}
