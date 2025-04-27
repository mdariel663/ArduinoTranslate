
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