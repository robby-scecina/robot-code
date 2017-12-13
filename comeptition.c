#pragma config(Motor,  port2,           motor1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motor2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           motor3,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           motor4,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

//Variables

//End Variables

//Functions
void leftWheels (int speed=0){
	// Set motors 1 and 2 to the variable speed
	motor[motor1]=speed;
	motor[motor2]=speed;
}
void rightWheels (int speed= 0){
	// Set motors 3 and 4 to the speed var
	motor[motor3]=speed;
	motor[motor4]=speed;
}

void moveArm (int speed=0 ) {
	motor[arm]=speed;
}

void moveClaw(int speed=0){
	motor[claw]=speed;
	}

//End Functions

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
// This code is just a placehoolder for the real autonomous code
leftWheels(127);
rightWheels(127);


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.
		//UserControlCodePlaceholderForTesting();

		leftWheels(vexRT[Ch3]); //
		rightWheels(vexRT[Ch2]);

		if (vexRT[Btn6U]==1){
			// if up button pressed
			moveArm(127); // move move arm up at full speed
		}
		else
		{
			if (vexRT[Btn6D]==1){
				//if down button pressed
				moveArm(-127); //move arm down at full speed
			}
			else{
				// If nothing pressed
				moveArm(0); //Stop arm movement
			}
		}
// End of the horrific mess of brackets
		if (vexRT[Btn5U]==1){
			// if up button pressed
			moveClaw(127); // move claw up at full speed
		}
		else
		{
			if (vexRT[Btn5D]==1){
				//if down button pressed
				moveClaw(-127); //close claw  at full speed
			}
			else{
				// If nothing pressed
				moveClaw(0); //Stop claw movement
			}
		}
// End of the horrific mess of brackets
	}
}
