#pragma once

#include "Action.h"

class DEL;
class ActionAlerte : public Action {
private:
    DEL* m_rouge;
    DEL* m_jaune;
    DEL* m_verte;
public:
    ActionAlerte(DEL* p_rouge, DEL* p_jaune, DEL* p_verte);

    virtual void executer();
};