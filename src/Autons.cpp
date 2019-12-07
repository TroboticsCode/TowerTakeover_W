#include "vex.h"
#include "Autons.h"
#include "Functions.h"

//Put your auton routines in here

void onePointBoth(){
  arms.spinToPosition(200,degrees);
  wait(1000,msec);
  arms.spinToPosition(90,degrees);
  move(24,100);
  wait(1000,msec);
  move(-24,100);
}
void Auton2(){
  arms.spinToPosition(200,degrees);
  wait(1000,msec);
  arms.spinToPosition(90,degrees);
  intakeDrive(60,100);
  intakeDrive(-48,70);
  turnLeft(90,40);
  move(14,40);
  runIntakeRev(1000);
  

}