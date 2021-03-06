#include "main.h"
#include "api.h"
#include "okapi/api.hpp"

class ShooterBot{
public:
	ShooterBot() = delete;
	~ShooterBot() = delete;
	static void init();
	static void zero();
	static void findTarget();//this might not be necessary, figure out our tracking
	static void aimTurret(double angle);
	static void aimHood(double angle);
	static void shoot(double angle);
	static int ballsLoaded();
	static void runIntake(int direction);
	static void runTransfer(int direction);
    static void turretManual(double val);
    static void hoodManual(double val);


	static okapi::ChassisControllerIntegrated chassis;
	static okapi::Motor hoodMotor;
	static okapi::Motor flyWheelMotor;
	static okapi::Motor turretMotor;
	static okapi::Motor intakeMotor;
	static okapi::Motor transferMotor;
	static double hoodAngle;
	static double turretAngle;
	//sensor ballSensor

	static okapi::ADIButton hoodLimitSwitch;
	static okapi::ADIButton turretLimitSwitch;
	static okapi::ADIButton transferLimitSwitchLower;
	static okapi::ADIButton transferLimitSwitchUpper;


};
