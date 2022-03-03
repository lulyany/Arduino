# 这是有关动态雕塑资料的整理指引

*步进电机型号：28BYJ48*

*主板型号：Arduino pro mini*

*Wifi模块型号:ESP8285-M3(淘宝)*

``` html
http://www.znjj.tv/product/60618.html
```

# sin-motor 文件夹

这是烧写到主板里直接运行，可用串口监测速度值，用Arduino IDE自带串口绘图工具可以看到三角函数图像

# Matric-motor 文件夹

连线注意代码里注释

是通过串口控制步进电机

- 指令格式：

时间+空格+模式 

time +‘ ’+ mode

e.g.

15 1

表示15秒后执行1模式 

- 模式

1. mode = 1

   三角函数（先逆时针后顺时针）

2. mode = 2

   全速逆时针

3. mode = 3 

   全速顺时针



# WiFi_motor

用电脑的网络调试助手向Wi-Fi模块发送指令。WiFi模块是透传模式。所以Arduino主办可以接收到原始指令。

- 用TCP发的时候指令前加#，后加&
- 依旧是时间+空格+模式 

即#指令$

e.g. 

#15 1$

# 备选通信方式

1. 无线，8266

2. 总线

   - I2C

     `https://www.aranacorp.com/en/manage-multiple-arduino-with-an-i2c-bus/`(vpn)

   - 
























