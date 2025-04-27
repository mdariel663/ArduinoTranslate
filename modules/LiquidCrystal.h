// LiquidCrystalStub.h
#ifndef LIQUIDCRYSTAL_STUB_H
#define LIQUIDCRYSTAL_STUB_H

#include <inttypes.h>

class LiquidCrystal {
public:
    void begin(uint8_t cols, uint8_t rows);
    void print(const char *str);
    void setCursor(uint8_t col, uint8_t row);
};

#endif // LIQUIDCRYSTAL_STUB_H
