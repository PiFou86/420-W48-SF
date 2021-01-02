#pragma once

#include <Arduino.h>

class Affichage4DigitsGen
{

private:
    int m_pinD[4];

    int m_digitOff;
    int m_digitOn;

protected:
    int m_segmentOff;
    int m_segmentOn;

    static int TROP_PETIT;
    static int TROP_GRAND;

public:
    void Afficher(const int& p_valeur, const int& p_base = DEC) const;


protected:
    Affichage4DigitsGen(const int& p_pinD1, const int& p_pinD2, const int& p_pinD3, const int& p_pinD4, const bool& p_cathodeCommune = true);
    // = 0 => Abstract ; const : la méthode ne modifit pas l'état de l'objet
    virtual void EnvoyerValeur(const byte& p_valeur) const = 0;

private:
    void AfficherDigits(const byte p_digits[4]) const;
    void AfficherDigit(const byte &p_segments, const int &p_position) const;

    void AfficherHex(const int& p_valeur) const;
    void AfficherDec(const int& p_valeur) const;

    void AfficherTropGrand() const;
    void AfficherTropPetit() const;

    void Reset() const;
};
