#include "UdpLogger.h"
#include <Arduino.h>
#include <WiFiUdp.h>
#include <ArduinoLog.h>

static WiFiUDP _udp;
static uint8_t _incomingPacket[64];

void UdpLogger::init(int port) {
	_udp.begin(port);
}

void UdpLogger::process() {
  int packetSize = _udp.parsePacket();
  if (packetSize) {
    int len = _udp.read(_incomingPacket, 64);
    if (len > 0) {
      print(_incomingPacket, packetSize);
    }
  }
}

void UdpLogger::print(uint8_t *data, uint16_t length) {
  int i;
  for (i = 0; i < length; i++) {
	Log.notice("%02X ", data[i]);
  }
}
