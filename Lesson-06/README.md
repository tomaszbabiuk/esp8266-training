# Lesson 06 - smart config (esp touch)

## GOAL: Sending wifi credentials to the device, getting more information on how flash of esp8266-arduino is structured

1. Install SmartConfig app from Google Play store:
https://play.google.com/store/apps/details?id=com.cmmakerclub.iot.esptouch

2. Erase flash data (wifi data from previous examples)
pio run --target erase

3. Deploy smart config code on esp8266:

main.cpp:
```cpp
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.mode(WIFI_AP_STA);
  delay(500);

  WiFi.beginSmartConfig();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.println(WiFi.smartConfigDone());
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {

}
```

4. Follow the instructions from "Smart Config" application and send wifi credentials to the device