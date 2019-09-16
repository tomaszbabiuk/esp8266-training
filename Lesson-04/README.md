# lesson 04 - morse

## GOAL: Using open-surce libraries, project configuration

1. Add "Morse" library to the project:
https://platformio.org/lib/show/6256/Morse/installation

platformio.ini:
```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
lib_deps = 6256 ; Morse
build_flags = -fpermissive ; required to compile Morse
```

2. Copy this code to main.cpp:

```cpp
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
```

4. Homework: blink led instead of using serial
