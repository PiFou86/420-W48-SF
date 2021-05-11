#include "Program.h"

#include "Affichage4Digits.h"
#include "Affichage4DigitsProxyTM1637.h"

byte segments[] = {0b00111111, 0b00000110};

Program::Program() : m_compteur(0) {
  this->m_affichage4Digits =
      new Affichage4Digits(new Affichage4DigitsProxyTM1637(2, 3));
}

void Program::loop() {
  this->m_affichage4Digits->afficher(
      segments[this->m_compteur >> 3 & 1], segments[this->m_compteur >> 2 & 1],
      segments[this->m_compteur >> 1 & 1], segments[this->m_compteur & 1]);

  this->m_compteur = (this->m_compteur + 1) % 16;
  delay(500);
}
