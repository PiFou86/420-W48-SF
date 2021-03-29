#pragma once

#include <Arduino.h>

class Affichage4DigitsBase
{

public:
    void Afficher(const int &p_valeur, const int &p_base = DEC) const;
    void Executer() const;

protected:
    Affichage4DigitsBase(const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4, const bool &p_cathodeCommune = true);
    // = 0 => Abstract ; const : la méthode ne modifit pas l'état de l'objet
    virtual void EnvoyerValeur(const byte p_valeur) const = 0;

protected:
    int m_segmentOff;
    int m_segmentOn;

private:
    int m_pinD[4];

    int m_digitOff;
    int m_digitOn;

    volatile mutable byte m_cache[4];
    volatile mutable int m_valeurCache;
    volatile mutable int m_baseCache;
    volatile mutable int m_digitCourant;
};
