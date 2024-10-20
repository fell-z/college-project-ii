#include "Music.h"

const uint16_t notes[] = {
  REST, NOTE_D5, REST, NOTE_E5, REST,
  NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_D5, REST, NOTE_E5, REST, NOTE_C5,
  NOTE_A4, NOTE_G4, NOTE_G4,

  REST, REST, NOTE_A5, REST, NOTE_A5, REST,
  NOTE_A5, REST, NOTE_A5, REST, NOTE_G5,

  REST, NOTE_C5, REST, NOTE_A4,
  NOTE_A4, NOTE_G4, NOTE_G4,
};

const int8_t durations[] = {
  1, 2, 1, 2, 1,
  -1, 2, 1, 1,
  1, 2, 1, 2, 1,
  1, 1, 1,

  1, 1, 1, 2, 1, 2,
  1, 2, 1, 2, 1,
  1, 1, 2, 1,
  1, 1, 1,
};

static NonBlockingSequence Music;
static int i_note = 0;
static bool playing = false;

static int note_duration_in_ms()
{
  int duration_in_ms = (SEMINIMA_IN_MS) / durations[i_note];

  if (durations[i_note] < 0) {
    duration_in_ms *= 1.5;
  }

  return abs(duration_in_ms);
}

static bool play_note()
{
  tone(BUZZER, notes[i_note], note_duration_in_ms() * 0.8);

  return true;
}

static bool stop_note()
{
  noTone(BUZZER);

  if (i_note < LENGTH(notes) - 1)
    i_note++;
  else
    i_note = 0;
  
  return true;
}

static bool is_final_note()
{
	return (i_note == 0);
}

void setup_music()
{
  Music.AddNewStep(&play_note);
  Music.AddDelayInMillis(note_duration_in_ms());
  Music.AddNewStep(&stop_note);
}

void play_music()
{
  if (music_playing()) {
    Music.DoSequence();

    if (is_final_note())
      playing = false;
    
    if (Music.Finish())
      Music.Restart();
  }
}

void set_playing(bool state)
{
  // in case horn stops, loops back to start
  if (state == false) {
    i_note = 0;
    Music.Restart();
  }

  playing = state;
}

bool music_playing()
{
  return playing;
}

