/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       JBormann                                                  */
/*    Created:      Nov. 2019                                                 */
/*    Description:  Trobotics Template File                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// frontRight           motor         2               
// tray                 motor         3               
// arms                 motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "Autons.h"
#include "Functions.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Controller1.ButtonR1.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void) 
{
 switch (state)
  {
    case NONE:
    break;

    case AutonR:    
      Auton1();
    break;

    case AutonB:
  
    break;
          
    // Default = NO autonomous
    default:
    break;
  }
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) { 
  tray.setVelocity(50,percent);
  tray.setStopping(hold);

//setting the arm to be controlled by the joystick
  int armPower = Controller1.Axis1.position(percent);
  arms.setStopping(hold);


  while (1) {


  if (Controller1.ButtonA.pressing()){
    tray.spin(forward);
  }
  else if (Controller1.ButtonB.pressing()){
    tray.spin(reverse);
  }
  else{
    tray.stop();
  }

  //this is an attempt to get the tray to move with the arm to avoid entanglement.
  //needs to be tested and developed further. the relative speed of the motors 
  //probably needs to be coordinated
  double armAngle = arms.position(degrees);
int SOMECONSTANT = 1; //need to figure out this constant
if (arms.isSpinning() == true){
if (armAngle > 300 && armAngle < 500){
  
    double trayAngle = armAngle*SOMECONSTANT;
    tray.spinToPosition(trayAngle,degrees, false);
  
}
}
else
{
  tray.stop();
}

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}


// Main will set up the competition functions and callbacks.

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
