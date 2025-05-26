#include <Arduino.h>

#include "Program.h"

Program* program = nullptr;
void setup() {
  Serial.begin(9600);
  program = new Program();
}

void loop() {
  program->loop();
}
