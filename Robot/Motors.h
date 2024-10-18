#ifndef MOTORS_H
#define MOTORS_H

static void forward();
static void reverse();
static void rotate_left();
static void rotate_right();
static void stop_motors();

extern void setup_motors();
extern void run_motors(byte movement);

#endif
