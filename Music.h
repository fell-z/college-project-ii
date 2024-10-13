#ifndef MUSIC_H
#define MUSIC_H

#include <NonBlockingSequence.h>

#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#define REST 0

#define TEMPO 90
// 60000 -> One minute in ms
#define SEMINIMA_IN_MS (60000 / TEMPO)

#define LENGTH(arr) sizeof(arr) / sizeof(arr[0])

extern int note_duration_in_ms();
extern bool play_note();
extern bool stop_note();
extern bool music_ended();
extern NonBlockingSequence newMusic();

#endif
