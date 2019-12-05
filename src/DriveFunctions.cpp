/**************************************/
/*  DriveFunctions.cpp                */
/*   This file exisits as an evolving */
/*   library of drive functions to    */
/*   help get your robot moving fast! */
/*   Its a work in progress!          */
/**************************************/
#include <math.h>
#include "DriveFunctions.h"

void go(float inches,int speed){
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