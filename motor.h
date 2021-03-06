#ifndef __MOTOR_H__
#define __MOTOR_H__
#include"common.h"
#define SPEED 90
#define FORWARD 1
#define OPPOSITE 0
#define CIRCLE 5

sbit motoA = P1 ^ 4;
sbit motoB = P1 ^ 5;
sbit motoC = P1 ^ 6;
sbit motoD = P1 ^ 7;

#define INICIAL_MOTO motoA=motoB=motoC=motoD=0;
void stepperMotor(un16 circle, bit direction);
#endif // !__MOTOR_H__
