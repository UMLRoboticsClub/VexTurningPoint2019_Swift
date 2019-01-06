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
#include <utility>
#include <algorithm>

#include "pros/apix.h"
#include "okapi/api.hpp"

#include "serial/serial.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

lv_vdb_t *framebuffer;

//TODO: change this later
const int vid_w = 800;
const int vid_h = 488;


//const int DRIVE_MOTOR_LEFT = 1;
//const int DRIVE_MOTOR_RIGHT = 2;
//auto chassis = okapi::ChassisControllerFactory::create(DRIVE_MOTOR_LEFT, DRIVE_MOTOR_RIGHT);

pros::Motor left_mtr(1);
pros::Motor right_mtr(2);

void drawRect(int x, int y, int w, int h, lv_color_t color){
    lv_area_t coords;
    lv_area_set(&coords, x, y, x + w, y + h);

    lv_style_plain.body.main_color = color;
    lv_style_plain.body.grad_color = color;
    lv_draw_rect(&coords, &coords, &lv_style_plain);
}

void clearScreen(){
    memset(framebuffer->buf, 0, LV_HOR_RES * LV_VER_RES * sizeof(lv_color_t));
}

void drawTarget(Point &p, lv_color_t color = LV_COLOR_BLUE){
    const int screen_x = p.first * LV_HOR_RES / vid_w;
    const int screen_y = p.second * LV_VER_RES / vid_h;

    drawRect(screen_x - 15, screen_y, 50, 30, color);
}

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
    //int dist = target->first - vid_w/2;

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
    clearScreen();

    //draw middle line
    drawRect(vid_h/2, 0, 1, LV_VER_RES, LV_COLOR_GREEN);

    for(auto &a : targets){
        drawTarget(a);
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
    puts("starting...\n");

    framebuffer = lv_vdb_get();

    Task ser_read(readAndParseVisionData);
    Task heartbeat(serialHeartbeat);

    vector<Point> targets;
    while(1){ 
        getTargets(targets);
        if(targets.size() == 0) continue;
        processPoints(targets);
    }
}
