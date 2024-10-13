#include "Music.h"

const uint16_t notes[] = {
  REST, NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_G3, NOTE_B3,
  REST, NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_G3, NOTE_B3,

  REST, REST,
  NOTE_G3, NOTE_G3, NOTE_FS3, NOTE_FS3,
  NOTE_E3, NOTE_E3, NOTE_D3
};

// TODO: Make it accept negative values to represent dotted notes.
const uint8_t durations[] = {
  4, 4, 4, 4,
  2, 2,
  4, 4, 4, 4,
  2, 2,

  2, 4,
  4, 4, 4, 4,
  4, 4, 1
};

static int i_note = 0;

// TODO: Adapt to use abs() for dotted notes.
int note_duration_in_ms()
{
  return (SEMINIMA_IN_MS) / durations[i_note];
}

bool play_note()
{
  tone(BUZZER, notes[i_note], note_duration_in_ms() * 0.9);

  return true;
}

bool stop_note()
{
  noTone(BUZZER);

  if (i_note < LENGTH(notes) - 1)
    i_note++;
  else
    i_note = 0;
  
  return true;
}

bool music_ended()
{
	return (i_note == 0);
}

NonBlockingSequence newMusic()
{
  NonBlockingSequence Music;

  Music.AddNewStep(&play_note);
  Music.AddDelayInMillis(note_duration_in_ms());
  Music.AddNewStep(&stop_note);

  return Music;
}
