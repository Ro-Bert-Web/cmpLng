#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)

///////////////////////////////////////////
//-|-----------------------------------|-//
//-| Sample Code On The Step Functions |-//
//-|-----------------------------------|-//
///////////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	float decimal = 3.1415926535;
	int roundUp, roundDown;
	roundUp = flr(decimal);
	roundDown = cel(decimal);
}
