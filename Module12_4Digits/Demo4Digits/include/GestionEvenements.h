#pragma once

#include "Evenement.h"

#define MAXIMUM_EVENEMENTS 32

class GestionEvenements {

private:
    Evenement *m_evenements[MAXIMUM_EVENEMENTS];
    int m_nombreEvenement;

public:
    GestionEvenements();
    void Ajouter(Evenement *p_event);
    void Executer();
};
