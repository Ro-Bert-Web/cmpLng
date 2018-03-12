#pragma config(Sensor, dgtl1,  rotation,       sensorQuadEncoder)
#pragma config(Motor,  port2,           arm,           tmotorVex393_MC29, openLoop)

/////////////////////////////////////////////
//-|-------------------------------------|-//
//-| Sample Code On The Mapping Function |-//
//-|-------------------------------------|-//
/////////////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){

	//Declare "goal" And "threshold", (The Distance From Goal That It Tries For)
	const int threshold = 60;
	int goal;

	while(1 == 1){

		//Set Goal To Joystick Channel 3
		goal = vexRT[Ch3];

		//Move The Arm To The Right Angle
		motor[arm] = map(SensorValue[rotation], goal - threshold, goal + threshold, 127, -127);
	}
}
