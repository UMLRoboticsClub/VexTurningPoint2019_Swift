#include "robot.h"

#include "serial.h"
#include "graphics.h"

using namespace okapi;

const static int MOTOR_L_A = 0;
const static int MOTOR_L_B = 1;
const static int MOTOR_L_C = 2;

const static int MOTOR_R_A = 3;
const static int MOTOR_R_B = 4;
const static int MOTOR_R_C = 5;

const static int MOTOR_HOOD     = 6;
const static int MOTOR_FLYWHEEL = 7;
const static int MOTOR_TURRET   = 8;
const static int MOTOR_INTAKE   = 9;
const static int MOTOR_TRANSFER = 10;

const static double SCALE_STRAIGHT = 3.25;
const static double SCALE_TURN     = 22.0;

Robot::Robot():
    chassis(ChassisControllerFactory::create(
                MotorGroup({MOTOR_L_A, MOTOR_L_B, MOTOR_L_C}),
                MotorGroup({MOTOR_R_A, MOTOR_R_B, MOTOR_R_C}),
                AbstractMotor::gearset::red,
                ChassisScales({SCALE_STRAIGHT, SCALE_TURN}))),
    hoodMotor(MOTOR_HOOD),
    flywheelMotor(MOTOR_FLYWHEEL),
    turretMotor(MOTOR_TURRET),
    intakeMotor(MOTOR_INTAKE),
    transferMotor(MOTOR_TRANSFER)
{
    Serial::initialize();
    Gfx::initialize();
    zero();
}

void Robot::zero(){
    //zero hood and turret angle by going until limit.
}

void Robot::findTarget(){
    //magic camera shit goes here
}

void Robot::aimTurret(double angle){
    //move turret to given angle measured relative to robot main axis
}

void Robot::aimHood(double angle){
    //move hood to specified angle
}

void Robot::shoot(double angle){
    //runs transfer until ball has exited the robot
}

int Robot::ballsLoaded(){
    //check dat sensor to figure out if we got balls
    return 0;
}

void Robot::runIntake(int direction){
    //1 intakes, -1 outtakes.
}

void Robot::runTransfer(int direction){
    //see runIntake.
}
