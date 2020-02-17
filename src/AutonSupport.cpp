/***********************************
 * AutonSupport.cpp
 * This file contains support
 * functions for selecting auton
 * routines
 * Update as needed, do not delete
***********************************/

#include "Autons.h"

int state = 0;
char state_name[] = "NONE";

/* void Paint_Screen()
* brief: this function will update the brain's display to show the currently selected auton program
*/
void Paint_Screen(void)
{
  Controller1.Screen.setCursor(3,1);
  Controller1.Screen.clearLine(3);
  Controller1.Screen.print("%s", state_name);
}

/*void cycle_autons
* brief: this function is called when a button on the controller is pressed to advance to the 
*          next auton routine
* Update this function as more auton programs are added
*/
void cycle_autons(void)
{
    if (state == 0)
    {
        state = onePoint;
        strcpy(state_name, "One Point");
    }
    else if (state == onePoint)
    {
         state = SKILLS;
         strcpy(state_name, "Skills");
    }
    
    else if (state == SKILLS)
    {
        state = fourPointB;
        strcpy(state_name, "4 Point Blue");
    }
    else if (state == fourPointB){
      state = fourPointR;
      strcpy(state_name,"4 Point Red");
    }
    else if (state == fourPointR){
      state = NONE;
      strcpy(state_name,"NONE");
    }
    Paint_Screen();
}

