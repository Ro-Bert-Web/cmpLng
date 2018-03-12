#pragma platform(VEX2)
#pragma competitionControl(Competition)

/////////////////////////////////////////////
//-|-------------------------------------|-//
//-| Sample Code On Autonomous Selection |-//
//-|-------------------------------------|-//
/////////////////////////////////////////////

#include "Vex_Competition_Includes.c"

//Include Competition Language
#include "Competition Language.c"

void pre_auton(){

	//Select between 3 autonomouses
	autonSelection(3);

}

task autonomous(){
	startAutonomousList{

	autonomousNumber(1):
		//Run autonomous 1 here
		endAutonomous;

	autonomousNumber(2):
		//Run autonomous 2 here
		endAutonomous;

	autonomousNumber(3):
		//Run autonomous 3 here
		endAutonomous;

		endAutonomousList;
	}
}

task usercontrol(){
}
