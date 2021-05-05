#pragma once
#include "Arduino.h"
#include "Temporisation.h"

class DEL : public Temporisation {
public:
    enum ModeDEL {
        DEL_ETEINTE = 0x0,
        DEL_ALLUMEE = 0x1,

        DEL_CLIGNOTANTE = 0x2,
        DEL_CLIGNOTANTE_ETEINTE = DEL_CLIGNOTANTE | DEL_ETEINTE,
        DEL_CLIGNOTANTE_ALLUMEE = DEL_CLIGNOTANTE | DEL_ALLUMEE
    };
    
private:
    uint16_t m_delaiAllumee;
    uint16_t m_delaiEteinte;
    ModeDEL m_mode;
    uint8_t m_pin;

    unsigned long m_prochainChangementEtat;

    void _allumer(void);
    void _eteindre(void);

public:
    DEL(int p_pin);
    void allumer(void);
    void eteindre(void);
    void clignoter(uint16_t p_delaiAllumee, uint16_t p_delaiEteinte);

    virtual void tick();
};
