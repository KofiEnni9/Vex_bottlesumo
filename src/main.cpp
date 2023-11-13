/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Prempeh College                                  */
/*    Created:      Fri Mar 10 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// right_foward         line          A               
// left_foward          line          B               
// Range_LE             sonar         C, D            
// Range_RI             sonar         E, F            
// Range_MI             sonar         G, H            
// RIGHT                motor_group   8, 7            
// LEFT                 motor_group   9, 10           
// Vision               vision        1               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>

using namespace vex;

int bump_count =0;
int break_value = 0;
int dist_value_RI = 0;
int dist_value_LE = 0;

/* (1st if) moves robot forward for both light sensors on white*/
/*(2nd if) moves only right side of robot for right_forward on black*/
/*(3rd if) moves only left side of the robot for left_forward on black*/
/*(4th if) stops the robot for left_forward and right_forward on black */


void edge(int speed){
  LEFT.setVelocity(speed, percent);
  RIGHT.setVelocity(speed, percent);
    if (right_foward.reflectivity() < 15 && left_foward.reflectivity() < 15){ 

      while(right_foward.reflectivity() < 15 && left_foward.reflectivity() < 15){
        LEFT.spin(reverse);
        RIGHT.spin(reverse);
      }
    LEFT.stop(brake); RIGHT.stop(brake);}

    if (left_foward.reflectivity() < 15) {

      while(left_foward.reflectivity() < 15){
        RIGHT.spin(reverse);
        LEFT.stop(brake); 
      }}

    if (right_foward.reflectivity() < 15) {
      while(right_foward.reflectivity() < 15){
        LEFT.spin(reverse);
        RIGHT.stop(brake);
      }}
      LEFT.stop(brake);
      RIGHT.stop(brake); 
      }

void edge__(int speed){
  
  LEFT.setVelocity(speed, percent);
  RIGHT.setVelocity(speed, percent);
  for(int i=0 ; i < 1 ; ++i){
  
    break_value =0;
    if (right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){ 
      while(right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){
        LEFT.spin(forward);
        RIGHT.spin(forward);
      } LEFT.stop(brake); RIGHT.stop(brake);}
    if (right_foward.reflectivity() < 15 && left_foward.reflectivity() < 15){
      break;
    }
    LEFT.setVelocity(30, percent);
    RIGHT.setVelocity(30, percent);
   
      if(left_foward.reflectivity() > 15) {
        while(left_foward.reflectivity() > 15 && right_foward.reflectivity() < 15){
          RIGHT.spin(forward);
          LEFT.spin(reverse); 
        }

        while(left_foward.reflectivity() > 15){
          RIGHT.spin(forward);
          LEFT.stop(brake); 
        }
        LEFT.stop(brake); RIGHT.stop(brake);
    
      }
      if (right_foward.reflectivity() > 15) {
        while(right_foward.reflectivity() > 15 && left_foward.reflectivity() < 15){
          LEFT.spin(forward);
          RIGHT.spin(reverse);
        }
        while(right_foward.reflectivity() > 15){
          LEFT.spin(forward);
          RIGHT.stop(brake);
        }
        RIGHT.stop(brake);
        LEFT.stop(brake);
        }
     
      LEFT.setVelocity(30, percent);
      RIGHT.setVelocity(30, percent);
      if(right_foward.reflectivity() < 10) {
      while(right_foward.reflectivity() < 10){
        LEFT.spin(reverse);
        RIGHT.stop(brake); 
      }}
      if(left_foward.reflectivity() < 10) { 
      while(left_foward.reflectivity() < 10){
        RIGHT.spin(reverse);
        LEFT.stop(brake); 
      }}   
       }
      LEFT.stop(brake);
      RIGHT.stop(brake); 
    }

