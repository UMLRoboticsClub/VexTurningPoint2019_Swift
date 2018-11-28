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

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "serial/serial.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;

void processPoints(vector<Point> &targets){
    for(auto &a : targets){
        cout << "point:" << '[' << a.second << "," << a.first << ']' << endl;
    }
}

void opcontrol() {
    setCallback(processPoints);
    readAndParseVisionData();
}
