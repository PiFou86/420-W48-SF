#include "Program.h"

#include <Arduino.h>

#include "Actions/ActionAlerte.h"
#include "Actions/ActionAvertissement.h"
#include "Actions/ActionSecuritaire.h"
#include "Detecteurs/DetecteurDistanceHCSR04.h"

// Configuration

//#define DEMO 1
#define DEMO 2

const int pinTrigger = 10;
const int pinEcho = 8;

const int pinDELVerte = 2;
const int pinDELJaune = 3;
const int pinDELRouge = 4;

const double distanceAlerte = .1;
const double distanceAvertissement = .3;

// setup
Program::Program() {
  Serial.begin(9600);

  this->m_detecteurDistance = new DetecteurDistanceHCSR04(pinTrigger, pinEcho);
  this->m_DELVerte = new DEL(pinDELVerte);
  this->m_DELJaune = new DEL(pinDELJaune);
  this->m_DELRouge = new DEL(pinDELRouge);

  this->m_alerteDistance = new AlerteDistance(
      this->m_detecteurDistance, distanceAlerte, distanceAvertissement,
      new ActionAlerte(this->m_DELRouge, this->m_DELJaune, this->m_DELVerte),
      new ActionAvertissement(this->m_DELRouge, this->m_DELJaune,
                              this->m_DELVerte),
      new ActionSecuritaire(this->m_DELRouge, this->m_DELJaune,
                            this->m_DELVerte));
}

void Program::loop() {
#if DEMO == 1
  Serial.println("Distance : " +
                 String(this->m_detecteurDistance->obtenirDistanceMetres()) +
                 " m");
  delay(100);
#elif DEMO == 2
  // Démo 2
  this->m_alerteDistance->tick();
#endif

  // Si vous utilisez le clignotement
  this->m_DELVerte->tick();
  this->m_DELJaune->tick();
  this->m_DELRouge->tick();
}
