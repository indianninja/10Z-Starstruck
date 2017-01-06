#pragma config(Motor,  port1,           Lift1,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LF,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Lift2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           Lift3,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           Lift4,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RF,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          Lift5,         tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
void lift (int pwr)
{
	motor[Lift1] = motor[Lift2] = motor[Lift3] = motor[Lift4] = motor[Lift5] = pwr;
}

void claw (int pwr)
{
	motor[Claw] = pwr;
}
task DriveControl()
{
	int x = 0; //strafe
	int y = 0; //forward+back
	int r = 0; //rotate
	while (1)
	{
		x = vexRT[Ch4];
		y = vexRT[Ch3];
		r = vexRT[Ch1];

		motor[LF] = r + x + y;
		motor[LB] = r - x + y;
		motor[RF] = r + x - y;
		motor[RB] = r - x - y ;

		wait1Msec(20);
	}
}
task LiftControl()
{
	while (1)
	{
		if (vexRT[Btn5U])
		{
			lift(127);
		}
		else if (vexRT[Btn5D])
		{
			lift (-127);
		}
		else
		{
			lift(0);
		}

		if (vexRT[Btn6U])
		{
			claw(127);
		}
		else if (vexRT[Btn6D])
		{
			claw(-127);
		}
		else
		{
			claw(0);
		}
	}
}

void driveY (int pwr);

void driveX (int pwr);

void turn (int pwr);

void pre_auton()
{

}



task autonomous()
{

}



task usercontrol()
{
	startTask(DriveControl);
	startTask(LiftControl);
	while (1)
	{
			wait1Msec(20);
	}
}
