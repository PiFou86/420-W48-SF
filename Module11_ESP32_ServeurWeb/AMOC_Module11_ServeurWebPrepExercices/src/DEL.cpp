#include "DEL.h"

DEL::DEL(int const& p_id, String const& p_description, int p_pin, bool p_estAllumee)
    : Actionneur(p_id, p_description), m_pin(p_pin), m_estAllumee(p_estAllumee) {
  pinMode(this->m_pin, OUTPUT);
  if (this->m_estAllumee) {
    this->allumer();
  } else {
    this->eteindre();
  }
}

void DEL::allumer() {
  digitalWrite(this->m_pin, HIGH);
  this->m_estAllumee = true;
}

void DEL::eteindre() {
  digitalWrite(this->m_pin, LOW);
  this->m_estAllumee = false;
}

bool DEL::estAllume() const { return this->m_estAllumee; }
