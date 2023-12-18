#pragma once

#include <Arduino.h>
#include <CRC16.h>
#include <EEPROM.h>

#include "SauvegardeDonnees.h"
#include "stringUtil.h"

// Pour les couleurs voir : https://en.wikipedia.org/wiki/ANSI_escape_code
// Pour voir les couleurs, modifier le fichier platformio.ini et ajouter "monitor_filters = direct"

// Pour désactiver la couleur mettre la ligne suivante en commentaire
#define USE_COLOR_TERMINAL
#define TEXT_BLUE "\033[34m"
#define TEXT_GREEN "\033[32m"
#define TEXT_RED "\033[31m"
#define TEXT_YELLOW "\033[33m"
#define TEXT_RESET "\033[0m"
#define TEXT_BG_BLACK "\033[40m"
#define TEXT_BOLD "\033[1m"

// Organisation EEPROM :
// || signature app (2 octets) || adresse debut donnees (2 octets) || ...
// || nombre ecritures (2 octets) || crc donnees utilisateur (2 octets) ||
// donnees utilisateur (sizeof(TypeDonneesASauvegarder) octets) || ... ||
inline String padLeft(String p_texte, uint16_t p_tailleMin,
                      char p_remplissage = ' ');

template <typename TypeDonneesASauvegarder>
class SauvegardeDonneesEEPROM
    : public SauvegardeDonnees<TypeDonneesASauvegarder> {
 public:
  SauvegardeDonneesEEPROM(const uint16_t& signatureApp);
  virtual bool sauvegarder() override;
  virtual bool charger() override;
  virtual void initIfFirstTime();
  virtual void effacerEEPROM();

  static void afficherContenuEEPROM();
  static uint16_t tailleDonnees();

 private:
  static uint16_t adresseCompteurEcritures(const uint16_t& adresseDonnees);
  static uint16_t adresseCRCDonneesUtilisateur(const uint16_t& adresseDonnees);
  static uint16_t adresseDonneesUtilisateur(const uint16_t& adresseDonnees);

  const uint16_t SIGNATURE_APP;

  static const uint16_t ADRESSE_SIGNATURE_APP;
  static const uint16_t ADRESSE_ADRESSE_DEBUT_DONNEES;
  static const uint16_t ADRESSE_DEBUT_DONNEES_INITIALISATION;
  static const uint16_t MAX_ECRIRE_PAR_ADRESSE;
};

template <typename TypeDonneesASauvegarder>
const uint16_t
    SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::ADRESSE_SIGNATURE_APP = 0;
template <typename TypeDonneesASauvegarder>
const uint16_t SauvegardeDonneesEEPROM<
    TypeDonneesASauvegarder>::ADRESSE_ADRESSE_DEBUT_DONNEES = 2;
template <typename TypeDonneesASauvegarder>
const uint16_t SauvegardeDonneesEEPROM<
    TypeDonneesASauvegarder>::ADRESSE_DEBUT_DONNEES_INITIALISATION = 4;
template <typename TypeDonneesASauvegarder>
const uint16_t
    SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::MAX_ECRIRE_PAR_ADRESSE =
        2;
template <typename TypeDonneesASauvegarder>
SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::SauvegardeDonneesEEPROM(
    const uint16_t& signatureApp)
    : SIGNATURE_APP(signatureApp) {
  ;
}

template <typename TypeDonneesASauvegarder>
uint16_t SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::tailleDonnees() {
  return sizeof(uint16_t) + sizeof(uint16_t) + sizeof(TypeDonneesASauvegarder);
}

template <typename TypeDonneesASauvegarder>
uint16_t
SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::adresseCompteurEcritures(
    const uint16_t& adresseDonnees) {
  return adresseDonnees;
}

template <typename TypeDonneesASauvegarder>
uint16_t
SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::adresseCRCDonneesUtilisateur(
    const uint16_t& adresseDonnees) {
  return adresseCompteurEcritures(adresseDonnees) + sizeof(uint16_t);
}

