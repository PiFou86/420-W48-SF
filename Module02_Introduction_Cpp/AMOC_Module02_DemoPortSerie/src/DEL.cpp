#include <Arduino.h>

#include "DEL.h"

DEL::DEL(const int &p_pinDEL)
    : m_pinDEL(p_pinDEL)
{
    pinMode(this->m_pinDEL, OUTPUT);
}

// const à la fin de la déclaration de la méthode
// => la méthode ne modifie pas les données membres
void DEL::allumer() const
{
    digitalWrite(this->m_pinDEL, HIGH);
}

void DEL::eteindre() const
{
    digitalWrite(this->m_pinDEL, LOW);
}
