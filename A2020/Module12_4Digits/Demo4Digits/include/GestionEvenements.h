#pragma once

#include "Evenement.h"

#include "Config.h"

class GestionEvenementsClass {

private:
    Evenement *m_evenements[MAXIMUM_EVENEMENTS];
    volatile int m_nombreEvenement;

public:
    GestionEvenementsClass();
    void Ajouter(Evenement *p_event);
    void Executer();
    void Start();
};

// __attribute__ ((unused)) : éviter les avertissements si GestionEvenements non utilisé
extern GestionEvenementsClass GestionEvenements __attribute__ ((unused));
