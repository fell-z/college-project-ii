/// @author fell-z  matheusfelipeagapito@hotmail.com
/// @brief  A implementation that grants movement and special moves to a 'Sumo Robot'
/// @note   A proper special move implementation has to be made yet

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

void setup()
{
  Serial.begin(9600);
  
  pinMode(REVERSE_LEFT, OUTPUT);
  pinMode(FORWARD_LEFT, OUTPUT);
  
  pinMode(REVERSE_RIGHT, OUTPUT);
  pinMode(FORWARD_RIGHT, OUTPUT);
}

void move_forward(void);
void move_backwards(void);
void left_steer(void);
void right_steer(void);
void stop_motors(void);

byte buffer[5];
int8_t movement = 0;
int8_t steer = 0;

void loop()
{
  if (Serial.available() > 0)
    Serial.readBytes(buffer, 5);

  movement = -(buffer[0]) + buffer[1];
  steer = -(buffer[2]) + buffer[3];

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