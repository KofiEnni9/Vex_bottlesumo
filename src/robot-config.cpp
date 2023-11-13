#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
line right_foward = line(Brain.ThreeWirePort.A);
line left_foward = line(Brain.ThreeWirePort.B);
sonar Range_LE = sonar(Brain.ThreeWirePort.C);
sonar Range_RI = sonar(Brain.ThreeWirePort.E);
sonar Range_MI = sonar(Brain.ThreeWirePort.G);
motor RIGHTMotorA = motor(PORT8, ratio18_1, true);
motor RIGHTMotorB = motor(PORT7, ratio18_1, true);
motor_group RIGHT = motor_group(RIGHTMotorA, RIGHTMotorB);
motor LEFTMotorA = motor(PORT9, ratio18_1, false);
motor LEFTMotorB = motor(PORT10, ratio18_1, false);
motor_group LEFT = motor_group(LEFTMotorA, LEFTMotorB);
/*vex-vision-config:begin*/
signature Vision__WHITEBOX = signature (1, -917, -347, -632, -425, 341, -42, 0.6, 0);
signature Vision__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 4, 0);
vision Vision = vision (PORT1, 50, Vision__WHITEBOX, Vision__SIG_2);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}