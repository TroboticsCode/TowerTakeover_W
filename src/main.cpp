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
// frontLeft            motor         11              
// frontRight           motor         2               
// tray                 motor         19              
// arms                 motor         3               
// backRight            motor         6               
// backLeft             motor         20              
// leftIntake           motor         12              
// rightIntake          motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "Autons.h"
#include "Functions.h"
//#include "Autons.cpp"
//#include "DriveFunctions.cpp"

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
  
  Controller1.ButtonRight.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void) 
{
 switch (state)
  {
    case NONE:
    break;

    case onePoint:    
      onePointBoth();
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
int rightPower;
int leftPower;

  tray.setVelocity(50,percent);
  tray.setStopping(hold);
  leftIntake.setStopping(hold);
  rightIntake.setStopping(hold);
//setting the arm to be controlled by the joystick
  //int armPower = Controller1.Axis1.position(percent);
  arms.setStopping(hold);


  while (1) {
//this measures the arm motor angle and prints the value to the brain screen
double armAngle = arms.position(degrees);
Brain.Screen.clearLine();
Brain.Screen.print(armAngle);

//this command moves the arms to a set position that is correct to intake cubes
if (Controller1.ButtonY.pressing()){
arms.spinToPosition(90,degrees);
}

    //this is the drive command, it makes the wheels go
    leftPower = (Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent))/2;
    rightPower = (Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent))/2;
    frontLeft.setVelocity(leftPower,pct);
    backLeft.setVelocity(leftPower,pct);
    frontRight.setVelocity(rightPower,pct);
    backRight.setVelocity(rightPower,pct);

    frontLeft.spin(forward);
    backLeft.spin(forward);
    frontRight.spin(forward);
    backRight.spin(forward);
  //this controlls the tray
  if (Controller1.ButtonA.pressing()){
    tray.spin(forward);
  }
  else if (Controller1.ButtonB.pressing()){
    tray.spin(reverse);
  }
  else{
    tray.stop();
  }
  //this controlls the intake rollers on the ends of the arms
  if (Controller1.ButtonR1.pressing()){
    leftIntake.setVelocity(100,percent);
    rightIntake.setVelocity(100,percent);
    leftIntake.spin(forward);
    rightIntake.spin(forward);
  }
  else if (Controller1.ButtonR2.pressing()){
    leftIntake.setVelocity(50,percent);
    rightIntake.setVelocity(50,percent);
    leftIntake.spin(reverse);
    rightIntake.spin(reverse);
  }
  else{
    leftIntake.stop();
    rightIntake.stop();
  }
  //this controlls the arms
  if (Controller1.ButtonL1.pressing()){
    arms.spin(forward);
  }
  else if (Controller1.ButtonL2.pressing()){
    arms.spin(reverse);
  }
  else{
    arms.stop();
  }
    
  
  

  //this is an attempt to get the tray to move with the arm to avoid entanglement.
  //needs to be tested and developed further. the relative speed of the motors 
  //probably needs to be coordinated
/*if (armPower != 0){
  arms.setVelocity(armPower,percent);
tray.setVelocity(armPower,percent);
tray.spin(forward);
arms.spin(forward);
}
else{
  arms.stop();
}
*/


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
