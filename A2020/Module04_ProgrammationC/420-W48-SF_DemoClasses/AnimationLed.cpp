#include <Arduino.h>

#include "AnimationLed.h"
#include "Util.h"

void animerLed(int p_pinDel, int p_increment, int p_nombreCycles, int p_delaiEteinte) {  
  int delai = 0;
  for (int numeroCycle = 0; numeroCycle < p_nombreCycles; ++numeroCycle) {
    digitalWrite(p_pinDel, HIGH);
    delay(delai);
    
    digitalWrite(p_pinDel, LOW);
    delay(p_delaiEteinte);
    
    delai = contraintValeur(delai + p_increment, 0, 32767);
  }
}
