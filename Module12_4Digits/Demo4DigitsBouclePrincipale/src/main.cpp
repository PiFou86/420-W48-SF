#include <Arduino.h>

#include "Affichage4DigitsDirect.h"

Affichage4DigitsDirect adr(6, 7, 8, 9,
                           10, 11, 12, 13,
                           2, 3, 4, 5);

void setup()
{
#if UTILISER_INTERRUPTION
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  // doit être < 65536
  // Pour 1000Hz (16*10^6) / (64 * 1000) - 1
  OCR1A = 249;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Déf CS10 et CS11 bits pour 64 prescaler
  TCCR1B |= (1 << CS11) | (1 << CS10);
  // Activer la comparaison pour l’interruption
  TIMSK1 |= (1 << OCIE1A);
  sei();
#endif

  adr.Afficher(1, 2, 3, 4);
}

void loop()
{
#if !UTILISER_INTERRUPTION
  adr.Executer();
#endif
}

#if UTILISER_INTERRUPTION
ISR(TIMER1_COMPA_vect)
{
 adr.Executer();
}
#endif