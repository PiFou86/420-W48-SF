// #include "Macros.h"
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
   
    DBG_LINENUMBER_;
    DBG_DETAILS_;
    float var1=3.2;
    int   var2=4;
    DBG_CONTEXTE_(var1 , var1);
    DBG_CONTEXTE_(var2 , var2);
    DBG_CONTEXTE_(var2 , var2%2);
    DBG_CONTEXTE_(var2 , var2<<2);
    DBG_CONTEXTE_(var2 , decaler(&var2, 2));
    DBG_LINENUMBER_;
    Serial.println("\nfin");   
}

void loop() {
while (true);
}