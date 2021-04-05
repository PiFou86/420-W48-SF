#pragma once

class DEL {
private:
    int m_pinDEL;

public:
    DEL(const int& p_pinDEL);
    // const à la fin de la déclaration de la méthode 
    // => la méthode ne modifie pas les données membres
    void allumer() const; 
    void eteindre() const;
};
