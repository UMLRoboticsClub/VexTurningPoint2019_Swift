#include "shooterBot.h"

ShooterBot::ShooterBot(): chassis(okapi::ChassisControllerFactory::create(okapi::MotorGroup({0,1,2}), okapi::MotorGroup({3,4,5}), okapi::AbstractMotor::gearset::red, okapi::ChassisScales({3.25, 22.0}))), hoodMotor(6), flyWheelMotor(7), turretMotor(8), intakeMotor(9), transferMotor(10){
	hoodAngle = 0;
	turretAngle = 0;

	//okapi::MotorGroup leftDriveTrain({0, 1, 2});
	//okapi::MotorGroup rightDriveTrain({3, 4, 5});
	
	//okapi::ChassisScales scale(3.25_in, 22_in);

	//chassis = okapi::chassisControllerFactory::create(leftDriveTrain, rightDriveTrain, AbstractMotor::gearset::red, scale);

	//hoodmotor = okapi::Motor(6);
	//flyWheelMotor = okapi::Motor(7);
	//turretMotor = okapi::Motor(8);
	//intakeMotor = okapi::Motor(9);
	//transferMotor = okapi::Motor(10);
	zero();
}

void ShooterBot::zero(){
	//zero hood and turret angle by going until limit.
}

void ShooterBot::findTarget(){
	//magic camera shit goes here
}

void ShooterBot::aimTurret(double angle){
	//move turret to given angle measured relative to robot main axis
}

void ShooterBot::aimHood(double angle){
	//move hood to specified angle
}

void ShooterBot::shoot(double angle){
	//runs transfer until ball has exited the robot
}

int ShooterBot::ballsLoaded(){
	//check dat sensor to figure out if we got balls
}

void runIntake(int direction){
	//1 intakes, -1 outtakes.
}

void runTransfer(int direction){
	//see runIntake.
}
