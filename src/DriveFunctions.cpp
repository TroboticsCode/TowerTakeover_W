/**************************************/
/*  DriveFunctions.cpp                */
/*   This file exisits as an evolving */
/*   library of drive functions to    */
/*   help get your robot moving fast! */
/*   Its a work in progress!          */
/**************************************/
#include <vex.h>
#include "Functions.h"

bool ranSetup = false;

void move(float inches,int speed){
  //this defines how much it needs to move to go an inch
  float driveSpins = inches/(4 * M_PI);
  //this sets how fast the motors will go useing int speed
  frontLeft.setVelocity(speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(speed,percent);
  backRight.setVelocity(speed,percent);
//this makes the motors go using float wheel spins
  frontLeft.spinFor(driveSpins,turns,false);
  frontRight.spinFor(driveSpins,turns,false);
  backLeft.spinFor(driveSpins,turns,false);
  backRight.spinFor(driveSpins,turns,true);
}
void turnRight(float degrees, int speed){
  float turnSpins = degrees/106;

  frontLeft.setVelocity(-speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(-speed,percent);
  backRight.setVelocity(speed,percent);

  frontLeft.spinFor(turnSpins,turns,false);
  frontRight.spinFor(-turnSpins,turns,false);
  backLeft.spinFor(turnSpins,turns,false);
  backRight.spinFor(-turnSpins,turns);

  }
void turnLeft(float degrees, int speed){
  float turnSpins = degrees/106; //expect to tune the denominator for accuracy with robot

  frontLeft.setVelocity(speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(speed,percent);
  backRight.setVelocity(speed,percent);

  frontLeft.spinFor(-turnSpins,turns, false);
  frontRight.spinFor(turnSpins,turns, false);
  backLeft.spinFor(-turnSpins,turns, false);
  backRight.spinFor(turnSpins,turns);
  }
  void intakeDrive(float inches, int speed){
    float driveSpins = inches/(4 * M_PI);
    frontLeft.setVelocity(speed,percent);
    frontRight.setVelocity(speed,percent);
    backLeft.setVelocity(speed,percent);
    backRight.setVelocity(speed,percent);
    rightIntake.setVelocity(100,percent);
    leftIntake.setVelocity(100,percent);
    leftIntake.setStopping(hold);
    rightIntake.setStopping(hold);
    leftIntake.spin(forward);
    rightIntake.spin(forward);
    frontLeft.spinFor(driveSpins,turns,false);
    frontRight.spinFor(driveSpins,turns,false);
    backLeft.spinFor(driveSpins,turns,false);
    backRight.spinFor(driveSpins,turns,true);
    leftIntake.stop();
    rightIntake.stop();
  }
  void intakeDriveRev(float inches, int speed){
    float driveSpins = inches/(4 * M_PI);
    frontLeft.setVelocity(speed,percent);
    frontRight.setVelocity(speed,percent);
    backLeft.setVelocity(speed,percent);
    backRight.setVelocity(speed,percent);
    rightIntake.setVelocity(25,percent);
    leftIntake.setVelocity(25,percent);
    leftIntake.setStopping(hold);
    rightIntake.setStopping(hold);
    leftIntake.spin(forward);
    rightIntake.spin(forward);
    frontLeft.spinFor(driveSpins,turns,false);
    frontRight.spinFor(driveSpins,turns,false);
    backLeft.spinFor(driveSpins,turns,false);
    backRight.spinFor(driveSpins,turns,true);
    leftIntake.stop();
    rightIntake.stop();
  }
  void runIntakeFwd(double miliseconds){
    leftIntake.setVelocity(100,percent);
    rightIntake.setVelocity(100,percent);
    leftIntake.setStopping(hold);
    rightIntake.setStopping(hold);
    leftIntake.spin(forward);
    rightIntake.spin(forward);
    wait(miliseconds,msec);
    rightIntake.stop();
    leftIntake.stop();
  }
  void runIntakeRev(double miliseconds){
    leftIntake.setVelocity(25,percent);
    rightIntake.setVelocity(25,percent);
    leftIntake.setStopping(hold);
    rightIntake.setStopping(hold);
    leftIntake.spin(reverse);
    rightIntake.spin(reverse);
    wait(miliseconds,msec);
    rightIntake.stop();
    leftIntake.stop();
  }
  void moveTrayFwd(){
    tray.setVelocity(25,percent);
    tray.setStopping(hold);
    tray.setTimeout(2500,msec);
    tray.spinToPosition(382,degrees,true);
    tray.stop();
  }
  void moveTrayRev(){
    tray.setVelocity(25,percent);
    tray.spinToPosition(0,degrees);
  }
  void score(float backUp){
    runIntakeRev(750);
    moveTrayFwd();
    intakeDriveRev(-backUp,40);
    moveTrayRev();
  }
  void setUp(void){
    //if(ranSetup == false){runIntakeRev(1500);
    tray.setPosition(0,degrees);
    arms.setPosition(0,degrees);
    runIntakeRev(750);
    tray.spinToPosition(62,degrees,false);
    wait(500,msec);
    arms.spinToPosition(140,degrees);
    tray.spinToPosition(44,degrees);
    tray.setPosition(0,degrees);
    arms.spinToPosition(0,degrees);
    //ranSetup = true;
    }
  void towerSm(){
    runIntakeRev(800);
    tray.spinToPosition(109,degrees);
    arms.spinToPosition(340,degrees);
    arms.setStopping(hold);
    arms.stop();
    move(11,30);
    wait(500,msec);
    runIntakeRev(1000);
    move(-12,30);
    arms.spinToPosition(0,degrees);
    tray.spinToPosition(0,degrees);
  }
  void towerMd(){
    runIntakeRev(800);
    tray.spinToPosition(109,degrees);
    arms.spinToPosition(422.6,degrees);
    arms.setStopping(hold);
    arms.stop();
    move(12,30);
    wait(500,msec);
    runIntakeRev(1000);
    move(-12,30);
    arms.spinToPosition(0,degrees);
    tray.spinToPosition(0,degrees);
  }
  
/*
  void moveArms(bool armUp)
  {
    if(armUp){
      arms.setVelocity(100,percent);
    }
    else if(!armUp)
    {
      arms.setVelocity(100,percent);
      arms.spinFor(
    }
  }*/