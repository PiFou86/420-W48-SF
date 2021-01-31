#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // adress and format LCD

const int analogInPin = A0;           // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;           // Analog output pin that the LED is attached to

int sensorValue = 0;                  // value read from the pot
int outputValue = 0;                  // value output to the PWM (analog out)

void setup() {
  lcd.init();                         // init LCD
  lcd.backlight();
  lcd.home();
  lcd.setCursor(5, 0);                // place static text
  lcd.print("ADC = ");
  lcd.setCursor(15, 0);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("LED : ");
  lcd.setCursor(12, 1);
  lcd.print("%");
  Serial.begin(9600);                 // optional serial monitor
}

void loop() {
  int sensorValue = analogRead(analogInPin);          // read analog A0 en store in sensorValue
  float voltValue = 5.0 / 1024.0 * sensorValue;       // calculate volt at analog A0 and store in voltValue
  float percentValue = sensorValue / 1024.0 * 100.0;  // calculate percentage analog A0 and store in percentValue
  outputValue = map(sensorValue, 0, 1023, 0, 255);    // map analog input to analog output and store in outputValue
  analogWrite(analogOutPin, outputValue);             // write outputValue to analogOutPin

  lcd.setCursor(0, 0);                                // set cursor at deserid position
  leadingZeros(sensorValue, 4);                       // print sensorvalue with number of leading-characters (0 or space as specified in function leadingZeros)
  lcd.setCursor(10, 0);                               // set cursor at deserid position
  lcd.print(voltValue);                               // print voltValue
  lcd.setCursor(6, 1);                                // set cursor at deserid position
  lcd.print(percentValue);                            // print percentValue

  Serial.print("sensor = " );                         // print the results to the serial monitor:
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\t procent = ");
  Serial.println(percentValue);

  delay(1000);                                        // set delay
}

void leadingZeros( int value, int width) {            // display result with leading characters
  char valueStr[6];                                   // large enough to hold an int
  itoa (value, valueStr, 10);                         // itoa converts int to string
  int len = strlen(valueStr);                         // calculate length of valueStr
  if (len < width) {
    len = width - len;
    while (len--)
      lcd.print(' ');                                 // for leading zeros place '0' between (), for leading spaces place ' ' between ()
  }
  lcd.print(valueStr);
}