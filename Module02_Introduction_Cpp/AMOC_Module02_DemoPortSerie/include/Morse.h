#pragma once

class Morse {
private:
    int m_dureePoint;

public:
    Morse(const int& p_dureePoint);
    virtual void afficherPoint() const = 0;
    virtual void afficherTrait() const = 0;

    int getDureePoint() const;
    
    void afficherSOS();
};