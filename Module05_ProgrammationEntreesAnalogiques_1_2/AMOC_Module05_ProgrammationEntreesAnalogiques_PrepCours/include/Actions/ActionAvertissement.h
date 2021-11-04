#pragma once

#include "Action.h"

class DEL;
class ActionAvertissement : public Action {
private:
    DEL* m_rouge;
    DEL* m_jaune;
    DEL* m_verte;
public:
    ActionAvertissement(DEL* p_rouge, DEL* p_jaune, DEL* p_verte);

    virtual void executer();
};