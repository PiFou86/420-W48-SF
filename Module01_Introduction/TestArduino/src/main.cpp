#include <Arduino.h>

void allumerDELInterne(int p_duree);
void eteindreDELInterne(int p_duree);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  allumerDELInterne(500);
  eteindreDELInterne(500);
}

void allumerDELInterne(int p_duree) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);  
}

void eteindreDELInterne(int p_duree) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);  
}

