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