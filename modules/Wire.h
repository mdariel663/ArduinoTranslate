// WireStub.h - Prototipos de Wire.h (sin implementación)
#ifndef WIRE_STUB_H
#define WIRE_STUB_H

#include <inttypes.h>

#define BUFFER_LENGTH 32

class TwoWire {
public:
  // Métodos principales
  void begin();
  void begin(uint8_t address);
  void end();
  
  // Transmisión
  void beginTransmission(uint8_t address);
  uint8_t endTransmission(bool sendStop = true);
  uint8_t endTransmission(void);
  
  // Solicitud de datos
  uint8_t requestFrom(uint8_t address, uint8_t quantity, bool sendStop = true);
  uint8_t requestFrom(uint8_t address, uint8_t quantity);
  
  // Escritura
  size_t write(uint8_t data);
  size_t write(const uint8_t *data, size_t quantity);
  
  // Lectura
  int available(void);
  int read(void);
  int peek(void);
  
  // Callbacks (modo esclavo)
  void onReceive(void (*)(int));
  void onRequest(void (*)(void));
  
  // Utilidades
  void setClock(uint32_t clock);
  void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false);
  bool getWireTimeoutFlag(void);
  void clearWireTimeoutFlag(void);
};

extern TwoWire Wire;

#endif // WIRE_STUB_H
