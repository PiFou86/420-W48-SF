#pragma once

#include "EvenementToujours.h"
#include "Affichage4DigitsGen.h"

class Affichage4DigitsAvecEvenement : public EvenementToujours {

private:
    const Affichage4DigitsGen& m_affichage4DigitsGen;
    int m_base;
    int m_valeur;

protected:
    virtual void _executer();

public:
    Affichage4DigitsAvecEvenement(const Affichage4DigitsGen& p_affichage4DigitsGen, const int& p_base = DEC);
    void Valeur(int p_valeur);
    void Base(int p_base);
};
