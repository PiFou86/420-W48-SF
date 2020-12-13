#include <Arduino.h>

#include "Flasher.h"

Flasher::Flasher(int p_pinDel, int p_dureeAllumeeEteinte)
  : m_pinDel(p_pinDel), m_dureeAllumeeEteinte(p_dureeAllumeeEteinte)
{
  pinMode(this->m_pinDel, OUTPUT);
  digitalWrite(this->m_pinDel, LOW);
}

void Flasher::FaireClignoter(int p_nombreCycles) {
  for (int numCycle = 0; numCycle < p_nombreCycles; ++numCycle)
  {
    digitalWrite(this->m_pinDel, HIGH);
    delay(this->m_dureeAllumeeEteinte);
    digitalWrite(this->m_pinDel, LOW);
    delay(this->m_dureeAllumeeEteinte);
  }
}
