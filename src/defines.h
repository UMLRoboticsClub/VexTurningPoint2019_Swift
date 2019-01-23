//controller mapping for SwiftBot

//things that need to be analog controlled
//drive train requires 2
//hood requires 1
//turret requires 1

//left joystick
const int DRIVETRAINTURN = 4;
const int DRIVETRAINMAIN = 3;

//right joystick
const int TURRETCONTROL = 1;
const int HOODCONTROL = 2;

//R2 to fire
const int SHOOTCONTROL = 8;


 //intake - L1 and L2 control direction
const int INTAKEIN = 6;
const int INTAKEPUKE = 7;

 //manual override for transfer
 //x and b
const int TRANSFERIN = 14;
const int TRANSFEROUT = 16;

//directionals
const int TARGETSWAPUP = 11;
const int TARGETSWAPDOWN = 12;
const int TARGETSWAPLEFT = 13;
const int TARGETSWAPRIGHT = 14;

//hold R2 to find target
const int FINDTARGET = 9;

//y and a respectively
const int ESTOP = 17;
const int ZERO = 15;
