#include"SegDis.h"
#include"motor.h"

un8 value = 0;
char password[9] = { 7,3,5,5,6,0,8,-1,-2 };

void main()
{
	bit matButton(void);
	bit checkPassword(char*);
	void rightPassword(void);
	void wrongPassword(void);
	char display[9] = { -1,-1,-1,-1,    -1,-1,-1,-1 ,-2};
	char* input = display;
	INICIAL_SEG
	INICIAL_MOTO
	while (1)
	{
		if (matButton())
			switch (value)
			{
			case 10://��λ
				input--;
				*input = -1;
				break;
			case 11://���
				for (input = display; *input != -2; input++)
					*input = -1;
				input = display;
				break;
			case 12://ȷ��
				if (checkPassword(display))
					rightPassword();
				else
					wrongPassword();
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				break;
			case 16:
				break;
			default:
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

bit checkPassword(char* input)
{
	char* pas = password;
	while (*input != -2 && *input++ == *pas++)
		;
	return (*input == -2) ? 1 : 0;
}
void rightPassword(void)
{
	un8 time = 200;
	stepperMotor(CIRCLE, FORWARD);
	while (time--)
		delay(5000);
	stepperMotor(CIRCLE, OPPOSITE);
}
void wrongPassword(void)
{
	un16 time;
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

	P1 = 0x0f;
	if (P1 != 0x0f)
	{
		delay(1000);
		if (P1 != 0x0f)
		{
			value = 3 - findZero(P1);
			P1 = 0xf0;
			value += (4 * findZero(P1 / 0x10));
			while (P1 != 0xf0)
				delay(1000);
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