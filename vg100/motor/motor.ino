//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int M1 = 4;    //M1 Direction Control

void setup() {
pinMode(E1, OUTPUT); 
pinMode(M1, OUTPUT);
Serial.println("Run keyboard control");
}

void loop() {
  analogWrite(M1, 255);
  
  digitalWrite(E1,HIGH);
  Serial.println("Run keyboard control");
}
