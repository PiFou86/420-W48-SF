#pragma once

#include "Evenement.h"

#define UTILISER_TIMER1
#define MAXIMUM_EVENEMENTS 32

class GestionEvenementsClass {

private:
    Evenement *m_evenements[MAXIMUM_EVENEMENTS];

public:
    volatile int m_nombreEvenement;

public:
    GestionEvenementsClass();
    void Ajouter(Evenement *p_event);
    void Executer();
    void Start();
};

// __attribute__ ((unused)) : éviter les avertissements si GestionEvenements non utilisé
extern GestionEvenementsClass GestionEvenements __attribute__ ((unused));
