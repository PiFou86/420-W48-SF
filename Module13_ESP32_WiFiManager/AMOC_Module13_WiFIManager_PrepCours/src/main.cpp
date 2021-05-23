#include <Arduino.h>
#include <WiFiManager.h>
#include <uri/UriRegex.h>

WiFiManager wm;
char const* SSIDPortail = "ConfigurationESP32";
char const* motPasseAPPortail = "Bonjour01.+";
IPAddress adresseIPPortail(192, 168, 23, 1);
IPAddress passerellePortail(192, 168, 23, 1);
IPAddress masqueReseauPortail(255, 255, 255, 0);
WebServer serveurWeb;
WiFiManagerParameter paramerePersonnalise("identifiant_unique_champ",
                                          "Nom du champ",
                                          "ValeurQuiEtaitSauvegardee", 40);
void setup() {
  Serial.begin(115200);

  wm.setDebugOutput(false);  // Mettre à true si vous avez des problèmes
  wm.setAPCallback([](WiFiManager* p_wiFiManager) {
    Serial.println("Connexion au réseau WiFi échouée, on lance le portail !");
  });

  wm.setConfigPortalTimeout(180);

  wm.setSaveParamsCallback([&paramerePersonnalise]() {
    Serial.println(
        "Sauvegarde de la configuration effectuée par l'utilisateur dans le "
        "portail...");
    Serial.println(String("Nouvelle valeur du paramètre : ") +
                   paramerePersonnalise.getValue());

    // Exemple d'actions...
    // Sauvegarde des données en JSON
    // Redémarrage : ESP.restart();
    // etc.
  });

  wm.addParameter(&paramerePersonnalise);

  wm.setAPStaticIPConfig(adresseIPPortail, passerellePortail,
                         masqueReseauPortail);

  wm.setParamsPage(true);

  // Pour le débug, on peut forcer l'effacement de la configuration du WiFi
  // wm.erase();

  // Essaie de se connecter au réseau WiFi. Si échec, il lance le portail de
  // configuration. L'appel est bloquant -> rend la main après le timeout
  wm.autoConnect(SSIDPortail, motPasseAPPortail);

  // Pour lancer le portail manuellement
  // wm.startConfigPortal();

  serveurWeb.on(UriRegex("/.*"), []() {
    serveurWeb.send(200, "text/plain", "Bienvenue sur mon site web !");
  });

  if (WiFi.isConnected()) {
    serveurWeb.begin();
    Serial.println("Connecté au réseau : " + WiFi.SSID() +
                   " avec l'adresse : " + WiFi.localIP().toString());
  }
}

void loop() {
  if (WiFi.isConnected()) {
    serveurWeb.handleClient();
  }
}