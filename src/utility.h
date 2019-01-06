#pragma once

#include "pros/apix.h"

typedef std::pair<int, int> Point;

//RAII wrapper for pros::Mutex, similar to std::lock_guard
class lock_guard {
    public:
        lock_guard(pros::Mutex &mutex);
        ~lock_guard();
    private:
        pros::Mutex &_mutex;
};

