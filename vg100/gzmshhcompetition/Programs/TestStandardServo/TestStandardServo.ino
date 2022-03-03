/*#include <Servo.h>
Servo servo;*/
 int ServoPin = 2;
/*int posOfServo = 90;
int servoDir = 10;
int servoTarget = 90;
int every1 = 15;*/
void setup() {
   Serial.begin(9600);
 pinMode (ServoPin, OUTPUT) ;
}

 void servo1(int angle) { 
    for(int i=0;i<50;i++){
    int pulsewidth = (angle * 11) + 500; 
    digitalWrite(ServoPin, HIGH);   
    delayMicroseconds(pulsewidth);  
    digitalWrite(ServoPin, LOW);    
    delayMicroseconds(20000 - pulsewidth);
      delay(100);
  }
 }


void loop() {
servo1(0);

}

/*void setup(){
  servo.attach(ServoPin,500,2500);
  Serial.begin(9600);
  servo.write(posOfServo);
  delay(500);
}

void loop(){
  static uint32_t Timer;
  if (Timer > millis())
    return;
  Timer = millis() + every1;
  if (posOfServo > 179)
    servoTarget = 0;
  if (posOfServo < 1)
    servoTarget = 180;
  
  if (posOfServo < servoTarget)
    posOfServo += servoDir;
  else if (posOfServo == servoTarget)
    return;
  else
    posOfServo -= servoDir;
  servo.write(posOfServo);
}*/
