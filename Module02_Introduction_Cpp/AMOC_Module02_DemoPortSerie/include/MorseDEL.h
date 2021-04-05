#pragma once

#include "Morse.h"
#include "DEL.h"

class MorseDEL : public Morse {
private:
    DEL m_DEL;

public:
    MorseDEL(const int& p_dureePoint, const int& p_pinDEL);

    virtual void afficherPoint() const;
    virtual void afficherTrait() const;
};
