#pragma once

#include "EvenementHorlorge.h"
#include "Affichage4DigitsAvecEvenement.h"

class Traitement : public EvenementHorloge {

private:
    volatile long m_valeur;
    long m_min;
    long m_max;
    Affichage4DigitsAvecEvenement &m_a4dae;

protected:
    virtual void _executer();


public:
    Traitement(Affichage4DigitsAvecEvenement &p_a4dae, const long& p_min, const long& p_max);
};