template <typename TypeDonneesASauvegarder>
uint16_t
SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::adresseDonneesUtilisateur(
    const uint16_t& adresseDonnees) {
  return adresseCRCDonneesUtilisateur(adresseDonnees) + sizeof(uint16_t);
}

template <typename TypeDonneesASauvegarder>
bool SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::sauvegarder() {
  bool succes = true;
  uint16_t adresseDonnees = 0;
  uint16_t compteurEcritures = 0;

  this->initIfFirstTime();
  EEPROM.get(ADRESSE_ADRESSE_DEBUT_DONNEES, adresseDonnees);
  EEPROM.get(adresseCompteurEcritures(adresseDonnees), compteurEcritures);

  if (compteurEcritures >= MAX_ECRIRE_PAR_ADRESSE) {
    adresseDonnees += tailleDonnees();
    if (adresseDonnees + tailleDonnees() > EEPROM.length()) {
      succes = false;
    }
    compteurEcritures = 0;
    if (succes) {
      EEPROM.put(ADRESSE_ADRESSE_DEBUT_DONNEES, adresseDonnees);
    }
  }

  ++compteurEcritures;
  if (succes) {
    CRC16 crc;
    crc.add((uint8_t*)&this->donnees(), sizeof(TypeDonneesASauvegarder));

    EEPROM.put(adresseCompteurEcritures(adresseDonnees), compteurEcritures);
    EEPROM.put(adresseCRCDonneesUtilisateur(adresseDonnees), crc.calc());
    EEPROM.put(adresseDonneesUtilisateur(adresseDonnees), this->donnees());

    succes = this->charger();
    CRC16 crc2;
    crc2.add((uint8_t*)&(this->donnees()), sizeof(TypeDonneesASauvegarder));
    succes = crc2.calc() == crc.calc();
  }

  return succes;
}

template <typename TypeDonneesASauvegarder>
void SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::initIfFirstTime() {
  uint16_t signatureAppEEPROM = 0;
  EEPROM.get(ADRESSE_SIGNATURE_APP, signatureAppEEPROM);

  if (signatureAppEEPROM != this->SIGNATURE_APP) {
    this->effacerEEPROM();
    EEPROM.put(ADRESSE_SIGNATURE_APP, this->SIGNATURE_APP);
    EEPROM.put(ADRESSE_ADRESSE_DEBUT_DONNEES,
               ADRESSE_DEBUT_DONNEES_INITIALISATION);
  }
}

template <typename TypeDonneesASauvegarder>
bool SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::charger() {
  bool succes = true;
  uint16_t adresseDonnees = 0;
  uint16_t crcSauvegarde = 0;
  TypeDonneesASauvegarder donnees;

  this->initIfFirstTime();
  EEPROM.get(ADRESSE_ADRESSE_DEBUT_DONNEES, adresseDonnees);
  EEPROM.get(adresseCRCDonneesUtilisateur(adresseDonnees), crcSauvegarde);
  EEPROM.get(adresseDonneesUtilisateur(adresseDonnees), donnees);

  CRC16 crc;
  crc.add((uint8_t*)&donnees, sizeof(TypeDonneesASauvegarder));
  succes = crcSauvegarde == crc.calc();

  if (succes) {
    this->donnees(donnees);
  }

  return succes;
}

template <typename TypeDonneesASauvegarder>
void SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::effacerEEPROM() {
  for (uint16_t adresseEEPROM = 0; adresseEEPROM < EEPROM.length();
       ++adresseEEPROM) {
    EEPROM.write(adresseEEPROM, 0);
  }
}

