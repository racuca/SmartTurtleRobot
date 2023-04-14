#define echoPin 4
#define trigPin 7
#define ledPin 13
int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration / 58.2;
  if (distance >= maximumRange || distance <= minimumRange) {
    Serial.println("-1");
    digitalWrite(ledPin, HIGH);
  }
  else {
    Serial.println(distance);
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