void spindetect(int speed, int angl_){
  double calc2 = (365*angl_)/105;

  LEFT.setVelocity(speed, percent); 
  RIGHT.setVelocity(speed,percent);
  Range_LE.setMaximum(800, mm);
  Range_RI.setMaximum(800, mm);
  
  LEFT.setPosition(0,degrees);

  while (fabs(LEFT.position(degrees)) < calc2  && !(Range_LE.foundObject()) && !(Range_RI.foundObject()) 
  && right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){
    LEFT.spin(reverse); LEFT.spin(reverse);
    RIGHT.spin(forward);  RIGHT.spin(forward);
  }
  LEFT.stop(brake);
  RIGHT.stop(brake);  
  wait(0.1, seconds);
}

//distance program

void dist_(int speed,int cm_){
  double calc3 = (cm_ * 360)/ 28.5;
  RIGHT.setVelocity(speed, percent); RIGHT.setVelocity(speed, percent);
  LEFT.setVelocity(speed, percent);  LEFT.setVelocity(speed, percent);
  LEFT.setPosition(0, degrees); LEFT.setPosition(0, degrees);
    repeat(4){
  if(fabs(LEFT.position(degrees)) < calc3){
  while(fabs(LEFT.position(degrees)) < calc3){
    RIGHT.spin(forward); RIGHT.spin(forward);
    LEFT.spin(forward); LEFT.spin(forward);
  }
  wait(0.1, seconds);
  }}  RIGHT.stop(brake);  RIGHT.stop(brake);
  LEFT.stop(brake); LEFT.stop(brake);

  }
  
void spin_ (int speed, int angl_){
  double calc2 = (365*angl_)/105;

  LEFT.setVelocity(speed, percent);  LEFT.setVelocity(speed, percent);
  RIGHT.setVelocity(speed,percent);  RIGHT.setVelocity(speed,percent);
  RIGHT.setPosition(0,degrees);      LEFT.setPosition(0,degrees);
  LEFT.setPosition(0,degrees);      LEFT.setPosition(0,degrees);


  while ((fabs(RIGHT.position(degrees)) < calc2 || fabs(LEFT.position(degrees)) < calc2) &&
   right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){
    LEFT.spin(reverse); LEFT.spin(reverse);
    RIGHT.spin(forward); RIGHT.spin(forward);
  }
  LEFT.stop(brake); LEFT.stop(brake);
  RIGHT.stop(brake); RIGHT.stop(brake);
  wait(0.1, seconds);
}

void follower(int speed){
 
  while(true){
    RIGHT.setVelocity(speed, percent);
    LEFT.setVelocity(speed, percent);
    RIGHT.spin(forward);
    LEFT.spin(forward);
    
    if(left_foward.reflectivity() < 15 || right_foward.reflectivity() < 15){
      break;
    }   
    
    if(Range_LE.distance(mm) < 800 && (Range_LE.distance(mm)< Range_RI.distance(mm))){

        LEFT.stop(brake); LEFT.stop(brake);
      }
 
    if(Range_RI.distance(mm) < 800 && (Range_RI.distance(mm) < Range_LE.distance(mm))){
      RIGHT.stop(brake); RIGHT.stop(brake);
        }
  }

  RIGHT.stop(brake); RIGHT.stop(brake); LEFT.stop(brake); LEFT.stop(brake);
}


void spindetect_edge(int speed, int angl_){
  double calc2 = (365*angl_)/105;

  LEFT.setVelocity(speed, percent);  
  RIGHT.setVelocity(speed,percent); 
  
  LEFT.setPosition(0,degrees);

  while (fabs(LEFT.position(degrees)) < calc2  && Range_LE.distance(mm) > 800 && Range_RI.distance(mm) > 800
  && right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){
    LEFT.spin(reverse);   
    RIGHT.spin(forward);  
  }
  LEFT.stop(brake); RIGHT.stop(brake);
  
  if(fabs(LEFT.position(degrees)) < 200 && (Range_LE.distance(mm) < 800 || Range_RI.distance(mm) < 800)){
    if(Range_LE.distance(mm) < 800){
      if(Range_LE.distance(mm) < 200){
        spin_(-80, 40);
        follower(80);
        }
      else {
        spin_(-80, 87);
      }
    }
    else {
      if(Range_RI.distance(mm) < 200){
        spin_(80, 40);
        follower(80);
        }
      else {
        spin_(80, 87);
      }
    }
  }
  wait(0.1, seconds);
}

    // distance whiles sensing
