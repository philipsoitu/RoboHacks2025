// calibration
const int LEFT_MAX = 150;
const int RIGHT_MAX = 150;
const int MOTOR_DELAY_TIME = 50;

// Pin Definitions
const int leftForwardPin = 2;
const int leftBackPin = 3;
const int rightForwardPin = 4;
const int rightBackPin = 5;
const int leftSpeedPin = 10;
const int rightSpeedPin = 11;

const int rightIRPin = 7;
const int leftIRPin = 8;

const int S0 = 14;
const int S1 = 15;
const int S2 = 16;
const int S3 = 17;
const int sensorOut = 18;

void setup()
{
  // Set up motor pins
  pinMode(leftForwardPin, OUTPUT);
  pinMode(leftBackPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackPin, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  // Set up IR sensor pins
  pinMode(rightIRPin, INPUT);
  pinMode(leftIRPin, INPUT);

  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600); // Start Serial communication for debugging
}

void loop()
{
  // Move both wheels at the same speed forward (small step)
  moveForward(100); // 100 for example speed

  // Check for obstacles
  if (digitalRead(rightIRPin) == HIGH)
  { // Obstacle detected on the right
    turnRight();
  }

  if (digitalRead(leftIRPin) == HIGH)
  { // Obstacle detected on the left
    turnLeft();
  }

  // Check color sensor
  String colorDetected = detectColor(); // Assume this function returns a string like "green" or "blue"
  Serial.println(colorDetected);

  if (colorDetected == "green")
  {
    // Go forward until no green detected, then stop
    moveForward(100);
    while (colorDetected == "green")
    {
      colorDetected = detectColor();
    }
    stopMotors();

    // Drop seed (assume there’s a function for this)
    dropSeed();

    // Go forward again
    moveForward(100);
  }

  if (colorDetected == "blue")
  {
    // Stop for 10 seconds
    stopMotors();
    delay(10000);
  }
}

void moveForward(int speed)
{
  // Move both motors forward at the given speed
  analogWrite(leftSpeedPin, speed);
  analogWrite(rightSpeedPin, speed);
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void stopMotors()
{
  // Stop both motors
  analogWrite(leftSpeedPin, 0);
  analogWrite(rightSpeedPin, 0);
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void turnRight()
{
  // Turn right by moving only the left wheel forward
  analogWrite(leftSpeedPin, 100);
  analogWrite(rightSpeedPin, 0);
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void turnLeft()
{
  // Turn left by moving only the right wheel forward
  analogWrite(leftSpeedPin, 0);
  analogWrite(rightSpeedPin, 100);
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

String getColor() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // RED : 32 - 75
  redColor = map(redFrequency, 32, 75, 255,0);
  
  // Printing the RED (R) value
  // Serial.print("R = ");
  // Serial.print(redColor);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // GREEN: 48 - 91
  greenColor = map(greenFrequency, 48, 91, 255, 0);
  
  // Printing the GREEN (G) value  
  // Serial.print(" G = ");
  // Serial.print(greenColor);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);

  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // BLUE VALUES: 29 - 78
  blueColor = map(blueFrequency, 29, 78, 255, 0);
  
  // Printing the BLUE (B) value 
  // Serial.print(" B = ");
  // Serial.print(blueColor);
  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor && redColor > blueColor){
      return "RED";
  }
  if(greenColor > redColor && greenColor > blueColor){
    return "GREEN";
  }
  if(blueColor > redColor && blueColor > greenColor){
    return "BLUE";
  }
}

void dropSeed()
{
  // Placeholder function for dropping a seed
  // You would implement the seed dropping mechanism here
  Serial.println("Seed dropped!");
}
