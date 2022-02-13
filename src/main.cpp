#include <Arduino.h>

#include "Program.h"

Program* program = nullptr;

void setup(void) {
	program = new Program();
}

void loop(void) {
  program->loop();
}