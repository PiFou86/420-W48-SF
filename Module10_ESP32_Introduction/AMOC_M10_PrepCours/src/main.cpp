#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "config.h"

#define DEMO_GET_GOOGLE
#define DEMO_DESERIALISATION_JSON
#define DEMO_SERIALISATION_JSON
#define DEMO_IF_CONFIG
#define EXERCICE_METEO

void getGoogleAffichageSurConsole();
void demoDeserialiserJSON();
void demoSerialiserJSON();
void demoIfconfig();
void afficherMeteoMontreal();

void setup() {
  Serial.begin(115200);
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

#ifdef DEMO_GET_GOOGLE
  getGoogleAffichageSurConsole();
  Serial.println("");
#endif

#ifdef DEMO_DESERIALISATION_JSON
  demoDeserialiserJSON();
  Serial.println("");
#endif

#ifdef DEMO_SERIALISATION_JSON
  demoSerialiserJSON();
  Serial.println("");
#endif

#ifdef DEMO_IF_CONFIG
  demoIfconfig();
  Serial.println("");
#endif

#ifdef EXERCICE_METEO
  afficherMeteoMontreal();
  Serial.println("");
#endif
}

void loop() { ; }

void demoDeserialiserJSON() {
  const char* input =
      "{"
      "  \"menu\": {"
      "    \"id\": \"file\","
      "    \"value\": \"File\","
      "    \"popup\": {"
      "      \"menuitem\": ["
      "        {"
      "          \"value\": \"New\","
      "          \"onclick\": \"CreateNewDoc()\""
      "        },"
      "        {"
      "          \"value\": \"Open\","
      "          \"onclick\": \"OpenDoc()\""
      "        },"
      "        {"
      "          \"value\": \"Close\","
      "          \"onclick\": \"CloseDoc()\""
      "        }"
      "      ]"
      "    }"
      "  }"
      "}";
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, input);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  JsonObject menu = doc["menu"];
  const char* menu_id = menu["id"];        // "file"
  const char* menu_value = menu["value"];  // "File"
  Serial.println(String("id: ") + menu_id);
  Serial.println(String("value: ") + menu_value);

  for (JsonObject elem : menu["popup"]["menuitem"].as<JsonArray>()) {
    const char* value = elem["value"];  // "New", "Open", "Close"
    const char* onclick =
        elem["onclick"];  // "CreateNewDoc()", "OpenDoc()", "CloseDoc()"

    Serial.println(String("menu item: ") + value + " - " + onclick);
  }
}

void getGoogleAffichageSurConsole() {
  if (WiFi.status() == WL_CONNECTED) {
    String url = "https://www.google.com/";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();
    String contenu = httpClient.getString();
    Serial.println("Code : " + String(codeStatut));
    if (codeStatut < 0) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      Serial.println(contenu);
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }
}

void demoSerialiserJSON() {
  DynamicJsonDocument doc(1024);

  JsonObject menu = doc.createNestedObject("menu");
  menu["id"] = "file";
  menu["value"] = "File";

  JsonArray menu_popup_menuitem = menu["popup"].createNestedArray("menuitem");

  JsonObject menu_popup_menuitem_0 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_0["value"] = "New";
  menu_popup_menuitem_0["onclick"] = "CreateNewDoc()";

  JsonObject menu_popup_menuitem_1 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_1["value"] = "Open";
  menu_popup_menuitem_1["onclick"] = "OpenDoc()";

  JsonObject menu_popup_menuitem_2 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_2["value"] = "Close";
  menu_popup_menuitem_2["onclick"] = "CloseDoc()";

  // Voir https://arduinojson.org/v6/api/json/serializejson/ pour écrire
  // directement dans un fichier Ou le Serial
  // File file = xyz.open(filename, FILE_WRITE);
  // serializeJson(doc, file);
  // file.close();
  // serializeJson(doc, file);
  // ou
  // serializeJson(doc, Serial);
  char chaineTmp[1024];
  serializeJson(doc, chaineTmp);
  Serial.println(chaineTmp);
}

String obtenirIPExterne() {
  String res = "";
  if (WiFi.status() == WL_CONNECTED) {
    String url = "https://ifconfig.co/json";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if (codeStatut != 200) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      res = httpClient.getString();
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }

  return res;
}

void afficherInformationIPExterneAPartirJSON(const String& json) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, json);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  Serial.println(String("Adresse IP publique: ") + (const char*)doc["ip"]);
  Serial.println(String("Pays: ") + (const char*)doc["country"]);
  Serial.println(String("Région: ") + (const char*)doc["region_name"]);
  Serial.println(String("Latitude: ") + (const char*)doc["latitude"]);
  Serial.println(String("Longitude: ") + (const char*)doc["longitude"]);
}

void demoIfconfig() {
  String json = obtenirIPExterne();
  if (json != "") {
    afficherInformationIPExterneAPartirJSON(json);
  } else {
    Serial.println("Erreur d'obtention de l'adresse externe");
  }
}

String obtenirMeteoMontreal() {
  String res = "";
  if (WiFi.status() == WL_CONNECTED) {
    String url = "https://www.metaweather.com/api/location/3534/";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if (codeStatut != 200) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      res = httpClient.getString();
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }

  return res;
}

void afficherInformationMeteoAPartirJSON(const String& json) {
  DynamicJsonDocument doc(4096);
  DeserializationError error = deserializeJson(doc, json);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  Serial.println(String("Ville: ") + (const char*)doc["title"]);
  Serial.println(
      String("Prévision: ") +
      (const char*)doc["consolidated_weather"][0]["weather_state_name"]);
  Serial.println(String("Température minimum: ") +
                 (float)doc["consolidated_weather"][0]["min_temp"]);
  Serial.println(String("Température maximum: ") +
                 (float)doc["consolidated_weather"][0]["max_temp"]);
}

void afficherMeteoMontreal() {
  String json = obtenirMeteoMontreal();
  if (json != "") {
    afficherInformationMeteoAPartirJSON(json);
  } else {
    Serial.println("Erreur d'obtention de la météo");
  }
}
