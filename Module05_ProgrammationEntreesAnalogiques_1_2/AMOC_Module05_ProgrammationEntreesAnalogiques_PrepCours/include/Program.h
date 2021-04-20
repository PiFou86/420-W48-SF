#pragma once

#include "DetecteurDistance.h"
#include "DEL.h"
#include "AlerteDistance.h"

class Program {
private:
    DetecteurDistance *m_detecteurDistance;
    DEL *m_DELVerte;
    DEL *m_DELJaune;
    DEL *m_DELRouge;
    AlerteDistance* m_alerteDistance;
public:
    Program();
    void loop();
};
