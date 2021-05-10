#include <Arduino.h>
#include "Program.h"

Program* program = nullptr;
void setup() {
  program = new Program();
}

void loop() {
  program->loop();
}