#include "Affichage4DigitsAvecEvenement.h"

Affichage4DigitsAvecEvenement::Affichage4DigitsAvecEvenement(const Affichage4DigitsBase& p_affichage4Digits, const int& p_base)
: m_affichage4Digits(p_affichage4Digits), m_base(p_base), m_valeur(0)
{
    ;
}

void Affichage4DigitsAvecEvenement::_executer() {
    this->m_affichage4Digits.Executer();
}

void Affichage4DigitsAvecEvenement::Valeur(int p_valeur) {
    this->m_valeur = p_valeur;
    this->m_affichage4Digits.Afficher(this->m_valeur, this->m_base);
}

void Affichage4DigitsAvecEvenement::Base(int p_base) {
    this->m_base = p_base;
    this->m_affichage4Digits.Afficher(this->m_valeur, this->m_base);
}
