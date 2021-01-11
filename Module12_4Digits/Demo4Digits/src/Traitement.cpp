#include "Traitement.h"

Traitement::Traitement(Affichage4DigitsAvecEvenement &p_a4dae, const long& p_min, const long& p_max)
    : EvenementHorloge(100), m_valeur(p_min), m_min(p_min), m_max(p_max), m_a4dae(p_a4dae)
{
    ;
}

void Traitement::_executer()
{
    this->m_a4dae.Valeur(this->m_valeur);

    //++this->m_valeur;
    this->m_valeur = constrain(this->m_valeur, this->m_min, this->m_max);
    if (this->m_valeur >= this->m_max)
    {
        this->m_valeur = this->m_min;
    }
}
