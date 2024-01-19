#include <Arduino.h>

#include "Program.h"

#define DEMO_WebServer 1
#define DEMO_Filesystem 2

//#define DEMO DEMO_WebServer
//#define DEMO DEMO_Filesystem

#if DEMO == DEMO_WebServer

Program* program;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  program = new Program();
}

void loop() {
  program->loop();
}

#elif DEMO == DEMO_Filesystem


#include <Arduino.h>

#ifdef FS_LITTLEFS

#include <LittleFS.h>
#define FS LittleFS

#else

#include <SPIFFS.h>
#define FS SPIFFS

#endif

void afficherFichiers(File p_repertoire, int p_nbEspaces = 1);

void setup() {
    Serial.begin(112500);
 
    delay(500);
 
    Serial.println(F("Initialisation du système de fichiers..."));
      if (FS.begin(true)) {
        #ifdef FS_LITTLEFS
        Serial.println(F("LittleFS est correctement monté."));
        #else
        Serial.println(F("SPIFFS est correctement monté."));
        #endif
    }else{
        #ifdef FS_LITTLEFS
        Serial.println(F("Une erreur est survenue lors du montage de LittleFS."));
        #else
        Serial.println(F("Une erreur est survenue lors du montage de SPIFFS."));
        #endif
    }
 
    unsigned int totalBytes = FS.totalBytes();
    unsigned int usedBytes = FS.usedBytes();
 
    Serial.println("===== Information du système de fichiers =====");
 
    Serial.print("Espace total :         ");
    Serial.print(totalBytes);
    Serial.println(" octets");
 
    Serial.print("Espace total utilisé : ");
    Serial.print(usedBytes);
    Serial.println(" octets");
 
    Serial.println();
 
    File dir = FS.open("/");

    afficherFichiers(dir);
}

void afficherFichiers(File p_repertoire, int p_nbEspaces) {
  // Serial.println(String("Traitement du répertoire : ") + p_repertoire.name());

  File fichier = p_repertoire.openNextFile();
  while (fichier) {
    for (uint8_t i = 0; i < p_nbEspaces; i++) {
      Serial.print("  ");
    }
    Serial.print(fichier.name());
    Serial.print(" - ");
    Serial.print(fichier.isDirectory() ? "Dossier" : "Fichier");
    if (fichier.isDirectory()) {
      Serial.println("/");
      afficherFichiers(fichier, p_nbEspaces + 1);
    } else {
      Serial.print("    ");
      Serial.println(fichier.size(), DEC);
    }
    fichier.close();

    fichier = p_repertoire.openNextFile();
  }
}

void loop() {
  ;
} 

#endif
