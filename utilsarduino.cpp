#include "utilsarduino.h"
#include <string>
#include <iostream>
#include <random>

using std::cout;
namespace Arduino {

_serial_internal::_serial_internal() {
    initialized = false;
}

void _serial_internal::begin(int baud) {
    initialized = true;
    baudRate = baud;
    cout << "Serial communication started at baud rate " << baudRate << '\n';
}

void _serial_internal::end() {
    initialized = false;
    cout << "Serial communication stopped" << '\n';
}


void pinMode(int pin, PinMode mode) {
    if (mode == OUTPUT) { cout << "[DEBUG] -> Pin " << pin << " OUTPUT" << '\n';}
    else { cout << "[DEBUG] -> Pin " << pin << " INPUT" << '\n';}
}


void digitalWrite(int pin, PinState state) {
    if (state == HIGH) {cout << "[DEBUG] -> Pin " << pin << " HIGH" << '\n';
    } else {cout << "[DEBUG] -> Pin " << pin << " LOW" << '\n';}
}

double analogRead(int pin)
{
    std::random_device rd;
    std::mt19937 gen(rd()); // Motor de números aleatorios
    std::uniform_int_distribution<> dis(pin, 500); // 0-5v mas o menos
    std::normal_distribution<> normal_dis(0.0, 1.0);
    return normal_dis(gen);
}

}

