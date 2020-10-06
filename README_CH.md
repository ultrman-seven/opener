# 开门器
C51

使用stc单片机搭建密码锁开门系统。
输入密码正确则控制步进电机运转，完成开门动作，一段时间后，步进电机反转，解开门。
输入密码错误则数码管显示error。

# steppedMotor.c 和 motor.h
控制五线四相步进电机的代码。

！！！！步进电机初始化INICIAL_MOTO（存放于motor.h）！！一定要写在main里，防止电机烧坏！！！！！

一个函数控制电机运行，其中参数direction控制旋转方向，forward正转，opposite反转。
具体见注释

# LED Segment Displays.c 和 SegDis.h
控制数码管的代码

void print(char* input)
将输入显示在数码管上。

void error(void)
密码输入错误时的显示。

# common.h
自定义变量类型和延时函数

# doorOpen.h
main函数和矩阵按键控制

bit matButton(void)
在有按键按下时，函数返回真并将全局变量value的值置为按键对应数值

main中，首先电机初始化和数码管初始化，尤其是电机初始化！因为该芯片io口默认输出高电平，经uln2003将步进电机所有线圈一直导通，会烧坏电机！！！！！
在有按键按下时，进行switch，0-9为输入对应数字，10为退位（backspace），11为全部清空，12为确认密码。
