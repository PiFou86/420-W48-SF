#include <Arduino.h>

void setup()
{
  Serial.begin(9600);

  int valeur1 = 42;
  int valeur2 = 13;
  Serial.println(42);
  Serial.println("Bonjour à tous !");
  Serial.println(String(42, HEX));
  Serial.println("0x" + String(42, HEX));
  Serial.println("0x" + String((uint16_t)(&valeur1), HEX));
  Serial.println("0x" + String((uint16_t)(&valeur2), HEX));
}

void loop()
{
  ;
}
