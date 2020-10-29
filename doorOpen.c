#include"SegDis.h"
#include"motor.h"
#include"beep.h"
#define KEY P3
#define OPENTIME 19
sbit LED_GREEN = P1 ^ 1;
sbit LED_RED = P1 ^ 2;
un8 value = 0;
un8 time = 0;
un8 second = 0;
//char password[9] = { 7,3,5,5,6,0,8,-1,-2 };
char code password[9] = { 1,1,2,3, 5,8,1,1, -2 };
char code c4[9] = { 7,3,5,5, 6,0,8, -1, -2 };
char code hwh[9] = { 2,0,0,1, 0,8,2,8 ,-2 };
char code qdy[9] = { 3,4,8, 1,1,1,1, -1, -2};

void timerOpen(void)
{
	EA = 1;
	ET0 = 1;
	TMOD = 0x01;
	//定时50ms
	TL0 = 0xb0;
	TH0 = 0x3c;

	TF0 = 0;
	TR0 = 1;
}

void timeInterrupt(void) //interrupt 1
{
	TL0 = 0xb0;
	TH0 = 0x3c;

	TF0 = 0;
	if (time < 20)
		time++;
	else
	{
		time = 0;
		if (second < OPENTIME)
			second++;
		else
			second = TR0 = 0;
	}
	countDown(second);
}

void main()
{
	bit matButton(void);
	bit checkPassword(char*,char*);
	void rightPassword(void);
	void wrongPassword(void);
	char display[9] = { -1,-1,-1,-1,    -1,-1,-1,-1 ,-2};
	char* input = display;
	INICIAL_SEG
	INICIAL_MOTO
		bep = 0;
	LED_RED = 0;
	while (1)
	{
		if (matButton())//输入为13进制最多8位
			switch (value)
			{
			case 13://退位
				input--;
				*input = -1;
				break;
			case 14://清空
				for (input = display; *input != -2; input++)
					*input = -1;
				input = display;
				break;
			case 15://确认
				if (checkPassword(display,password) || checkPassword(display,hwh) || checkPassword(display,qdy) || checkPassword(display,c4))
					rightPassword();
				else
					wrongPassword();
				for (input = display; *input != -2; input++)
					*input = -1;
				input = display;
				break;
			default://0-13为输入数字
				if (*input != -2)
				{
					*input = value;
					input++;
				}
				break;
			}
		print(display);
	}
}

bit checkPassword(char* input,char* pas)
{
	while (*input != -2 && *input++ == *pas++)
		;
	return (*input == -2) ? 1 : 0;
}
void rightPassword(void)
{
	un16 timeWait = 500;
	LED_RED = 1;
	LED_GREEN = 0;
	rightBeep();
	timerOpen();
	stepperMotor(CIRCLE, FORWARD);
	while (timeWait--)
		delay(1000);
	stepperMotor(CIRCLE, OPPOSITE);
	LED_RED = 0;
	LED_GREEN = 1;
	INICIAL_SEG
}
void wrongPassword(void)
{
	un16 time;
	wrongBeep();
	for (time = ERR_DIS; time--;)
		error();
	delay(ERR_TWINKLE);
	for (time = ERR_DIS; time--;)
		error();
}

bit matButton(void)
{
	void delay(un16);
	char findZero(un8);

	KEY = 0x0f;
	if (KEY != 0x0f)
	{
		delay(1000);
		if (KEY != 0x0f)
		{
			value = findZero(KEY);
			KEY = 0xf0;
			value += (4 * findZero(KEY / 0x10));
			while (KEY != 0xf0)
			{
				bep = 1;
				delay(PRESS);
				bep = 0;
				delay(PRESS);
			}
			return 1;
		}
	}
	return 0;
}
char findZero(un8 n)
{
	char count;
	for (count = 0; n % 2; n /= 2)
		count++;
	return count;
}
void delay(un16 time)
{
	while (time--);
}