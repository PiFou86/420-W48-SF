#pragma once

#include <Arduino.h>

#include "Affichage8DELsGen.h"

class Affichage8DELsRegistre : public Affichage8DELsGen {
private:
  int m_pinDS;
  int m_pinSH;
  int m_pinST;
  
public:  
  Affichage8DELsRegistre(int p_pinDS, int p_pinSH, int p_pinST);
  void Afficher(byte p_valeur) const;
};
