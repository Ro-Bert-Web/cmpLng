////////////////////////////////////
//-|----------------------------|-//
//-| Sample Code On Query Speed |-//
//-|----------------------------|-//
////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int value, speed;

	while(1 == 1){

	//Initialize The Position Of Joystick Channel 3
	seedSpeed(vexRT[Ch3]);

	//Get The Speed Of Joystick Channel 3
	querySpeed(speed, vexRT[Ch3]);



	//Initialize The Value Of "value"
	seedSpeed(value);

	//--------------------------------//
	//	Change The Value Inside Here	//
	//--------------------------------//
	value *= value;

	//Get The Speed (Change / Time) Of "value"
	querySpeed(speed, value);
	}
}
