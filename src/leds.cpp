#include "leds.h"

#ifdef ENABLE_LEDS

CRGB leds[FASTLED_LEDS];


#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN
byte rbpHue = 0;
bool rbpBlackout = false;
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
}

#endif // ENABLE_LEDS