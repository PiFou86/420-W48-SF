#pragma once

#include "Morse.h"

class MorseSerie : public Morse {

public:
    MorseSerie(const int& p_dureePoint);

    virtual void afficherPoint() const;
    virtual void afficherTrait() const;
};
