#pragma once

#include "okapi/api.hpp"

using namespace okapi;

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
        ChassisControllerIntegrated chassis;
        Motor hoodMotor;
        Motor flywheelMotor;
        Motor turretMotor;
        Motor intakeMotor;
        Motor transferMotor;
};
