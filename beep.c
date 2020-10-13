#include"beep.h"
void rightBeep(void)
{
	music(DO);
	music(RE);
	music(MI);
}

void wrongBeep(void)
{
	music(MI);
	music(RE);
	music(DO);
}

void music(un8 tone)
{
	un8 time;
	for (time = BEEP_TIME; time; time--)
	{
		bep = 0;
		delay(tone);
		bep = 1;
		delay(tone);
	}
}