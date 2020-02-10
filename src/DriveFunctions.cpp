/**************************************/
/*  DriveFunctions.cpp                */
/*   This file exisits as an evolving */
/*   library of drive functions to    */
/*   help get your robot moving fast! */
/*   Its a work in progress!          */
/**************************************/
#include <vex.h>
#include "DriveFunctions.h"

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
  float turnSpins = degrees*360/70.243567;

  frontLeft.setVelocity(-speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(-speed,percent);
  backRight.setVelocity(speed,percent);

  frontLeft.spinFor(turnSpins,turns);
  frontRight.spinFor(turnSpins,turns);
  backLeft.spinFor(turnSpins,turns);
  backRight.spinFor(turnSpins,turns);

  }
void turnLeft(float degrees, int speed){
  float turnSpins = degrees*360/70.243567; //expect to tune the denominator for accuracy with robot

  frontLeft.setVelocity(speed,percent);
  frontRight.setVelocity(-speed,percent);
  backLeft.setVelocity(speed,percent);
  backRight.setVelocity(-speed,percent);

  frontLeft.spinFor(turnSpins,turns);
  frontRight.spinFor(turnSpins,turns);
  backLeft.spinFor(turnSpins,turns);
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
    tray.spinToPosition(100,degrees/*change later*/);
  }
  void moveTrayRev(){
    tray.spinToPosition(0,degrees);
  }
  void score(){
    runIntakeRev(1000);
    moveTrayFwd();
    runIntakeRev(1000);
    move(-24,20);
  }
  void setUp(){
    runIntakeRev(1000);
    tray.spinToPosition(62,degrees);
    arms.spinToPosition(110,degrees);
    tray.spinToPosition(44,degrees);
    tray.setPosition(0,degrees);
  }
  void putInTheTower(){
    runIntakeRev(500);
    arms.spinToPosition(100,degrees); //number will be changed
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