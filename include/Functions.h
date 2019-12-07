#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//always include vex.h because it has all the robot setup declarations
//as well as the API for the code.
#include "vex.h"

//enter the prototypes for other functions here
//lift, claw, etc
//drive function prototypes can go here but they should be in the DriveFunctions.h file


void move(float inches,int speed);
void turnRight(float degrees,int speed);
void turnLeft(float degrees,int speed);
void intakeDrive(float inches, int speed);
void runIntakeFwd(double miliseconds);
void runIntakeRev(double miliseconds);


#endif