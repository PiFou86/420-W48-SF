#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "Program.h"

#include "ServeurWeb.h"

Program::Program() { 
  this->connexionReseau();
  this->m_serveurWeb = new ServeurWeb();
}

void Program::loop() {
  this->m_serveurWeb->tick();
}

void Program::connexionReseau() {
  const uint8_t nbEssaisMaximum = 30;
  uint8_t nbEssais = 0;

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connexion : ");
  while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    nbEssais++;
  }
  Serial.println("");

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  }
}

