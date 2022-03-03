#include "HUSKYLENS.h"
#include "SoftwareSerial.h"
int Trig=13;
int Echo=12;

float cm,temp;

HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);
long long timerf=millis(),timerl=millis(),timerr=millis();
int state=3;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
}

void loop() {
    digitalWrite(Trig, LOW); 
    delayMicroseconds(2);    
    digitalWrite(Trig,HIGH); 
    delayMicroseconds(10);    
    digitalWrite(Trig, LOW); 
  
    temp = float(pulseIn(Echo, HIGH));
    cm = (temp * 17 )/1000;
    //if (cm<50) {Serial.println("$DST!"); delay(1000);}
    /*else*/ if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()){ 
      if(state==3&&(millis()-timerf)>1250){
        Serial.println("$DGT:2-5,1!");
        timerf=millis();
        timerl=0;
        timerr=0;
      }
      else
      if(state==1&&(millis()-timerl)>1500){
        Serial.println("$DGT:6-9,1!");
        timerl=millis();
        timerr=0;
        timerf=0;
      }
      else
      if(state==2&&(millis()-timerr)>1500){
        Serial.println("$DGT:10-13,1!");
        timerr=millis();
        timerl=0;
        timerf=0;
      }
    }
    else
    {
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            //printResult(result);
            if (((state==3&&result.xCenter<=240&&result.xCenter>=80)||(state==1&&result.xCenter>=160)||(state==2&&result.xCenter<=160))&&(millis()-timerf)>1250) {
              Serial.println("$DGT:2-5,1!");
              timerf=millis();
              timerl=0;
              timerr=0;
              state=3;
            }
            else if ((state==1||result.xCenter<80)&&(millis()-timerl)>1500){
              Serial.println("$DGT:6-9,1!");
              timerl=millis();
              timerr=0;
              timerf=0;
              state=1;
            }
            else if ((state==2||result.xCenter>240)&&(millis()-timerr)>1500){
              Serial.println("$DGT:10-13,1!");
              timerr=millis();
              timerl=0;
              timerf=0;
              state=2;
            }
        }
    }
    delay(50);
}

/*
void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}
*/
