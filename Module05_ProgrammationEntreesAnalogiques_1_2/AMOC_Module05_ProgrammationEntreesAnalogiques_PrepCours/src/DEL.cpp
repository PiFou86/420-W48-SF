#include "DEL.h"

DEL::DEL(int p_pin)
    : m_delaiAllumee(0),
      m_delaiEteinte(0),
      m_mode(DEL_ETEINTE),
      m_pin(p_pin),
      m_prochainChangementEtat(0) {
  pinMode(this->m_pin, INPUT);
}

void DEL::allumer(void) {
  this->m_mode = DEL_ALLUMEE;
  this->_allumer();
}

void DEL::_allumer(void) {
  digitalWrite(this->m_pin, HIGH);
}

void DEL::eteindre(void) {
  this->m_mode = DEL_ETEINTE;
  this->_eteindre();
}

void DEL::_eteindre(void) {
  digitalWrite(this->m_pin, LOW);
}

void DEL::clignoter(uint16_t p_delaiAllumee, uint16_t p_delaiEteinte) {
  this->m_delaiAllumee = p_delaiAllumee;
  this->m_delaiEteinte = p_delaiEteinte;
  this->m_mode = DEL_CLIGNOTANTE_ALLUMEE;

  this->m_prochainChangementEtat = millis() + this->m_delaiAllumee;
  this->_allumer();
}

void DEL::tick() {
    unsigned long date = millis();
    if (this->m_mode & DEL_CLIGNOTANTE && date >= this->m_prochainChangementEtat) {
        int etatCourant = this->m_mode & DEL_ALLUMEE;
        if (etatCourant == DEL_ALLUMEE) {
            while (date >= this->m_prochainChangementEtat)
            {
                this->m_prochainChangementEtat += this->m_delaiEteinte;
            }     
            this->m_mode = DEL_CLIGNOTANTE_ETEINTE;
            this->_eteindre();
        } else {
            while (date >= this->m_prochainChangementEtat)
            {
                this->m_prochainChangementEtat += this->m_delaiAllumee;
            }
            this->m_mode = DEL_CLIGNOTANTE_ALLUMEE;
            this->_allumer();
        }
    }
}
