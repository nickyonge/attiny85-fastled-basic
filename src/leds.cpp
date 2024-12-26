#include "leds.h"

#ifdef ENABLE_LEDS

CRGB leds[FASTLED_LEDS];

void setupLEDs()
{
    // prep LED strip via FastLED
    FastLED.addLeds<WS2812B, PIN_LED_DATA, GRB>(leds, FASTLED_LEDS);

}
void loopLEDs()
{
}

#endif // ENABLE_LEDS