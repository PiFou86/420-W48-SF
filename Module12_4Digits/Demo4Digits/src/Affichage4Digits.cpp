#include "Affichage4Digits.h"

#include "OptimiserEntreesSorties.h"

Affichage4Digits::Affichage4Digits(const int &p_pinSegmentA, const int &p_pinSegmentB, const int &p_pinSegmentC, const int &p_pinSegmentD,
                                   const int &p_pinSegmentE, const int &p_pinSegmentF, const int &p_pinSegmentG, const int &p_pinSegmentDP,
                                   const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4, const bool &p_cathodeCommune)
    : Affichage4DigitsGen(p_pinD1, p_pinD2, p_pinD3, p_pinD4, p_cathodeCommune),
      m_pinSegments{p_pinSegmentA, p_pinSegmentB, p_pinSegmentC, p_pinSegmentD,
                    p_pinSegmentE, p_pinSegmentF, p_pinSegmentG, p_pinSegmentDP}
{
    for (int segmentIndex = 0; segmentIndex < 8; ++segmentIndex)
    {
        pinMode(this->m_pinSegments[segmentIndex], OUTPUT);
    }
}

void Affichage4Digits::EnvoyerValeur(const byte &p_valeur) const
{
   // for (int i = 0; i < 8; ++i)
    //{
    //    monDigitalWrite(this->m_pinSegments[i], ((p_valeur >> (7 - i)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    //}

    monDigitalWrite(this->m_pinSegments[0], ((p_valeur >> (7)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[1], ((p_valeur >> (6)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[2], ((p_valeur >> (5)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[3], ((p_valeur >> (4)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[4], ((p_valeur >> (3)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[5], ((p_valeur >> (2)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[6], ((p_valeur >> (1)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[7], ((p_valeur >> (0)) & 1) ? this->m_segmentOn : this->m_segmentOff);
}