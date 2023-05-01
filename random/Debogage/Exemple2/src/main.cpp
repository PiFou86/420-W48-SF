// #include "MesMacros.h"
#include <Arduino.h>

const int LED_PIN = 13;
int decaler(int*nombre, int decal) {
   return *nombre<<decal; };
void setup()
{
    Serial.end();
    Serial.begin(9600);
    Serial.println("\ndebut\n Tester macros");
    pinMode(LED_PIN,OUTPUT);
   
       digitalWrite(LED_PIN, LOW);
   
    DEBUG_LINENUMBER_;
    DEBUG_DETAILS_;
    float var1=3.2;
    int   var2=4;
    DEBUG_CONTEXTE_(var1 , var1);
    DEBUG_CONTEXTE_(var2 , var2);
    DEBUG_CONTEXTE_(var2 , var2%2);
    DEBUG_CONTEXTE_(var2 , var2<<2);
    DEBUG_CONTEXTE_(var2 , decaler(&var2, 2));
    DEBUG_LINENUMBER_;
    Serial.println("\nfin");   
}

void loop() {
while (true);
}