#include "Actions/ActionSecuritaire.h"

#include "DEL.h"

ActionSecuritaire::ActionSecuritaire(DEL* p_rouge, DEL* p_jaune, DEL* p_verte)
    : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
  ;
}

void ActionSecuritaire::executer() {
  this->m_rouge->eteindre();
  this->m_jaune->eteindre();
  this->m_verte->allumer();
}
