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

#include "pros/apix.h"

#include "serial/serial.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

////
//consider flushing stdout after writing
////

lv_obj_t *ta1;

//void drawRect(lv_vdb_t *fb, int x, int y, int w, int h, lv_color_t color){
//
//}
//
//void drawTarget(Point &p){
//    const int vid_w = 800;
//    const int vid_h = 488;
//
//    int screen_x = p.first * LV_HOR_RES / vid_w;
//    int screen_y = p.second * LV_VER_RES / vid_h;
//
//    lv_vdb_t *fb = lv_vdb_get();
//    lv_color_t col;
//    col.full = COLOR_BLUE;
//    drawRect(fb, 50, 50, 50, 50, col);
//}

void processPoints(vector<Point> &targets){

    for(auto &a : targets){
        //cout << "point:" << '[' << a.second << "," << a.first << ']' << endl;

        string pt_str;
        pt_str += "point:";
        pt_str += "[";
        pt_str += std::to_string(a.first);
        pt_str += ",";
        pt_str += std::to_string(a.second);
        pt_str += "]\n";

        //lv_ta_add_text(ta1, pt_str.c_str());

        cout << pt_str << endl;
        //drawTarget(a);
    }
    //lv_vdb_flush();
    //delay(5);
    fflush(stdout);

    //if(millis() > 5000){
    //    lv_ta_set_text(ta1, "");
    //}
}

void opcontrol() {
    puts("starting...\n");

    //create text area
    ta1 = lv_ta_create(lv_scr_act(), NULL);
    lv_obj_set_size(ta1, 480, 240);
    lv_ta_set_text(ta1, "");

    setVisionCallback(processPoints);

    Task ser_read(readAndParseVisionData);

    asm("nop");

    while(1){ delay(1000); }
}
