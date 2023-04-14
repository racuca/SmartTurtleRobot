int pinI1 = 5;
int pinI2 = 6;
//int speedpin = 3;
int pinI3 = 10;
int pinI4 = 11;
//int speedpin1 = 9;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pinI1, OUTPUT);
  pinMode(pinI2, OUTPUT);
  //pinMode(speedpin, OUTPUT);
  pinMode(pinI3, OUTPUT);
  pinMode(pinI4, OUTPUT);
  //pinMode(speedpin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char a = Serial.read();
  if (!(a == 'g' || a=='b' || a=='l' || a=='r' || a == 's')) {
   return; 
  }
  delay(1000);
  Serial.println(a);
  if (a == 'g') {
    // straight
    //analogWrite(speedpin, 150);
    //analogWrite(speedpin1, 150);
    digitalWrite(pinI3, HIGH);
    digitalWrite(pinI4, LOW);   
    digitalWrite(pinI1, HIGH);  // make the DC motor turn (right) clockwise
    digitalWrite(pinI2, LOW);
    delay(2000);
  }
  else if (a == 'b') {
    // backwards
    //analogWrite(speedpin, 150);
    //analogWrite(speedpin1, 150);
    digitalWrite(pinI3, LOW);
    digitalWrite(pinI4, HIGH);
    digitalWrite(pinI1, LOW);
    digitalWrite(pinI2, HIGH);
    delay(2000);
  }
  else if (a == 'r') {
  // turning left
  //analogWrite(speedpin, 60);
  //analogWrite(speedpin1, 60);
  digitalWrite(pinI3, HIGH);
  digitalWrite(pinI4, LOW);
  digitalWrite(pinI1, LOW);
  digitalWrite(pinI2, HIGH);
  delay(2000);
  }
  else if (a == 'l') {
    // turning left
    //analogWrite(speedpin, 100);
    //analogWrite(speedpin1, 100);
    digitalWrite(pinI3, LOW);
    digitalWrite(pinI4, HIGH);
    digitalWrite(pinI1, HIGH);
    digitalWrite(pinI2, LOW);
    delay(2000);
  }
  else if (a == 's') {
    // stop
    digitalWrite(pinI4, HIGH);
    digitalWrite(pinI3, HIGH);
    digitalWrite(pinI1, HIGH);
    digitalWrite(pinI2, HIGH);
    delay(2000);
  }
}
