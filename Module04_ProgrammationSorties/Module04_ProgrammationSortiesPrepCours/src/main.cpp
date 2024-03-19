#include <Arduino.h>

#define DEMO 3

#if DEMO == 1
#define DEMO_MESURE_TEMPS
#elif DEMO == 2
#define DEMO_PWM
#elif DEMO == 3
#define DEMO_POTENTIOMETRE
#endif

#ifdef DEMO_MESURE_TEMPS
// Mesure du temps
void MesureDuTempsExecutionSetup(void);
void MesureDuTempsExecution(void);

const int pinMesureDuTemps = 2;
#endif

#ifdef DEMO_PWM
// PWM
void PWMSurLes5SortiesSetup(void);

const int pinPWM1 = 3;
const int pinPWM2 = 5;
const int pinPWM3 = 6;
const int pinPWM4 = 9;
const int pinPWM5 = 10;
const int pinPWM6 = 11;
#endif

#ifdef DEMO_MESURE_TEMPS
const int pinMesureTemps = 2;
#endif

#ifdef DEMO_POTENTIOMETRE
// Démo potentiomètre
void DemoPotentiometrePWMSetup(void);
void DemoPotentiometrePWM(void);

const int pinMesurePotentiometre = A0;
const int pinPWM = 3;
#endif

void setup()
{
#ifdef DEMO_PWM
    PWMSurLes5SortiesSetup();
#endif
#ifdef DEMO_MESURE_TEMPS
    MesureDuTempsExecutionSetup();
#endif
#ifdef DEMO_POTENTIOMETRE
    DemoPotentiometrePWMSetup();
#endif
}

void loop()
{
#ifdef DEMO_MESURE_TEMPS
    MesureDuTempsExecution();
#endif
#ifdef DEMO_POTENTIOMETRE
    DemoPotentiometrePWM();
#endif
}

#ifdef DEMO_PWM
void PWMSurLes5SortiesSetup(void)
{
    pinMode(pinPWM1, OUTPUT);
    pinMode(pinPWM2, OUTPUT);
    pinMode(pinPWM3, OUTPUT);
    pinMode(pinPWM4, OUTPUT);
    pinMode(pinPWM5, OUTPUT);
    pinMode(pinPWM6, OUTPUT);

    analogWrite(pinPWM1, 128);
    analogWrite(pinPWM2, 128);
    analogWrite(pinPWM3, 128);
    analogWrite(pinPWM4, 128);
    analogWrite(pinPWM5, 128);
    analogWrite(pinPWM6, 128);
}
#endif

#ifdef DEMO_MESURE_TEMPS
void MesureDuTempsExecutionSetup(void)
{
    pinMode(pinMesureTemps, OUTPUT);
}
#endif

#ifdef DEMO_MESURE_TEMPS
int valeurIncrement = 0;

#define OPTIMISATION

void MesureDuTempsExecution(void)
{
    digitalWrite(pinMesureTemps, LOW);

    valeurIncrement++;
#ifndef OPTIMISATION
    valeurIncrement = valeurIncrement % 8;
#else
    if (valeurIncrement >= 8)
    {
        valeurIncrement -= 8;
    }
#endif

    digitalWrite(pinMesureTemps, HIGH);
}
#endif

#ifdef DEMO_POTENTIOMETRE

void DemoPotentiometrePWMSetup(void)
{
    pinMode(pinPWM, OUTPUT);
}

void DemoPotentiometrePWM(void)
{
    analogWrite(pinPWM, analogRead(pinMesurePotentiometre) / 4);
}
#endif
