#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display = TM1637Display(CLK, DIO);

const uint8_t tousAllumes[] = {0xff, 0xff, 0xff, 0xff};
const uint8_t tousEteints[] = {0x00, 0x00, 0x00, 0x00};

const uint8_t fin[] = {
    SEG_A | SEG_E | SEG_F | SEG_G,  // F
    SEG_E,                          // i
    SEG_C | SEG_E | SEG_G,          // n
    SEG_B | SEG_C | SEG_DP          // !
};

// Create degree Celsius symbol:
const uint8_t celsius[] = {
    SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
    SEG_A | SEG_D | SEG_E | SEG_F   // C
};

void setup() {
  display.clear();
  display.setBrightness(7);
  delay(100);
}

void loop() {
  uint8_t unSegment[] = {0x0};
  uint8_t un =     0b00000110;
  uint8_t trois =  0b01001111;
  uint8_t quatre = 0b01100110;

  uint8_t pi[] = {
    trois | SEG_DP,
    un,
    quatre,
    un
  };
  display.setSegments(tousAllumes);
  delay(500);

  display.setSegments(tousEteints);
  delay(500);

  for (int intensite = 0; intensite < 8; intensite++) {
    display.setBrightness(intensite);
    display.setSegments(tousAllumes);
    delay(200);
  }

  for (uint8_t digit = 0; digit < 4; ++digit) {
    unSegment[0] = 1;

    for (uint8_t segment = 0; segment < 8; ++segment) {
      display.clear();
      display.setSegments(unSegment, 1, digit);
      unSegment[0] <<= 1;
      delay(200);
    }
  }

  display.showNumberDecEx(3141, 0b10000000);
  delay(5000);
  
  display.setSegments(pi, 4, 0);
  delay(5000);

  for (int valeur = -1200; valeur < 11000; ++valeur) {
    display.showNumberDec(valeur, true);
  }

  display.setSegments(fin);

  delay(5000);
}
