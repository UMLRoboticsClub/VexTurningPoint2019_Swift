#pragma once

#include <vector>
#include <string>

#include "utility.h"

namespace Serial {
    void initialize();
    void getTargets(std::vector<Point> &targets);
};
