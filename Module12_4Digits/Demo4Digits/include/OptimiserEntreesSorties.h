#pragma once

#define OPTIMISE_ENTREESSORTIES

#ifdef OPTIMISE_ENTREESSORTIES
// code adapté de Cyrob : https://www.youtube.com/watch?v=ZXcmeEMK730
#define etatHaut(pin)            ( (pin) < 8 ? PORTD |=  (1 << (pin)) : PORTB |=  (1 << (pin - 8)))
#define etatBas(pin)             ( (pin) < 8 ? PORTD &= ~(1 << (pin)) : PORTB &= ~(1 << (pin - 8)))
#define digitalWrite(pin, etat)  ( (etat)?etatHaut(pin):etatBas(pin))

#endif