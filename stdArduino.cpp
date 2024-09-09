#include "stdArduino.h"
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
    Debugger() << "SerialBegin: " << baud;
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
    if (state == HIGH) {
        cout << "[DEBUG] -> Pin " << pin << " HIGH" << '\n';
    } else {
        cout << "[DEBUG] -> Pin " << pin << " LOW" << '\n';
    }
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


std::string Debugger::selectLoggerLevel(DebugLevel logType){
    switch (logType) {
    case DEBUG:
        return "[DEBUG] ";
    case WARN:
        return "[WARN] ";
    default:
        return "[INFO] ";
    }
}

Debugger::~Debugger(){
//    if (m_out){
//        delete m_out;
//        m_out = nullptr;
//    }
}

#define INTERNAL_DEBUGGER
//#define INTERNAL_FILE_LOGGER

template<typename T>
Debugger &Debugger::operator <<(const T &object)
{
    std::string LogLevelStr = selectLoggerLevel(LogLevel);

// TODO: Implementar FileLogger
//#ifdef INTERNAL_FILE_LOGGER
//#endif

#ifdef INTERNAL_DEBUGGER
    if (!m_out)
        m_out = &std::cout;

    (*m_out) << LogLevelStr << object;
#endif
    return *this;

}
