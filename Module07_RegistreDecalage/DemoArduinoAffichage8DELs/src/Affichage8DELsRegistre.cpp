#include "Affichage8DELsRegistre.h"

Affichage8DELsRegistre::Affichage8DELsRegistre(int p_pinDS, int p_pinSH, int p_pinST)
  : m_pinDS(p_pinDS), m_pinSH(p_pinSH), m_pinST(p_pinST)
{
  // Si vous utilisez pas l'initialisaton après la parenthèse fermante :
  // this.m_pinDS = p_pinDS;
  // this.m_pinSH = p_pinSH;
  // this.m_pinST = p_pinST;
  
  pinMode(this->m_pinDS, OUTPUT);
  pinMode(this->m_pinSH, OUTPUT);
  pinMode(this->m_pinST, OUTPUT);
}


void Affichage8DELsRegistre::Afficher(byte p_valeur) const {
  digitalWrite(this->m_pinST, LOW);

  for (int i = 7; i >= 0; --i) {
    digitalWrite(this->m_pinSH, LOW);
    digitalWrite(this->m_pinDS, (p_valeur >> i) & 1);
    digitalWrite(this->m_pinSH, HIGH);
  }

  digitalWrite(this->m_pinST, HIGH);
  digitalWrite(this->m_pinST, LOW);
}
