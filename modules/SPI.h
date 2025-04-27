// SPIStub.h
#ifndef SPI_STUB_H
#define SPI_STUB_H

#include <Arduino.h>

class SPIClass {
public:
    void begin();
    void end();
    void beginTransaction(uint32_t settings);
    void endTransaction();
    uint8_t transfer(uint8_t data);
};

extern SPIClass SPI;

#endif // SPI_STUB_H
