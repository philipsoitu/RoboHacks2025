#define RIGHT_IR_PIN 21  // right
#define LEFT_IR_PIN 20 // left 

void setup() {
  pinMode(RIGHT_IR_PIN, INPUT);
  pinMode(LEFT_IR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorStateRight = digitalRead(RIGHT_IR_PIN);
  int sensorStateLeft = digitalRead(LEFT_IR_PIN);
  // Right sensor
  if (sensorStateRight == 0) {
    Serial.println("RIGHT object detected!");  // Some modules output LOW when detecting an object
  } else {
    Serial.println("RIGHT nothing.");
  }

  // Left sensor
    if (sensorStateLeft == 0) {
    Serial.println("LEFT object detected!");  // Some modules output LOW when detecting an object
  } else {
    Serial.println("LEFT nothing.");
  }
  delay(500);
}
