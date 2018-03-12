#pragma config(Motor,  port2,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393_MC29, openLoop)

///////////////////////////////////////
//-|-------------------------------|-//
//-| Sample Code On Drive Commands |-//
//-|-------------------------------|-//
///////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){

	//Tells Competition Language what the names or ports the drive motors are in
	setDrive(leftFront, leftBack, rightFront, rightBack);

	//Configures the polarity of the drive (Reverses the right side)
	configDrive;

	while(1 == 1){

		//----------------------------------//
		//			Drive Commands Go Here			//
		//	Use One Of The Next 3 Commands	//
		//----------------------------------//

		//(How To Run Tank Drive)
		tankDrive(vexRT[Ch3], vexRT[Ch2]);

		//(How To Run Single Joystick)
		singleJoystick(vexRT[Ch3], vexRT[Ch1]);

		//(How To Run Holonomic Drive)
		straffDrive(vexRT[Ch3], vexRT[Ch4], vexRT[Ch1]);
	}
}
