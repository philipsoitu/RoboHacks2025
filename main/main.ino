// Pin Definitions
const int leftForwardPin = 2;
const int leftBackPin = 3;
const int rightForwardPin = 4;
const int rightBackPin = 5;
const int leftSpeedPin = 10;
const int rightSpeedPin = 11;
const int rightIRPin = 20;
const int leftIRPin = 21;
const int colorSensorPins[] = {15, 16, 17, 18, 19}; // Example color sensor pins

void setup() {
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
  
  // Set up color sensor pins
  for (int i = 0; i < 5; i++) {
    pinMode(colorSensorPins[i], INPUT);
  }

  Serial.begin(9600);  // Start Serial communication for debugging
}

void loop() {
  // Move both wheels at the same speed forward (small step)
  moveForward(100); // 100 for example speed
  
  // Check for obstacles
  if (digitalRead(rightIRPin) == HIGH) { // Obstacle detected on the right
    turnRight();
  }
  
  if (digitalRead(leftIRPin) == HIGH) { // Obstacle detected on the left
    turnLeft();
  }

  // Check color sensor
  String colorDetected = detectColor();  // Assume this function returns a string like "green" or "blue"
  Serial.println(colorDetected);
  
  if (colorDetected == "green") {
    // Go forward until no green detected, then stop
    moveForward(100);
    while (colorDetected == "green") {
      colorDetected = detectColor();
    }
    stopMotors();
    
    // Drop seed (assume there’s a function for this)
    dropSeed();
    
    // Go forward again
    moveForward(100);
  }

  if (colorDetected == "blue") {
    // Stop for 10 seconds
    stopMotors();
    delay(10000);
  }
}

void moveForward(int speed) {
  // Move both motors forward at the given speed
  analogWrite(leftSpeedPin, speed);
  analogWrite(rightSpeedPin, speed);
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void stopMotors() {
  // Stop both motors
  analogWrite(leftSpeedPin, 0);
  analogWrite(rightSpeedPin, 0);
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void turnRight() {
  // Turn right by moving only the left wheel forward
  analogWrite(leftSpeedPin, 100);
  analogWrite(rightSpeedPin, 0);
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

void turnLeft() {
  // Turn left by moving only the right wheel forward
  analogWrite(leftSpeedPin, 0);
  analogWrite(rightSpeedPin, 100);
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftBackPin, LOW);
  digitalWrite(rightBackPin, LOW);
}

String detectColor() {
  // Placeholder function to detect the color
  // Implement the color detection logic here
  // For now, we simulate it as returning a color
  int colorReading = analogRead(colorSensorPins[0]); // Example read from the color sensor
  if (colorReading > 500) {
    return "green";
  } else if (colorReading < 100) {
    return "blue";
  } else {
    return "none";
  }
}

void dropSeed() {
  // Placeholder function for dropping a seed
  // You would implement the seed dropping mechanism here
  Serial.println("Seed dropped!");
}
