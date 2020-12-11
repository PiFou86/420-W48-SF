#include <Arduino.h>

#include "Affichage8DELsRegistre.h"
#include "Affichage8DELs.h"
#include "Animations.h"

const int pinST = 11;
const int pinSH = 8;
const int pinDS = 12;

Affichage8DELsRegistre a8DELs(pinDS, pinSH, pinST);
//Affichage8DELs a8DELs(2, 3, 4, 5, 6, 7, 8, 9);
void setup()
{
  ;
}

void loop()
{
  Compter(a8DELs);
  
  GaucheDroite(a8DELs, 10);
  
  K2000(a8DELs, 10);
}
