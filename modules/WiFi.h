// WiFiStub.h
#ifndef WIFI_STUB_H
#define WIFI_STUB_H

#include <IPAddress.h>

class WiFiClass {
public:
    int begin(const char* ssid, const char* password);
    IPAddress localIP();
};

extern WiFiClass WiFi;

#endif // WIFI_STUB_H
