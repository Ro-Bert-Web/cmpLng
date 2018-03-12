#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           mtr,           tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

////////////////////////////////////
//-|----------------------------|-//
//-| Sample Code On Conversions |-//
//-|----------------------------|-//
////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int rotation = 0;
	int distance = 0;
	doUntil(distance > 4 ft){	//ft Convertst The 4 To 48 (inches)

		//Finds The Rotation In Degrees Of The Encoder On The Back Of "mtr"
		rotation = encoderDegrees(mtr);

		//Converts The Rotation To A Distance Traveled By A 4.5 Inch Wheel
		distance = wheelDistance(4.5, rotation);
	}
}
