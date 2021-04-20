#pragma once

#include "DetecteurDistanceUltrason.h"

class DetecteurDistanceHCSR04 : public DetecteurDistanceUltrason
{
private:
    uint8_t m_pinTrigger;
    uint8_t m_pinEcho;
public:
    DetecteurDistanceHCSR04(uint8_t p_pinTrigger, uint8_t p_pinEcho);
    virtual double obtenirDistanceMetres();
};
