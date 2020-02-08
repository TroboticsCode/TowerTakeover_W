using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeft;
extern motor frontRight;
extern motor tray;
extern motor arms;
extern motor backRight;
extern motor backLeft;
extern motor leftIntake;
extern motor rightIntake;
extern controller Controller1;
extern pot Pot;
extern pot PotentiometerB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );