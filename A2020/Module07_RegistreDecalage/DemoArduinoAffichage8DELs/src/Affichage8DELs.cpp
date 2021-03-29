#include "Affichage8DELs.h"

Affichage8DELs::Affichage8DELs() 
  : Affichage8DELs::Affichage8DELs(-1, -1, -1, -1, -1, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, -1, -1, -1, -1, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, -1, -1, -1, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, p_pinDel2, -1, -1, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, p_pinDel2, p_pinDel3, -1, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                               int p_pinDel4) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, p_pinDel2, p_pinDel3, p_pinDel4, -1, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                               int p_pinDel4, int p_pinDel5) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, p_pinDel2, p_pinDel3, p_pinDel4, p_pinDel5, -1, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                               int p_pinDel4, int p_pinDel5, int p_pinDel6) 
  : Affichage8DELs::Affichage8DELs(p_pinDel0, p_pinDel1, p_pinDel2, p_pinDel3, p_pinDel4, p_pinDel5, p_pinDel6, -1) 
{
  ;
}

Affichage8DELs::Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                               int p_pinDel4, int p_pinDel5, int p_pinDel6, int p_pinDel7)
  : m_pinDELs{
    p_pinDel0, p_pinDel1, p_pinDel2, p_pinDel3,
    p_pinDel4, p_pinDel5, p_pinDel6, p_pinDel7
  }
{
    for (int delIndex = 0; delIndex < 8; ++delIndex) {
      if (this->m_pinDELs[delIndex] != Affichage8DELs::NONDEFINIES) {
        pinMode(this->m_pinDELs[delIndex], OUTPUT);
      }
    }
}

void Affichage8DELs::Afficher(byte p_valeur) const {
  byte valeurLed = 0;
  for (int delIndex = 0; delIndex < 8; ++delIndex) {
    if (this->m_pinDELs[delIndex] != Affichage8DELs::NONDEFINIES) {
      valeurLed = (p_valeur >> delIndex) & 1;
      digitalWrite(this->m_pinDELs[delIndex], valeurLed?HIGH:LOW);
    }
  }  
}
