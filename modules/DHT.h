#include "stdArduino.h"
#include <iostream>
#include <string>
#define DHT22 "DHT22"
#define DHT11 "DHT11"
using std::string;
// Definición de la pseudo clase DHT
class DHT {
private:
    int pin;
    string type;

public:
    // Constructor
    DHT(int p, string t) {
        pin = p;
        type = t;

    Debugger() << "DHT object created with pin " << pin << " and type " << type << '\n';

    }
    void begin(){
}
    // Método para leer la humedad
    float readHumidity() {

        // Aquí iría el código para leer la humedad del sensor DHT
        // En este ejemplo, simplemente devolvemos un valor aleatorio
        return 50.0;
    }

    // Método para leer la temperatura
    float readTemperature() {
        // Aquí iría el código para leer la temperatura del sensor DHT
        // En este ejemplo, simplemente devolvemos un valor aleatorio
        return 25.0;
    }
};
