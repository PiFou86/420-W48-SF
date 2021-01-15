#pragma once

#include <Arduino.h>


#define UTILISER_INTERRUPTION   1


class Affichage4DigitsDirect
{
public:
    Affichage4DigitsDirect(const int& p_pinSegmentA, const int& p_pinSegmentB, const int& p_pinSegmentC, const int& p_pinSegmentD,
                           const int& p_pinSegmentE, const int& p_pinSegmentF, const int& p_pinSegmentG, const int& p_pinSegmentDP,
                           const int& p_pinD1, const int& p_pinD2, const int& p_pinD3, const int& p_pinD4, const unsigned long &p_dureeAffichageDigit = 1000);
    void Afficher(const int &p_valeurDigit1, const int &p_valeurDigit2, const int &p_valeurDigit3, const int &p_valeurDigit4) const;

    void Executer() const; 

private:
    void EnvoyerValeur(const byte p_valeur) const;

private:
    int m_segmentOff;
    int m_segmentOn;
    int m_digitOff;
    int m_digitOn;

    int m_pinD[4];
    int m_pinSegments[8];

    volatile mutable byte m_cache[4];
    volatile mutable int m_digitCourant;
    volatile mutable unsigned long m_microsDernierChangement;

    const int m_dureeAffichageDigit;
};