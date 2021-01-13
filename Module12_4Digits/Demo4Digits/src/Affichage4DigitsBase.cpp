#include "Affichage4DigitsBase.h"

#include "OptimiserEntreesSorties.h"

int Affichage4DigitsBase::TROP_PETIT = 0b00010000;
int Affichage4DigitsBase::TROP_GRAND = 0b10000000;

static const byte valeurSegements[] = {
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

static const int nombreConfigurations = sizeof(valeurSegements);
static const int blanc = 17;
static const int tropGrand = 18;
static const int tropPetit = 19;
static const int moins = 16;

Affichage4DigitsBase::Affichage4DigitsBase(const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4, const bool &p_cathodeCommune)
    : m_pinD{p_pinD1, p_pinD2, p_pinD3, p_pinD4}
{
    if (p_cathodeCommune)
    {
        this->m_digitOff = HIGH;
        this->m_digitOn = LOW;
        this->m_segmentOff = LOW;
        this->m_segmentOn = HIGH;
    }
    else
    {
        this->m_digitOff = LOW;
        this->m_digitOn = HIGH;
        this->m_segmentOff = HIGH;
        this->m_segmentOn = LOW;
    }

    for (size_t i = 0; i < 4; i++)
    {
        pinMode(this->m_pinD[i], OUTPUT);
    }
}

const byte valeurSegmentTropGrand = valeurSegements[tropGrand];
const byte valeurSegmentTropPetit = valeurSegements[tropPetit];
const byte valeurSegmentBlanc = valeurSegements[blanc];
const byte valeurSegmentMoins = valeurSegements[moins];

// Affichage des 4 digits en 4 cycle d'appel et utilisation d'une cache
// Idées cache et afficher digit / digit prises de la très bonne vidéo de Cyrob : https://www.youtube.com/watch?v=CS4t0j1yzH0
void Affichage4DigitsBase::Afficher(const int &p_valeur, const int &p_base) const
{
    if (p_valeur != this->m_valeurCache || p_base != this->m_baseCache)
    {
        this->m_valeurCache = p_valeur;
        this->m_baseCache = p_base;

        if (p_base == DEC && p_valeur > 9999)
        {
            this->m_cache[0] = valeurSegmentTropGrand;
            this->m_cache[1] = valeurSegmentTropGrand;
            this->m_cache[2] = valeurSegmentTropGrand;
            this->m_cache[3] = valeurSegmentTropGrand;
        }
        else if (p_base == DEC && p_valeur < -999)
        {
            this->m_cache[0] = valeurSegmentTropPetit;
            this->m_cache[1] = valeurSegmentTropPetit;
            this->m_cache[2] = valeurSegmentTropPetit;
            this->m_cache[3] = valeurSegmentTropPetit;
        }
        else
        {
            switch (p_base)
            {
            case HEX:
                this->m_cache[0] = valeurSegements[(byte)(p_valeur >> 12 & 0x0F)];
                this->m_cache[1] = valeurSegements[(byte)((p_valeur >> 8) & 0x0F)];
                this->m_cache[2] = valeurSegements[(byte)((p_valeur >> 4) & 0x0F)];
                this->m_cache[3] = valeurSegements[(byte)(p_valeur & 0x0F)];
                break;

            case DEC: // par défault décimale. Autres bases non gérées.
            default:
            {
                int valeur = p_valeur < 0 ? -p_valeur : p_valeur;
                int index = 3;
                while (valeur != 0 && index >= 0)
                {
                    this->m_cache[index] = valeurSegements[valeur % 10];
                    valeur /= 10;
                    --index;
                }

                while (index >= 0)
                {
                    this->m_cache[index] = valeurSegmentBlanc;
                    --index;
                }

                if (p_valeur < 0)
                {
                    this->m_cache[0] = valeurSegmentMoins;
                }
            }
            break;
            }
        }
    }
}

void Affichage4DigitsBase::Executer() const
{
    monDigitalWrite(this->m_pinD[this->m_digitCourant], this->m_digitOff);

    ++this->m_digitCourant;
    if (this->m_digitCourant > 3)
    {
        this->m_digitCourant = 0;
    }

    this->EnvoyerValeur(this->m_cache[this->m_digitCourant]);
    
    monDigitalWrite(this->m_pinD[this->m_digitCourant], this->m_digitOn);
}
