#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//#define DEMO_IOT
#define MESURE_OSCILLOSCOPE

void setup() {
  Serial.begin(9600);
  byte coeur[8] = {0b00000, 0b01010, 0b11111, 0b11111,
                   0b11111, 0b01110, 0b00100, 0b00000};

  lcd.init();
  lcd.backlight();
#ifdef DEMO_IOT
  lcd.createChar(0, coeur);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bonjour a tous !");
  lcd.setCursor(0, 1);
  lcd.print("Bienvenue !");
  lcd.write((byte)0);
#endif
}

void loop() {
#ifdef MESURE_OSCILLOSCOPE
  lcd.print("ABC");
  // lcd.print("E");
  delay(1000);

  /*
  Analyse oscilloscope "ABC" :
  Envoi de 4bits en 3 étapes (préparation, envoi, validation)
   1 : 0100 1001  // A : >>0100<< 0001  0x41
   2 : 0100 1101  
   3 : 0100 1001

   4 : 0001 1001  // A : 0100 >>0001<<  0x41
   5 : 0001 1101
   6 : 0001 1001


   7 : 0100 1001  // B : 0100 0010
   8 : 0100 1101
   9 : 0100 1001

  10 : 0010 1001
  11 : 0010 1101
  12 : 0010 1001


  13 : 0100 1001  // C : 0100 0011
  14 : 0100 1101
  15 : 0100 1001

  16 : 0011 1001
  17 : 0011 1101
  18 : 0011 1001


  Analyse oscilloscope "E" :
   1 : 0100 1001  // E : 0100 0101
   2 : 0100 1101
   3 : 0100 1001

   4 : 0101 1001
   5 : 0101 1101
   6 : 0101 1001

  */
#endif
}
