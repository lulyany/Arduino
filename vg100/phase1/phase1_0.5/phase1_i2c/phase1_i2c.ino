#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);

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

    pinMode(E1, OUTPUT);
    pinMode(M1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(M2, OUTPUT);
    pinMode(3,OUTPUT);
    analogWrite(E1, 50);
    digitalWrite(M1,HIGH);
    analogWrite(E2, 50);
    digitalWrite(M2,HIGH);
    digitalWrite(3,HIGH);//light
    
    //delay(5000);//delete before gameday!
}

void loop() {
    if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
              digitalWrite(E1,LOW);
              digitalWrite(E2,LOW);
//            HUSKYLENSResult result = huskylens.read();
//            printResult(result);
        }    
    }
}

//void printResult(HUSKYLENSResult result){
//    if (result.command == COMMAND_RETURN_BLOCK){
//        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
//    }
//    else if (result.command == COMMAND_RETURN_ARROW){
//        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
//    }
//    else{
//        Serial.println("Object unknown!");
//    }
//}
