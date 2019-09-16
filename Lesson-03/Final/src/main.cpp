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