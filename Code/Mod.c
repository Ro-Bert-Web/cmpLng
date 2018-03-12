//////////////////////////////////////////////
//-|--------------------------------------|-//
//-| Sample Code On The Modulous Function |-//
//-|--------------------------------------|-//
//////////////////////////////////////////////

//Include Competition Language
#include "Competition Language.c"

task main(){
	int value = 0;
	while(1 == 1){

		//If Button 8U Is Pressed, Increase "value"
		if(vexRT[Btn8U] == 1){
			value++;
			until(vexRT[Btn8U] == 0);
		}

		//If Button 8D Is Pressed, Decrease "value"
		if(vexRT[Btn8D] == 1){
			value--;
			until(vexRT[Btn8D] == 0);
		}

		//Modulate "value" Around 5, If It Is Below 0, It Will Wrap Up To 5
		value = mod(value, 5);
	}
}
