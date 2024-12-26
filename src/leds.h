#ifndef LEDS_H
#define LEDS_H

#include "main.h"

#ifdef ENABLE_LEDS

#include <FastLED.h>
#include "pindef.h"

// number of LEDs in the LED strip
#define FASTLED_LEDS 22
// global brightness FastLED will use, if > 0
#define FASTLED_BRIGHTNESS 100
// max voltage FastLED will use, if > 0, and `FASTLED_MAX_CURRENT_MA` is also > 0
#define FASTLED_MAX_VOLTAGE 5
// max current in mA FastLED will use, if > 0, and `FASTLED_MAX_VOLTAGE` is also > 0
#define FASTLED_MAX_CURRENT_MA 250
// if true, assigns rainbow colors on start
#define SET_LEDS_RAINBOW_ON_START false
// if true, use rainbow blackout pattern to test LEDs
#define DEBUG_RAINBOW_BLACKOUT_PATTERN true
// delay interval between LEDs in rainbow blackout pattern (will interfere with input smoothing)
#define DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY 10
// how many loops between LEDs rainbow pattern and blackout
#define DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT 3
// if > 0, only update this number of LEDs
#define DEBUG_LED_LOOP_UPDATE_LIMIT 0

// -------------------------------------------- DEFINITION VALIDATION CHECKS ---
#if defined(FASTLED_LEDS) && FASTLED_LEDS + 0 <= 0
#undef FASTLED_LEDS // check for valid definition (`true` or x > 0)
#endif
#if defined(FASTLED_BRIGHTNESS) && FASTLED_BRIGHTNESS + 0 <= 0
#undef FASTLED_BRIGHTNESS // check for valid definition (`true` or x > 0)
#endif
#if defined(FASTLED_MAX_VOLTAGE) && FASTLED_MAX_VOLTAGE + 0 <= 0
#undef FASTLED_MAX_VOLTAGE // check for valid definition (`true` or x > 0)
#endif
#if defined(FASTLED_MAX_CURRENT_MA) && FASTLED_MAX_CURRENT_MA + 0 <= 0
#undef FASTLED_MAX_CURRENT_MA // check for valid definition (`true` or x > 0)
#endif
#if defined(FASTLED_MAX_VOLTAGE) && !defined(FASTLED_MAX_CURRENT_MA)
#undef FASTLED_MAX_VOLTAGE // cannot have voltage without current
#endif
#if defined(FASTLED_MAX_CURRENT_MA) && !defined(FASTLED_MAX_VOLTAGE)
#undef FASTLED_MAX_CURRENT_MA // cannot have current without voltage
#endif
#if defined(ONLY_UPDATE_LEDS_ON_CHANGE) && ONLY_UPDATE_LEDS_ON_CHANGE + 0 <= 0
#undef ONLY_UPDATE_LEDS_ON_CHANGE // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN) && DEBUG_RAINBOW_BLACKOUT_PATTERN + 0 <= 0
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY) && DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY + 0 <= 0
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT) && DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT + 0 <= 1
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT // check for valid definition (`true` or x > 0)
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY) && !defined(DEBUG_RAINBOW_BLACKOUT_PATTERN)
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY // can't have delay without pattern
#endif
#if defined(DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT) && !defined(DEBUG_RAINBOW_BLACKOUT_PATTERN)
#undef DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT // can't have loopcount without pattern
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