#pragma config(Sensor, dgtl1,  piston,         sensorDigitalOut)
#pragma config(Sensor, dgtl2,  button,         sensorTouch)

//////////////////////////////////////////
//-|----------------------------------|-//
//-| Sample Code On Actuator Commands |-//
//-|----------------------------------|-//
//////////////////////////////////////////

#include "Competition Language.c"

task main(){

	//These all extend the actuator named "piston"
	extendActuator(piston);
	setActuator(piston, true);
	setActuator(piston, 1);

	//These all retracts the actuator named "piston"
	retractActuator(piston);
	setActuator(piston, false);
	setActuator(piston, 0);

	//Sets the actuator named "piston" to the value of a button (pressed = out)
	setActuator(piston, SensorValue[button]);
}
