#define AP_SSID   "ABS-001" //这里改成你的设备当前环境下要连接的接入点名字
#define PASSWORD  "abs1234567890"         //这里改成你的设备当前环境下要连接的接入点密码
#define LOCAL_IP  "192.168.0.112"
#define PORT 8070

void setup()
{
  delay(5000);
  
  Serial.begin(115200);
  Serial.println();

  delay(500);
  Serial.print("AT+CWMODE=1\r\n");
  delay(10);
  
  Serial.print("AT+CWJAP=\"ABS-001\",\"abs1234567890\"\r\n");
  delay(10);
  
  Serial.print("AT+CIPMUX=0\r\n");
  delay(10);  

  Serial.print("AT+CIPMODE=1\r\n");
  delay(10); 

  Serial.print("AT+CIPSTART=\"TCP\",\"192.168.0.112\",8070\r\n");
  delay(10); 

//  Serial.print("AT+SAVETRANSLINK\r\n");
//  delay(10); 

  Serial.print("AT+CIPSEND\r\n");
  delay(10);
}

void loop() {
  }
