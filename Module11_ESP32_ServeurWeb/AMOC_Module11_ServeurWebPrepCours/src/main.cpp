#include <Arduino.h>

#include "Program.h"

Program* program;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  program = new Program();
}

// https://tttapa.github.io/ESP8266/Chap11%20-%20SPIFFS.html
void loop() {
  // void loop(void) {
  //   server.handleClient();
  // }

  program->loop();
}

void configurerServeurWeb() {}