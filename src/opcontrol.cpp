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

const int vid_w = 800;
const int vid_h = 488;

void drawTarget(Point &p){
    int screen_x = p.first * LV_HOR_RES / vid_w;
    int screen_y = p.second * LV_VER_RES / vid_h;

    drawRect(screen_x, screen_y, 50, 30, LV_COLOR_BLUE);
}

void clearScreen(){
    memset(framebuffer->buf, 0, LV_HOR_RES * LV_VER_RES * sizeof(lv_color_t));
}

void processPoints(vector<Point> &targets){
    clearScreen();

    //draw middle line
    drawRect(488/2, 0, 1, LV_VER_RES, LV_COLOR_GREEN);

    for(auto &a : targets){
        cout << "point:" << '[' << a.second << "," << a.first << ']' << endl;
        drawTarget(a);
    }
    lv_vdb_flush();
    fflush(stdout);
    delay(5);
}

void opcontrol() {
    puts("starting...\n");

    framebuffer = lv_vdb_get();

    setVisionCallback(processPoints);

    Task ser_read(readAndParseVisionData);

    Task heartbeat(serialHeartbeat);

    //asm("nop");

    while(1){ delay(1000); }
}
