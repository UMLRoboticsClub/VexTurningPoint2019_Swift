#include "shooterBot.h"

//define class variables
	//position vars
	double ShooterBot::hoodAngle = 0;
	double ShooterBot::turretAngle = 0;
	//motor groups for each side of the bot
	okapi::MotorGroup mgl({0,1,2});
	okapi::MotorGroup mgr({3,4,5});
	//gearset for drive motors
	okapi::AbstractMotor::gearset gearSet = okapi::AbstractMotor::gearset::red;
	//wheel diameter and distance between wheels across robot
	okapi::ChassisScales scale({3.25, 22});
	//actual chassic constructed from above definitions
	okapi::ChassisControllerIntegrated ShooterBot::chassis(okapi::ChassisControllerFactory::create(mgr, mgl, gearSet, scale));
	//individual motors.  Will need gearsets added.
	okapi::Motor ShooterBot::hoodMotor(6);
	okapi::Motor ShooterBot::flyWheelMotor(7);
	okapi::Motor ShooterBot::turretMotor(8);
	okapi::Motor ShooterBot::intakeMotor(9);
	okapi::Motor ShooterBot::transferMotor(10);

	okapi::ADIButton ShooterBot::hoodLimitSwitch(11);
	okapi::ADIButton ShooterBot::turretLmitSwitch(12);
	okapi::ADIButton ShooterBot::transferLimitSwitchLower(13);
	okapi::ADIButton ShooterBot::transferLimitSwitchUpper(14);


void ShooterBot::init(){
	zero();
}

void ShooterBot::zero(){
	//zero hood and turret angle by going until limit.
	while(!ShooterBot::hoodLimitSwitch.isPressed()){
		ShooterBot::hoodMotor.moveVelocity(10);
	}
	ShooterBot::hoodMotor.setZeroPosition();
	while(!ShooterBot::turretLimitSwitch.isPressed()){
		ShooterBot::turretMotor.moveVelocity(10);
	}
	ShooterBot::turretMotor.setZeroPosition();
}

void ShooterBot::findTarget(){
	//magic camera shit goes here
}

void ShooterBot::aimTurret(double angle){
	//move turret to given angle measured relative to robot main axis
	ShooterBot::turretMotor.moveAbsolute(/*math here*/);
}

void ShooterBot::aimHood(double angle){
	//move hood to specified angle
	ShooterBot::hoodMotor.moveAbsolute(/*doSometMath*/);
}

void ShooterBot::shoot(double angle){
	//runs transfer until ball has exited the robot
	bool twoBalls = ShooterBot::transerLimitSwitchLower.isPressed()
	//this will be a little tricky timeing wise.  Theoretically just run until
	//top trigger no longer pressed, then reverse so bottom one is pressed?
	//but only the latter if it was initially pressed
}

int ShooterBot::ballsLoaded(){
	//check dat sensor to figure out if we got balls
	int count = 0;
	if (ShooterBot::transferLimitSwitchLower.isPressed())
		count++;
	if (ShooterBot::transferLimitSwitchUpper.isPressed())
		count++;
}

void runIntake(int direction){
	ShooterBot::intakeMotor.moveVelocity(direction*100);
}

void runTransfer(int direction){
	ShooterBot::transferMotor.moveVelocity(direction*100);
}
