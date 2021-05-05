#include "AlerteDistance.h"

AlerteDistance::AlerteDistance(DetecteurDistance* p_detecteurDistance,
                               double p_distanceAlerte,
                               double p_distanceAvertissement,
                               Action* p_actionAlerte,
                               Action* p_actionAvertissement,
                               Action* p_actionSecuritaire)
    : m_detecteurDistance(p_detecteurDistance),
      m_distanceAlerte(p_distanceAlerte),
      m_distanceAvertissement(p_distanceAvertissement),
      m_actionAlerte(p_actionAlerte),
      m_actionAvertissement(p_actionAvertissement),
      m_actionSecuritaire(p_actionSecuritaire),
      m_etatPrecedent(NONCONNU) {
  ;
}

void AlerteDistance::tick() {
  double distance = this->m_detecteurDistance->obtenirDistanceMetres();
  if (distance <= this->m_distanceAlerte) {
    if (this->m_etatPrecedent != ALERTE) {
      this->m_actionAlerte->executer();
      this->m_etatPrecedent = ALERTE;
    }
  } else if (distance <= this->m_distanceAvertissement) {
    if (this->m_etatPrecedent != AVERTISSEMENT) {
      this->m_actionAvertissement->executer();
      this->m_etatPrecedent = AVERTISSEMENT;
    }
  } else {
    if (this->m_etatPrecedent != SECURITAIRE) {
      this->m_actionSecuritaire->executer();
      this->m_etatPrecedent = SECURITAIRE;
    }
  }
}