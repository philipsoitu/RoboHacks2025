#include <Servo.h>

Servo myServo;
const int servoPin = 2;

void setup()
{
    Serial.println("Initializing...");
    myServo.attach(servoPin);
}

void loop()
{
    myServo.write(10);
    myServo.write(-10);
    delay(2000)
}
