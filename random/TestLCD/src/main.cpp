#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  byte coeur[8] = {0b00000, 0b01010, 0b11111, 0b11111,
                   0b11111, 0b01110, 0b00100, 0b00000};

  lcd.init();
  lcd.createChar(0, coeur);
  lcd.backlight();
  Serial.begin(9600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bonjour a tous !");
  lcd.setCursor(0, 1);
  lcd.print("Bienvenue !");
  lcd.write((byte)0);
}

void loop() {}
