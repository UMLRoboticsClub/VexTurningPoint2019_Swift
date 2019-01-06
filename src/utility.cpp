#include "utility.h"

lock_guard::lock_guard(pros::Mutex &mutex):
    _mutex(mutex){
        _mutex.take(TIMEOUT_MAX);
    }

lock_guard::~lock_guard(){
    _mutex.give();
}

