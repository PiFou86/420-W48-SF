#include <Arduino.h>
#include "MorseSerie.h"

MorseSerie::MorseSerie(const int &p_dureePoint)
    : Morse(p_dureePoint)
{
    ;
}

void MorseSerie::afficherPoint() const
{
    Serial.print(".");
}

void MorseSerie::afficherTrait() const
{
    Serial.print("-");
}
