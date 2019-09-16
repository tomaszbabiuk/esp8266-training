#ifndef UdpLogger_h
#define UdpLogger_h

#include <Arduino.h>

class UdpLogger
{
  public:
    static void init(int port);
    static void process();

  private:
    static void print(uint8_t *data, uint16_t length);
};

#endif
