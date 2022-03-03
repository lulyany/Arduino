#define red 3 
#define green 5
#define blue 6

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop(){
  for (int i =0; i <= 255;i++) 
  {
    analogWrite(red, i);
    delay(2000/250);
  }

   for (int i =255; i >=0;i--) { 
    analogWrite(red, i);
    delay(2000/250);
   }



 for (int i =0; i <= 255;i++) 
  {
    analogWrite(green, i);
    delay(2000/250);
  }

   for (int i =255; i >=0;i--) { 
    analogWrite(green, i);
    delay(2000/250);

   }

for (int i =0; i <= 255;i++) 
  {
    analogWrite(blue, i);
    delay(2000/250);
  }

   for (int i =255; i >=0;i--) { 
    analogWrite(blue, i);
    delay(2000/250);
}

}
