#include "Affichage4DigitsDirect.h"

#include "OptimiserEntreesSorties.h"

Affichage4DigitsDirect::Affichage4DigitsDirect(const int &p_pinSegmentA, const int &p_pinSegmentB, const int &p_pinSegmentC, const int &p_pinSegmentD,
                                               const int &p_pinSegmentE, const int &p_pinSegmentF, const int &p_pinSegmentG, const int &p_pinSegmentDP,
                                               const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4, const bool &p_cathodeCommune)
    : Affichage4DigitsBase(p_pinD1, p_pinD2, p_pinD3, p_pinD4, p_cathodeCommune),
      m_pinSegments{p_pinSegmentA, p_pinSegmentB, p_pinSegmentC, p_pinSegmentD,
                    p_pinSegmentE, p_pinSegmentF, p_pinSegmentG, p_pinSegmentDP}
{
    for (size_t segmentIndex = 0; segmentIndex < 8; ++segmentIndex)
    {
        pinMode(this->m_pinSegments[segmentIndex], OUTPUT);
    }
}

void Affichage4DigitsDirect::EnvoyerValeur(const byte p_valeur) const
{
    DEBUG_A1_START;
#if !OPTIMISE_BOUCLE_ENVOYERVALEUR
    for (size_t i = 0; i < 8; ++i)
    {
        monDigitalWrite(this->m_pinSegments[i], ((p_valeur >> (7 - i)) & 1) ? this->m_segmentOn : this->m_segmentOff);
    }
#else
    monDigitalWrite(this->m_pinSegments[0], p_valeur & 0x80 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[1], p_valeur & 0x40 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[2], p_valeur & 0x20 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[3], p_valeur & 0x10 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[4], p_valeur & 0x08 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[5], p_valeur & 0x04 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[6], p_valeur & 0x02 ? this->m_segmentOn : this->m_segmentOff);
    monDigitalWrite(this->m_pinSegments[7], p_valeur & 0x01 ? this->m_segmentOn : this->m_segmentOff);

#endif
    DEBUG_A1_STOP;
}