#include "graphics.h"

#include "globals.h"

namespace Gfx {
    //TODO: change this later
    const int vid_w = 800;
    const int vid_h = 488;

    static lv_vdb_t *framebuffer;

    void initialize(){
        framebuffer = lv_vdb_get();
        clearScreen();
    }

    void clearScreen(){
        //is this safe? who knows
        memset(framebuffer->buf, 0, LV_HOR_RES * LV_VER_RES * sizeof(lv_color_t));
    }

    void drawRect(int x, int y, int w, int h, lv_color_t color){
        lv_area_t coords;
        lv_area_set(&coords, x, y, x + w, y + h);

        lv_style_plain.body.main_color = color;
        lv_style_plain.body.grad_color = color;
        lv_draw_rect(&coords, &coords, &lv_style_plain);
    }

    void drawTarget(Point &p){
        const int screen_x = p.first * LV_HOR_RES / vid_w;
        const int screen_y = p.second * LV_VER_RES / vid_h;

        drawRect(screen_x - 15, screen_y, 50, 30, LV_TEAM_COLOR);
    }
};
