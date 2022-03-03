//使用arduino IDE自带的Stepper.h库文件
//注意28BYJ-48为减速电机所以速度不会很快
#include <Stepper.h>
#include <Math.h>

#define PI 3
#define STEPS 100 // 这里设置步进电机旋转一圈是多少步
#define Speed 500

//设置步进电机的步数和引脚（4，6，5，7分别对应IN1～IN4连接的四个数字口）. 引脚要互换
Stepper stepper(STEPS, 4, 6, 5, 7);

//定义的函数
void serial_check();
void run_motor(int time_motor, int mode_motor);
void run_motor_1(int time_motor, int mode_motor);
void run_motor_2(int time_motor, int mode_motor);
void run_motor_3(int time_motor, int mode_motor);

//初始化
void setup()
{
    delay(15000);
    
    // 设置电机的转速：每分钟为*步
    stepper.setSpeed(Speed);
    // 初始化串口，用于调试输出信息,串口监视器调成一半波特率
    Serial.begin(115200);
    Serial.println("请输入指令:"); 
}


int data[2];

//主函数
void loop()
{
    while (Serial.available() > 0){
      serial_check();
      int time_main = data[0]; 
      int mode_main = data[1];
      //Serial.println(time_main);//要删去
      run_motor(time_main, mode_main);
      Serial.println("指令已完成");
    }
    //Serial.println("请输入指令");
}


//读取串口，处理数据：提取数据，转换类型
void serial_check(){
    String comdata = "";
    while (Serial.available() > 0)
    {
        comdata += char(Serial.read());
        delay(2);
    }
    if (comdata.length() > 0)
    {
        int index = 0;
        for (int i = 0; i<=comdata.length();i++){
          if (comdata[i]==' ') {
            index = i;
            break;
          }
        }
        
        String stime; String smode;
        stime = comdata.substring(index_command_begin+1,index-index_command_begin-1);
        smode = comdata.substring(index+1,index_command_end-index-1);
        
        int itime = stime.toInt();
        int imode = smode.toInt(); 
        
        Serial.println("您输入了：");
        Serial.print(itime);
        Serial.print(' ');
        Serial.println(imode);

        data[0] = itime;
        data[1] = imode;
        
        comdata = "";
    }
}

//判断mode
void run_motor(int time_motor, int mode_motor){
  if(mode_motor==1){
    delay(time_motor);
    run_motor_1(time_motor, mode_motor);
    }
  if(mode_motor==2){
    delay(time_motor);
    run_motor_2(time_motor, mode_motor);
    }
  if(mode_motor==3){
    delay(time_motor);
    run_motor_3(time_motor, mode_motor);
    }
}

//模式1
void run_motor_1(int time_motor, int mode_motor){
        float t = 0.1;
        int v = 0;
        while (t < PI)
        {
            // 顺时针旋转
            v = int(Speed * sin(t));
            stepper.setSpeed(v);
            stepper.step(72); //4步模式下旋转一周用2048 步。
            t += 0.1;
        }

        while (t > 0)
        {
            // 逆时针旋转
            v = int(Speed * sin(t));
            stepper.setSpeed(v);
            stepper.step(-72); //4步模式下旋转一周用2048 步。
            t -= 0.1;
        }
}

//模式2
void run_motor_2(int time_motor, int mode_motor){
        float t = 0.1;
        int v = 0;
        while (t < PI)
        {
            // 顺时针旋转
            v = int(Speed);
            stepper.setSpeed(v);
            stepper.step(72); //4步模式下旋转一周用2048 步。
            t += 0.1;
        }
}

//模式3
void run_motor_3(int time_motor, int mode_motor){
        float t = 0.1;
        int v = 0;
        while (t < PI)
        {
            // 顺时针旋转
            v = int(Speed);
            stepper.setSpeed(v);
            stepper.step(-72); //4步模式下旋转一周用2048 步。
            t += 0.1;
        }
}
