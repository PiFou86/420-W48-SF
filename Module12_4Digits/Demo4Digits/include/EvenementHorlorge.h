#pragma once

#include "Evenement.h"

class EvenementHorloge : public Evenement {
    
private:
    unsigned long m_pasMillis;
    unsigned long m_dernierMillis;

public:
    EvenementHorloge(unsigned long p_pasMillis);

    virtual void Executer();
};
