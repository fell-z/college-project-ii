/// @author fell-z  matheusfelipeagapito@hotmail.com
/// @brief  A implementation that grants movement and special moves to a 'Sumo Robot'
/// @note   the code is a WIP as for the current iteration

void setup()
{
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);
}

byte buffer[5];

void loop()
{
  if (Serial.available() > 0)
    Serial.readBytes(buffer, 5);

  if (buffer[4] == 1)
    digitalWrite(8, HIGH);
  else if (buffer[4] == 0)
    digitalWrite(8, LOW);
}
