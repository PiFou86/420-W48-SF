#include <Arduino.h>

#include "passageParametres.h"
#include "Flasher.h"

#include "Morse.h"
#include "MorseSerie.h"
#include "MorseDEL.h"

Flasher flasher(LED_BUILTIN, 500);
void setup()
{
    Serial.end();
    Serial.begin(9600);

    int valeur1 = 42;
    int valeur2 = 13;

    Serial.println();
    Serial.println("Tests de l'affichage sur la console");
    Serial.println(42);
    Serial.println("Bonjour à tous !");
    Serial.println(String(42, HEX));
    Serial.println("0x" + String(42, HEX));
    Serial.println("int valeur1 (int * : 0x" + String((uint16_t)(&valeur1), HEX) + ") = " + String(valeur1));
    Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur2), HEX) + ") = " + String(valeur2));
    Serial.println();

    Serial.println("Appel de passageDeParametres1(valeur1, valeur1, &valeur2);");
    passageDeParametres1(valeur1, valeur1, &valeur2);
    Serial.println();

    Serial.println("Déclaration d'un objet local et affectation à l'objet global");
    Flasher flasherDuSetup(LED_BUILTIN, 200);
    flasher = flasherDuSetup;
    Serial.println();

    Serial.println("Appel des fonctions avec différents mode de passage avec flasher");
    Serial.println("flasher (flasher * : 0x" + String((uint16_t)(&flasher), HEX) + ")");
    passageDeParametresCopie(flasher);
    passageDeParametresReference(flasher);
    passageDeParametresPointeur(&flasher);
    Serial.println();

    Morse* morse;
    Serial.println("Test du MorseSerie");
    morse = new MorseSerie(500);
    morse->afficherSOS();
    delete morse;
    morse = NULL;
    Serial.println();

    Serial.println("Test du MorseDEL");
    morse = new MorseDEL(500, LED_BUILTIN);
    morse->afficherSOS();
    delete morse;
    morse = NULL;
    Serial.println();
}

void loop()
{
    flasher.FaireClignoter(1);
}
