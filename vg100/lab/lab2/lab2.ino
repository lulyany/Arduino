#include <Servo.h>

#define Motor1 12
#define Motor2 11
#define micro 9


void setup() {
  // put your setup code here, to run once:

pinMode(Motor1, OUTPUT); //to control the direction of the motor pinMode(Motor2, OUTPUT);
pinMode(Motor2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Motor1, LOW);
analogWrite(Motor2, 200); 
analogWrite (micro, 255);
delay(1000); 

}
