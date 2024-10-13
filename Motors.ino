#include "Motors.h"

enum PINS {
  REVERSE_LEFT = 4,
  FORWARD_LEFT,
  REVERSE_RIGHT,
  FORWARD_RIGHT,
};

enum DIRECTIONS {
  FORWARD = -1,
  BACKWARDS = 1,
  LEFT_STEER = -1,
  RIGHT_STEER = 1
};

void run_motors(int8_t movement, int8_t steer)
{
  if (movement == FORWARD)
    move_forward();
  else if (movement == BACKWARDS)
    move_backwards();
  else
    stop_motors();

  if (steer == LEFT_STEER)
    left_steer();
  else if (steer == RIGHT_STEER)
    right_steer();
  else
    stop_motors();
}

void move_forward(void)
{
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
}

void move_backwards(void)
{
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);
}

void left_steer(void)
{
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
}

void right_steer(void)
{
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);
}

void stop_motors(void)
{
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);
}
