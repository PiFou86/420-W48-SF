/*reference https://forum.arduino.cc/t/collection-of-basic-functionilities-how-do-i/1016498
demonstration de l'usage de directives de compilations pour deboguer des programmes en langage C
*/
#include <Arduino.h>

#ifndef DEBUG_ 
      #define DEBUG_ true      // false pour masquer les traces   
#endif

#define DEBUG_STRING_(x) if (DEBUG_) {Serial.print(x); };

const int LED_PIN = 13;
const int DELAIS_BASE = 85;      // ­1/5 second for a Dit or Dash signal

void afficherPoint() {
    Serial.print(".");
    digitalWrite(LED_PIN, HIGH);
    delay(DELAIS_BASE);
    digitalWrite(LED_PIN, LOW);
    delay(DELAIS_BASE);
}
void afficherTiret() {
    Serial.print("-");
    digitalWrite(LED_PIN, HIGH);
    delay(3*DELAIS_BASE);
    digitalWrite(LED_PIN, LOW);
    delay(3*DELAIS_BASE);
}
void afficherSOS() {             // Dit Dit Dit Dash Dash Dash Dit Dit Dit 
   if (DEBUG_) {
        Serial.print("S");
   }
    afficherPoint();
    afficherPoint();
    afficherPoint();
    delay(3*DELAIS_BASE);
    if (DEBUG_) {
        Serial.print("O");
   }
    afficherTiret();
    afficherTiret();
    afficherTiret();   
    delay(3*DELAIS_BASE);

    if (DEBUG_) {
        Serial.print("S");
    }
    afficherPoint();
    afficherPoint();
    afficherPoint();
    delay(3*DELAIS_BASE);
    Serial.println('\n');
}

void setup()
{
    Serial.end();
    Serial.begin(9600);
    Serial.println("\ndebut\n **Debogage avec macros**");
    pinMode(LED_PIN,OUTPUT);
    digitalWrite(LED_PIN, LOW);
/*   if (DEBUG_) {
       DEBUG_STRING_("appel afficherSOS()");
   }
*/
    afficherSOS();
/*   if (DEBUG_) {
       DEBUG_STRING_("retour de afficherSOS()");
   }
*/
    Serial.println("fin");   
}

void loop() {;}
