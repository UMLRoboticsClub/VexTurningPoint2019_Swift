#pragma once

#include "okapi/api.hpp"

class Robot {
    public:
        Robot();
        //~Robot();

        void zero();
        void findTarget();
        void aimTurret(double angle);
        void aimHood(double angle);
        void shoot(double angle);
        int ballsLoaded();
        void runIntake(int direction);
        void runTransfer(int direction);

    private:
        okapi::ChassisControllerIntegrated chassis;
        okapi::Motor hoodMotor;
        okapi::Motor flywheelMotor;
        okapi::Motor turretMotor;
        okapi::Motor intakeMotor;
        okapi::Motor transferMotor;
};
