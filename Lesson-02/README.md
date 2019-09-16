# Lesson 02 - blinky!

## GOAL: Explaining the idea of Arduino

1. Learn about Arduino from: https://www.arduino.cc/en/Tutorial/HomePage

2. Play with LED using methods from Arduino (pinMode and digitalWrite)

main.cpp:

```cpp
#include <Arduino.h>

#define LED 16 //Define blinking LED pin

void setup() {
  pinMode(LED, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
  digitalWrite(LED, LOW); // Turn the LED on (Note that LOW is the voltage level)
  delay(1000); // Wait for a second
  digitalWrite(LED, HIGH); // Turn the LED off by making the voltage HIGH
  delay(1000); // Wait for two seconds
}
```

3. Task: find correct pin to lid the LED. The board schematic can be found here: https://www.electrodragon.com/w/ESP_Light