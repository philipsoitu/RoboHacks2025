// Define L298N Pins for Arduino Nano
#define LEFT_SPEED 5   // (D2)
#define LEFT_DIR1 6    // (D3)
#define LEFT_DIR2 7    // (D4)
#define RIGHT_SPEED 8  // (D5)
#define RIGHT_DIR1 9   // (D6)
#define RIGHT_DIR2 10  // (D7)

/************************************************/
/* direction: true - forward, false - backward  */
/* speed:     0 - 255                           */
/************************************************/
void left_motor_control(bool direction, int speed) {
  digitalWrite(LEFT_DIR1, direction ? HIGH : LOW);
  digitalWrite(LEFT_DIR2, direction ? LOW : HIGH);
  analogWrite(LEFT_SPEED, speed);
}


void left_motor_stop() {
  digitalWrite(LEFT_DIR1, LOW);
  digitalWrite(LEFT_DIR2, LOW);
  analogWrite(LEFT_SPEED, 0);
}

/************************************************/
/* direction: true - forward, false - backward  */
/* speed:     0 - 255                           */
/************************************************/
void right_motor_control(bool direction, int speed) {
  digitalWrite(RIGHT_DIR1, direction ? HIGH : LOW);
  digitalWrite(RIGHT_DIR2, direction ? LOW : HIGH);
  analogWrite(RIGHT_SPEED, speed);
}

void right_motor_stop() {
  digitalWrite(RIGHT_DIR1, LOW);
  digitalWrite(RIGHT_DIR2, LOW);
  analogWrite(RIGHT_SPEED, 0);
}

void setup() {
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_DIR1, OUTPUT);
  pinMode(LEFT_DIR2, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(RIGHT_DIR1, OUTPUT);
  pinMode(RIGHT_DIR2, OUTPUT);
}

void loop() {
  // Move Forward
  left_motor_control(true, 150);
  right_motor_control(true, 150);
  delay(2000);

  // Stop
  left_motor_stop();
  right_motor_stop();
  delay(1000);

  // Move Backward
  left_motor_control(false, 150);
  right_motor_control(false, 150);
  delay(2000);
}
