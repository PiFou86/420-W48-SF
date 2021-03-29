#include <Arduino.h>

void allumerLedInterne(int p_delay);
void eteindreLedInterne(int p_delay);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  allumerLedInterne(500);
  eteindreLedInterne(500);
}

void allumerLedInterne(int p_delay) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_delay);  
}

void eteindreLedInterne(int p_delay) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_delay);  
}

