#include <Arduino.h>
#include <EEPROM.h>

#include "SauvegardeDonneesEEPROM.h"

struct MyStruct {
  int a;
  int b;
};

void setup() {
  Serial.begin(115200);
  EEPROM.begin();

  MyStruct myStruct;
  myStruct.a = 0x1234;
  myStruct.b = 0x4321;
  SauvegardeDonneesEEPROM<MyStruct> sauvegardeDonneesEEPROM(0x6666);
  sauvegardeDonneesEEPROM.afficherContenuEEPROM();
  for (size_t i = 0; i < 1024; i++) {
    sauvegardeDonneesEEPROM.donnees(myStruct);
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
