#pragma once

template <typename TypeDonneesASauvegarder>
class SauvegardeDonnees {
public:
    virtual bool sauvegarder() = 0;
    virtual bool charger() = 0;

    inline void donnees(const TypeDonneesASauvegarder& donnees) {
        this->m_donnees = donnees;
    }

    inline const TypeDonneesASauvegarder& donnees() const {
        return this->m_donnees;
    }
private:
    TypeDonneesASauvegarder m_donnees;
};
