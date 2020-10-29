# opener
C51

using STC MCU to open the door.
Input the right password and then the door opened due to the operation of the stepper motor is triggered. If the password is wrong， the digital tube would display "Error".

## steppedMotor.c and motor.h
codes about controlling five-wire four-phase stepper motor.

!!!MAKE SURE THAT YOU PUT 'INITIAL_MOTO' IN 'main', or your motor would be burned.

Only one function to control the motor, the direction in controled by the parameter 'direction'.

## LED Segment Displays.c and SegDis.h
codes about controlling digital tube.

void print(char* input) 
it will display what you've input.
void error(void)
it will display "Error" in the 2ed,3th,4th,5th,6th tube.

## common.h
un8 and un16.
the function delay.

## doorOpen.h
main and codes about keys.

bit matButton(void)

while the key is pressed, the function will return true and give the value which key represent to 'value'.

in 'main', firstly initialize the digit tube and the motor, especially the motor!!! especially the motor!!! especially the motor!!!
<!--hhhhhhh>
<--!
hhhh
-->
<!--
hhh
>