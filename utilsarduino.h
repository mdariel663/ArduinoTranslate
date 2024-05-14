#ifndef UTILSARDUINO_H
#define UTILSARDUINO_H
#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
using std::cout;

enum PINOUTS_ARDUINO{
    A0,
    A1,
    A2,
    A3,
    A4,
    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13 //Pines digitales. D0 y D1 también se utilizan para la comunicación serial (RX y TX respectivamente).
    //PWM D3, D5, D6, D9, D10 y D11 en Arduino Uno).

};
namespace Arduino {

enum PinMode {
    INPUT,
    OUTPUT
};
enum PinState{
    HIGH,
    LOW
};
double analogRead(int pin);
void pinMode(int pin, PinMode mode);

void digitalWrite(int pin, PinState state);

typedef std::string String; // Creando el String como deftype

class _serial_internal {
private:
    bool initialized;
    int baudRate;

public:
    // Constructor
    _serial_internal();

    // Método para iniciar la comunicación _serial_internal
    void begin(int baud);

    // Método para detener la comunicación _serial_internal
    void end();

    // Método para enviar datos
    template<typename T>
    void print(T data){
        if (initialized) {
            cout << data;
        } else {
            cout << "Serial communication not initialized. Cannot send data." << '\n';
        }
    }

    template<typename T>
    void println(T data) {
        if (initialized) {
            cout << data << '\n';
        } else {
            cout << "Serial communication not initialized. Cannot send data." << '\n';
        }
    }

};
}
using namespace Arduino;

#endif // UTILSARDUINO_H

