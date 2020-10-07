#include"motor.h"
void stepperMotor(un16 circle,bit direction)//circle 转的圈数，direction 转动方向
{
	circle *= 256;
	if(direction)
		while (circle--)
		{
			//通电顺序：AB-B-BC-C-CD-D-DA-A-

			motoA = motoB = 1;
			delay(SPEED);
			//AB-

			motoA = 0;
			delay(SPEED);
			//B-

			motoC = 1;
			delay(SPEED);
			//BC-

			motoB = 0;
			delay(SPEED);
			//C-

			motoD = 1;
			delay(SPEED);
			//CD-

			motoC = 0;
			delay(SPEED);
			//D-

			motoA = 1;
			delay(SPEED);
			//DA-

			motoD = 0;
			delay(SPEED);
			//A-
		}
	else
		while (circle--)
		{
			//AD-D-DC-C-CB-B-BA-A-

			motoA = motoD = 1;
			delay(SPEED);
			//AD-

			motoA = 0;
			delay(SPEED);
			//D-

			motoC = 1;
			delay(SPEED);
			//DC-

			motoD = 0;
			delay(SPEED);
			//C-

			motoB = 1;
			delay(SPEED);
			//CB-

			motoC = 0;
			delay(SPEED);
			//B-

			motoA = 1;
			delay(SPEED);
			//BA-

			motoB = 0;
			delay(SPEED);
			//A-
		}
	motoA = motoB = motoC = motoD = 0;//防止烧坏
}