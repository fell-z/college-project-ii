#include "Motors.h"

enum PINS {
  REVERSE_LEFT = 4,
  FORWARD_LEFT,
  REVERSE_RIGHT,
  FORWARD_RIGHT
};

enum MOVEMENTS_MASK {
  STOP_BIT         = 0b0000,

  FORWARD_BIT      = 0b0001,
  REVERSE_BIT      = 0b0010,
  ROTATE_LEFT_BIT  = 0b0100,
  ROTATE_RIGHT_BIT = 0b1000,
};

void setup_motors()
{
  pinMode(REVERSE_LEFT, OUTPUT);
  pinMode(FORWARD_LEFT, OUTPUT);
  pinMode(REVERSE_RIGHT, OUTPUT);
  pinMode(FORWARD_RIGHT, OUTPUT);
}

void run_motors(byte movement)
{
  if (movement == STOP_BIT)
    stop_motors();

  if (movement & FORWARD_BIT)
    forward();
  else if (movement & REVERSE_BIT)
    reverse();

  if (movement & ROTATE_LEFT_BIT)
    rotate_left();
  else if (movement & ROTATE_RIGHT_BIT)
    rotate_right();
}

void combo()
{
  rotate_left();
  delay(1500);
  stop_motors();

  reverse();
  delay(500);
  stop_motors();

  rotate_right();
  delay(1500);
  stop_motors();
}

static void forward()
{
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
}

static void reverse()
{
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);
}

static void rotate_left()
{
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(FORWARD_RIGHT, HIGH);
}

static void rotate_right()
{
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);
}

static void stop_motors()
{
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);
}
