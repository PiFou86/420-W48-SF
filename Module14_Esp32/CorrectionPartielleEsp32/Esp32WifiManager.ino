/*
Wifi Manager 
*/
#include <Arduino.h>
#include <Credential.h>
#include <WifiManager.h>

// LED on GPIO2
int ledPin = 2;

const char* ssid = MYSSID ;
const char* password = MYPSW ;

WiFiManager wm;

void setup() {
    pinMode(ledPin , OUTPUT);      // set the LED pin mode
    Serial.begin(115200);
    delay(10);
    wm.resetSettings();  // effacer le profil d'autentification

    // We start by connecting to a WiFi network

    Serial.println("\n");
    Serial.print("Try to connect to :");
    Serial.println(ssid);
    if (! wm.autoConnect(ssid, password)) {
      Serial.println("non connecte :") ;
    }
   else {
      Serial.print("connecte a:") ;
      Serial.println(ssid) ;
    }

}

void loop(){
while (true) ; 
}