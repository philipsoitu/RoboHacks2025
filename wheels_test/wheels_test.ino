const int OUT1 = 2;
const int OUT2 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
}

void loop() {

  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  delay(1000);
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  delay(1000);
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);  
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  delay(1000);
}
