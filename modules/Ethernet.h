// EthernetStub.h
#ifndef ETHERNET_STUB_H
#define ETHERNET_STUB_H

#include <IPAddress.h>

class EthernetClass {
public:
    void begin(uint8_t *mac, IPAddress ip);
    void maintain();
};

extern EthernetClass Ethernet;

#endif // ETHERNET_STUB_H
