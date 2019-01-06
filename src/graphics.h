#pragma once

#include "utility.h"

namespace Graphics {
    void initialize();
    void clearScreen();
    void drawRect(int x, int y, int w, int h, lv_color_t color);
    void drawTarget(Point &p);
};
