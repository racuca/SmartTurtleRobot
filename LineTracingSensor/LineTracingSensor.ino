const int sensorPin = 2;
const int ledPin = 13;
int sensorState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorState = digitalRead(sensorPin);

  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
