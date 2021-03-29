#pragma once

#include <Arduino.h>

class Affichage8DELsGen {

public:
// = 0 => Abstract ; const : la méthode ne modifit pas l'état de l'objet
  virtual void Afficher(byte p_valeur) const = 0;  
};
