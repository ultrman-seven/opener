#include"beep.h"
void rightBeep(void)
{
	music(DO);
	delay(BEEP_DELAY);
	music(RE);
	delay(BEEP_DELAY);
	music(MI);
	delay(BEEP_DELAY);
}

void wrongBeep(void)
{
	music(MI);
	delay(BEEP_DELAY);
	music(RE);
	delay(BEEP_DELAY);
	music(DO);
	delay(BEEP_DELAY);
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