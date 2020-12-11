#include "Animations.h"

void GaucheDroite(const Affichage8DELsGen &p_afficheur, const int &p_nombreIterations, const int &p_delai) {
  for (int iterationCourante = 0; iterationCourante < p_nombreIterations; ++iterationCourante) {
    for (int indiceLed = 0; indiceLed < 8; ++indiceLed) {
      p_afficheur.Afficher(1 << indiceLed);
      delay(p_delai);
    }
  
    for (int indiceLed = 0; indiceLed < 8; ++indiceLed) {
      p_afficheur.Afficher(0x80 >> indiceLed);
      delay(p_delai);
    }
  }
}

void Compter(const Affichage8DELsGen &p_afficheur, const int &p_nombreIterations, const int &p_delai) {
  for (int iterationCourante = 0; iterationCourante < p_nombreIterations; ++iterationCourante) {
    for (int valeur = 0; valeur < 256; ++valeur) {
      p_afficheur.Afficher(valeur);
      delay(p_delai);
    }
  }
}

void K2000(const Affichage8DELsGen &p_afficheur, const int &p_nombreIterations, const int &p_delai) {
  for (int iterationCourante = 0; iterationCourante < p_nombreIterations; ++iterationCourante) {
    for (int indiceLed = 0; indiceLed < 8; ++indiceLed) {
      p_afficheur.Afficher(0xE0 >> indiceLed);
      delay(p_delai);
    }
    
    for (int indiceLed = 0; indiceLed < 8; ++indiceLed) {
      p_afficheur.Afficher(7 << indiceLed);
      delay(p_delai);
    }
    delay(p_delai * 6);
  }
}
