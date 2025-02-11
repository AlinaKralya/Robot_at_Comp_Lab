/*-----------------------------------------------------------------------------------------
Robot Code ARC Spring 2025
------------------------------------------------------------------------------------------*/
#include <Servo.h>

Servo Lpan;  
Servo Ltilt;
Servo Lelbow;
Servo Rpan;
Servo Rtilt;
Servo Relbow;

int LPval = 176, LTval = 35, LEval = 180, x = 0, RPval = 13, RTval = 117, REval = 2; // Start positions

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void wave() {
  Serial.println(10);

  for(; REval < 92, RPval < 103; REval++, RPval++){
    Relbow.write(REval);
    Rpan.write(RPval);
    delay(15);
    }
  for(; REval < 112, RPval < 123; REval++, RPval++){
    Relbow.write(REval);
    Rpan.write(RPval);
    delay(15);
    }
  for(int i = 0; i < 3; i++) {
    for(; RTval < 127; RTval++) {
      Rtilt.write(RTval);
      delay(20);
    }
    for(; RTval > 107; RTval--) {
      Rtilt.write(RTval);
      delay(20);
    }}
  for(; RTval < 117; RTval++) {
    Rtilt.write(RTval);
    delay(15);
  }
  for(; REval > 2, RPval > 13; REval--, RPval--){
    Relbow.write(REval);
    Rpan.write(RPval);
    delay(10);
    }
}
