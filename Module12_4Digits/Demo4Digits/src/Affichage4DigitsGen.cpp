#include "Affichage4DigitsGen.h"

#include "OptimiserEntreesSorties.h"

int Affichage4DigitsGen::TROP_PETIT = 0b00010000;
int Affichage4DigitsGen::TROP_GRAND = 0b10000000;

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

Affichage4DigitsGen::Affichage4DigitsGen(const int &p_pinD1, const int &p_pinD2, const int &p_pinD3, const int &p_pinD4, const bool &p_cathodeCommune)
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

// Affichage des 4 digits en un appel
void Affichage4DigitsGen::Afficher(const int &p_valeur, const int &p_base) const
{
    if (p_base == DEC && p_valeur > 9999)
    {
        AfficherTropGrand();
    }
    else if (p_base == DEC && p_valeur < -999)
    {
        AfficherTropPetit();
    }
    else
    {
        switch (p_base)
        {
        case HEX:
            this->AfficherHex(p_valeur);
            break;

        case DEC: // par défault décimale. Autres bases non gérées.
        default:
            this->AfficherDec(p_valeur);
            break;
        }
    }
}

// Affichage des 4 digits en 4 appel et utilisation d'une cache
// Idées prises de la très bonne vidéo de Cyrob : https://www.youtube.com/watch?v=CS4t0j1yzH0
void Affichage4DigitsGen::AfficherV2(const int &p_valeur, const int &p_base) const
{
    const byte valeurSegmentTropGrand = valeurSegements[tropGrand];
    const byte valeurSegmentTropPetit = valeurSegements[tropPetit];
    const byte valeurSegmentBlanc = valeurSegements[blanc];
    const byte valeurSegmentMoins = valeurSegements[moins];

    if (this->m_digitCourant >= 4)
    {
        this->m_digitCourant = 0;
    }

    int digitCourant = this->m_digitCourant;
    if (digitCourant == 0 && (p_valeur != this->m_valeurCache || p_base != this->m_baseCache))
    {
        //Serial.println("Recalcul");
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
            this->m_valeurCache = p_valeur;
            this->m_baseCache = p_base;
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

    byte valeurSegment = this->m_cache[digitCourant];

    this->AfficherDigit(valeurSegment, digitCourant);

    ++this->m_digitCourant;
}

void Affichage4DigitsGen::AfficherHex(const int &p_valeur) const
{
    byte valeursDigits[] = {
        (byte)(p_valeur >> 12 & 0x0F),
        (byte)((p_valeur >> 8) & 0x0F),
        (byte)((p_valeur >> 4) & 0x0F),
        (byte)(p_valeur & 0x0F)};
    this->AfficherDigits(valeursDigits);
}

void Affichage4DigitsGen::AfficherDec(const int &p_valeur) const
{
    int valeur = p_valeur < 0 ? -p_valeur : p_valeur;
    int index = 3;
    byte valeursDigits[] = {blanc, blanc, blanc, blanc};
    while (valeur != 0 && index >= 0)
    {
        valeursDigits[index] = valeur % 10;
        valeur /= 10;
        --index;
    }

    if (p_valeur < 0)
    {
        valeursDigits[0] = 16; // '-'
    }

    this->AfficherDigits(valeursDigits);
}

void Affichage4DigitsGen::AfficherTropPetit() const
{
    const byte car = 0b00010000;

    this->AfficherDigit(car, 0);
    this->AfficherDigit(car, 1);
    this->AfficherDigit(car, 2);
    this->AfficherDigit(car, 3);
    // But de ce qui suit : attendre le même temps / digit
    this->AfficherDigit(valeurSegements[blanc], 4);
}

void Affichage4DigitsGen::AfficherTropGrand() const
{
    const byte car = 0b10000000;

    this->AfficherDigit(car, 0);
    this->AfficherDigit(car, 1);
    this->AfficherDigit(car, 2);
    this->AfficherDigit(car, 3);
    // But de ce qui suit : attendre le même temps / digit
    this->AfficherDigit(valeurSegements[blanc], 4);
}

void Affichage4DigitsGen::AfficherDigits(const byte p_digits[4]) const
{
    const byte inconnue = 0xFF;

    this->AfficherDigit(p_digits[0] > nombreConfigurations ? inconnue : valeurSegements[p_digits[0]], 0);
    this->AfficherDigit(p_digits[1] > nombreConfigurations ? inconnue : valeurSegements[p_digits[1]], 1);
    this->AfficherDigit(p_digits[2] > nombreConfigurations ? inconnue : valeurSegements[p_digits[2]], 2);
    this->AfficherDigit(p_digits[3] > nombreConfigurations ? inconnue : valeurSegements[p_digits[3]], 3);
    // But de ce qui suit : attendre le même temps / digit
    this->AfficherDigit(valeurSegements[blanc], 4);
}

void Affichage4DigitsGen::AfficherDigit(const byte &p_segments, const int &p_position) const
{
    int ancienDigit = (p_position == 0)?3: p_position - 1;
    monDigitalWrite(this->m_pinD[ancienDigit], this->m_digitOff);

   // monDigitalWrite(this->m_pinD[0], this->m_digitOff);
   // monDigitalWrite(this->m_pinD[1], this->m_digitOff);
   // monDigitalWrite(this->m_pinD[2], this->m_digitOff);
   // monDigitalWrite(this->m_pinD[3], this->m_digitOff);

    this->EnvoyerValeur(p_segments);

    if (p_position < 4)
    {
        monDigitalWrite(this->m_pinD[p_position], this->m_digitOn);
    }
}

void Affichage4DigitsGen::Reset() const
{
    this->EnvoyerValeur(0x00);
    monDigitalWrite(this->m_pinD[0], this->m_digitOff);
    monDigitalWrite(this->m_pinD[1], this->m_digitOff);
    monDigitalWrite(this->m_pinD[2], this->m_digitOff);
    monDigitalWrite(this->m_pinD[3], this->m_digitOff);
}
