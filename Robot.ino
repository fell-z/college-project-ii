/// @author fell-z  matheusfelipeagapito@hotmail.com
/// @brief  A implementation that grants movement and special moves to a 'Sumo Robot'
/// @note   A proper special move implementation has to be made yet

#include "Motors.h"
#include "Music.h"
#include "Lights.h"

#define BUZZER 12

void setup()
{
  Serial.begin(9600);
  
  pinMode(REVERSE_LEFT, OUTPUT);
  pinMode(FORWARD_LEFT, OUTPUT);
  
  pinMode(REVERSE_RIGHT, OUTPUT);
  pinMode(FORWARD_RIGHT, OUTPUT);

  setup_lights();
}

byte buffer[5];
int8_t movement = 0;
int8_t steer = 0;

NonBlockingSequence Music = newMusic();
bool music_playing = false;

void loop()
{
  if (Serial.available() > 0)
    Serial.readBytes(buffer, 5);

  movement = -(buffer[0]) + buffer[1];
  steer = -(buffer[2]) + buffer[3];

  run_motors(movement, steer);

  if (buffer[4] == 1)
    music_playing = true;
  
  if (music_playing) {
    Music.DoSequence();
    update_lights();

    if (music_ended()) {
      music_playing = false;
      turn_off_lights();
    }
    
    if (Music.Finish())
      Music.Restart();
  }

  show_lights();
}
