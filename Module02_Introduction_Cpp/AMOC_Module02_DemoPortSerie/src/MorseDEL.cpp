#include <Arduino.h>

#include "MorseDEL.h"

MorseDEL::MorseDEL(const int& p_dureePoint, const int& p_pinDEL) 
    : Morse(p_dureePoint), m_DEL(p_pinDEL)
{
    pinMode(p_pinDEL, OUTPUT);
}

void MorseDEL::afficherPoint() const {
    this->m_DEL.allumer();
    delay(this->getDureePoint());
    this->m_DEL.eteindre();
    delay(this->getDureePoint());
}

void MorseDEL::afficherTrait() const {
    this->m_DEL.allumer();
    delay(3 * this->getDureePoint());
    this->m_DEL.eteindre();
    delay(this->getDureePoint());
}
