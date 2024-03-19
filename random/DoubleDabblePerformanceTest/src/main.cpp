#include <Arduino.h>

#include "BCD.h"

void setup() {
  #ifdef ESP32
  Serial.begin(115200);
  #else
  Serial.begin(9600);
  #endif

  unsigned long start = micros();
  for (uint8_t i = 0; i < 100; i++)
  {
      uint16_t v = double_dabble8(i);
      String s = bcd2String(v);
      if (s != String(i)) {
          Serial.println(String("1 - Error: ") + String(i) + " -> " + s);
      }
      if (i % 1000 == 0) {
          Serial.println(i);
      }
  }
  Serial.println(String("Temps 1 :") + (micros() - start));

  start = micros();
  for (uint8_t i = 0; i < 100; i++)
  {
      String s = int2String(i);
      if (s != String(i)) {
          Serial.println(String("2 - Error: ") + String(i) + " -> " + s);
      }
      if (i % 1000 == 0) {
          Serial.println(i);
      }
  }
  Serial.println(String("Temps 2 :") + (micros() - start));

    start = micros();
  for (uint16_t i = 0; i < 10000; i++)
  {
      uint32_t v = double_dabble32(i);
      String s = bcd2String(v);
      if (s != String(i)) {
          Serial.println(String("3 - Error: ") + String(i) + " -> " + s);
      }
      if (i % 1000 == 0) {
          Serial.println(i);
      }
  }
  Serial.println(String("Temps 3 :") + (micros() - start));

  start = micros();
  for (uint16_t i = 0; i < 10000; i++)
  {
      String s = int2String(i);
      if (s != String(i)) {
          Serial.println(String("4 - Error: ") + String(i) + " -> " + s);
      }
      if (i % 1000 == 0) {
          Serial.println(i);
      }
  }
  Serial.println(String("Temps 4 :") + (micros() - start));
}

void loop() {
  ;
}

// Sortie série: (arduino)
// 0
// 15532 => 2 fois plus rapide sur 16 bits
// 0
// 31052
// 0
// 1000
// 2000
// 3000
// 4000
// 5000
// 6000
// 7000
// 8000
// 9000
// 29351500
// 0
// 1000
// 2000
// 3000
// 4000
// 5000
// 6000
// 7000
// 8000
// 9000
// 5997608 => 5 fois plus rapide sur 32 bits

// Sortie série: (ESP32)
// 0
// Temps 1 :1386
// 0
// Temps 2 :1406
// 0
// 1000
// 2000
// 3000
// 4000
// 5000
// 6000
// 7000
// 8000
// 9000
// Temps 3 :477074
// 0
// 1000
// 2000
// 3000
// 4000
// 5000
// 6000
// 7000
// 8000
// 9000
// Temps 4 :207296 => 2 fois plus rapide sur 16 bits
