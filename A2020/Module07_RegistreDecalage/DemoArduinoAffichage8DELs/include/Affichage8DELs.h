#pragma once

#include "Affichage8DELsGen.h"

class Affichage8DELs : public Affichage8DELsGen {
private:
  int m_pinDELs[8];
  
public:  
  Affichage8DELs();
  Affichage8DELs(int p_pinDel0);
  Affichage8DELs(int p_pinDel0, int p_pinDel1);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                 int p_pinDel4);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                 int p_pinDel4, int p_pinDel5);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                 int p_pinDel4, int p_pinDel5, int p_pinDel6);
  Affichage8DELs(int p_pinDel0, int p_pinDel1, int p_pinDel2, int p_pinDel3,
                 int p_pinDel4, int p_pinDel5, int p_pinDel6, int p_pinDel7);
  
  void Afficher(byte p_valeur) const;
  
  static const int NONDEFINIES = -1;
};
