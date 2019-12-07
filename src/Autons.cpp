#include "vex.h"
#include "Autons.h"
#include "Functions.h"

//Put your auton routines in here

void onePointBoth(){
  move(-24,70);
  wait(1000,msec);
  move(24,70);
  arms.spinToPosition(400,degrees);
  wait(1000,msec);
  arms.spinToPosition(0,degrees);
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