void dist_sense(int speed,int cm_){
  double calc3 = (cm_ * 360)/ 28.5;
  RIGHT.setVelocity(speed, percent);  
  LEFT.setVelocity(speed, percent);
  RIGHT.setPosition(0, degrees);
  
  if(fabs(RIGHT.position(degrees)) < calc3 && Range_RI.distance(mm) > 800 && Range_LE.distance(mm) > 800 &&
  right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){

  while(fabs(RIGHT.position(degrees)) < calc3 && Range_RI.distance(mm) > 800 && Range_LE.distance(mm) > 800 &&
  right_foward.reflectivity() > 15 && left_foward.reflectivity() > 15){

    RIGHT.spin(forward); 
    LEFT.spin(forward); 

  }}
  RIGHT.stop(brake); LEFT.stop(brake);
  LEFT.setPosition(0, degrees);
  if(Range_RI.distance(mm) < 800){
    dist_value_RI = Range_RI.distance(mm)/15;
  } 
  if(Range_LE.distance(mm) < 800){
    dist_value_LE = Range_LE.distance(mm)/15;
  }}

 /*Program for when the robot detects the bottle */

void follow_count(int speed){
  while(true){
    RIGHT.setVelocity(speed, percent);  RIGHT.setVelocity(speed, percent);
    LEFT.setVelocity(speed, percent);   LEFT.setVelocity(speed, percent);   
    RIGHT.spin(forward);                RIGHT.spin(forward);
    LEFT.spin(forward);                 LEFT.spin(forward);

    if(left_foward.reflectivity() < 15 || right_foward.reflectivity() < 15 || Range_MI.distance(mm) < 200
    || Range_LE.distance(mm) < 70 || Range_RI.distance(mm) < 70){
      break;
    }

    if(Range_LE.distance(mm) < 800 && (Range_LE.distance(mm)< Range_RI.distance(mm))){
        RIGHT.stop(brake);  RIGHT.stop(brake);
      }

    if(Range_RI.distance(mm) < 800 && (Range_RI.distance(mm) < Range_LE.distance(mm))){
      LEFT.stop(brake);  LEFT.stop(brake);
        }

  }
  RIGHT.stop(brake);  RIGHT.stop(brake); LEFT.stop(brake);   LEFT.stop(brake);
}


int main(){
  // Initializing Robot Configuration. DO NOT REMOVE!

  vexcodeInit();

  Range_LE.distance(mm); Range_MI.distance(mm); Range_RI.distance(mm);
  wait(1, seconds);
  Brain.resetTimer();
  //spindetect(80, 200);

  while(bump_count != 3 && Brain.timer(seconds) < 40){
    dist_sense(90, 70);
    spindetect(80, 87);
    if(Range_LE.distance(mm) < 800 || Range_RI.distance(mm) < 800){
      follow_count(90);
      if(Range_MI.distance(mm) < 200 || Range_LE.distance(mm) < 70 || Range_RI.distance(mm) < 70){
        bump_count++;
        edge__(60);
      }
    }
    if(right_foward.reflectivity()<15 || left_foward.reflectivity()<15){
      edge__(60);
      dist_(-80, 20);
      spindetect_edge(-80, 85);
    }
    }
    spindetect(80, 180);
    if(Range_LE.distance(mm)<800 || Range_RI.distance(mm)<800){
      follower(80);
      }
    
      
    
      
              /*Range_LE.distance(mm); Range_MI.distance(mm); Range_RI.distance(mm);
    wait(1, seconds);
    follow_count(70);*/
    vexSystemExitRequest();
} 
