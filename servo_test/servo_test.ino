#include <Servo.h>

Servo myServo;
const int servoPin = 2;

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");
    myServo.attach(servoPin);
}

void loop() {
    for (int pos = 0; pos <= 180; pos += 1) {
        myServo.write(pos);
//        Serial.print("Moving to: ");
//        Serial.println(pos);
        delay(15);
    }

    for (int pos = 180; pos >= 0; pos -= 1) {
        myServo.write(pos);
//        Serial.print("Moving to: ");
//        Serial.println(pos);
        delay(15);
    }
}
