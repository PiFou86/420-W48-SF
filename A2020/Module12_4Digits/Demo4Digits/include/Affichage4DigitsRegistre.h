#pragma once

#include <Arduino.h>

#include "Affichage4DigitsBase.h"

class Affichage4DigitsRegistre : public Affichage4DigitsBase
{
private:
    int m_pinDS;
    int m_pinSH;
    int m_pinST;

public:
    Affichage4DigitsRegistre(const int& p_pinDS, const int& p_pinSH, const int& p_pinST, const int& p_pinD1, const int& p_pinD2, const int& p_pinD3, const int& p_pinD4, const bool& p_cathodeCommune = true);

protected:
    virtual void EnvoyerValeur(const byte p_valeur) const;

private:

};
