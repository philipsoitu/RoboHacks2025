#define SENSOR_PIN 5  // Connect OUT pin to D2

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(SENSOR_PIN);
  if (sensorState == HIGH) {
    Serial.println("Obstacle Detected!");  // Some modules output LOW when detecting an object
  } else {
    Serial.println("No Obstacle.");
  }
  delay(500);
}
