#include"SegDis.h"
#include"motor.h"
#include"beep.h"
#define KEY P3
sbit LED_GREEN = P1 ^ 1;
sbit LED_RED = P1 ^ 2;
un8 value = 0;
//char password[9] = { 7,3,5,5,6,0,8,-1,-2 };
char code password[9] = { 1,1,2,3, 5,8,1,1, -2 };
char code c4[9] = { 7,3,5,5, 6,0,8, -1, -2 };
char code hwh[9] = { 2,0,0,1, 0,8,2,8 ,-2 };
char code qdy[9] = { 3,4,8, 1,1,1,1, -1, -2};

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
	un8 time = 500;
	LED_RED = 1;
	LED_GREEN = 0;
	rightBeep();
	stepperMotor(CIRCLE, FORWARD);
	while (time--)
		delay(1000);
	stepperMotor(CIRCLE, OPPOSITE);
	LED_RED = 0;
	LED_GREEN = 1;
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