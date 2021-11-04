#include "Actions/ActionAlerte.h"

#include "DEL.h"

ActionAlerte::ActionAlerte(DEL* p_rouge, DEL* p_jaune, DEL* p_verte)
    : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
  ;
}

void ActionAlerte::executer() {
  this->m_rouge->allumer();
  this->m_jaune->eteindre();
  this->m_verte->eteindre();
}
