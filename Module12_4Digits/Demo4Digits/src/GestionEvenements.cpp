#include "GestionEvenements.h"

GestionEvenements::GestionEvenements()
: m_nombreEvenement(0)
{
    ;
}

void GestionEvenements::Ajouter(Evenement *p_event) {
    this->m_evenements[this->m_nombreEvenement++] = p_event;
}

void GestionEvenements::Executer() {
    for (int i = 0; i < this->m_nombreEvenement; i++)
    {
       this->m_evenements[i]->Executer(); 
    }
    
}
