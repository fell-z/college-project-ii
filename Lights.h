#ifndef LIGHTS_H
#define LIGHTS_H

#include <FastLED.h>

#define DATA_PIN    9
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    4

#define BRIGHTNESS        20
#define FRAMES_PER_SECOND 120

extern void setup_lights();
extern void turn_off_lights();
extern void update_lights();
extern void show_lights();

#endif
