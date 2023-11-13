using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern line right_foward;
extern line left_foward;
extern sonar Range_LE;
extern sonar Range_RI;
extern sonar Range_MI;
extern motor_group RIGHT;
extern motor_group LEFT;
extern signature Vision__WHITEBOX;
extern signature Vision__SIG_2;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );