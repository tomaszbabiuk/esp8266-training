#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif

#define LOCAL_DISCOVERY_PORT 8888

const char* ssid     = STASSID;
const char* password = STAPSK;

static WiFiUDP _udp;
static uint8_t _incomingPacket[64];

void udp_begin() {  
  _udp.begin(LOCAL_DISCOVERY_PORT);
}

void udp_print(uint8_t *data, uint16_t length) {
  int i;
  for (i = 0; i < length; i++) {
    Serial.printf("%02X ", data[i]);
  }
    Serial.printf("\n");
}

void udp_process() {
  int packetSize = _udp.parsePacket();
  if (packetSize) {
    int len = _udp.read(_incomingPacket, 64);
    if (len > 0) {
      udp_print(_incomingPacket, packetSize);
    }
  }
}

void wifi_begin() {
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);

  wifi_begin();
  udp_begin();
}

void loop() {
  udp_process();
}