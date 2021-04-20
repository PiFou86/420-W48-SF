#include <Arduino.h>

#include "DetecteurDistanceHCSR04.h"

DetecteurDistanceHCSR04::DetecteurDistanceHCSR04(uint8_t p_pinTrigger, uint8_t p_pinEcho)
    : m_pinTrigger(p_pinTrigger), m_pinEcho(p_pinEcho)
{
    pinMode(this->m_pinTrigger, OUTPUT);
    digitalWrite(this->m_pinTrigger, LOW);

    pinMode(this->m_pinEcho, INPUT);
}

double DetecteurDistanceHCSR04::obtenirDistanceMetres()
{
    digitalWrite(this->m_pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->m_pinTrigger, LOW);

    unsigned long duree = pulseIn(this->m_pinEcho, HIGH, ULTRASOUND_MEASURE_TIMEOUT);

    return (duree / 2.0) * SOUND_SPEED_US;
}
