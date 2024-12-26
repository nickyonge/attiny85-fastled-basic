#include "leds.h"

#ifdef ENABLE_LEDS

CRGB leds[FASTLED_LEDS];

#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN
byte rbpHue = 0;
bool rbpBlackout = false;
#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT
byte rbpLoopCount = 0;
#endif
#endif // DEBUG_RAINBOW_BLACKOUT_PATTERN

void setupLEDs()
{
    // prep LED strip via FastLED
    FastLED.addLeds<WS2812B, PIN_LED_DATA, GRB>(leds, FASTLED_LEDS);

#ifdef FASTLED_BRIGHTNESS
    FastLED.setBrightness(FASTLED_BRIGHTNESS);
#endif

#if defined(FASTLED_MAX_VOLTAGE) && defined(FASTLED_MAX_CURRENT_MA)
    FastLED.setMaxPowerInVoltsAndMilliamps(FASTLED_MAX_VOLTAGE, FASTLED_MAX_CURRENT_MA);
#endif

    // clear any residual data in the LED strip
    FastLED.clearData();

#ifdef SET_LEDS_RAINBOW_ON_START
    byte rainbowMultiplier = 255 / FASTLED_LEDS;
#else
#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN
    rbpBlackout = true; // if using debug pattern and non-rainbow start, invert so first pass is NOT blackout
#endif
#endif

    for (int i = 0; i < FASTLED_LEDS; i++)
    {
#ifdef SET_LEDS_RAINBOW_ON_START
        leds[i] = CRGB(CHSV(i * rainbowMultiplier, 255, 255));
#else
        leds[i] = CRGB::Black;
#endif
    }
    FastLED.show();
}
void loopLEDs()
{
#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN
#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT
    rbpLoopCount++;
    if (rbpLoopCount > DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT)
    {
        rbpLoopCount = 0;
        // rbpBlackout = !rbpBlackout; // entire loop cycle as black
    }
    rbpBlackout = rbpLoopCount == 0; // only black on loop cycle reset
#else
    rbpBlackout = !rbpBlackout;
#endif // DEBUG_RAINBOW_BLACKOUT_PATTERN_LOOPCOUNT
    for (int i = 0; i < NUM_LEDS; i++)
    {
        rbpHue += 7;
        delay(DEBUG_RAINBOW_BLACKOUT_PATTERN_DELAY); // note - this delay will screw with input smoothing
        leds[i] = rbpBlackout ? CRGB::Black : CRGB(CHSV(rbpHue, 255, 255));
        FastLED.show();
    }
#endif // DEBUG_RAINBOW_BLACKOUT_PATTERN
}

#endif // ENABLE_LEDS