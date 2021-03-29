/*
  ESP32 Blink
  esp32-blink.ino
  Rewrite of classic Blink sketch for ESP32
  Use LED on GPIO2
   
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
#include <Arduino.h>

// LED on GPIO2
int ledPin = 2;
 
void setup()
{
    // Set LED as output
    pinMode(ledPin, OUTPUT);
    
    // Serial monitor setup
    Serial.begin(115200);
}
 
void loop()
{
    Serial.print("Hello");
    digitalWrite(ledPin, HIGH);
    
    delay(500);
    
    Serial.println(" world!");
    digitalWrite(ledPin, LOW);
    
    delay(500);
}