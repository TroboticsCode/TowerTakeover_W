/**************************************/
/*  DriveFunctions.cpp                */
/*   This file exisits as an evolving */
/*   library of drive functions to    */
/*   help get your robot moving fast! */
/*   Its a work in progress!          */
/**************************************/
#include <math.h>
#include "DriveFunctions.h"

void drive(float inches,int speed){
  float wheelSpins = inches/(4 * M_PI);
  frontLeft.setVelocity(speed);

  frontLeft.spinFor(wheelSpins,turns,false);
}