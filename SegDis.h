#ifndef __SEGDIS_H__
#define __SEGDIS_H__
#include"common.h"
#include<intrins.h>
#define SEG P0
#define SEG_BIT P2
#define VISUAL_TIME 200
#define ERR_DIS 150
#define ERR_TWINKLE 50000
#define INICIAL_SEG SEG = 0xff;

//sbit in_hc138_0 = P2 ^ 2;
//sbit in_hc138_1 = P2 ^ 3;
//sbit in_hc138_2 = P2 ^ 4;

void print(char* input);
void error(void);
void countDown(un8 time);
#endif // !__SEGDIS_H__