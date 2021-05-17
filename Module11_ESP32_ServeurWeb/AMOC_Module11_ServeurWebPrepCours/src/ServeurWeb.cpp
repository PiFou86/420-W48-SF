#include "ServeurWeb.h"

#include <Arduino.h>
#include <SPIFFS.h>
#include <WebServer.h>

ServeurWeb::ServeurWeb() {
  SPIFFS.begin();

  pinMode(2, OUTPUT);

  this->m_webServer = new WebServer();
  this->m_webServer->begin();
  this->m_webServer->on("/", HTTPMethod::HTTP_GET,
                        [this]() { this->afficherRacine(); });
  this->m_webServer->on("/allumer", HTTPMethod::HTTP_GET,
                        [this]() { this->allumer(); });
  this->m_webServer->on("/eteindre", HTTPMethod::HTTP_GET,
                        [this]() { this->eteindre(); });
  this->m_webServer->onNotFound(
      [this]() { this->renvoyerRessource(this->m_webServer->uri()); });
}

void ServeurWeb::tick() { this->m_webServer->handleClient(); }

void ServeurWeb::afficherRacine() {
  Serial.println("Réception requête");
  Serial.println(this->m_webServer->uri());

  this->renvoyerRessource("/index.html");
}

void ServeurWeb::renvoyerRessource(const String& p_nomRessource) {
  String contentType = obtenirContentType(p_nomRessource);

  if (SPIFFS.exists(p_nomRessource)) {
    File fichier = SPIFFS.open(p_nomRessource, "r");
    size_t sent = this->m_webServer->streamFile(fichier, contentType);
    fichier.close();
  } else {
    this->m_webServer->send(404, "text/plain",
                            "Ressource " + p_nomRessource + " non trouvée !");
  }
}

String ServeurWeb::obtenirContentType(const String& p_nomRessource) {
  if (p_nomRessource.endsWith(".html"))
    return "text/html";
  else if (p_nomRessource.endsWith(".js"))
    return "application/javascript";
  else if (p_nomRessource.endsWith(".css"))
    return "text/css";
  return "text/plain";
}

void ServeurWeb::allumer() {
  digitalWrite(2, HIGH);
  this->m_webServer->send(200, "text/plain", "DEL allumée");
}

void ServeurWeb::eteindre() {
  digitalWrite(2, LOW);
  this->m_webServer->send(200, "text/plain", "DEL éteinte");
}