///////////////////////////////////////
//-|-------------------------------|-//
//-| Sample Code On Debug Commands |-//
//-|-------------------------------|-//
///////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int value = 0;

	//Open The Debug Window On The LCD
	debugLCD;

	while(1 == 1){

		//Increase "value" When Button 8D Is Pressed
		if(vexRT[Btn8U] == 1){
			value++;
			until(vexRT[Btn8U] == 0);
		}

		//Display "value" In The Debug Window Under V1
		debugVar[V1] = value;

		//If "value" Is Greater Than 10, End The Debug Window
		if(value > 10){
			endDebug;
		}
	}
}
