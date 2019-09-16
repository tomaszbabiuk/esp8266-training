#include <Arduino.h>

#include "Morse.h"

Morse morse;

String s;

void receiver(char e) {
  // receiving a message (letter by letter)

  Serial.print(e);
  delay(50);
}

void transmiter(uint8_t e) {
  s += String(e);
  if (e == MORSE_GAP) Serial.print("");
  if (e == MORSE_CHAR) Serial.print("/");
  else if (e == MORSE_SPACE) Serial.print("   ");
  else if (e == MORSE_EOL) Serial.println(" EOL ");
  else {
    if (e == MORSE_DI) Serial.print("_");
    else if (e == MORSE_DIT) Serial.print("-");
    else if (e == MORSE_DAH) Serial.print("�");
    else {
      Serial.print("");
    }
  }
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  morse.begin(receiver, transmiter);
}

void loop() {
  delay(3000);
  morse.print("hello");
  // put your main code here, to run repeatedly:
}
