int input1=5; // 定义uno的pin 5 向 in1 输出   
int input2=6; // 定义uno的pin 6 向 in2 输出  
int input3=3; // 定义uno的pin 9 向 in3 输出  
int input4=4; // 定义uno的pin 10 向 in4 输出  
 
void setup() {  
Serial.begin (9600);  
//初始化各IO,模式为OUTPUT 输出模式  
pinMode(input1,OUTPUT);  
pinMode(input2,OUTPUT);  
pinMode(input3,OUTPUT);  
pinMode(input4,OUTPUT);    
}
 
void loop(){  
  //forward 向前转  
 digitalWrite(input1,HIGH); //给高电平  
 digitalWrite(input2,LOW);  //给低电平  
 digitalWrite(input3,HIGH); //给高电平  
 digitalWrite(input4,LOW);  //给低电平  
 delay(1000);   //延时1秒  
 
 //stop 停止  
 digitalWrite(input1,LOW);  
 digitalWrite(input2,LOW);    
 digitalWrite(input3,LOW);  
 digitalWrite(input4,LOW);    
 delay(500);  //延时0.5秒  
    
//back 向后转  
 digitalWrite(input1,LOW);  
 digitalWrite(input2,HIGH);    
 digitalWrite(input3,LOW);  
 digitalWrite(input4,HIGH);    
 delay(1000);      
} 
