#include "Affichage4DigitsProxyTM1637.h"

#include <TM1637Display.h>

Affichage4DigitsProxyTM1637::Affichage4DigitsProxyTM1637(int p_pinHorloge,
                                                         int p_pinDonnees) {
  this->m_tm1637 = new TM1637Display(p_pinHorloge, p_pinDonnees);
}

void Affichage4DigitsProxyTM1637::afficher(uint8_t p_d1, uint8_t p_d2,
                                           uint8_t p_d3, uint8_t p_d4) {
  uint8_t segments[] = {p_d1, p_d2, p_d3, p_d4};
  this->m_tm1637->setSegments(segments);
}