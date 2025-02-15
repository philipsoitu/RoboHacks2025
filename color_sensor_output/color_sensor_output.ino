// Define sensor pins
#define S0 8         // D5
#define S1 9         // D6
#define S2 10        // D7
#define S3 11        // D8
#define sensorOut 12 // D9

unsigned int redFreq = 0;
unsigned int greenFreq = 0;
unsigned int blueFreq = 0;

void setup() {
    // Set pin modes
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    // Set frequency scaling to 20% (S0 HIGH, S1 LOW)
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    Serial.begin(9600);
}

void loop() {
    // Read RED frequency
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    redFreq = pulseIn(sensorOut, LOW);

    // Read GREEN frequency
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenFreq = pulseIn(sensorOut, LOW);

    // Read BLUE frequency
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueFreq = pulseIn(sensorOut, LOW);

    // Map frequencies to RGB values (inverse relationship)
    int redValue = map(redFreq, 100, 3000, 255, 0);
    int greenValue = map(greenFreq, 100, 3000, 255, 0);
    int blueValue = map(blueFreq, 100, 3000, 255, 0);

    // Ensure RGB values are within the 0-255 range
    redValue = constrain(redValue, 0, 255);
    greenValue = constrain(greenValue, 0, 255);
    blueValue = constrain(blueValue, 0, 255);

    // Print RGB values to Serial Monitor
    Serial.print("R: ");
    Serial.print(redValue);
    Serial.print(" G: ");
    Serial.print(greenValue);
    Serial.print(" B: ");
    Serial.println(blueValue);

    delay(500);  // Wait before next reading
}
