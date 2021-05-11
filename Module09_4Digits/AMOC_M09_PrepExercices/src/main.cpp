#include <Arduino.h>
#include "Program.h"

Program* program = nullptr; 
void setup() {
  // put your setup code here, to run once:
  program = new Program();
}

void loop() {
  program->loop();
}