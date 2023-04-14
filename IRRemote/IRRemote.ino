#include <IRremote.h>

int RECV_PIN= 11;
int errorcount = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();    
  }
  else {
    Serial.println(errorcount++);
  }
  delay(1000);
}
