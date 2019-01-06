#pragma once

#include "pros/apix.h"

typedef std::pair<int, int> Point;

class lock_guard {
    public:
        lock_guard(pros::Mutex &mutex):
            _mutex(mutex){
                _mutex.take(TIMEOUT_MAX);
            }
        ~lock_guard(){
            _mutex.give();
        }
    private:
        pros::Mutex &_mutex;
};

