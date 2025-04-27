// FirmataStub.h
#ifndef FIRMATA_STUB_H
#define FIRMATA_STUB_H

#include <stddef.h>

class FirmataClass {
public:
    void begin();
    void sendAnalog(byte pin, int value);
};

extern FirmataClass Firmata;

#endif // FIRMATA_STUB_H
