#include "stdArduino.h"
#include <string>
#include <iostream>
#include <random>
#include <map> 
#include <algorithm> // Incluir para std::sort
#include "events.h"


std::map<int, int> digitalPinStates; // Guarda HIGH o LOW
std::map<int, int> analogPinStates;  // Guarda valores 0-255

using std::cout;

std::chrono::steady_clock::time_point lastChangeTime;
int lastPin = -1;
int lastState = LOW;

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

    // Guardar duración del último estado
    if (lastPin != -1) {
        auto now = std::chrono::steady_clock::now();
        int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastChangeTime).count();
        pinEvents.back().duration += elapsed;
    }
}


void digitalWrite(int pin, int state) {
    digitalPinStates[pin] = state; // Guardamos estado
    Debugger() << "Pin " << pin << " set " << (state == HIGH ? "HIGH" : "LOW") << '\n';

    auto now = std::chrono::steady_clock::now();

    // Si el pin cambia o es el primer cambio
    if (pin != lastPin || state != lastState) {
        if (lastPin != -1) {
            int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastChangeTime).count();
            pinEvents.back().duration += elapsed;
        }
        pinEvents.push_back({pin, state, 0});
        lastPin = pin;
        lastState = state;
        lastChangeTime = now;
    }
}

void detectPatron() {
    if (pinEvents.size() < 2) {
        return; // No hay suficientes eventos para detectar patrones
    }

    // Ordenamos los eventos por timestamp (en caso de que no lleguen en orden)
    std::sort(pinEvents.begin(), pinEvents.end(), [](const PinEvent& e1, const PinEvent& e2) {
        return e1.timestamp < e2.timestamp;
    });

    // Detectar patrones
    for (size_t i = 0; i + 1 < pinEvents.size(); i++) {
        auto& e1 = pinEvents[i];
        auto& e2 = pinEvents[i + 1];

        // Detectar "Blink" (parpadeo clásico)
        if (e1.pin == e2.pin && e1.state == HIGH && e2.state == LOW &&
            std::abs(e1.duration - e2.duration) <= 200 && // Tolerancia de tiempo
            e1.duration >= 800 && e1.duration <= 1200) { // Duración cerca de 1 segundo
            Debugger() << "Detectado patrón: Blink en pin " << e1.pin << '\n';
        }

        // Detectar "Fade" (cambio gradual)
        if (e1.pin == e2.pin && e1.state == HIGH && e2.state == LOW &&
            std::abs(e1.duration - e2.duration) <= 200 && // Tolerancia en duración
            e1.duration > 1200 && e2.duration > 1200) { // Duraciones largas (fade gradual)
            Debugger() << "Detectado patrón: Fade en pin " << e1.pin << '\n';
        }

        // Detectar "Morse" (código morse)
        if (e1.state == HIGH && e2.state == LOW &&
            (e1.duration >= 200 && e1.duration <= 500) &&  // Cortos
            (e2.duration >= 500 && e2.duration <= 1000)) { // Largos
            Debugger() << "Detectado patrón: Morse en pin " << e1.pin << '\n';
        }

        // Detectar "On/Off rápido" (estroboscópico)
        if (e1.state == HIGH && e2.state == LOW &&
            e1.duration < 100 && e2.duration < 100) { // Duración muy corta
            Debugger() << "Detectado patrón: On/Off rápido en pin " << e1.pin << '\n';
        }

        // Detectar "Secuencial" (encender pines en secuencia)
        if (i > 0 && e1.state == HIGH && e2.state == HIGH) {
            if (pinEvents[i - 1].pin == e1.pin - 1 && e2.pin == e1.pin + 1) {
                Debugger() << "Detectado patrón: Secuencia en pins " << e1.pin << " y " << e2.pin << '\n';
            }
        }
    }
}

int digitalRead(int pin) {
    int value = digitalPinStates.count(pin) ? digitalPinStates[pin] : generateRandomDigitalValue(); // Si no se escribió nada, es LOW
    Debugger() << "Pin " << pin << " digitalRead: " << value << '\n';
    return value;
}

void analogWrite(int pin, int value) {
    if (value < 0 || value > 255) {
        Debugger() << "Pin " << pin << " analogWrite: value must be between 0 and 255" << '\n';
        return;
    }
    analogPinStates[pin] = value; // Guardamos el valor PWM
    Debugger() << "Pin " << pin << " analogWrite: " << value << '\n';
}

double analogRead(int pin) {
    double value = analogPinStates.count(pin) ? analogPinStates[pin] * (500.0 / 255.0) : generateRandomAnalogValue(); // Convertimos el PWM a un valor analógico
    Debugger() << "Pin " << pin << " analogRead: " << value << '\n';
    return value;
}
int generateRandomDigitalValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(0.5); // 50% probabilidad de HIGH (1) o LOW (0)
    return dis(gen) ? 1 : 0;
}
double generateRandomAnalogValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 500);
    return dis(gen);
}

void pinMode(int pin, int mode) {
    if (mode == OUTPUT)
    Debugger() << "Pin " << pin << " OUTPUT" << '\n';
    else 
    Debugger() << "Pin " << pin << " INPUT" << '\n';
}

/*
void digitalWrite(int pin, int state) {
    if (state == HIGH) {
        cout << "[DEBUG] -> Pin " << pin << " HIGH" << '\n';
    } else {
        cout << "[DEBUG] -> Pin " << pin << " LOW" << '\n';
    }
}

int digitalRead(int pin) {
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Motor de números aleatorios
    std::bernoulli_distribution dis(0.5); // 50% probabilidad de HIGH (1) o LOW (0)

    int value = dis(gen) ? 1 : 0; // Devuelve 1 o 0
    std::cout << "[DEBUG] -> Pin " << pin << " digitalRead: " << value << '\n';
    return value;
}
void analogWrite(int pin, int value) {
    if (value < 0 || value > 255) {
        Debugger() << "Pin " << pin << " analogWrite: value must be between 0 and 255" << '\n';
        return;
    }
    std::cout << "[DEBUG] -> Pin " << pin << " analogWrite: " << value << '\n';
}
double analogRead(int pin) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 5000);

    int value = dis(gen);
    cout << "[DEBUG] -> Pin " << pin << " analogRead: " << value << '\n';
    return static_cast<double>(value);
}

*/

namespace Arduino {
SerialInternal::SerialInternal() : initialized(false), baudRate(9600) {}

    void SerialInternal::begin(int baud) {
        initialized = true;
        baudRate = baud;
        Debugger() << "SerialBegin: " << baud;
    }

    void SerialInternal::end() {
        initialized = false;
        Debugger() << "Serial stopped" << '\n';
    }

    bool SerialInternal::isInitialized() const {
        return initialized;
    }

}
