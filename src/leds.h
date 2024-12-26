#ifndef LEDS_H
#define LEDS_H

#include "main.h"

#ifdef ENABLE_LEDS

#include <FastLED.h>
#include "pindef.h"

// number of LEDs in the LED strip
#define FASTLED_LEDS 22
// should LEDs only be updated when a change in RGB value is detected?
#define ONLY_UPDATE_LEDS_ON_CHANGE true
// if true, assigns rainbow colors on start
#define SET_LEDS_RAINBOW_ON_START true
// if true, use rainbow blackout pattern to test LEDs
#define DEBUG_RAINBOW_BLACKOUT_PATTERN false
// if > 0, only update this number of LEDs
#define DEBUG_LED_LOOP_UPDATE_LIMIT 0

// -------------------------------------------- DEFINITION VALIDATION CHECKS ---
#if defined(FASTLED_LEDS) && FASTLED_LEDS + 0 <= 0
#undef FASTLED_LEDS // check for valid definition (`true` or x > 0)
#endif
#if defined(ONLY_UPDATE_LEDS_ON_CHANGE) && ONLY_UPDATE_LEDS_ON_CHANGE + 0 <= 0
#undef ONLY_UPDATE_LEDS_ON_CHANGE // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN) && DEBUG_RAINBOW_BLACKOUT_PATTERN + 0 <= 0
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_LED_LOOP_UPDATE_LIMIT) && DEBUG_LED_LOOP_UPDATE_LIMIT + 0 <= 0
#undef DEBUG_LED_LOOP_UPDATE_LIMIT // check for valid definition (`true` or x > 0)
#endif
#if defined(SET_LEDS_RAINBOW_ON_START) && SET_LEDS_RAINBOW_ON_START + 0 <= 0
#undef SET_LEDS_RAINBOW_ON_START // check for valid definition (`true` or x > 0)
#endif

// number of LEDs to update in `loopLEDs`, respecting any debugging
const int NUM_LEDS =
#ifdef DEBUG_LED_LOOP_UPDATE_LIMIT
    DEBUG_LED_LOOP_UPDATE_LIMIT;
#elif defined(FASTLED_LEDS)
    FASTLED_LEDS;
#else
    0;
#endif

void setupLEDs();
void loopLEDs();

#endif // ENABLE_LEDS

#endif // LEDS_H