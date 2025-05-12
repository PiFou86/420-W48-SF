#include <Arduino.h>

const uint8_t pinBouton = 2;
int etatPrecedant = 0;
bool delAllumee = false;
void setup() {
  Serial.begin(9600);

  pinMode(pinBouton, INPUT);
  etatPrecedant = digitalRead(pinBouton);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, delAllumee);
}

void loop() {
  // put your main code here, to run repeatedly:
  int etatCourant = digitalRead(pinBouton);

  if (etatPrecedant != etatCourant) {
    Serial.print(millis());
    Serial.print(" : ");
    Serial.print(etatPrecedant);
    Serial.print(" ");
    Serial.println(etatCourant);
    if (etatPrecedant == LOW && etatCourant == HIGH) {
      delAllumee = !delAllumee;
      digitalWrite(LED_BUILTIN, delAllumee);
    }

    etatPrecedant = etatCourant;
  }
}
