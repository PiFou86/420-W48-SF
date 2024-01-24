#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>

#define WIFI_SSID "iot_lab"
#define WIFI_PASSWORD "engagelejeuquejelegagne"

// Pour exécuter le code, il faut un serveur MQTT connecté sur le même réseau
// que l'ESP32
// Vous pouvez créer un serveur MQTT en utilisant le docker-compose du répertoire
// docker-compose-mosquitto. À partir du répertoire docker-compose-mosquitto, tapez :
// > docker-compose up -d
// Le serveur MQTT sera accessible à l'adresse de votre PC sur le port 1883.
// Il existera les deux utilisateurs esp32_demo et mqttexplorer avec le mot "Bonjour01.+"

// Avec le docker-compose, vous avez aussi un explorateur de message MQTT. Pour y accéder,
// ouvrez un navigateur et tapez l'adresse suivante : http://localhost:4000 et créez une connexion
// avec les informations suivantes :
// - Name : Locale
// - Host : mqtt
// - Port : 1883
// - Username : mqttexplorer
// - Password : Bonjour01.+

// Pour tester le code, vous devez adapter en fonction de votre IP
// Pour trouver votre IP, vous pouvez utiliser la commande suivante :
// Windows : ipconfig
// Linux : ifconfig
// Mac : ifconfig | grep "inet "
#define MQTT_SERVER "10.23.209.13"
#define MQTT_PORT 1883
#define MQTT_USER "esp32_demo"
#define MQTT_PASSWORD "Bonjour01.+"

void connectWiFi();
bool reconnectMQTTSiNecessaire();

WiFiClient* espClient = nullptr;
PubSubClient* pubSubClient = nullptr;
String nomUnique;
unsigned long lastSentMessageDate = 0;

void setup() {
  Serial.begin(115200);
  connectWiFi();

  // MQTT
  espClient = new WiFiClient();
  pubSubClient = new PubSubClient(*espClient);
  pubSubClient->setBufferSize(1024);
  pubSubClient->setServer(MQTT_SERVER, MQTT_PORT);
  nomUnique = String("ESP32Client") + String(ESP.getEfuseMac(), HEX);

  // LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  static unsigned long messageId = 0;

  if (reconnectMQTTSiNecessaire()) {
    // Pour traiter les messages MQTT
    pubSubClient->loop();
    if (lastSentMessageDate + 5000 < millis()) {
      lastSentMessageDate = millis();
      String topic = nomUnique + "/data";
      String payload = String("Hello World! - ") + String(messageId++);
      Serial.print("Envoi du message [");
      Serial.print(topic);
      Serial.print("] ");
      Serial.println(payload);
      pubSubClient->publish(topic.c_str(), payload.c_str());
    }
  }
}

void connectWiFi() {
  const uint8_t nbEssaisMaximum = 50;
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
  } else {
    Serial.println("Echec de connexion au réseau WiFi");
    Serial.println("");
    ESP.restart();
  }
}

bool reconnectMQTTSiNecessaire() {
  if (!pubSubClient->connected()) {
    Serial.println("Connexion au broker MQTT...");
    if (pubSubClient->connect(nomUnique.c_str(), MQTT_USER, MQTT_PASSWORD,
                              (nomUnique + "/status").c_str(), 0, 0,
                              "offline")) {
      Serial.println("Connecté au broker MQTT");
      pubSubClient->publish((nomUnique + "/status").c_str(), "online");
      pubSubClient->subscribe("broadcast/#");
      pubSubClient->setCallback(
          [](char* topic, byte* payload, unsigned int length) {
            Serial.print("Message reçu [");
            Serial.print(topic);
            Serial.print("] ");
            String payloadString = "";

            for (int i = 0; i < length; i++) {
              payloadString += (char)payload[i];
            }
            Serial.println(payloadString);

            // DEL
            if (String(topic) == "broadcast/led") {
              if (payloadString == "on") {
                digitalWrite(LED_BUILTIN, HIGH);
              } else if (payloadString == "off") {
                digitalWrite(LED_BUILTIN, LOW);
              }
            }
          });
    } else {
      Serial.print("Echec de connexion au broker MQTT : ");
      Serial.println(pubSubClient->state());
      Serial.println("Nouvelle tentative dans 5 secondes");
      delay(5000);
    }
  }

  return pubSubClient->connected();
}