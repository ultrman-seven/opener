#include"SegDis.h"
un8 dis_num[] = { 0x3f,0x06, 0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,/*0-9*/
							0x77,0x7c,0x58, 0x5e, 0x79,0x71,/*a-f*/		0x80/*.*/ };
un8 disError[] = { 0,0x79,0x50,0x50,0x5c,0x50,0 };
//void hc138(un8 n)
//{
//	if (0 <= n && n <= 7)
//	{
//		in_hc138_0 = n % 2;
//		n /= 2;
//		in_hc138_1 = n % 2;
//		n /= 2;
//		in_hc138_2 = n % 2;
//	}
//}

void print(char* input)
{
	un8 total = 0;
	un8 count;
	while (input[total] >= 0)
		total++;
	count = total - 1;
	while (total--)
	{
		SEG_BIT = _crol_(0x01,count - total);//hc138(count - total);
		SEG = ~dis_num[input[total]];
		delay(VISUAL_TIME);
		SEG = 0xff;
	}
}

void error(void)
{
	un8 count;
	for ( count = 1; count < 7; count++)
	{
		SEG_BIT = _crol_(0x01,count);//hc138(count);
		SEG = ~disError[7 - count];
		delay(VISUAL_TIME);
		SEG = 0xff;
	}
}