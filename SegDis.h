#ifndef __SEGDIS_H__
#define __SEGDIS_H__
#include"common.h"

#define SEG P0
#define VISUAL_TIME 200
#define ERR_DIS 400
#define ERR_TWINKLE 20000
#define INICIAL_SEG SEG = 0x00;

sbit in_hc138_0 = P2 ^ 2;
sbit in_hc138_1 = P2 ^ 3;
sbit in_hc138_2 = P2 ^ 4;

void print(char* input);
void error(void);
#endif // !__SEGDIS_H__