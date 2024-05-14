#ifndef ARDUINO
#include "utilsarduino.h"
_serial_internal Serial;

// modulos extra
#include <DHT.h>
#include "LiquidCrystal_I2C.h"
#define DHTTYPE "DHT22"
#define DHTPIN 2
#else
#define DHTPIN 2
#define DHTTYPE DHT22
#endif




/* EXAMPLE
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);   // Set the LCD address to 0x27 for a 16 chars and 2line display
// variables de temperatura y humedad
float t = 0;
int h = 0;


void tempHumDisplay() {
    h = dht.readHumidity();
    t = dht.readTemperature();
    lcd.setCursor(0, 1);        // display print
    lcd.print("Hum Amb = ");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(10, 1);        // display print
    lcd.print("Temp Amb= ");
    lcd.print(t);
    lcd.print("C");
}


*/
void setup(){
    // put your setup code here, to run once
    Serial.begin(9600);
    Serial.println("Inicializando...");
}


void loop() {
 // put your loop code here, to run every
}



#ifndef ARDUINO
int main(){
    setup();
    while (true) loop();
}
#endif
