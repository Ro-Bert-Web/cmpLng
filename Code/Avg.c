#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)

////////////////////////////////////////////
//-|------------------------------------|-//
//-| Sample Code On The Average Function|-//
//-|------------------------------------|-//
////////////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int liftPosition;
	while(1 == 1){

		//Calculate The Position Of The Lift As Average Both Sides
		liftPosition = avg(SensorValue[leftEncoder], SensorValue[rightEncoder]);
	}
}
