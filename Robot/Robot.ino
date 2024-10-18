/// @author fell-z  matheusfelipeagapito@hotmail.com
/// @brief  A implementation that grants movement and special moves to a 'Sumo Robot'
/// @note   A proper special move implementation has to be made yet

#include "Motors.h"
#include "Music.h"
#include "Lights.h"

void setup()
{
  Serial.begin(9600);
  
  setup_motors();
  setup_music();
  setup_lights();
}

enum ACTIONS_MASK {
  HORN_BIT  = 0b0000001,
  COMBO_BIT = 0b0000010,
};

byte buffer[2];
byte movement; // movement spans up to 4 bits
byte action;   // action spans up to 7 bits

void loop()
{
  if (Serial.available() > 0)
    Serial.readBytes(buffer, 2);

  movement = buffer[0];
  action = buffer[1];

  run_motors(movement);

  if (action & HORN_BIT) {
    set_playing(true);
    action = bitSet(action, 6);
  }
  else {
    set_playing(false);
    action = bitClear(action, 6);
  }
  
  if (music_playing()) {
    play_music();
  }

  run_lights(action);
}
