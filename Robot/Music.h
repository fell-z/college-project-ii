#ifndef MUSIC_H
#define MUSIC_H

#include <NonBlockingSequence.h>

#define BUZZER 12

#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#define REST 0

#define TEMPO 180
// 60000 -> One minute in ms
#define SEMINIMA_IN_MS (60000 / TEMPO)

#define LENGTH(arr) sizeof(arr) / sizeof(arr[0])

static int note_duration_in_ms();
static bool play_note();
static bool stop_note();
static bool is_final_note();

extern void setup_music();
extern void play_music();
extern void set_playing(bool state);
extern bool music_playing();

#endif
