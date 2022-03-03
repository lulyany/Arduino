//使用arduino IDE自带的Stepper.h库文件
//注意28BYJ-48为减速电机所以速度不会很快
//具体引脚不写了看图片吧
#include <Stepper.h>
#include <Math.h>
// 这里设置步进电机旋转一圈是多少步
#define PI 3
#define STEPS 100
#define Speed 500
//设置步进电机的步数和引脚（就是注意点2里面说的驱动板上IN1～IN4连接的四个数字口）。
Stepper stepper(STEPS, 4, 6, 5, 7); //引脚要互换

void setup()
{
    // 设置电机的转速：每分钟为*步
    stepper.setSpeed(Speed);
    // 初始化串口，用于调试输出信息,串口监视器调成一半波特率
    Serial.begin(9600);
}
void loop() {
    float t = 0.1; 
    int v = 0;
    //t = (PI / 2);
    while (t < PI)
    {
        // 顺时针旋转
        v = int (Speed * sin(t));
        stepper.setSpeed(v);
        stepper.step(72); //4步模式下旋转一周用2048 步。
        Serial.println(v);
        t += 0.1;
        //delay(50);
    }
    //delay(500);
    while (t > 0)
    {
        // 逆时针旋转
        v = int (Speed * sin(t));
        stepper.setSpeed(v);
        stepper.step(-72); //4步模式下旋转一周用2048 步。
        Serial.println(-v);
        t -= 0.1;
        //delay(50);
    }
    //delay(500);
}
