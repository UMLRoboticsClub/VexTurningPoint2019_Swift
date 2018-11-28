#include "main.h"
#include "api.h"

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
	okapi::motor hoodMotor;
	okapi::motor flyWheelMotor;
	okapi::motor turretMotor;
	okapi::motor intakeMotor;
	okapi::motor transferMotor;
	double hoodAngle;
	double turretAngle;
	//sensor ballSensor	


}
