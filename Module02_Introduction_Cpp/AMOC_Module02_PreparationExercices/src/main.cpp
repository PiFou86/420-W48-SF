#include <Arduino.h>

#include "GestionDELInterne.h"
#include "Configuration.h"
#include "MesMacros.h"

void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Méthode avec macro
  allumerDELInterne(DUREE_DEL_ALLUMEE);
  eteindreDELInterne(DUREE_DEL_ETEINTE);

  // Méthode avec variables constantes version 1
  allumerDELInterne(dureeDELAllumee);
  eteindreDELInterne(dureeDELEteinte);

  Serial.println(calculerMinimum(2 + 3, 4 + 7));
  Serial.println(calculerMaximum(2.0 + 3, 4.0 + 7));
}


