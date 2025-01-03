#ifndef MAIN_H
#define MAIN_H

#define ENABLE_LEDS // is LED system enabled?

#include <Arduino.h>

#include "leds.h"

// delay, in ms, between each step of setup
#define SETUP_STEP_DELAY 1
// delay, in ms, after setup() has complete, before beginning loop() 
#define SETUP_FINISH_DELAY 20

// duration, in ms, at the end of each `loop()` cycle in `main.h` 
#define LOOP_DELAY_INTERVAL 5

void setup();
void loop();

#endif // MAIN_H