// Code tiré de l'exemple d'adafruit
// et de
// https://create.arduino.cc/projecthub/abdularbi17/how-to-scan-i2c-address-in-arduino-eaadda
// pour scanner les adresses I2C

#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

//#define TESTADRESSES
//#define TESTBME280
#define TESTBMP280

#define SEALEVELPRESSURE_HPA (1013.25)

void testerAdresses();
void printValues();
void printValuesBMP();

Adafruit_BME280 bme;
Adafruit_BMP280 bmp;
unsigned long delayTime = 500;

void setup() {
#ifdef TESTADRESSES
  Wire.begin();
#endif

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

#ifdef TESTBME280
  Serial.println(F("BME280 test"));

  unsigned status = bme.begin(0x76);  // 0x76 => adresse de mon BME280
  if (!status) {
    Serial.println(
        "Could not find a valid BME280 sensor, check wiring, address, sensor "
        "ID!");
  }
  Serial.println();
#endif

#ifdef TESTBMP280
  Serial.println(F("BMP280 test"));

  unsigned status = bmp.begin(0x76);  // 0x76 => adresse de mon BME280
  if (!status) {
    Serial.println(
        "Could not find a valid BMP280 sensor, check wiring, address, sensor "
        "ID!");
  }
  Serial.println();
#endif
}

void loop() {
#ifdef TESTADRESSES
  testerAdresses();
#endif

#ifdef TESTBME280
  printValues();
#endif
#ifdef TESTBMP280
  printValuesBMP();
#endif
  delay(delayTime);
}

void printValuesBMP() {
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(F(" *C"));

  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(F(" Pa"));

  Serial.print(F("Altitude = "));
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(F(" m"));

  Serial.println();
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure = ");

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}

void testerAdresses() {
  byte error, address;  // variable for error and I2C address
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
}