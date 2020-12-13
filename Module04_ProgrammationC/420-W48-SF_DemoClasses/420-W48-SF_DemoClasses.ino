#include "Flasher.h"
#include "AnimationLed.h"

const int pinDel = 13;
Flasher flasherLent(pinDel, 500);
Flasher flasherRapide(pinDel, 100);
void setup() {
  pinMode(pinDel, OUTPUT);
}

void loop() {
  animerLed(pinDel);

  
  flasherLent.FaireClignoter(5);
  flasherRapide.FaireClignoter(25);
  delay(1);
}
