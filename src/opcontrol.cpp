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

lv_vdb_t *framebuffer;

void drawRect(int x, int y, int w, int h, lv_color_t color){
    lv_area_t coords;
    lv_area_set(&coords, x, y, x + w, y + h);

    lv_style_plain.body.main_color = color;
    lv_style_plain.body.grad_color = color;
    lv_draw_rect(&coords, &coords, &lv_style_plain);
}

void drawTarget(Point &p){
    const int vid_w = 800;
    const int vid_h = 488;

    int screen_x = p.first * LV_HOR_RES / vid_w;
    int screen_y = p.second * LV_VER_RES / vid_h;

    drawRect(screen_x, screen_y, 50, 30, LV_COLOR_BLUE);
}

void processPoints(vector<Point> &targets){

    memset(framebuffer->buf, 0, LV_HOR_RES * LV_VER_RES * sizeof(lv_color_t));

    for(auto &a : targets){
        //cout << "point:" << '[' << a.second << "," << a.first << ']' << endl;

        string pt_str;
        pt_str += "point:";
        pt_str += "[";
        pt_str += std::to_string(a.first);
        pt_str += ",";
        pt_str += std::to_string(a.second);
        pt_str += "]\n";

        cout << pt_str << endl;
        drawTarget(a);
    }
    lv_vdb_flush();
    fflush(stdout);
    delay(5);
}

void opcontrol() {
    puts("starting...\n");

    framebuffer = lv_vdb_get();

    //while(1){
    //    memset(framebuffer->buf, 0, LV_HOR_RES * LV_VER_RES * sizeof(lv_color_t));
    //    drawRect(50, 50, 50, 50, LV_COLOR_BLUE);
    //    lv_vdb_flush();
    //    delay(100);
    //}

    setVisionCallback(processPoints);

    Task ser_read(readAndParseVisionData);

    //asm("nop");

    while(1){ delay(1000); }
}
