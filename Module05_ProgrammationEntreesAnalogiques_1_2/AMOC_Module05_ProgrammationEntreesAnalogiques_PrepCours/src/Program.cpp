#include <Arduino.h>

#include "Program.h"

#include "DetecteurDistanceHCSR04.h"

// Configuration
const int pinTrigger = 10;
const int pinEcho = 8;

const int pinDELVerte = 2;
const int pinDELJaune = 3;
const int pinDELRouge = 4;

const int clignotementAllumee = 200;
const int clignotementEteinte = 200;

const double distanceAlerte = .1;
const double distanceAvertissement = .3;

class ActionAlerte : public Action {
private:
    DEL* m_rouge;
    DEL* m_jaune;
    DEL* m_verte;
public:
    ActionAlerte(DEL* p_rouge, DEL* p_jaune, DEL* p_verte) : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
      ;
    }

    virtual void executer() {
      this->m_rouge->allumer();
      this->m_jaune->eteindre();
      this->m_verte->eteindre();
    }
};

class ActionAvertissement : public Action {
private:
    DEL* m_rouge;
    DEL* m_jaune;
    DEL* m_verte;
public:
    ActionAvertissement(DEL* p_rouge, DEL* p_jaune, DEL* p_verte) : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
      ;
    }

    virtual void executer() {
      this->m_rouge->eteindre();
      //this->m_jaune->allumer();
      this->m_jaune->clignoter(clignotementAllumee, clignotementEteinte);
      this->m_verte->eteindre();
    }
};

class ActionSecuritaire : public Action {
private:
    DEL* m_rouge;
    DEL* m_jaune;
    DEL* m_verte;
public:
    ActionSecuritaire(DEL* p_rouge, DEL* p_jaune, DEL* p_verte) : m_rouge(p_rouge), m_jaune(p_jaune), m_verte(p_verte) {
      ;
    }

    virtual void executer() {
      this->m_rouge->eteindre();
      this->m_jaune->eteindre();
      this->m_verte->allumer();
    }
};

// setup
Program::Program() {
    Serial.begin(9600);

    this->m_detecteurDistance = new DetecteurDistanceHCSR04(pinTrigger, pinEcho);
    this->m_DELVerte = new DEL(pinDELVerte);
    this->m_DELJaune = new DEL(pinDELJaune);
    this->m_DELRouge = new DEL(pinDELRouge);

    this->m_alerteDistance = new AlerteDistance(this->m_detecteurDistance, 
                                                distanceAlerte, distanceAvertissement, 
                                                new ActionAlerte(this->m_DELRouge, this->m_DELJaune, this->m_DELVerte),
                                                new ActionAvertissement(this->m_DELRouge, this->m_DELJaune, this->m_DELVerte),
                                                new ActionSecuritaire(this->m_DELRouge, this->m_DELJaune, this->m_DELVerte)
                                                );
}

void Program::loop() {
  // Démo 1
  //Serial.println("Distance : " + String(this->m_detecteurDistance->obtenirDistanceMetres()) + " m");
  //delay(100);

  // Démo 2
  this->m_alerteDistance->tick();

  // Si vous utilisez le clignotement
  this->m_DELVerte->tick();
  this->m_DELJaune->tick();
  this->m_DELRouge->tick();
}
