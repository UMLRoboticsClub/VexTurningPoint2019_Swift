#pragma once

#include <vector>
#include <string>

#include "globals.h"
#include "utility.h"

namespace Serial {
    void initialize();
    void getTargets(std::vector<Point> &targets);
};
