// ServoStub.h
#ifndef SERVO_STUB_H
#define SERVO_STUB_H

#include <inttypes.h>

class Servo {
public:
    bool attach(int pin);
    void write(int angle);
    int read();
};

#endif // SERVO_STUB_H
