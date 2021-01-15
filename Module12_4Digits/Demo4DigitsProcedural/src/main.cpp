#include <Arduino.h>

volatile int valeurAAfficher = 1234;
volatile int baseAAfficher = DEC;

const int pinD[] = {2, 3, 4, 5};
const int pinSegments[] = {6, 7, 8, 9,
                           10, 11, 12, 13};

void modifierValeur(int p_valeur);

void setup()
{
  Serial.begin(9600);

  for (size_t i = 0; i < 4; i++)
  {
    pinMode(pinD[i], OUTPUT);
  }

  for (size_t i = 0; i < 8; i++)
  {
    pinMode(pinSegments[i], OUTPUT);
  }

  modifierValeur(valeurAAfficher);

  cli();
  //set timer1 interrupt at 1Hz
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1 = 0;  //initialize counter value to 0
  // set compare match register for 1000hz increments
  OCR1A = 249;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS11 bits for 64 prescaler
  TCCR1B |= (1 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void loop()
{
  ;
}

// code adapté de Cyrob : https://www.youtube.com/watch?v=ZXcmeEMK730
#define etatHaut(pin) ((pin) < 8 ? PORTD |= (1 << (pin)) : PORTB |= (1 << (pin - 8)))
#define etatBas(pin) ((pin) < 8 ? PORTD &= ~(1 << (pin)) : PORTB &= ~(1 << (pin - 8)))
#define monDigitalWrite(pin, etat) ((etat) ? etatHaut(pin) : etatBas(pin))

const int TROP_PETIT = 0b00010000;
const int TROP_GRAND = 0b10000000;

const byte valeurSegements[] = {
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

const int nombreConfigurations = sizeof(valeurSegements);
const int blanc = 17;
const int tropGrand = 18;
const int tropPetit = 19;
const int moins = 16;

int digitCourant = 0;
int ancienDigit = 3;
int valeurCache = 0;
int baseCache = 0;
byte cacheDigits[4] = {valeurSegements[0], valeurSegements[1], valeurSegements[2], valeurSegements[3]};

const byte valeurSegmentTropGrand = valeurSegements[tropGrand];
const byte valeurSegmentTropPetit = valeurSegements[tropPetit];
const byte valeurSegmentBlanc = valeurSegements[blanc];
const byte valeurSegmentMoins = valeurSegements[moins];

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(A0, HIGH);

  etatHaut(pinD[digitCourant]);
  ++digitCourant;
  if (digitCourant > 3)
  {
    digitCourant = 0;
  }

  byte segments = cacheDigits[digitCourant];
  monDigitalWrite(pinSegments[0], segments & 0x80);
  monDigitalWrite(pinSegments[1], segments & 0x40);
  monDigitalWrite(pinSegments[2], segments & 0x20);
  monDigitalWrite(pinSegments[3], segments & 0x10);
  monDigitalWrite(pinSegments[4], segments & 0x08);
  monDigitalWrite(pinSegments[5], segments & 0x04);
  monDigitalWrite(pinSegments[6], segments & 0x02);
  monDigitalWrite(pinSegments[7], segments & 0x01);

  etatBas(pinD[digitCourant]);


  digitalWrite(A0, LOW);
}

void modifierValeur(int p_valeur)
{
  if ((p_valeur != valeurCache || baseAAfficher != baseCache))
  {
    valeurCache = p_valeur;
    baseCache = baseAAfficher;

    //Serial.println("Recalcul");
    if (baseAAfficher == DEC && p_valeur > 9999)
    {
      cacheDigits[0] = valeurSegmentTropGrand;
      cacheDigits[1] = valeurSegmentTropGrand;
      cacheDigits[2] = valeurSegmentTropGrand;
      cacheDigits[3] = valeurSegmentTropGrand;
    }
    else if (baseAAfficher == DEC && p_valeur < -999)
    {
      cacheDigits[0] = valeurSegmentTropPetit;
      cacheDigits[1] = valeurSegmentTropPetit;
      cacheDigits[2] = valeurSegmentTropPetit;
      cacheDigits[3] = valeurSegmentTropPetit;
    }
    else
    {
      switch (baseAAfficher)
      {
      case HEX:
        cacheDigits[0] = valeurSegements[(byte)(p_valeur >> 12 & 0x0F)];
        cacheDigits[1] = valeurSegements[(byte)((p_valeur >> 8) & 0x0F)];
        cacheDigits[2] = valeurSegements[(byte)((p_valeur >> 4) & 0x0F)];
        cacheDigits[3] = valeurSegements[(byte)(p_valeur & 0x0F)];
        break;

      case DEC: // par défault décimale. Autres bases non gérées.
      default:
      {
        int valeur = p_valeur < 0 ? -p_valeur : p_valeur;
        int index = 3;
        while (valeur != 0 && index >= 0)
        {
          cacheDigits[index] = valeurSegements[valeur % 10];
          valeur /= 10;
          --index;
        }

        while (index >= 0)
        {
          cacheDigits[index] = valeurSegmentBlanc;
          --index;
        }

        if (valeurAAfficher < 0)
        {
          cacheDigits[0] = valeurSegmentMoins;
        }
      }
      break;
      }
    }
  }

}
