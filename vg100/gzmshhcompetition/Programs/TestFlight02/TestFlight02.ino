 #include <SoftwareSerial.h>
SoftwareSerial BT752(0,1);
 
 int IN1 = 4; 
 int IN2 = 5;
 int IN3 = 6;
 int IN4 = 7; 
 int IN5 = 8; 
 int IN6 = 9;
 int IN7 = 10;
 int IN8 = 11; 

 int count = 0;
int num[2];
int vall;
int cal;
int state=0;
boolean stp;

 void setup(){
 Serial.begin(38400);
 Serial1.begin(38400);
 pinMode (IN1, OUTPUT) ;
 pinMode (IN2, OUTPUT) ;
 pinMode (IN3, OUTPUT) ;
 pinMode (IN4, OUTPUT) ;
 pinMode (IN5, OUTPUT) ;
 pinMode (IN6, OUTPUT) ;
 pinMode (IN7, OUTPUT) ;
 pinMode (IN8, OUTPUT) ;
 Serial.println("BT is ready!");
 BT752.begin(38400);
 }

void run(int time)     
{
 digitalWrite(IN1, HIGH);  
 digitalWrite(IN2, LOW);  
 analogWrite(IN1, 255);
 analogWrite(IN2, 0);  
 digitalWrite(IN3, HIGH); 
 digitalWrite(IN4, LOW); 
 analogWrite(IN3, 255); 
 analogWrite(IN4, 0);
 digitalWrite(IN5, HIGH);  
 digitalWrite(IN6, LOW);  
 analogWrite(IN5, 255);
 analogWrite(IN6, 0);  
 digitalWrite(IN7, HIGH); 
 digitalWrite(IN8, LOW); 
 analogWrite(IN7, 255); 
 analogWrite(IN8, 0);
}

void brake(int time) 
{
 digitalWrite(IN1, LOW);  
 digitalWrite(IN2, LOW);  
 digitalWrite(IN3, LOW); 
 digitalWrite(IN4, LOW); 
 delay(time * 100);                
}
 
void loop()
{ 
  while(Serial.available()){
    vall = Serial.read();
    vall = Serial1.read();
    Serial.println(vall);
    Serial1.println(vall);
    num[count]=vall;
    count = count + 1;
      if(count>=3){
        count = 0;
        stp=true;
      }

    Serial.print("NUM[");
    Serial.print(count);
    Serial.print("]=");
    Serial.println(num[count]);
  }
run(5000); 
 
}
