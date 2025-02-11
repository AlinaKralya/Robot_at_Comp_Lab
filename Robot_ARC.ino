//-----------------------------------------------------------------------------------------
//Robot Code ARC Spring 2025
//-----------------------------------------------------------------------------------------
#include <Servo.h>

//Initializing all of the Servos
//------------------------------
//Left side
Servo Lpan;
Servo Ltilt;
Servo Lelbow;

//Right side
Servo Rpan;
Servo Rtilt;
Servo Relbow;
//------------------------------

//Pins for the servos
const int Lpan_pin = 2;
const int Ltilt_pin = 3;
const int Lelbow_pin = 4;

const int Rpan_pin = 5;
const int Rtilt_pin = 6;
const int Relbow_pin = 7;

//Initial positions
int LPval = 176, LTval = 35, LEval = 180;
int RPval = 13, RTval = 117, REval = 2;

//Functions
void wave();


//--------------------------------------MAIN-BODY------------------------------------------

void setup() {
  
  Serial.begin(115200); //for test purposes

  //Attach servos to the Board 1
  Lpan.attach(Lpan_pin);
  Ltilt.attach(Ltilt_pin);
  Lelbow.attach(Lelbow_pin);

  Rpan.attach(Rpan_pin);
  Rtilt.attach(Rtilt_pin);
  Relbow.attach(Relbow_pin);

  //Set servos to their starting positions
  Lpan.write(LPval);
  Ltilt.write(LTval);
  Lelbow.write(LEval);
  
  Rpan.write(RPval);
  Rtilt.write(RTval);
  Relbow.write(REval);
  
}

void loop() {
  //TEST on Serial Console
  Serial.println("Left side positions:\nLpan - " + String(LPval) + "\nLtilt - " + String(LTval) + "\nLelbow - " + String(LEval)
  + "\n\nRight side positions:\nRpan - " + String(RPval) + "\nRtilt - " + String(RTval) + "\nRelbow - " + String(REval));

  delay(500); //how long it waits until run loop once again (milliseconds)

}

//------------------------------------------FUNCTIONS-------------------------------------
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
