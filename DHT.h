#include <string>
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
#ifdef DEBUG
        std::cout << "DHT object created with pin " << pin << " and type " << type << endl;
#endif
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
