#ifndef MOTORS_H
#define MOTORS_H

void run_motors(int8_t movement, int8_t steer);
void move_forward();
void move_backwards();
void left_steer();
void right_steer();
void stop_motors();

#endif
