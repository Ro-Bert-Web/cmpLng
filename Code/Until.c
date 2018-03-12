#pragma config(Sensor, dgtl1,  led1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  led2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  button,         sensorTouch)

//////////////////////////////////////
//-|------------------------------|-//
//-| Sample Code On Until Command |-//
//-|------------------------------|-//
//////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	//Initialize LEDs
	SensorValue[led1] = 0;
	SensorValue[led2] = 0;

	//Wait Till "button" Is Pressed, Then Light Up "led1"
	until(SensorValue[button] == 1);
	SensorValue[led1] = 1;

	//Until "button" Is Released, Flash "led2"
	doUntil(SensorValue[button] == 0){
		SensorValue[led2] = ~SensorValue[led2];
		wait1Msec(500);
	}
}
