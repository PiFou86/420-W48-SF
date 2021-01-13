#include "GestionEvenements.h"
#include <Arduino.h>

#include "Config.h"
#include "OptimiserEntreesSorties.h"

GestionEvenementsClass::GestionEvenementsClass()
    : m_nombreEvenement(0)
{
    ;
#if DEBUG_TIMER
    pinMode(A0, OUTPUT);
#endif
}

void GestionEvenementsClass::Ajouter(Evenement *p_event)
{
    this->m_evenements[this->m_nombreEvenement] = p_event;
    this->m_nombreEvenement++;
}

void GestionEvenementsClass::Executer()
{
    for (int i = 0; i < this->m_nombreEvenement; i++)
    {
        this->m_evenements[i]->Executer();
    }
}

void GestionEvenementsClass::Start()
{
#if UTILISER_TIMER1
    // Basé sur https://www.instructables.com/Arduino-Timer-Interrupts/
    // Et : https://www.youtube.com/watch?v=2kr5A350H7E
    cli();
    //set timer1 interrupt at 1Hz
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;  //initialize counter value to 0
    // set compare match register for 1000hz increments
    OCR1A = TIMER1_VALEUR_A_COMPARER; // = (16*10^6) / (64*1000) - 1 (must be <65536)   // 1000Hz
   // OCR1A =  8332; // = (16*10^6) / (64*30) - 1 (must be <65536) // 30 Hz
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS11 bits for 64 prescaler
    TCCR1B |= (1 << CS11) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();
#endif
}

#if UTILISER_TIMER1
ISR(TIMER1_COMPA_vect)
{
#if DEBUG_TIMER
    digitalWrite(A0, HIGH);
#endif
    GestionEvenements.Executer();
#if DEBUG_TIMER
    digitalWrite(A0, LOW);
#endif
}
#endif

GestionEvenementsClass GestionEvenements __attribute__((unused));
