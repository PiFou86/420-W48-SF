/*
 référence:https://github.com/espressif/arduino-esp32/tree/master/librairies/
*/
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#include <config.h>

const int pinInterne = 2;
const char *ssid = WIFI_SSID; 

const char *password = WIFI_PASSWORD;
WebServer server(80);

void handleRoot() {
  digitalWrite(pinInterne, HIGH);
  server.send(200, "text/plain", "Bonjour à partir de mon ESP32 !");
  digitalWrite(pinInterne, LOW);
}

void handleNotFound() {
  digitalWrite(pinInterne, HIGH);
  String message = "Oups. Site non trouvé\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(pinInterne, LOW);
}

void setup(void) {
  pinMode(pinInterne, OUTPUT);
  digitalWrite(pinInterne, LOW);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // connexion au serveur web à ajouter

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("serveur actif");
}

void loop(void) {
  server.handleClient();
  delay(2); 
}
