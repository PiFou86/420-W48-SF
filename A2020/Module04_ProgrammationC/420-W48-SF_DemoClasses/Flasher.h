#pragma once

class Flasher {
private:
    int m_pinDel;
    int m_dureeAllumeeEteinte;
public:
    Flasher(int p_pinDel, int p_dureeAllumeeEteinte);
    void FaireClignoter(int p_nombreCycles);
};
