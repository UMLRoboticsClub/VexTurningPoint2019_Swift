//controller mapping for SwiftBot



//things that need to be analog controlled
//drive train requires okapi::ControllerDigital
//hood requires okapi::ControllerDigital
//turret requires okapi::ControllerDigital

//left joystick
const okapi::ControllerAnalog DRIVETRAIN_TURN = okapi::ControllerAnalog::leftX;
const okapi::ControllerAnalog DRIVETRAIN_MAIN = okapi::ControllerAnalog::leftY;

//right joystick
const okapi::ControllerAnalog TURRET_CONTROL = okapi::ControllerAnalog::rightX;
const okapi::ControllerAnalog HOOD_CONTROL = okapi::ControllerAnalog::rightY;

//R2 to fire
const okapi::ControllerDigital SHOOT_CONTROL = okapi::ControllerDigital::R2;


 //intake - L1 and L2 control direction
const okapi::ControllerDigital INTAKE_IN = okapi::ControllerDigital::L2;
const okapi::ControllerDigital INTAKE_PUKE = okapi::ControllerDigital::L1;

 //manual override for transfer
 //x and b
const okapi::ControllerDigital TRANSFER_IN = okapi::ControllerDigital::X;
const okapi::ControllerDigital TRANSFER_OUT = okapi::ControllerDigital::B;

//directionals
const okapi::ControllerDigital TARGET_SWAP_UP = okapi::ControllerDigital::up;
const okapi::ControllerDigital TARGET_SWAP_DOWN = okapi::ControllerDigital::down;
const okapi::ControllerDigital TARGET_SWAP_LEFT = okapi::ControllerDigital::left;
const okapi::ControllerDigital TARGET_SWAP_RIGHT = okapi::ControllerDigital::right;

//hold R1 to find target
const okapi::ControllerDigital FIND_TARGET = okapi::ControllerDigital::R1;

//y and a respectively
const okapi::ControllerDigital ESTOP = okapi::ControllerDigital::A;
const okapi::ControllerDigital ZERO = okapi::ControllerDigital::Y;
