# lesson 03 - multiplatform blinky

## GOAL: Passing build parameters to code. Writing one code for multiple platforms.

1. Use source code from previous lesson (blinky)

2. Change blinky sample to use led pin from configuration:

```cpp
#include <Arduino.h>

void setup() {
  pinMode(LED_PIN_FROM_BUILD_FLAGS, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
  digitalWrite(LED_PIN_FROM_BUILD_FLAGS, LOW); // Turn the LED on (Note that LOW is the voltage level)
  delay(1000); // Wait for a second
  digitalWrite(LED_PIN_FROM_BUILD_FLAGS, HIGH); // Turn the LED off by making the voltage HIGH
  delay(1000); // Wait for two seconds
}
```

3. Add LED_PIN_FROM_BUILD_FLAGS flag to platform.ini:
   
```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
build_flags = -DLED_PIN_FROM_BUILD_FLAGS=16
```
4. Add nRF52840 board to platform.ini
  
```ini
[env:esp12e]
(...)

[env:nrf52840_dk]
platform = nordicnrf52
board = nrf52840_dk
framework = arduino
debug_tool = jlink
build_flags = -DLED_PIN_FROM_BUILD_FLAGS=2
```

5. Run the same code on nrf52840_dk. In order to deploy on nRF board only use nrf52840_dk use default_envs

```ini
[platformio]
default_envs = nrf52840_dk

[env:esp12e]
(...)

[env:nrf52840_dk]
(...)
```

6. For more information about platformio.ini, see https://docs.platformio.org/en/latest/projectconf.html