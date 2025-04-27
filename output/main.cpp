
#ifndef ARDUINO
#include "stdArduino.h"
#endif


int potPin = 0; 		// Pin de entrada para el potenciómetro 
int ledPin = 13; 		// Pin de salida para el LED
void setup() { 
   pinMode(ledPin, OUTPUT); 	// Declara el pin del LED como de salida
} 
void loop() { 
   digitalWrite(ledPin, HIGH);	// Enciende el LED 
   delay(analogRead(potPin));		// Lee el valor del potenciómetro 
   digitalWrite(ledPin, LOW);		// Apaga el LED 
   delay(analogRead(potPin)); 	 
} 
#ifndef ARDUINO
int main(){
	setup();
	int i=0 ;
	while(true) {
		std::cout << "Tick : "<< i++ << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(/*1000*/ 50));
		if (i > 5){
			std::cout<<"Activando Deteccion de patron"<<std::endl;
			detectPatron();
		}
		loop();
		}
	}

#endif

