#include "Lights.h"

enum LIGHTS_MASK {
  HAZARD_LIGHT_BIT 	 = 0b0000100,
  CAR_LIGHT_BIT  		 = 0b0001000,
  LEFT_SIGNAL_BIT    = 0b0010000,
  RIGHT_SIGNAL_BIT   = 0b0100000,
	RAINBOW_LIGHTS_BIT = 0b1000000
};

enum LIGHTS {
	LEFT_CAR_LIGHT,
	RIGHT_CAR_LIGHT,
	RIGHT_SIGNAL_LIGHT,
	LEFT_SIGNAL_LIGHT
};

static CRGB leds[NUM_LEDS];

static uint8_t hue = 0;
static uint8_t delta_hue = 7;

void setup_lights()
{
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void run_lights(byte lights)
{
	if (lights & RAINBOW_LIGHTS_BIT) {
		rainbow_lights();
		show_lights();

		return;
	}
  else {
    turn_off_light_range(LEFT_CAR_LIGHT, LEFT_SIGNAL_LIGHT);
  }

	if (lights & HAZARD_LIGHT_BIT) {
		turn_on_light_range(LEFT_CAR_LIGHT, LEFT_SIGNAL_LIGHT, CRGB::Yellow);
		show_lights();

		return;
	}
  else {
    turn_off_light_range(LEFT_CAR_LIGHT, LEFT_SIGNAL_LIGHT);
  }

	if (lights & CAR_LIGHT_BIT) {
		turn_on_light_range(LEFT_CAR_LIGHT, RIGHT_CAR_LIGHT, CRGB::PowderBlue);
	}
	else {
		turn_off_light_range(LEFT_CAR_LIGHT, RIGHT_CAR_LIGHT);
	}

	leds[RIGHT_SIGNAL_LIGHT] = (lights & RIGHT_SIGNAL_BIT) ? CRGB::Yellow : CRGB::Black;
	leds[LEFT_SIGNAL_LIGHT] = (lights & LEFT_SIGNAL_BIT) ? CRGB::Yellow : CRGB::Black;

	show_lights();
}

static void show_lights()
{
  EVERY_N_MILLISECONDS(1000/FRAMES_PER_SECOND) { FastLED.show(); }
}

static void turn_on_light_range(int first, int last, CRGB::HTMLColorCode color)
{
	fill_solid(&(leds[first]), last + 1, color);
}

static void turn_off_light_range(int first, int last)
{
	fill_solid(&(leds[first]), last + 1, CRGB::Black);
}

static void rainbow_lights()
{
  fill_rainbow(leds, NUM_LEDS, hue, delta_hue);  
  EVERY_N_MILLISECONDS(20) { hue++; }
}
