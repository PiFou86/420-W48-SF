#include <Arduino.h>
#include <EEPROM.h>

#include "SauvegardeDonneesEEPROM.h"

struct MaStructure {
  int a;
  int b;
  char c[16];
};

void setup() {
  Serial.begin(115200);
  EEPROM.begin();

  MaStructure maStructure;
  maStructure.a = 0x1234;
  maStructure.b = 0x4321;
  strcpy(maStructure.c, "Chocolatine !");
  SauvegardeDonneesEEPROM<MaStructure> sauvegardeDonneesEEPROM(0x0666);
  sauvegardeDonneesEEPROM.afficherContenuEEPROM();
  //for (size_t i = 0; i < 1024; i++) {
  for (size_t i = 0; i < 2; i++) {
    sauvegardeDonneesEEPROM.donnees(maStructure);
    if (sauvegardeDonneesEEPROM.sauvegarder()) {
      Serial.println("Sauvegarder OK");
    } else {
      Serial.println("Sauvegarder KO");
      break;
    }
    if (sauvegardeDonneesEEPROM.charger()) {
      Serial.println("Chargement OK");
    } else {
      Serial.println("Chargement KO");
      break;
    }
    Serial.println(sauvegardeDonneesEEPROM.donnees().a);
    Serial.println(sauvegardeDonneesEEPROM.donnees().b);
    Serial.println();
    sauvegardeDonneesEEPROM.afficherContenuEEPROM();
  }
    if (sauvegardeDonneesEEPROM.charger()) {
      Serial.println("Chargement OK");
    } else {
      Serial.println("Chargement KO");
    }
    Serial.println(sauvegardeDonneesEEPROM.donnees().a, HEX);
    Serial.println(sauvegardeDonneesEEPROM.donnees().b, HEX);
    Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
}
