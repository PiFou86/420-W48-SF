/**
 * Based on WiFiWebClient
 */

#include <Arduino.h>
#include <Credential.h>
#include <WiFi.h>

void printWifiStatus();

const char* ssid = MYSSID ;
const char* password = MYPSW ;

int status = WL_IDLE_STATUS;

char server[] = "ipinfo.io"; 

WiFiClient client;

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
