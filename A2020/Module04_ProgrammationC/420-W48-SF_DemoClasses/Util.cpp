#include "Util.h"

int contraintValeur(int p_valeur, int p_min, int p_max) {
  int resultat = p_valeur;
  
  if (p_valeur < p_min)
  {
    p_valeur = p_min;
  }
  
  if (p_valeur > p_max)
  {
    p_valeur = p_max;
  }

  return p_valeur;
}
