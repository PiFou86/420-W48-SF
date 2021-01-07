#include "Affichage4DigitsAvecEvenement.h"

Affichage4DigitsAvecEvenement::Affichage4DigitsAvecEvenement(const Affichage4DigitsGen& p_affichage4DigitsGen, const int& p_base)
: m_affichage4DigitsGen(p_affichage4DigitsGen), m_base(p_base), m_valeur(0)
{
    ;
}

void Affichage4DigitsAvecEvenement::_executer() {
    this->m_affichage4DigitsGen.AfficherV2(this->m_valeur, this->m_base);
}

void Affichage4DigitsAvecEvenement::Valeur(int p_valeur) {
    this->m_valeur = p_valeur;
}

void Affichage4DigitsAvecEvenement::Base(int p_base) {
    this->m_base = p_base;
}
