#ifndef LIGHTS_H
#define LIGHTS_H

#include <FastLED.h>

#define DATA_PIN    9
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    4

#define BRIGHTNESS        20
#define FRAMES_PER_SECOND 120
#define BLINK_INTERVAL    400

static void show_lights();
static void blink_signal_light(int light);
static void blink_hazard_lights();
static void turn_on_light_range(int first, int last, CRGB::HTMLColorCode color);
static void turn_off_light_range(int first, int last);
static void rainbow_lights();

extern void setup_lights();
extern void run_lights(byte lights);

#endif
