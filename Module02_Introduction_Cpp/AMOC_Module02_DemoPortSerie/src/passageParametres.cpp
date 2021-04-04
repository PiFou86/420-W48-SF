#include <Arduino.h>

#include "passageParametres.h"

void passageDeParametres1(int p_v1, int &p_r1, int *p_p1) {
  Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_v1), HEX) + ") = " + String(p_v1));
  Serial.println("int &p_r1 (int * : 0x" + String((uint16_t)(&p_r1), HEX) + ") = " + String(p_r1));
  Serial.println("int *p_p1 (int ** : 0x" + String((uint16_t)(&p_p1), HEX) + ") adresse : 0x" + String((uint16_t)p_p1, HEX) + " = " + String(*p_p1));
}
