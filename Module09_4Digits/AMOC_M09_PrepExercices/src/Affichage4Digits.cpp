#include "Affichage4Digits.h"

#include "Affichage4DigitsProxy.h"

const int8_t segments[] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111   // 9
};

Affichage4Digits::Affichage4Digits(Affichage4DigitsProxy* p_proxy)
    : m_proxy(p_proxy) {
  ;
}

void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3,
                                uint8_t p_d4) const {
  this->m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}

void Affichage4Digits::afficherBinaire(uint8_t p_valeur) const {
  this->m_proxy->afficher(segments[p_valeur >> 3 & 1],
                          segments[p_valeur >> 2 & 1],
                          segments[p_valeur >> 1 & 1], segments[p_valeur & 1]);
}

void Affichage4Digits::afficherDecimal(uint16_t p_valeur) const {
  uint16_t valeur = p_valeur;
  uint8_t d4 = valeur % 10;
  valeur /= 10;
  uint8_t d3 = valeur % 10;
  valeur /= 10;
  uint8_t d2 = valeur % 10;
  valeur /= 10;
  uint8_t d1 = valeur % 10;

  this->m_proxy->afficher(segments[d1], segments[d2], segments[d3],
                          segments[d4]);
}
