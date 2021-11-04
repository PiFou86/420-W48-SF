#pragma once
#include <Arduino.h>
#include "Temporisation.h"
#include "Detecteurs/DetecteurDistance.h"
#include "Actions/Action.h"

class AlerteDistance : public Temporisation {
private:
    DetecteurDistance* m_detecteurDistance;
    double m_distanceAlerte;
    double m_distanceAvertissement;
    Action* m_actionAlerte;
    Action* m_actionAvertissement;
    Action* m_actionSecuritaire;

    enum EtatAlerteDistance : uint8_t {
        NONCONNU = 4,
        ALERTE = 2,
        AVERTISSEMENT = 1,
        SECURITAIRE = 0
    };

    EtatAlerteDistance m_etatPrecedent;

public:
    AlerteDistance(DetecteurDistance* p_detecteurDistance,
                   double p_distanceAlerte,
                   double p_distanceAvertissement,
                   Action* p_actionAlerte,
                   Action* p_actionAvertissement,
                   Action* p_actionSecuritaire);

    virtual void tick();
};
