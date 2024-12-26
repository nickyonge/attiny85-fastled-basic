#include <main.h>

void setup()
{

#ifdef ENABLE_LEDS
    delay(SETUP_STEP_DELAY);
    setupLEDs();
#endif // ENABLE_LEDS

    delay(SETUP_FINISH_DELAY);
}

void loop()
{

#ifdef ENABLE_LEDS
    loopLEDs();
#endif

    delay(LOOP_DELAY_INTERVAL);
}