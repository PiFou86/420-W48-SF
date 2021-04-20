#include <Arduino.h>

void DemoDelay();
void DemoBoutonDEL();
void DemoBoutonOnOff();

int dernierEtatLed = LOW;

const int borneEntree = 2;
const int borneSortie = 3;
const int borneMesureLoop = 13;
long derniereDateChangement = 0;
int dernierEtatBouton = HIGH;
int dernierEtatStableBouton = HIGH;
const int delaiMinPression = 25;

void setup() {
  pinMode(borneSortie, OUTPUT);
  pinMode(borneEntree, INPUT);

  pinMode(borneMesureLoop, OUTPUT);
}

void loop() {
  digitalWrite(borneMesureLoop, LOW);

  //DemoDelay();
   DemoBoutonDEL();
  // DemoBoutonOnOff();

  digitalWrite(borneMesureLoop, HIGH);
}

int valBouton = LOW;
void DemoDelay() {
  valBouton = digitalRead(borneEntree);  // retourne LOW ou HIGH
  digitalWrite(borneSortie, !valBouton);
  delay(500);  //  s’assure de la stabilité du contact
}

void DemoBoutonDEL() {
  int etatBouton = digitalRead(borneEntree);
  long dateActuelle = millis();
  if (etatBouton != dernierEtatBouton) {
    derniereDateChangement = dateActuelle;
    dernierEtatBouton = etatBouton;
  }

  if (dateActuelle - derniereDateChangement > delaiMinPression) {
    if (dernierEtatStableBouton == HIGH && etatBouton == LOW) {
      // bouton appuyé
      // Action à réaliser
      digitalWrite(borneSortie, HIGH);
    } else if (dernierEtatStableBouton == LOW && etatBouton == HIGH) {
      // bouton relaché
      // ... et donc comme click
      // Action à réaliser
      digitalWrite(borneSortie, LOW);
    }
    dernierEtatStableBouton = etatBouton;
  }
}

void DemoBoutonOnOff() {
  int etatBouton = digitalRead(borneEntree);
  long dateActuelle = millis();
  if (etatBouton != dernierEtatBouton) {
    derniereDateChangement = dateActuelle;
    dernierEtatBouton = etatBouton;
  }
  if (dateActuelle - derniereDateChangement > delaiMinPression) {
    if (dernierEtatStableBouton == HIGH && etatBouton == LOW) {
      // bouton appuyé
      // Action à réaliser
    } else if (dernierEtatStableBouton == LOW && etatBouton == HIGH) {
      // bouton relaché
      // ... et donc comme click
      // Action à réaliser
      dernierEtatLed = !dernierEtatLed;
      digitalWrite(borneSortie, dernierEtatLed);
    }
    dernierEtatStableBouton = etatBouton;
  }
}

// Version simplifiée : ne fonctionne pas si
// dépassements pour le calcul de fin
void monDelay(unsigned long p_ms) {
  unsigned long fin = micros() + p_ms * 1000;

  while (fin > micros()) {
    yield();
  }
}
