#ifndef __BEEP_H__
#define __BEEP_H__
#include"common.h"
#define DO 10
#define RE 20
#define MI 30
#define PRESS 15
#define BEEP_TIME 1000
sbit bep = P1 ^ 4;

void rightBeep(void);
void wrongBeep(void);
void music(un8);
#endif // !__BEEP_H__
