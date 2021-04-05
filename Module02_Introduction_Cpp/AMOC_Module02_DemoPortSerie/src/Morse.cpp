#include "Morse.h"

Morse::Morse(const int& p_dureePoint) 
: m_dureePoint(p_dureePoint)
{
    ;
}

int Morse::getDureePoint() const {
    return this->m_dureePoint;
}

void Morse::afficherSOS() {
    this->afficherPoint();
    this->afficherPoint();
    this->afficherPoint();

    this->afficherTrait();
    this->afficherTrait();
    this->afficherTrait();

    this->afficherPoint();
    this->afficherPoint();
    this->afficherPoint();
}
