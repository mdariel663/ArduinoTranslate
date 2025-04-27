#ifndef STDARDUINO_H
#define STDARDUINO_H

#include <iostream>
#include <math.h>
#include <cstring>
#include <iosfwd>
#include <chrono>
#include <thread>
#include "debugger.h"
using std::cout;

void delay(int);
void detectPatron();
double analogRead(int pin);
void pinMode(int pin, int mode);
void analogWrite(int pin, int value);
void digitalWrite(int pin, int state);
int digitalRead(int pin);

int generateRandomDigitalValue();
double generateRandomAnalogValue();

namespace Arduino {
class SerialInternal {
private:
    bool initialized;
    int baudRate;

public:
    // Constructor
    SerialInternal();

    // Método para iniciar la comunicación _serial_internal
    void begin(int baud);

    // Método para detener la comunicación _serial_internal
    void end();
    bool isInitialized() const;
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
static SerialInternal Serial;
#endif // STDARDUINO_H

