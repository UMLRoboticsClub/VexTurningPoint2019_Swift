#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

int startingHAngle = 70;//the starting angle for the hood of swift
int startingTAngle; = 70//the starting angle for the turret of swift
int LMport = 1;//Left Motor port
int RMport = 2;//Right Motor port
//if velocity is used for motors then ...
//for gear set 1
int fVel1 = 100;//fast velocity
int sVel1 = 50;//slow velocity
//for gear set 2
int fVel2 = 200;
int sVel2 = 100;
//for gear set 3
int fVel3 = 600;
itn fVel3 = 400;
//if voltage is intended for motors then ...
int sVolt = 11;//Strong volttage 
int wVolt = 9;//weak volttage 
double turn_dist = 1000.0;//distance to turn 90 degrees
double dist1; // distance from the start square to the first disc of spheres
double dist2; // distance from the first disc to the second disc of spheres
double dist3; // distance from first disc to second disc of spheres (mainly if it is a bad idea to go towards other team's side)

void autonomous() {
	//set hood's angle to the shooting angle for the first flag
	aimHood(startingHAngle);
	aimTurret(startingTAngle);
	shoot();
	runIntake();
	//assumming that the robot will be arranged so that it is already pointing toward the first duo of poms
	move_absolute(dist1, sVolt);//3.25 diameter inches

	/*
	flag targeting code from jackson
	*/
	aimTurret();
	shoot();


	//if going to the other team's side is an good idea
	motor_move_absolute(LMport, turn_dist/2, sVolt);//imagining the angle that the robot reaches the first disc is a 45 degree angle
	move_absolute(dist2, sVolt);

	/*
	flag targeting code from jackson
	*/
	aimTurret();
	shoot(); 
	
	//if going to the other team's side is an bad idea
	motor_move_absolute(LMport, turn_dist*3/2, sVolt);//imagining the angle that the robot reaches the first disc is a 45 degree angle
	move_absolute(dist3, sVolt);

	/*
	flag targeting code from jackson
	*/
	aimTurret();
	shoot();
}
