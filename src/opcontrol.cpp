#include "main.h"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

#define DRAW
//#define ECHO

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "pros/apix.h"

#include "serial.h"
#include "graphics.h"
#include "utility.h"
#include "globals.h"
#include "shooterBot.h"
<<<<<<< Updated upstream
=======
#include "defines.h"

>>>>>>> Stashed changes

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

const vector<Point>::iterator findOptimalTarget(vector<Point> &targets){
    //highest target
    return std::min_element(targets.begin(), targets.end(),
            [](const Point &a, const Point &b){ return a.second < b.second; });

    //vector<Point>::iterator min = targets.begin();
    //for(auto it = targets.begin() + 1; it != targets.end(); ++it){
    //    if(it->second < min->second){
    //        min = it;
    //    }
    //}
    //return min;
}

void processPoints(vector<Point> &targets){

    //const auto target = findOptimalTarget(targets);
    //int dist = target->first - Gfx::vid_w/2;

    //cout << "dist: " << dist << endl;

    //int speed = 10 + abs(dist/20);

    //if(dist > 10){
    //    left_mtr  = speed;
    //    right_mtr = speed;
    //} else if(dist < -10){
    //    left_mtr  = -speed;
    //    right_mtr = -speed;
    //} else {
    //    left_mtr  = 0;
    //    right_mtr = 0;
    //}

#ifdef DRAW
    Gfx::clearScreen();

    //draw middle line
    Gfx::drawRect(Gfx::vid_h/2, 0, 1, LV_VER_RES, LV_COLOR_GREEN);

    for(auto &a : targets){
        Gfx::drawTarget(a);
    }

    lv_vdb_flush();
#endif

#ifdef ECHO
    for(auto &a : targets){
        cout << "point:" << '[' << a.second << "," << a.first << ']' << endl;
    }
    fflush(stdout);
#endif
}

void opcontrol() {
    vector<Point> targets;
	okapi::Controller controller
    while(1){
        Serial::getTargets(targets);
        if(targets.size() == 0) continue;
        processPoints(targets);

		//actual robot input
		//determine motion required based on left joystick
		ShooterBot::chassis.driveVector(controller.getAnalog(DRIVE_TRAIN_MAIN), controller.getAnalog(DRIVE_TRAIN_TURN));

		if(!controller.getDigital(FIND_TARGET)){
			ShooterBot::turretManual(controller.getAnalog(TURRET_CONTROL));
			ShooterBot::hoodManual(controller.getAnalog(HOOD_CONTROL));
		}

		if(controller.getDigitial(INTAKE_IN)){
			ShooterBot::runIntake(1);
		}
		else if(controller.getDigital(INTAKE_OUT)){
			ShooterBot::runIntake(-1);
		}

		if(controller.getDigital(TRANSFER_IN)){
			ShooterBot::runTransfer(1);
		}
		else if(controller.getDigital(TRANSFER_OUT)){
			ShooterBot::runTransfer(controller.getDigital(-1));
		}

		//handle target swapping however we decide to do that.

		//maybe not have the estop be such a simple easily accessible button
		//or just have estop set all motors to stop

		//zero should be run onChange
		//so that needs to be registerd as an individual button.

    }
}
