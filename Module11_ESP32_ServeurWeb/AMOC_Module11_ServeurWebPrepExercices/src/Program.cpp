#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "Program.h"

#include "ServeurWeb.h"
#include "DEL.h"

Program::Program() { 
  this->connexionReseau();

  // Configurer l'ensemble de vos actionneurs.
  // Ici je n'ai mis que des DELs et j'ai triché en utilisant que la DEL qui
  // est soudée sur l'ESP32
  // DEL(idUnique, "description", pin, allumée?)
  // La configuration des actions pourraient même être enregistrée dans un fichier json.
  // Les routes sont :
  // GET /actionneurs    -> renvoie la liste des actionneurs avec le statut
  // PUT /actionneurs/id -> permet de mettre à jour un actionneur avec la struture 
  // exemples : {"id":1,"statut":"eteint"}, {"id":1,"statut":"allume"}
  this->m_actionneurs.push_back(new DEL(1, "DEL 1", 2, false));
  this->m_actionneurs.push_back(new DEL(2, "DEL 2", 2, false));
  this->m_actionneurs.push_back(new DEL(3, "DEL 3", 2, false));
  this->m_actionneurs.push_back(new DEL(4, "DEL 4", 2, false));
  this->m_actionneurs.push_back(new DEL(5, "DEL 5", 2, false));
  this->m_actionneurs.push_back(new DEL(6, "DEL 6", 2, false));
  
  this->m_serveurWeb = new ServeurWeb(this->m_actionneurs);
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

