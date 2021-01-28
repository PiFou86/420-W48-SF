#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Bonjour AMOC !");
  lcd.setCursor(0, 1);
  lcd.print((char)200);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
