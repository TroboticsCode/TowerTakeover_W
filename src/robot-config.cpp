#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontLeft = motor(PORT11, ratio18_1, false);
motor frontRight = motor(PORT2, ratio18_1, true);
motor tray = motor(PORT19, ratio36_1, false);
motor arms = motor(PORT3, ratio36_1, false);
motor backRight = motor(PORT6, ratio18_1, true);
motor backLeft = motor(PORT20, ratio18_1, false);
motor leftIntake = motor(PORT12, ratio18_1, false);
motor rightIntake = motor(PORT5, ratio18_1, true);
controller Controller1 = controller(primary);
pot Pot = pot(Brain.ThreeWirePort.H);
pot PotentiometerB = pot(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}