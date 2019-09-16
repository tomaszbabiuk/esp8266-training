# lesson 09 - udp server, refined with dependencies

## GOAL: Using local libraries and dependencies

1. Use the code from previous lesson as starting point

2. Add ArduinoLog library to platformio.ini

```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
lib_deps = ArduinoLog
```

2. Create folders: "UdpLogger" and "UdpLogger/src" in "./lib"

3. Delegate udp logging to separate library
   
  File: lib/UdpLogger/src/UdpLogger.h:
  
```cpp
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
```

File: lib/UdpLogger/src/UdpLogger.cpp:
```cpp
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
```

File: lib/UdpLogger/library.json:
```json
{
  "name": "UdpLogger",
  "version": "1.0"
}
```


4. Refine main.cc to use new libraries

```cpp
#include <ESP8266WiFi.h>
#include <UdpLogger.h>
#include <ArduinoLog.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif

#define UDP_PORT 8888

const char* ssid     = STASSID;
const char* password = STAPSK;

UdpLogger udpLogger;

void wifi_begin() {
  Log.verbose("Connecting to %s\r\n", ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Log.verbose("Waiting for connection...\r\n");
  }

  Log.verbose("WiFi connected, IP address: %d.%d.%d.%d\r\n", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);
}

void setup() {
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);

  wifi_begin();
  udpLogger.init(UDP_PORT);
}

void loop() {
  udpLogger.process();
}
```

5. Homework: "extract logic responsible for Wi-Fi into another local library"