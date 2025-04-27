// SDStub.h
#ifndef SD_STUB_H
#define SD_STUB_H

class File {
public:
    size_t write(const uint8_t *buf, size_t size);
    int read();
};

class SDClass {
public:
    bool begin(uint8_t csPin);
    File open(const char *filename);
};

extern SDClass SD;

#endif // SD_STUB_H
