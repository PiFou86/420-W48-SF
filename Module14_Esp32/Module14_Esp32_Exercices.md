# Module 14 - Introduction au microcontrôleur Esp32

## Exercice 1 - Programme de test

Ce programme fait clignoter la DELs soudée sur la carte Esp32. Cette DEL est reliée à la borne GPIO 02 (non à la NO 13 comme dans Arduino).

### Matériel

- Microcontrôleur Esp32
- câble USB-micro

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO

- nommez le projet esp32Blink

-configurez le fichier platformio.ini. Ajouter la vitesse de communication série du Esp32.


<details>
    <summary>Configuration </summary>

[env:esp32doit-devkit-v1]

platform = espressif32

board = esp32doit-devkit-v1

framework = arduino

monitor_speed = 115200

</details>

### Étape 2 Exécution

- Entrez le code du programme esp32Blink

- Exécutez et déboggez votre environnement de développement

<details>
    <summary>Code</summary>

```cpp
/*
  ESP32 Blink
  esp32-blink.ino
  Rewrite of classic Blink sketch for ESP32
  Use LED on GPIO2
   
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
 
// LED on GPIO2
int ledPin = 2;
 
void setup()
{
    // Set LED as output
    pinMode(ledPin, OUTPUT);
    
    // Serial monitor setup
    Serial.begin(115200);
}
 
void loop()
{
    Serial.print("Hello");
    digitalWrite(ledPin, HIGH);
    
    delay(500);
    
    Serial.println(" world!");
    digitalWrite(ledPin, LOW);
    
    delay(500);
}
```
</details>

## Exercice 2 - Afficher les réseaux disponibles
 
Dans cet exercice, votre Esp32 affichera les réseaux Wifi à proximité.
 
### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO nommé Esp32ListeSSIDs

- Entrez le code du programme

- Exécutez et déboggez votre environnement de développement

<details>
    <summary>Code</summary>

```cpp
/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include <Arduino.h>
#include <Credential.h>
#include <WiFi.h>

void setup()
{
    Serial.begin(9600);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop()
{
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}
```
</details>

## Exercice 3 - Esp32 comme serveur Web
 
Dans cet exercice, votre Esp32 servira de serveur web. Votre PC ou votre cellulaire pourra faire clingoter ou non la DEL bleu de la carte.

### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO nommé esp32_Web_server

- Utilisez l'exercice précédent pour ajuster votre environnement de développement

- Dans le répertoire, créez le fichier Credential.h qui contient la configuration de votre routeur 

<details>
    <summary>Configuration </summary>

#define MYSSID "MONFOURNISSEURPUBLIC"

#define MYPSW "MOTDEPASSESECRET"

</details>

- Entrez le code du programme esp32_Web_server

- Exécutez et déboggez votre environnement de développement

<details>
    <summary>Code</summary>

```cpp
/*
 WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 5.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 5

 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */
#include <Arduino.h>
#include <WiFi.h>
#include <Credential.h>

// LED on GPIO2
int ledPin = 2;

const char* ssid = MYSSID ;
const char* password = MYPSW ;

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(ledPin , OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
		Serial.print(".");
		digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
		delay(500);
 }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(ledPin, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(ledPin, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
```
</details>

### Étape 2 Test de fonctionnement

- Notez l'adresse IP fournie dans la console du serveur web, à l'étape 1 (exemple 192.168.0.123)

- Ouvrez un navigateur et entrez l'adresse IP dans la fenêtre de l'URL

- Cliquez alternativement sur les boutons pour contrôler le clignotement de la DEL de l'Esp32.

### Étape 3 Questions

- Pourquoi faut-il entrer l'adresse ip plutôt que le lien URL pour accéder au serveur?

<details>
    <summary>Indice</summary>

- Aucune configuration DNS est disponible pour ce site web.

</details>

### Étape 4 Boucle d'attente

- Ajouter un compteur dans la boucle d'attente de connexion. La boucle doit effectuer 10 tentatives avant de signaler un échec. 

### Étape 5 Dépannage de connexion

Dans cet étape, vous allez vérifier l'existance du réseau.

### Étape 5.1 Dépannage sur PC et sur cellulaire

- Ouvrez une console sur votre PC (rappel cmd.exe). Utilisez la commande ping pour réaliser une liaison avec l'adresse IP du serveur Esp32.

- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaxcessible.

- Sur votre cellulaire, téléchargez l'application qui ping les adresses IP. Sur iphone, l'application s'appelle "network ping lite".

- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaxcessible.

## Exercice 3 - Esp32 comme client Web
 
Dans cet exercice, votre Esp32 se connectera à un site web.

### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO

- nommez le projet esp32_client_web

- Utilisez l'exercice précédent pour ajuster votre environnement de développement

- Entrez le code du programme esp32_client_web

- Exécutez et déboggez votre environnement de développement

<details>
    <summary>Code</summary>

```cpp

/**
 * Based on WiFiWebClient
 */

#include <Arduino.h>
#include <Credential.h>

#include <SPI.h>
#include <WiFi.h>

const char* ssid = MYSSID ;
const char* password = MYPSW ;

int status = WL_IDLE_STATUS;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {} //wait for serial
  WiFi.begin(ssid, password);
  Serial.print("Try to Connect to: ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");
   delay(100);
  }
     
  Serial.println("Connected to wifi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET /ip HTTP/1.1");
    client.println("Host: ipinfo.io");
    client.println("Connection: close");
    client.println();
  }
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print 
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
```
</details>
