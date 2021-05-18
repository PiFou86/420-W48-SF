#include "ServeurWeb.h"

#include <Arduino.h>
#include <SPIFFS.h>
#include <WebServer.h>
#include <detail/RequestHandlersImpl.h>

// Note: pour bootstrap, nous pourrions utiliser un CDN ce qui
// - économiserait de l'espace
// - permettrait de gagner du temps de traitement car
// potentiellement déjà dans la cache du navigateur

ServeurWeb::ServeurWeb() {
  SPIFFS.begin();

  pinMode(2, OUTPUT);

  this->m_webServer = new WebServer();

  this->ajouterFichiersStatiques("/");

  this->m_webServer->on("/", HTTPMethod::HTTP_GET,
                        [this]() { this->afficherRacine(); });
  this->m_webServer->on("/allumer", HTTPMethod::HTTP_GET,
                        [this]() { this->allumer(); });
  this->m_webServer->on("/eteindre", HTTPMethod::HTTP_GET,
                        [this]() { this->eteindre(); });
  this->m_webServer->onNotFound(
      [this]() { this->ressourceNonTrouvee(this->m_webServer->uri()); });

  this->m_webServer->begin();
}

void ServeurWeb::tick() { this->m_webServer->handleClient(); }

void ServeurWeb::afficherRacine() {
  Serial.println("Réception requête");
  Serial.println(this->m_webServer->uri());

  this->m_webServer->sendHeader("Location", "index.html", true);
  this->m_webServer->send(301, "text/plain", "");
}

void ServeurWeb::ajouterFichiersStatiques(String const& p_debutNomFichier) {
  File racine = SPIFFS.open("/");
  ajouterFichiersStatiques(p_debutNomFichier, racine);
}

void ServeurWeb::ajouterFichiersStatiques(String const& p_debutNomFichier,
                                          File& p_repertoire) {
  if (!p_repertoire) return;

  File fichier = p_repertoire.openNextFile();
  while (fichier) {
    String nomFichier = String(fichier.name());
    if (fichier.isDirectory()) {
      ajouterFichiersStatiques(p_debutNomFichier, fichier);
    } else {
      if (nomFichier.startsWith(p_debutNomFichier)) {
        Serial.println(String("Ajout du fichier statique: " + nomFichier));
        this->m_webServer->serveStatic(nomFichier.c_str(), SPIFFS,
                                       nomFichier.c_str());
      }
    }
    fichier.close();
    fichier = p_repertoire.openNextFile();
  }

  p_repertoire.close();
}

void ServeurWeb::ressourceNonTrouvee(const String& p_nomRessource) {
  Serial.println("Ressource '" + p_nomRessource + "' non trouvée !");
  this->m_webServer->send(404, "text/plain",
                          "Ressource '" + p_nomRessource + "' non trouvée !");
}

void ServeurWeb::allumer() {
  digitalWrite(2, HIGH);
  this->m_webServer->send(200, "text/plain", "DEL allumée");
}

void ServeurWeb::eteindre() {
  digitalWrite(2, LOW);
  this->m_webServer->send(200, "text/plain", "DEL éteinte");
}
