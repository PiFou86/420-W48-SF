#include <Arduino.h>

#include "Program.h"

Program* program;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  program = new Program();
}

void loop() {
  program->loop();
}

// void loop() {
 
// } 