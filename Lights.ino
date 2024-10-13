#include "Lights.h"

CRGB leds[NUM_LEDS];

static uint8_t g_hue = 0;
static uint8_t g_delta_hue = 7;

void setup_lights()
{
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void turn_off_lights()
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
}

void update_lights()
{
  fill_rainbow(leds, NUM_LEDS, g_hue, g_delta_hue);  
  EVERY_N_MILLISECONDS(20) { g_hue++; }
}

void show_lights()
{
  FastLED.delay(1000/FRAMES_PER_SECOND);
  FastLED.show();
}
