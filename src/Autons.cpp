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
void Auton2(){//skills
  setUp();
  intakeDrive(44,30);
  runIntakeFwd(500);
  intakeDrive(-44,50);
  wait(500,msec);
  move(18,50);
  turnLeft(135,40);
  move(21,40);
  runIntakeRev(750);
  moveTrayFwd();
  wait(500,msec);
  move(-21,40);
  moveTrayRev();
}
void fourPointBlue(){
  setUp();
  intakeDrive(44,35);
  intakeDrive(-26,70);
  turnLeft(135,40);
  move(17,60);
  runIntakeRev(750);
  moveTrayFwd();
  wait(250,msec);
  move(-21,60);
  moveTrayRev();
}
void fourPointRed(){
  setUp();
  intakeDrive(41,35);
  intakeDrive(-26,70);
  turnRight(135,40);
  move(17,60);
  runIntakeRev(750);
  moveTrayFwd();
  wait(250,msec);
  move(-21,60);
  moveTrayRev();
}
void TEST(){
  //setUp();
  intakeDrive(40,30);
  runIntakeFwd(500);
  move(-38,50);
  move(-4,30);
  wait(500,msec);
  move(20,50);
  turnLeft(135,40);
  move(21,40);
  score(23);
  turnRight(135,50);
  intakeDrive(28,40);
  runIntakeFwd(1000);
  intakeDrive(-12,50);
  towerSm();
}