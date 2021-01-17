#include "Affichage4DigitsDirect.h"

Affichage4DigitsDirect::Affichage4DigitsDirect(const int &p_pinSegmentA, const int &p_pinSegmentB, const int &p_pinSegmentC, const int &p_pinSegmentD,
                                               const int &p_pinSegmentE, const int &p_pinSegmentF, const int &p_pinSegmentG, const int &p_pinSegmentDP,
                                               const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4,
                                               const unsigned long &p_dureeAffichageDigit)
    : m_pinD{p_pinD1, p_pinD2, p_pinD3, p_pinD4},
      m_pinSegments{p_pinSegmentA, p_pinSegmentB, p_pinSegmentC, p_pinSegmentD,
                    p_pinSegmentE, p_pinSegmentF, p_pinSegmentG, p_pinSegmentDP},
      m_dureeAffichageDigit(p_dureeAffichageDigit)
{
    this->m_digitOff = HIGH;
    this->m_digitOn = LOW;
    this->m_segmentOff = LOW;
    this->m_segmentOn = HIGH;

    for (size_t digitIndex = 0; digitIndex < 4; digitIndex++)
    {
        pinMode(this->m_pinD[digitIndex], OUTPUT);
    }

    for (size_t segmentIndex = 0; segmentIndex < 8; ++segmentIndex)
    {
        pinMode(this->m_pinSegments[segmentIndex], OUTPUT);
    }

    this->m_microsDernierChangement = micros();

    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
}

static const byte valeurSegments[] = {
    //  Segements ABCDEFGP
    0b11111100, // 0   '0'           AAA
    0b01100000, // 1   '1'          F   B
    0b11011010, // 2   '2'         F   B
    0b11110010, // 3   '3'          GGG
    0b01100110, // 4   '4'         E   C
    0b10110110, // 5   '5'        E   C
    0b10111110, // 6   '6'         DDD  P
    0b11100000, // 7   '7'
    0b11111110, // 8   '8'
    0b11110110, // 9   '9'
    0b11101110, // 10  'A'
    0b00111110, // 11  'b'
    0b10011100, // 12  'C'
    0b01111010, // 13  'd'
    0b10011110, // 14  'E'
    0b10001110, // 15  'F'
    0b00000010, // 16  '-'
    0b00000000, // 17  ' '
    0b10000000, // 18  '¨' Trop grand
    0b00010000, // 19  '_' Trop petit
};

static const int tropGrand = 18;
static const int tropPetit = 19;

byte valeurDigitVersValeurSegments(const int &p_valeurDigit)
{
    if (p_valeurDigit < 0)
    {
        return valeurSegments[tropPetit];
    }
    if (p_valeurDigit > 15)
    {
        return valeurSegments[tropGrand];
    }

    return valeurSegments[p_valeurDigit];
}

void Affichage4DigitsDirect::Afficher(const int &p_valeurDigit1, const int &p_valeurDigit2, const int &p_valeurDigit3, const int &p_valeurDigit4) const
{
    this->m_cache[0] = valeurDigitVersValeurSegments(p_valeurDigit1);
    this->m_cache[1] = valeurDigitVersValeurSegments(p_valeurDigit2);
    this->m_cache[2] = valeurDigitVersValeurSegments(p_valeurDigit3);
    this->m_cache[3] = valeurDigitVersValeurSegments(p_valeurDigit4);
}

void Affichage4DigitsDirect::EnvoyerValeur(const byte p_valeur) const
{
#if UTILISER_BOUCLE_AFFICHAGE
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
}

void Affichage4DigitsDirect::Executer() const
{
    digitalWrite(A0, HIGH);

#if !UTILISER_INTERRUPTION
    unsigned long horloge = micros();
    if (this->m_microsDernierChangement + this->m_dureeAffichageDigit < horloge)
    {
        this->m_microsDernierChangement = horloge;
#endif
        digitalWrite(A1, HIGH);
        monDigitalWrite(this->m_pinD[this->m_digitCourant], this->m_digitOff);

#if !OPTIMISE_MODULO
        this->m_digitCourant = (this->m_digitCourant + 1) % 4;
#else
        if (++this->m_digitCourant >= 4) {
            this->m_digitCourant = 0;
        }
#endif
        this->EnvoyerValeur(this->m_cache[this->m_digitCourant]);

        monDigitalWrite(this->m_pinD[this->m_digitCourant], this->m_digitOn);
        digitalWrite(A1, LOW);

#if !UTILISER_INTERRUPTION
    }
#endif
    digitalWrite(A0, LOW);
}
