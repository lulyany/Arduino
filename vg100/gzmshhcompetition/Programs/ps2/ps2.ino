#include <QGPMaker_MotorShield.hpp>
#include <PS2X_lib.h>
using namespace QGPMaker;
MotorShield shield;
DCMotor<M1> & pMotorRightBack = Motor0;//右后
DCMotor<M2> & pMotorRightFront = Motor1;//右前
DCMotor<M3> & pMotorLeftFront = Motor2;//左前
DCMotor<M4> & pMotorLeftBack = Motor3;//左后
Servo<0> & rotateServo = Servo0;
Servo<1> & catchServo = Servo1;
Servo<2> & liftServo = Servo2;
PS2X ps2x;

const uint8_t CLKPin = 13;
const uint8_t ATTPin = 10;
const uint8_t CMDPin = 11;
const uint8_t DATPin = 12;

void setup()
{
    shield.begin(50);
    int errorCode = 0xFF;
    while (errorCode != 0)
    {
        errorCode = ps2x.config_gamepad(CLKPin, ATTPin, CMDPin, DATPin);
        delay(50);
    }
    catchServo.writeDegrees(55);
}

void loop()
{
    ps2x.read_gamepad();
    delay(5);
    //马达
    if (ps2x.Button(PSB_PAD_UP))//直行
    {
        pMotorLeftFront.run(250,FORWARD);
        pMotorLeftBack.run(250,FORWARD);
        pMotorRightFront.run(250,FORWARD);
        pMotorRightBack.run(250,FORWARD);
    }
    else if (ps2x.Button(PSB_PAD_DOWN))//后退
    {
        pMotorLeftFront.run(250,BACKWARD);
        pMotorLeftBack.run(250,BACKWARD);
        pMotorRightFront.run(250,BACKWARD);
        pMotorRightBack.run(250,BACKWARD);
    }
    else if (ps2x.Button(PSB_PAD_LEFT))//左转
    {
      pMotorLeftFront.run(150,BACKWARD);
      pMotorLeftBack.run(150,BACKWARD);
      pMotorRightFront.run(150,FORWARD);
      pMotorRightBack.run(150,FORWARD);
    }
    else if (ps2x.Button(PSB_PAD_RIGHT))//右转
    {
      pMotorLeftFront.run(150,FORWARD);
      pMotorLeftBack.run(150,FORWARD);
      pMotorRightFront.run(150,BACKWARD);
      pMotorRightBack.run(150,BACKWARD);
    }
    //舵机
    else if (ps2x.Button(PSB_TRIANGLE))//舵机上下
    {
      if (liftServo.readDegrees() == 0)
        liftServo.writeDegrees(55);
      else if (liftServo.readDegrees() == 55)
        liftServo.writeDegrees(0);
    }
    else if (ps2x.Button(PSB_CROSS))//舵机抓取
    {
      if (catchServo.readDegrees() == 180)
        catchServo.writeDegrees(125);
      else if (catchServo.readDegrees() == 125)
        catchServo.writeDegrees(180);
    }
    else if (ps2x.Button(PSB_CIRCLE))//舵机转动
    {
      if (rotateServo.readDegrees() == 0)
        rotateServo.writeDegrees(90);
      else if (rotateServo.readDegrees() == 90)
        rotateServo.writeDegrees(0);
    }
    else
    {
      pMotorLeftFront.run(0,RELEASE);
      pMotorLeftBack.run(0,RELEASE);
      pMotorRightFront.run(0,RELEASE);
      pMotorRightBack.run(0,RELEASE);
    }

    delay(10);
}
