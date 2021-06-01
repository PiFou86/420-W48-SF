#include "ServeurWeb.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <WebServer.h>
#include <detail/RequestHandlersImpl.h>
#include <uri/UriBraces.h>

#include <algorithm>
#include <functional>

#include "Actionneur.h"

// Note: pour bootstrap, nous pourrions utiliser un CDN ce qui
// - économiserait de l'espace
// - permettrait de gagner du temps de traitement car
// potentiellement déjà dans la cache du navigateur

ServeurWeb::ServeurWeb(std::vector<Actionneur*> const& p_actionneurs)
    : m_actionneurs(p_actionneurs) {
  SPIFFS.begin();

  this->m_webServer = new WebServer();

  this->ajouterFichiersStatiques("/");

  this->m_webServer->on("/", HTTPMethod::HTTP_GET,
                        [this]() { this->afficherRacine(); });
  this->m_webServer->on(Uri("/actionneurs"), HTTPMethod::HTTP_GET,
                        [this]() { this->statuts(); });
  this->m_webServer->on(UriBraces("/actionneurs/{}"), HTTPMethod::HTTP_PUT,
                        [this]() {
                          int id = atoi(this->m_webServer->pathArg(0).c_str());
                          this->actionner(id);
                        });
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

  Serial.println(String("Traitement du répertoire: ") + p_repertoire.name());

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

// classe cachée
class InformationActionneur {
 public:
  int id;
  String statut;
  String description;
};

InformationActionneur* deserialiserInformationActionneur(String const& p_json) {
  DynamicJsonDocument doc(256);
  InformationActionneur* res = nullptr;

  DeserializationError error = deserializeJson(doc, p_json);

  if (!error) {
    res = new InformationActionneur();
    res->id = doc["id"];
    res->statut = doc["statut"].as<String>();
    res->description = doc["description"].as<String>();
  }

  return res;
}

String serialiserInformationActionneur(InformationActionneur const& p_ia) {
  DynamicJsonDocument doc(256);
  char json[256];

  doc["id"] = p_ia.id;
  doc["statut"] = p_ia.statut;
  doc["description"] = p_ia.description;

  serializeJson(doc, json);

  return json;
}

void ServeurWeb::actionner(int const& p_id) {
  std::vector<Actionneur*>::const_iterator itActionneur = std::find_if(
      this->m_actionneurs.begin(), this->m_actionneurs.end(),
      [&](Actionneur* p_actionneur) { return p_actionneur->id() == p_id; });

  if (itActionneur != this->m_actionneurs.end()) {  // ressource trouvée
    String json = this->m_webServer->arg("plain");
    InformationActionneur* ia = deserialiserInformationActionneur(json);

    if (ia == nullptr || ia->id != p_id ||
        (ia->statut != "allume" && ia->statut != "eteint")) {
      this->m_webServer->send(
          400, "text/plain",
          "La requête ne respecte pas le format ou les paramètres attendus");
    } else {
      if (ia->statut == "allume") {
        (*itActionneur)->allumer();
      } else {
        (*itActionneur)->eteindre();
      }

      ia->statut = (*itActionneur)->estAllume() ? "allume" : "eteint";
      ia->description = (*itActionneur)->description();
      this->m_webServer->send(200, "text/json", serialiserInformationActionneur(*ia));
    }

    if (ia != nullptr) {
      delete ia;
      ia = nullptr;
    }

  } else {
    this->m_webServer->send(404, "text/plain", "Actionneur inconnu !");
  }
}

void ServeurWeb::statuts() const {
  DynamicJsonDocument doc(4096);

  for (Actionneur* actionneur : this->m_actionneurs) {
    JsonObject jsonActionneur = doc.createNestedObject();
    jsonActionneur["id"] = actionneur->id();
    jsonActionneur["statut"] = actionneur->estAllume() ? "allume" : "eteint";
    jsonActionneur["description"] = actionneur->description();
  }

  char json[4096];
  serializeJson(doc, json);

  this->m_webServer->send(200, "text/json", json);
}