template <typename TypeDonneesASauvegarder>
void SauvegardeDonneesEEPROM<TypeDonneesASauvegarder>::afficherContenuEEPROM() {
  uint16_t adresseDonnees = 0;
  uint16_t compteurEcritures = 0;
  uint16_t signatureApp = 0;
  uint16_t crcDonneesUtilisateur = 0;

  EEPROM.get(ADRESSE_SIGNATURE_APP, signatureApp);
  EEPROM.get(ADRESSE_ADRESSE_DEBUT_DONNEES, adresseDonnees);
  EEPROM.get(adresseCompteurEcritures(adresseDonnees), compteurEcritures);
  EEPROM.get(adresseCRCDonneesUtilisateur(adresseDonnees),
             crcDonneesUtilisateur);

  Serial.println("Taille donnees : " + String(tailleDonnees()));
  Serial.println("Signature app : 0x" +
                 padLeft(String(signatureApp, HEX), 4, '0'));
  Serial.println("Adresse debut donnees : 0x" +
                 padLeft(String(adresseDonnees, HEX), 4, '0'));
  Serial.println(
      "Adresse CRC donnees utilisateur : 0x" +
      padLeft(String(adresseCRCDonneesUtilisateur(adresseDonnees), HEX), 4,
              '0'));
  Serial.println(
      "Adresse debut donnees utilisateur : 0x" +
      padLeft(String(adresseDonneesUtilisateur(adresseDonnees), HEX), 4, '0'));
  Serial.println("Compteur ecritures : " + String(compteurEcritures, DEC));
  Serial.println("CRC donnees utilisateur : 0x" +
                 padLeft(String(crcDonneesUtilisateur, HEX), 4, '0'));
  Serial.println();

  Serial.println("Contenu de l'EEPROM :");
  Serial.println("Capacite dump : " + String(EEPROM.length(), DEC));

  uint16_t lineOffset = 16;
  Serial.print(padLeft("", 4));
  for (uint16_t compt = 0; compt < lineOffset; ++compt) {
    Serial.print("  " + padLeft(String(compt, HEX), 2, '0'));
  }
  Serial.println();

  for (uint16_t adresse = 0; adresse < EEPROM.length(); adresse += lineOffset) {
    Serial.print(padLeft(String((uint16_t)adresse, HEX), 4, '0'));
    for (uint16_t offset = 0;
         offset < lineOffset && adresse + offset < EEPROM.length(); ++offset) {
      uint16_t adresseAAfficher = adresse + offset;
#if defined(USE_COLOR_TERMINAL)
      if (adresseAAfficher == ADRESSE_SIGNATURE_APP ||
          adresseAAfficher == ADRESSE_SIGNATURE_APP + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_BLUE);
      } else if (adresseAAfficher == ADRESSE_ADRESSE_DEBUT_DONNEES ||
                 adresseAAfficher == ADRESSE_ADRESSE_DEBUT_DONNEES + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_YELLOW);
      } else if (adresseAAfficher == adresseDonnees ||
                 adresseAAfficher == adresseDonnees + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_BLUE);
      } else if (adresseAAfficher ==
                     adresseCRCDonneesUtilisateur(adresseDonnees) ||
                 adresseAAfficher ==
                     adresseCRCDonneesUtilisateur(adresseDonnees) + 1) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_YELLOW);
      } else if (adresseAAfficher >=
                     adresseDonneesUtilisateur(adresseDonnees) &&
                 adresseAAfficher < adresseDonneesUtilisateur(adresseDonnees) +
                                        sizeof(TypeDonneesASauvegarder)) {
        Serial.print(TEXT_BOLD);
        Serial.print(TEXT_BG_BLACK);
        Serial.print(TEXT_GREEN);
      }
#endif
      Serial.print("  " +
                   padLeft(String(EEPROM.read(adresseAAfficher), HEX), 2, '0'));
#if defined(USE_COLOR_TERMINAL)
      Serial.print(TEXT_RESET);
#endif
    }

    Serial.print("  |  ");
    for (uint16_t offset = 0;
         offset < lineOffset && adresse + offset < EEPROM.length(); ++offset) {
      char character = (char)EEPROM.read(adresse + offset);
      Serial.print(isprint(character) ? character : ' ');
    }

    Serial.println("  |");
  }

  Serial.println();
}
