#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontLeft = motor(PORT1, ratio18_1, false);
motor frontRight = motor(PORT2, ratio18_1, false);
motor tray = motor(PORT3, ratio36_1, false);
motor arms = motor(PORT4, ratio36_1, false);
motor backRight = motor(PORT8, ratio18_1, true);
motor backLeft = motor(PORT9, ratio18_1, false);
motor leftIntake = motor(PORT15, ratio18_1, false);
motor rightIntake = motor(PORT16, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}