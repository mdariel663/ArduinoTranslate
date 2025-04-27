// EEPROMStub.h
#ifndef EEPROM_STUB_H
#define EEPROM_STUB_H

template<typename T> 
T &EEPROM_get(int idx, T &t);

class EEPROMClass {
public:
    uint8_t read(int address);
    void write(int address, uint8_t val);
};

extern EEPROMClass EEPROM;

#endif // EEPROM_STUB_H
