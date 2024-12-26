#include "leds.h"

#ifdef ENABLE_LEDS

CRGB leds[FASTLED_LEDS];

#ifdef ONLY_UPDATE_LEDS_ON_CHANGE
CRGB lastRGB;
#endif

#ifdef DEBUG_RAINBOW_BLACKOUT_PATTERN
byte rbpHue = 0;
bool rbpBlackout = false;
#endif // DEBUG_RAINBOW_BLACKOUT_PATTERN

void setupLEDs()
{
    // prep LED strip via FastLED
    FastLED.addLeds<WS2812B, PIN_LED_DATA, GRB>(leds, FASTLED_LEDS);

    // prep initial RGB value
#ifdef ONLY_UPDATE_LEDS_ON_CHANGE
    lastRGB = CRGB::White;
#endif

    // clear any residual data in the LED strip
    FastLED.clearData();

#ifdef SET_LEDS_RAINBOW_ON_START
    byte rainbowMultiplier = 255 / FASTLED_LEDS;
#endif

    for (int i = 0; i < FASTLED_LEDS; i++)
    {
#ifdef SET_LEDS_RAINBOW_ON_START
        leds[i] = CRGB(CHSV(i * rainbowMultiplier, 255, 32));
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