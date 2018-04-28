/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*		||																		||		*/
/*		||				Competition Language				||		*/
/*		||			Produced By: Ro-Bert			||		*/
/*		||				Version Number: 1.0					||		*/
/*		||			Finished:	March 12 2018				||		*/
/*		||																		||		*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#pragma systemFile	//This prevents errors popping for not using functions or variables
#ifndef Competition_Language	//Ensures that these functions will only be called once if another command file uses these
#define Competition_Language

////////////////////////////////////////////
//----------------------------------------//
//				Math (Included in formulas)			//
//----------------------------------------//
////////////////////////////////////////////

//Conversions
#define ft * 12
#define in
#define rot * 360
#define deg
#define minutes * 60000
#define sec * 1000
#define millisec

//A custom modulous function that continues the pattern onto negative numbers
int mod(int cmpLngX, int cmpLngY){
	while(cmpLngX<0){
		cmpLngX += cmpLngY;
	}
	return cmpLngX%cmpLngY;
}

//Maps the value "x" onto a line of (x1,y1) and (x2,y2)
#define map(cmpLngX,cmpLngX1,cmpLngX2,cmpLngY1,cmpLngY2)	(((cmpLngX)-(cmpLngX1))*((cmpLngY2)-(cmpLngY1))/((cmpLngX2)-(cmpLngX1))+cmpLngY1)

//Outputs one if "x" is greater than "y"
#define grt(cmpLngX,cmpLngY)	((cmpLngX>cmpLngY) ? 1 : 0)

//Outputs the maximum value of the set "x" and "y"
#define max(cmpLngX,cmpLngY)	((cmpLngX>cmpLngY) ? cmpLngX : cmpLngY)

//Outputs the minimum value of the set "x" and "y"
#define min(cmpLngX,cmpLngY)	((cmpLngX<cmpLngY) ? cmpLngX : cmpLngY)

//Outputs "x" if it is in bounds, otherwise, outputs the closest bound
#define constrain(cmpLngX,cmpLngA,cmpLngB) min(max(cmpLngX,min(cmpLngA,cmpLngB)),max(cmpLngA,cmpLngB))

//Maps and bounds "x" onto the line of (x1,y1) and (x2,y2)
#define bound(cmpLngX,cmpLngX1,cmpLngX2,cmpLngY1,cmpLngY2)	constrain(map(cmpLngX,cmpLngX1,cmpLngX2,cmpLngY1,cmpLngY2),cmpLngY1,cmpLngY2)

//Finds the average of "x" and "y"
#define avg(cmpLngX,cmpLngY) ((cmpLngX+cmpLngY)/2)

///////////:|||||//|/|/||/|:////////////////
//----------------------------------------//
//						Commands(; or :)						//
//--------------031917--------------------//
////////////////////////////////////////////

int cmpLngSpeedAccuracy = 33;

//Sets the accuracy for speed readings
#define setSpeedAccuracy(x)	cmpLngSpeedAccuracy = x

//Sets x to the speed of y
#define sensorSpeed(cmpLngVar, cmpLngSnsr)\
SensorValue[cmpLngSnsr] = 0;\
time1[T4] = 0;\
wait1Msec(cmpLngSpeedAccuracy);\
cmpLngVar = SensorValue[cmpLngSnsr] * 1000;\
cmpLngVar /= time1[T4] * 6

//Sets x to the speed of y
#define encoderSpeed(cmpLngVar, cmpLngNcdr)\
nMotorEncoder[cmpLngNcdr] = 0;\
time1[T4] = 0;\
wait1Msec(cmpLngSpeedAccuracy);\
cmpLngVar = nMotorEncoder[cmpLngNcdr] * 60000;\
if(motorType[cmpLngNcdr] == tmotorVex393_HBridge || motorType[cmpLngNcdr] == tmotorVex393_MC29){\
	cmpLngVar /= 627.2;\
}\
else if(motorType[cmpLngNcdr] == tmotorVex393HighSpeed_HBridge || motorType[cmpLngNcdr] == tmotorVex393_MC29){\
	cmpLngVar /= 392;\
}\
else{\
	cmpLngVar /= 240.448;\
}\
cmpLngVar /= time1[T4]

int cmpLngQrySpdY;
//Seeds the starting speed of variable y
#define seedSpeed(cmpLngN)\
cmpLngQrySpdY = cmpLngN;\
time1[T4] = 0;\
wait1Msec(cmpLngSpeedAccuracy)

//Query's the average speed of variable y since you last seeded the speed in rpms
#define querySpeed(cmpLngVar, cmpLngN)\
cmpLngVar = (cmpLngN - cmpLngQrySpdY) * 1000;\
cmpLngVar /= time1[T4] * 6

//Waits until statement is true
#define until(x) do{}while((x) == false)
#define doUntil(x) while((x) == false)

//////////////////////////
//		Robot Movement		//
//////////////////////////

//Gets the encoder value in degrees
int encoderDegrees(tMotor cmpLngNcdr){
	if(motorType[cmpLngNcdr] == tmotorVex393_HBridge || motorType[cmpLngNcdr] == tmotorVex393_MC29){
		return nMotorEncoder[cmpLngNcdr]* 360 / 627.2;
	}
	else if(motorType[cmpLngNcdr] == tmotorVex393HighSpeed_HBridge || motorType[cmpLngNcdr] == tmotorVex393_MC29){
		return nMotorEncoder[cmpLngNcdr]* 360 / 392;
	}
	else{
		return nMotorEncoder[cmpLngNcdr]* 360 / 240.448;
	}
}

#define wheelDistance(cmpLngWheel, cmpLngDeg) PI * cmpLngWheel * cmpLngDeg / 360

//Sets the specified actuator to a certain value
#define setActuator(cmpLngPstn,cmpLngB) SensorValue[cmpLngPstn] = cmpLngB

//Extends the specified actuator
#define extendActuator(cmpLngPstn) setActuator(cmpLngPstn, 1)

//Retracts the specified actuator
#define retractActuator(cmpLngPstn) setActuator(cmpLngPstn, 0)

tMotor cmpLngDrvMtrs[4] = {port2, port3, port4, port5};
//Sets the motor ports and sets it to two motor drive
void	setDrive(tMotor cmpLngLD, tMotor cmpLngRD){
	cmpLngDrvMtrs[0] = cmpLngLD;
	cmpLngDrvMtrs[1] = cmpLngLD;
	cmpLngDrvMtrs[2] = cmpLngRD;
	cmpLngDrvMtrs[3] = cmpLngRD;
}

//Sets the motor ports and sets it to four motor drive
void setDrive(tMotor cmpLngLF, tMotor cmpLngLB, tMotor cmpLngRF, tMotor cmpLngRB){
	cmpLngDrvMtrs[0] = cmpLngLF;
	cmpLngDrvMtrs[1] = cmpLngLB;
	cmpLngDrvMtrs[2] = cmpLngRF;
	cmpLngDrvMtrs[3] = cmpLngRB;
}

//Configures the motors' rotations on the drive base
#define configDrive \
bMotorReflected[cmpLngDrvMtrs[0]] = false;\
bMotorReflected[cmpLngDrvMtrs[1]] = false;\
bMotorReflected[cmpLngDrvMtrs[2]] = true;\
bMotorReflected[cmpLngDrvMtrs[3]] = true

//Runs the drive at cmpLngLftSpd and cmpLngRitSpd
#define tankDrive(cmpLngLftSpd, cmpLngRitSpd)\
motor[cmpLngDrvMtrs[0]] = cmpLngLftSpd;\
motor[cmpLngDrvMtrs[1]] = cmpLngLftSpd;\
motor[cmpLngDrvMtrs[2]] = cmpLngRitSpd;\
motor[cmpLngDrvMtrs[3]] = cmpLngRitSpd

//Runs the drive at forward and rot
#define singleJoystick(cmpLngFwd, cmpLngRot)	tankDrive(cmpLngFwd + cmpLngRot, cmpLngFwd - cmpLngRot)

//Runs the drive at forward straff and rot
#define straffDrive(cmpLngFwd, cmpLngSdwas, cmpLngRot)\
motor[cmpLngDrvMtrs[0]] = cmpLngFwd + cmpLngSdwas + cmpLngRot;\
motor[cmpLngDrvMtrs[1]] = cmpLngFwd - cmpLngSdwas + cmpLngRot;\
motor[cmpLngDrvMtrs[2]] = cmpLngFwd - cmpLngSdwas - cmpLngRot;\
motor[cmpLngDrvMtrs[3]] = cmpLngFwd + cmpLngSdwas - cmpLngRot

////////////////////////
//		LCD Commmands		//
////////////////////////

//Opens a debugging menu on the LCD where you can veiw values from all ports
#define debugLCD startTask(cmpLngDebugLCD)

//Stops the debugging menu forcfully in the code
#define endDebug stopTask(cmpLngDebugLCD)

//Debugging menu's task
typedef enum cmpLngDebugVar{
	V1 = 0,
	V2 = 1,
	V3 = 2,
	V4 = 3,
	V5 = 4,
	V6 = 5,
	V7 = 6,
	V8 = 7
}cmpLngDebugVar;

int debugVar[10];

task cmpLngDebugLCD(){
	int cmpLngRotMenu = 0;
	int cmpLngRotType = 0;
	bool cmpLngRotDebugging = true;
	bLCDBacklight = true;
	do{
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(1, 0, "Menu  Type   End");
		int cmpLngRotButtons = nLCDButtons;
		switch(cmpLngRotButtons){
		case 1:											//Menu button
			cmpLngRotMenu += 1;
			wait1Msec(250);
			break;
		case 2:											//Type button
			cmpLngRotType += 1;
			wait1Msec(250);
			break;
		case 4:											//End button
			cmpLngRotDebugging = false;
			break;
		default:
			break;
		}
		cmpLngRotMenu %= 10;
		switch(cmpLngRotMenu){
		case 0:											//Analog
			cmpLngRotType %= 8;
			displayLCDString(0, 0, "in");
			displayLCDNumber(0, 2, cmpLngRotType+1);
			displayLCDString(0, 4, " = ");
			displayLCDNumber(0, 7, SensorValue[cmpLngRotType]);
			break;
		case 1:											//Digital
			cmpLngRotType %= 12;
			displayLCDString(0, 0, "dgtl");
			displayLCDNumber(0, 4, cmpLngRotType+1);
			displayLCDString(0, 6, " = ");
			displayLCDNumber(0, 9, SensorValue[cmpLngRotType+8]);
			break;
		case 2:											//Motors
			cmpLngRotType %= 10;
			displayLCDString(0, 0, "port");
			displayLCDNumber(0, 4, cmpLngRotType+1);
			displayLCDString(0, 6, " = ");
			displayLCDNumber(0, 9, motor[cmpLngRotType]);
			break;
		case 3:											//I2C
			cmpLngRotType %= 10;
			displayLCDString(0, 0, "port");
			displayLCDNumber(0, 4, cmpLngRotType+1);
			displayLCDString(0, 6, " = ");
			displayLCDNumber(0, 9, nMotorEncoder[cmpLngRotType]);
			break;
		case 4:											//Timers
			cmpLngRotType %= 4;
			displayLCDString(0, 0, "T");
			displayLCDNumber(0, 1, cmpLngRotType+1);
			displayLCDString(0, 2, " = ");
			displayLCDNumber(0, 5, time1[cmpLngRotType]);
			break;
		case 5:											//Vex Remote Channels
			cmpLngRotType %= 6;
			displayLCDString(0, 0, "Ch");
			displayLCDNumber(0, 2, cmpLngRotType+1);
			displayLCDString(0, 3, " = ");
			displayLCDNumber(0, 6, vexRT[cmpLngRotType]);
			break;
		case 6:											//Vex Remote Buttons
			cmpLngRotType %= 12;
			switch(cmpLngRotType){
			case 0:
				displayLCDString(0, 0, "Btn5D = ");
				break;
			case 1:
				displayLCDString(0, 0, "Btn5U = ");
				break;
			case 2:
				displayLCDString(0, 0, "Btn6D = ");
				break;
			case 3:
				displayLCDString(0, 0, "Btn6U = ");
				break;
			case 4:
				displayLCDString(0, 0, "Btn8D = ");
				break;
			case 5:
				displayLCDString(0, 0, "Btn8L = ");
				break;
			case 6:
				displayLCDString(0, 0, "Btn8U = ");
				break;
			case 7:
				displayLCDString(0, 0, "Btn8R = ");
				break;
			case 8:
				displayLCDString(0, 0, "Btn7D = ");
				break;
			case 9:
				displayLCDString(0, 0, "Btn7L = ");
				break;
			case 10:
				displayLCDString(0, 0, "Btn7U = ");
				break;
			case 11:
				displayLCDString(0, 0, "Btn7R = ");
				break;
			default:
				cmpLngRotType %= 12;
				break;
			}
			displayLCDNumber(0, 8, vexRT[cmpLngRotType+Btn5D]);
			break;
		case 7:											//Vex Remote Accelerometers
			cmpLngRotType %= 3;
			switch(cmpLngRotType){
			case 0:
				displayLCDString(0, 0, "AccelX = ");
				break;
			case 1:
				displayLCDString(0, 0, "AccelY = ");
				break;
			case 2:
				displayLCDString(0, 0, "AccelZ = ");
				break;
			default:
				cmpLngRotType %= 3;
				break;
			}
			displayLCDNumber(0, 9, vexRT[cmpLngRotType+AccelX]);
			break;
		case 8:											//Variables
			cmpLngRotType %= 8;
			displayLCDString(0, 0, "V");
			displayLCDNumber(0, 1, cmpLngRotType+1);
			displayLCDString(0, 2, " = ");
			displayLCDNumber(0, 5, debugVar[cmpLngRotType]);
			break;
		case 9:											//Cortex
			switch(cmpLngRotType){
			case 0:
				displayLCDString(0, 0, "Cortex = ");
				displayLCDNumber(0, 9, nImmediateBatteryLevel);
				break;
			case 1:
				displayLCDString(0, 0, "Backup = ");
				displayLCDNumber(0, 9, BackupBatteryLevel);
				break;
			default:
				cmpLngRotType %= 2;
				break;
			}
			displayLCDString(0, 13, "kV");
			break;
		default:
			cmpLngRotMenu %= 10;
			break;
		}
		wait1Msec(1);
	}
	while(cmpLngRotDebugging == true);
}

//////////////////////////////
//		Autonomous Commands		//
//////////////////////////////

int cmpLngAutonChoice = 0;
//Select from x autonomouses inside pre autonomous
#define autonSelection(x)\
bool cmpLngChoice = false;\
bLCDBacklight = true;\
do{\
	clearLCDLine(0);\
	clearLCDLine(1);\
	int cmpLngButtons = nLCDButtons;\
	switch(cmpLngButtons){\
	case 1:\
		cmpLngAutonChoice -= 1;\	//Go left
		wait1Msec(250);\
		break;\
	case 2:\
		cmpLngChoice = true;\	//Select
		break;\
	case 4:\
		cmpLngAutonChoice += 1;\	//Go right
		wait1Msec(250);\
		break;\
	default:\
		break;\
	}\
	cmpLngAutonChoice = mod(cmpLngAutonChoice, x + 1);\
	if(cmpLngAutonChoice == 0){\
		displayLCDString(0, 0, "Autonomous:");\
		displayLCDString(0, 11, "Empty");\
	}\
	else{\
		displayLCDString(0, 0, "Autonomous:");\
		displayLCDNumber(0, 12, cmpLngAutonChoice);\
	}\
	displayLCDString(1, 0, "Left  Slct Right");\
	wait1Msec(1);\
}while(cmpLngChoice==false && bIfiRobotDisabled==true)

//Starts the list of autonomouses
#define startAutonomousList	switch(cmpLngAutonChoice)

//Marks the start of autonomous number x
#define autonomousNumber(x)	case x

//Marks the end of the last autonomous
#define endAutonomous break

//Marks the end of the autonomous list
#define endAutonomousList \
default:\
break

//Used for testing, displays the string of code following it to see if command works
#ifdef cmpLngFactoryDebug
#define cmpLngTest(x) #x
#endif
#endif
