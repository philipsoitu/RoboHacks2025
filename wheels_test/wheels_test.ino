// callibration constants
const int left_max = 150;
const int right_max = 150;
const int delayTime = 50;

// pinout constants
const int LEFT_SPEED = 10; // has to be pwm
const int LEFT_FORWARDS = 2;
const int LEFT_BACKWARDS = 3;
const int RIGHT_SPEED = 11; // has to be pwm
const int RIGHT_FORWARDS = 4;
const int RIGHT_BACKWARDS = 5;



// double throttlePercentage: 0 to 1
// double rotation: 0 to 1
// int direction: -1: left, 1: right
void turn_bloop(double throttlePercentage, double rotation, int direction)
{
  // Ensure direction is either -1 (left) or 1 (right)
  direction = (direction < 0) ? -1 : 1;

  // Calculate speed adjustments based on rotation and direction
  int leftSpeed = (int)(left_max * throttlePercentage * (1.0 - (rotation * (direction == -1))));
  int rightSpeed = (int)(right_max * throttlePercentage * (1.0 - (rotation * (direction == 1))));

  // Ensure speed values are within valid range (0 to max)
  leftSpeed = constrain(leftSpeed, 0, left_max);
  rightSpeed = constrain(rightSpeed, 0, right_max);

  // Apply speeds to motors
  analogWrite(LEFT_SPEED, leftSpeed);
  digitalWrite(LEFT_FORWARDS, HIGH);
  digitalWrite(LEFT_BACKWARDS, LOW);

  analogWrite(RIGHT_SPEED, rightSpeed);
  digitalWrite(RIGHT_FORWARDS, HIGH);
  digitalWrite(RIGHT_BACKWARDS, LOW);

  // Wait for movement
  delay(delayTime);

  // Stop motors after delay
  analogWrite(LEFT_SPEED, 0);
  digitalWrite(LEFT_FORWARDS, LOW);
  digitalWrite(LEFT_BACKWARDS, LOW);

  analogWrite(RIGHT_SPEED, 0);
  digitalWrite(RIGHT_FORWARDS, LOW);
  digitalWrite(RIGHT_BACKWARDS, LOW);
}



void setup()
{
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_FORWARDS, OUTPUT);
  pinMode(LEFT_BACKWARDS, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(RIGHT_FORWARDS, OUTPUT);
  pinMode(RIGHT_BACKWARDS, OUTPUT);
}

void loop()
{
//  forward_bloop(1.0);
//  delay(1000);
  turn_bloop(1.0, 0.5);
  delay(1000);
}
