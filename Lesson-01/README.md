# lesson 01 - serial port logging

## GOAL: Showing how to create new project in PlatformIO, basic features of PlatformIO: Build/Upload/Serial Monitor

1. Open Visual Studio code
2. Open PlatformIO tab
3. Click Home
4. Choose "New project"
	* Name: RoverFW
	* Board: Espressif ESP8266 ESP-12E
	* Framework: Arduino

5. Find "main.cpp" and replace its content with

```cpp
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);
  Serial.write(".\r\n");
}
```

6. Play with "Upload", "Build" and "Serial monitor" buttons