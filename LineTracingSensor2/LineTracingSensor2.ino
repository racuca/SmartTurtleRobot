int MotorLeft1 = 5;
int MotorLeft2 = 6;
int MotorRight1 = 10;
int MotorRight2 = 11;
const int SensorLeft = 7;
const int SensorCenter = 4;
const int SensorRight = 3;

int SL;
int SM;
int SR;


void go_direction(char a) {
  if (!(a == 'g' || a=='b' || a=='l' || a=='r' || a == 's')) {
   return; 
  }
  if (a == 'g') {
    // straight
    digitalWrite(MotorRight1, HIGH);
    digitalWrite(MotorRight2, LOW);   
    digitalWrite(MotorLeft1, HIGH);  // make the DC motor turn (right) clockwise
    digitalWrite(MotorLeft2, LOW);
  }
  else if (a == 'b') {
    // backwards
    digitalWrite(MotorRight1, LOW);
    digitalWrite(MotorRight2, HIGH);
    digitalWrite(MotorLeft1, LOW);
    digitalWrite(MotorLeft2, HIGH);
  }
  else if (a == 'r') {
  // turning left
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, HIGH/*LOW*/);
  digitalWrite(MotorLeft2, HIGH);
  }
  else if (a == 'l') {
    // turning left
    digitalWrite(MotorRight1, LOW);
    digitalWrite(MotorRight2, HIGH);
    digitalWrite(MotorLeft1, HIGH);
    digitalWrite(MotorLeft2, HIGH/*LOW*/);
  }
  else if (a == 's') {
    // stop
    digitalWrite(MotorRight1, HIGH);
    digitalWrite(MotorRight2, HIGH);
    digitalWrite(MotorLeft1, HIGH);
    digitalWrite(MotorLeft2, HIGH);
  }
}


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(MotorLeft1, OUTPUT);
  pinMode(MotorLeft2, OUTPUT);  
  pinMode(MotorRight1, OUTPUT);
  pinMode(MotorRight2, OUTPUT);
  pinMode(SensorLeft, INPUT);
  pinMode(SensorCenter, INPUT);
  pinMode(SensorRight, INPUT);
  
}


void loop() {
  delay(100);
  SL = digitalRead(SensorLeft);
  SM = digitalRead(SensorCenter);
  SR = digitalRead(SensorRight);
  Serial.print("L M R : ");
  Serial.print(SL);
  Serial.print(SM);
  Serial.println(SR);

  if (SM == HIGH) {  // middle sensor in black area
    Serial.println("middle in black");
    if (SL == LOW & SR == HIGH) {
      Serial.println("turn left");
      go_direction('l');
    }
    else if (SR == LOW & SL == HIGH) {
      Serial.println("turn right");
      go_direction('r');
    }
    else {
      Serial.println("go straight");
      /*digitalWrite(MotorRight1, LOW);
      digitalWrite(MotorRight2, HIGH);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorLeft2, HIGH);
      analogWrite(MotorLeft1, 200);
      analogWrite(MotorLeft2, 200);
      analogWrite(MotorRight1, 200);
      analogWrite(MotorRight2, 200);*/
      go_direction('g');
    }
  }
  else {
    Serial.println("middle in white");
    if (SL == LOW & SR == HIGH) {
      Serial.println("turn left");
      /*digitalWrite(MotorRight1, LOW);
      digitalWrite(MotorRight2, HIGH);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorLeft2, LOW);*/
      go_direction('l');
    }
    else if (SR == LOW & SL == HIGH) {
      Serial.println("turn right");
      /*digitalWrite(MotorRight1, LOW);
      digitalWrite(MotorRight2, LOW);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorLeft2, HIGH);*/
      go_direction('r');
    }
    else {
      Serial.println("stop");
      /*digitalWrite(MotorRight1, HIGH);
      digitalWrite(MotorRight2, LOW);
      digitalWrite(MotorLeft1, HIGH);
      digitalWrite(MotorLeft2, LOW);*/
      go_direction('g');
    }
  } 
}
