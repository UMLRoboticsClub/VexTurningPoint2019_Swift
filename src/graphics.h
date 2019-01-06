#pragma once

#include "utility.h"

namespace Gfx {
    void initialize();
    void clearScreen();
    void drawRect(int x, int y, int w, int h, lv_color_t color);
    void drawTarget(Point &p);

    extern const int vid_w;
    extern const int vid_h;
};
