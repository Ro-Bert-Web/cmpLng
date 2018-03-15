#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  sensorPort,     sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           encoderPort,   tmotorVex393_MC29, openLoop, encoderPort, I2C_1)

///////////////////////////////////////
//-|-------------------------------|-//
//-| Sample Code On Speed Commands |-//
//-|-------------------------------|-//
///////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int sensor, encoder;

	//Set Speed Accuracy (Not Necessary, 33 Is Default)
	setSpeedAccuracy(33);

	while(1 == 1){

		//Get The Speed Of The Sensor
		sensorSpeed(sensor, sensorPort);

		//Get The Speed Of The Encoder
		encoderSpeed(encoder, encoderPort);
	}
}
