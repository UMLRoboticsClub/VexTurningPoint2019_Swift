#include "main.h"
#include "api.h"
#include "okapi/api.hpp"

class ShooterBot{
public:
	ShooterBot();
	~ShooterBot();
	void zero();
	void findTarget();//this might not be necessary, figure out our tracking
	void aimTurret(double angle);
	void aimHood(double angle);
	void shoot();
	int ballsLoaded();
	void runIntake(int direction);
	void runTransfer(int direction);
	
	
	okapi::ChassisControllerIntegrated chassis;
	okapi::Motor hoodMotor;
	okapi::Motor flyWheelMotor;
	okapi::Motor turretMotor;
	okapi::Motor intakeMotor;
	okapi::Motor transferMotor;
	double hoodAngle;
	double turretAngle;
	//sensor ballSensor	


};
