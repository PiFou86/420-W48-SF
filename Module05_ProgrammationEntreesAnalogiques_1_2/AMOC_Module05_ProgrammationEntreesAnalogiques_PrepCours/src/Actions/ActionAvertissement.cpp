#include "Actions/ActionAvertissement.h"

#include "DEL.h"

const int clignotementAllumee = 200;
const int clignotementEteinte = 200;

ActionAvertissement::ActionAvertissement(DEL* p_rouge, DEL* p_jaune,
                                         DEL* p_verte)
    : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
  ;
}

void ActionAvertissement::executer() {
  this->m_rouge->eteindre();
  // this->m_jaune->allumer();
  this->m_jaune->clignoter(clignotementAllumee, clignotementEteinte);
  this->m_verte->eteindre();
}
