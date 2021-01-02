#include <Arduino.h>

// Commenter si vous n'utilisez pas le registre à décalage
#define UTILISER_REGISTRE

// Démos :
// 1. Affichage décimale de -11000 à 11000
// 2. Affichage hexadécimale de 0x0 à 0xFFFF
#define DEMO 1


#include "Affichage4DigitsRegistre.h"
#include "Affichage4Digits.h"
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

#ifdef UTILISER_REGISTRE
Affichage4DigitsRegistre adr(pinDS, pinSH, pinST, pinD1, pinD2, pinD3, pinD4);
#else
Affichage4Digits adr(6, 7, 8, 9,
                     10, 11, 12, 13,
                     pinD1, pinD2, pinD3, pinD4);
#endif

GestionEvenements ge;

#if DEMO == 1
// Demo dec
Affichage4DigitsAvecEvenement a4dae(adr);
Traitement t(a4dae, -1020, 11000);
#elif DEMO == 2
// Demo hexa
Affichage4DigitsAvecEvenement a4dae(adr, HEX);
Traitement t(a4dae, 0x00, 0xFFFF);
#endif

void setup()
{
  Serial.begin(9600);
  ge.Ajouter(&a4dae);
  ge.Ajouter(&t);
}

void loop()
{
  ge.Executer();
}
