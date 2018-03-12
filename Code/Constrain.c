#pragma config(Motor,  port2,           flywheel,      tmotorVex393_MC29, openLoop)

///////////////////////////////////////////////
//-|---------------------------------------|-//
//-| Sample Code On The Constrain Function |-//
//-|---------------------------------------|-//
///////////////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	while(1 == 1){

		//Set The Motor To The Joystick Channel 3 Constrained Between -63 And 63
		motor[flywheel] = constrain(vexRT[Ch3], -63, 63);
	}
}
