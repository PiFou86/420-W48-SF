#include "EvenementHorlorge.h"

#include <Arduino.h>

EvenementHorloge::EvenementHorloge(unsigned long p_pasMillis)
    : m_pasMillis(p_pasMillis), m_dernierMillis(0)
{
    ;
}

void EvenementHorloge::Executer()
{
    if (this->m_dernierMillis + this->m_pasMillis < millis())
    {
        this->m_dernierMillis += this->m_pasMillis;
        this->_executer();
    }
}
