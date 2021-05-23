#include <Arduino.h>
#include <WebServer.h>

IPAddress adresseIPInterne(192, 168, 23, 1);
IPAddress passerelle(192, 168, 23, 1);
IPAddress masqueReseau(255, 255, 255, 0);
WebServer serveurWeb(80);
char const* SSID = "MonReseauESP32";
char const* motPasse = nullptr;
bool erreur = false;
void setup() {
  Serial.begin(115200);

  bool configReussie =
      WiFi.softAPConfig(adresseIPInterne, passerelle, masqueReseau);
  bool demarrageAPReussi = false;
  Serial.println(String("Configuration réseau du point d'accès : ") +
               (configReussie ? "Réussie" : "Échec !"));

  if (configReussie) {
    demarrageAPReussi = WiFi.softAP(SSID, motPasse);
    Serial.println(String("Démarrage du point d'accès : ") +
                 (demarrageAPReussi ? "Réussi" : "Échec !"));

    if (demarrageAPReussi) {
      Serial.print("Adresse IP du point d'accès : ");
      Serial.println(WiFi.softAPIP());

      serveurWeb.on("/", []() {
        serveurWeb.send(200, "text/plain", "Bienvenue sur le point d'accès !");
      });

      serveurWeb.begin();
    }
  }

  erreur = !(configReussie && demarrageAPReussi);
}

void loop() {
  if (!erreur) {
    serveurWeb.handleClient();
  }
}