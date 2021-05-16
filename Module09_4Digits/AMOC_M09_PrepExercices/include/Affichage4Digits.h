#pragma once
#include <Arduino.h>

class Affichage4DigitsProxy;

class Affichage4Digits {
public:
    Affichage4Digits(Affichage4DigitsProxy* p_proxy);
    void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4) const;
    void afficherBinaire(uint8_t p_valeur) const;
    void afficherDecimal(uint16_t p_valeur) const;
private:
    Affichage4DigitsProxy *m_proxy;
};
