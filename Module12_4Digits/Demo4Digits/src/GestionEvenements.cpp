#include "GestionEvenements.h"
#include <Arduino.h>

#include "OptimiserEntreesSorties.h"

#define DEBUG_TIMER

GestionEvenementsClass::GestionEvenementsClass()
    : m_nombreEvenement(0)
{
    ;
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
#ifdef UTILISER_TIMER1
    // Basé sur https://www.instructables.com/Arduino-Timer-Interrupts/
    // Et : https://www.youtube.com/watch?v=2kr5A350H7E
    cli();
    //set timer1 interrupt at 1Hz
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;  //initialize counter value to 0
    // set compare match register for 1000hz increments
    OCR1A = 249; // = (16*10^6) / (64*1000) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS11 bits for 64 prescaler
    TCCR1B |= (1 << CS11) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();
#endif
}

#ifdef UTILISER_TIMER1
ISR(TIMER1_COMPA_vect)
{
#ifdef DEBUG_TIMER
    digitalWrite(7, HIGH);
#endif
    GestionEvenements.Executer();
#ifdef DEBUG_TIMER
    digitalWrite(7, LOW);
#endif
}
#endif

GestionEvenementsClass GestionEvenements __attribute__((unused));
