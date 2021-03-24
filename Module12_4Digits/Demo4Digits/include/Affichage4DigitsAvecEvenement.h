#pragma once

#include "EvenementToujours.h"
#include "Affichage4DigitsBase.h"

class Affichage4DigitsAvecEvenement : public EvenementToujours {

private:
    const Affichage4DigitsBase& m_affichage4Digits;
    int m_base;
    int m_valeur;

protected:
    virtual void _executer();

public:
    Affichage4DigitsAvecEvenement(const Affichage4DigitsBase& p_affichage4Digits, const int& p_base = DEC);
    void Valeur(int p_valeur);
    void Base(int p_base);
};
