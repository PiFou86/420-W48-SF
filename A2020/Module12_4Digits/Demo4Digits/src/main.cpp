#include <Arduino.h>

#include "Config.h"

#include "Affichage4DigitsRegistre.h"
#include "Affichage4DigitsDirect.h"
#include "GestionEvenements.h"
#include "Affichage4DigitsAvecEvenement.h"
#include "Traitement.h"

const int pinST = 11;
const int pinSH = 8;
const int pinDS = 12;

const int pinD1 = 2;
const int pinD2 = 3;
const int pinD3 = 4;
const int pinD4 = 5;

#if UTILISER_REGISTRE_DECALAGE
Affichage4DigitsRegistre adr(pinDS, pinSH, pinST, 
                             pinD1, pinD2, pinD3, pinD4);
#else
Affichage4DigitsDirect adr(6, 7, 8, 9,
                           10, 11, 12, 13,
                           pinD1, pinD2, pinD3, pinD4);
#endif

Affichage4DigitsAvecEvenement a4dae(adr, BASE);
Traitement t(a4dae, VALEURDEBUT, VALEURFIN);

void setup()
{
  Serial.begin(9600);

  DEBUG_A0_CONFIG;
  DEBUG_A1_CONFIG;

  GestionEvenements.Ajouter(&a4dae);
  GestionEvenements.Ajouter(&t);
  GestionEvenements.Start();
}

void loop()
{
#if !UTILISER_TIMER1
  GestionEvenements.Executer();
#endif
}
