#include "main.h"

#include "kari/control/chassis.h"
#include "kari/control/rack.h"
#include "kari/control/arm.h"

#include "kari/util/odometry.h"
#include "kari/util/misc.h"
#include "kari/util/vision.h"

static Chassis chassis;
static Rack rack;
static Arm arm;
static Odom odom;

int angleoffset = 0;

using namespace io;

// Make Trigger

/*===========================================
  DICTIONARY
===========================================*/
// IDLE = 0
// DRIVING_POINT = 1
// DRIVING_DIST = 2
// TURNING = 3
// STRAFING = 4

void tester()
{
  odom.calibrateGyro();

  // roller(127);
  // chassis.drive(2100,65,4).withAngle(0, 80).withTol(30).waitUntilSettled();
  // chassis.drive(-300,70,4).withAngle(0, 80).withTol(30).waitUntilSettled();
  // chassis.turn(45,70).withTol(10).waitUntilSettled();
  // chassis.drive(500,40,2).withAngle(45, 80).withTol(30).waitUntilSettled();

  master.rumble(" . .");
}

/*===========================================
  PREMADE FUNCTIONS
===========================================*/
void deploy()
{
  arm.move(ARM_LOW_TOWER, 127).withTol(0.3).waitUntilSettled();
  arm.zero();
}

/*===========================================
  RED MATCH AUTONOMOUSES
===========================================*/
void redsmallzone11()
{
}

void redsmallzone8()
{
}

void redsmallzone7()
{
  roller(127);
  chassis.lock();
  chassis.drive(1050, 50, 2).withAngle(0, 50).withTol(40).waitUntilSettled();
  chassis.drive(-1300, 200, 5).withAngle(65, 127, 3).withTol(40).waitUntilSettled();
  chassis.turn(0, 127).withTol(10).waitUntilSettled();
  chassis.drive(1600, 60, 2).withAngle(0, 50).withTol(40).waitUntilSettled();
  chassis.drive(-1500, 127, 2).withTol(40).waitUntilSettled();
  chassis.turn(270, 80).withTol(10).waitUntilSettled();
  LF.move(100);
  LB.move(-100);
  RF.move(100);
  RB.move(-100);
  delay(800);
  rack.move(RACK_UP, 127, 7).withGain(0.1).withTol(30);
  roller(-0.3, 50);
  delay(500);
  chassis.left(50);
  chassis.right(50);
  roller(-0.2, 100);
  delay(800);
  chassis.left(30);
  chassis.right(30);
  rack.waitUntilSettled();
  rack.move(RACK_DOWN, 127, 8).withTol(20);
  roller(-70);
  chassis.lock();
  chassis.drive(-550, 60, 2).withAngle(270, 50).withTol(40).waitUntilSettled();
}

void redsmallzone5()
{
}

void redbigzone()
{
}

void redbigzonescore()
{
}

/*===========================================
  BLUE MATCH AUTONOMOUSES
===========================================*/
void bluesmallzone11()
{
}

void bluesmallzone8()
{
}

void bluesmallzone7()
{
}

void bluesmallzone5()
{
}

void bluebigzone()
{
}

void bluebigzonescore()
{
}

/*===========================================
  SKILLS AUTONOMOUSES
===========================================*/
void skills4()
{
  chassis.lock();
  odom.zero();
  chassis.drive(250, 60, 2).withAngle(0, 5).withTol(40);
  arm.move(1.05, 127);
  delay(800);
  chassis.setMode(0);
  arm.zero();
  chassis.left(-40);
  chassis.right(-40);
  delay(800);
  roller(127);
  chassis.drive(1600, 70, 2).withAngle(0, 60).withTurnGain(5, 0.3, 3).withTol(40).waitUntilSettled();
  delay(500);
  arm.tower(1);
  delay(300);
  chassis.turn(25, 70).withTol(10).waitUntilSettled();
  chassis.drive(300, 60, 2).withAngle(25, 50).withTol(40).waitUntilSettled();
  roller(-80);
  delay(300);
  chassis.drive(-400, 80, 2).withAngle(25, 50).withTol(40).waitUntilSettled();
  arm.zero();
  chassis.turn(0, 90).withTol(10).waitUntilSettled();
  roller(127);
  chassis.drive(2700, 55, 2).withAngle(0, 50).withTol(30).waitUntilSettled();
  delay(500);
  arm.tower(1);
  delay(100);
  chassis.turn(260, 70).withTol(10).waitUntilSettled();
  chassis.drive(150, 60, 2).withAngle(260, 50).withTol(40).waitUntilSettled();
  roller(-80);
  delay(300);
  chassis.drive(-200, 60, 2).withAngle(260, 50).withTol(40).waitUntilSettled();
  roller(127);
  chassis.turn(350, 70).withTol(10);
  delay(300);
  arm.zero();
  chassis.waitUntilSettled();
  chassis.unlock();
  chassis.drive(300, 127, 2).withAngle(350, 50).withTol(60).waitUntilSettled();
  roller(0);
  LF.move(0);
  LB.move(127);
  RF.move(0);
  RB.move(127);
  delay(1200);
  LF.move(-100);
  LB.move(100);
  RF.move(-100);
  RB.move(100);
  delay(800);
  rack.move(RACK_UP, 127, 7).withGain(0.1).withTol(30);
  roller(-0.3, 50);
  delay(500);
  chassis.left(50);
  chassis.right(50);
  roller(-0.2, 100);
  delay(800);
  chassis.left(30);
  chassis.right(30);
  rack.waitUntilSettled();
  rack.move(RACK_DOWN, 127, 8).withTol(20);
  roller(-70);
  chassis.lock();
  chassis.drive(-550, 60, 2).withAngle(270, 50).withTol(40).waitUntilSettled();
  chassis.strafe(1900, 75).withSlop(-520).withTol(40).waitUntilSettled();
  chassis.left(-70);
  chassis.right(-70);
  chassis.lock();
  delay(800);
  roller(127);
  chassis.drive(4050, 75, 2).withAngle(182, 60).withTurnGain(5, 0.3, 3).withTol(40).waitUntilSettled();
  rack.move(2000, 127).withTol(0);
  delay(300);
  chassis.turn(270, 70).withTol(10).waitUntilSettled();
  rack.move(RACK_DOWN, 127).withTol(0);
  chassis.drive(1300, 100, 2).withAngle(270, 50).withTol(40);
  delay(100);
  arm.tower(1);
  chassis.waitUntilSettled();
  roller(-80);
  delay(300);
  chassis.drive(-100, 127, 2).withAngle(270, 50).withTol(40).waitUntilSettled();
  LF.move(90);
  LB.move(-127);
  RF.move(90);
  RB.move(-127);
  delay(800);

  roller(127);
  arm.zero();
  delay(1500);
  chassis.left(100);
  chassis.right(100);
  delay(400);
  rack.move(RACK_UP, 127, 7).withGain(0.1).withTol(30);
  chassis.left(50);
  chassis.right(50);
  roller(-0.4, 50);
  delay(500);

  roller(-0.2, 100);
  delay(500);
  chassis.left(30);
  chassis.right(30);
  rack.waitUntilSettled();
  rack.move(RACK_DOWN, 127, 8).withTol(20);
  roller(-70);
  chassis.lock();
  chassis.drive(-4100, 127, 2).withAngle(275, 50).withTol(50).waitUntilSettled();
  roller(127);
  LF.move(100);
  LB.move(-100);
  RF.move(100);
  RB.move(-100);
  delay(400);
  chassis.strafe(-1700, 75, 2).withTol(60).waitUntilSettled();

  chassis.drive(1000, 80, 2).withAngle(270, 50).withTol(50).waitUntilSettled();
  delay(800);
  arm.tower(2);
  delay(800);
  chassis.drive(400, 127, 2).withAngle(270, 50).withTol(20).waitUntilSettled();
  roller(-90);
  delay(300);
  chassis.drive(-520, 127, 2).withAngle(270, 50).withTol(50).waitUntilSettled();
  delay(300);
  arm.zero();
  roller(127);

  chassis.turn(358, 100).withTol(10).waitUntilSettled();
  roller(127);
  chassis.drive(1100, 80, 2).withAngle(0, 50).withTol(40).waitUntilSettled();
  delay(500);
  arm.tower(1);
  chassis.turn(35, 70).withTol(10).waitUntilSettled();
  chassis.drive(300, 60, 2).withAngle(35, 50).withTol(40).waitUntilSettled();
  roller(-80);
  delay(300);
  chassis.drive(-400, 80, 2).withAngle(35, 50).withTol(40).waitUntilSettled();
  arm.zero();
  chassis.turn(0, 90).withTol(10).waitUntilSettled();
  roller(127);
  chassis.drive(2000, 127, 2).withAngle(0, 50).withTol(30).waitUntilSettled();
  arm.tower(2);
  delay(500);
  chassis.turn(315, 127).withTol(10).waitUntilSettled();
  chassis.drive(700, 90, 2).withAngle(315, 50).withTol(40).waitUntilSettled();
  roller(-90);
  delay(300);
  chassis.drive(-400, 80, 2).withAngle(315, 50).withTol(40);
  delay(300);
  arm.zero();
  chassis.waitUntilSettled();

  roller(127);
  delay(100000);
  arm.move(1.05, 127);
  delay(800);
  arm.zero();
  odom.reset();
  delay(800);
  arm.move(1.05, 127);
  chassis.lock();
  arm.waitUntilSettled();
}

// Good 1
// chassis.strafexdrive(12, 0, 80, 2).withGain(20).withAngle(60, 127, 4).withTurnGain(6).withTol(1).waitUntilSettled();
// Good 2
// chassis.strafexdrive(5, 12, 80, 2).withGain(20).withAngle(180, 127, 16).withTol(1).waitUntilSettled();

// chassis.drive(-300, 127).withTol(40).waitUntilSettled();
// chassis.strafexdrive(-16, 30, 80, 2).withGain(20).withAngle(45, 127, 4).withRelative(false, 0.7).withTurnGain(6).withTol(1).waitUntilSettled();
// chassis.drive(-300, 127).withTol(40).waitUntilSettled();

// chassis.strafexdrive(-13, 34, 127, 2).withGain(20).withTol(1).waitUntilSettled();
// chassis.turn(45, 127).withTol(5).waitUntilSettled();
// chassis.strafexdrive(-20, 40, 127, 2).withGain(20).withTol(1).waitUntilSettled();
// chassis.turn(90, 127).withTol(5).waitUntilSettled();
// chassis.strafexdrive(-40, 30, 127, 2).withGain(20).withTol(1).waitUntilSettled();
// chassis.strafexdrive(0, 0, 127, 2).withGain(20).withTol(1).waitUntilSettled();

// chassis.strafexdrive(-40, 30, 80, 2).withGain(20).withAngle(90, 127, 4).withRelative(false, 0.2).withTurnGain(6).withTol(1).waitUntilSettled();
// chassis.strafexdrive(0, 0, 127, 2).withGain(20).withAngle(0, 127, 4).withRelative(false, 0.2).withTurnGain(6).withTol(1).waitUntilSettled();

void skills5()
{
  //init
  chassis.lock();
  odom.zero();
  //flip out
  roller(-100);
  chassis.strafexdrive(-14, 0, 100, 2).withGain(20).withTol(.8).waitUntilSettled();
  delay(100);
  roller(127);
  scorer(-63);

  //begin driving
  chassis.drive(550, 127, 2).withTol(40).waitUntilSettled();
  scorer(25);

  //1st goal drive to
  // roller(-30);
  chassis.strafexdrive(-7, 38, 100, 2).withGain(20).withAngle(-45, 127, 4).withRelative(false, 0.5).withTurnGain(6).withTol(3).waitUntilSettled();
  // roller(-30);
  roller(0); //was -30, maybe change back
  //score start
  autonscore(3, 600, 700);
  // score(3, 600);
  // delay(1000);
  // roller(-30);
  // scorer(-25); //not sure if this is needed
  //score finish
  chassis.drive(-500, 127, 2).withGain(1).withTol(60).waitUntilSettled();
  afterscore();
  //1st goal finished

  //go to wall ball
  // chassis.turn(45, 127).withTol(5).waitUntilSettled();
  //toward wall ball
  // chassis.drive(380, 80, 2).withGain(1).withTol(80).waitUntilSettled();

  //2nd goal, turn and drive to
  // chassis.turn(90, 127).withTol(5).waitUntilSettled();
  // chassis.strafexdrive(-35, 33, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  //test this tmrw
  // chassis.strafexdrive(-35, 33, 80, 2).withGain(20).withAngle(90, 127, 20).withRelative(false, 0.9).withTurnGain(6).withTol(1).waitUntilSettled();
  // chassis.strafexdrive(-35, 33, 100, 2).withGain(20).withAngle(90, 127, 16).withRelative(false, 0.6).withTurnGain(6).withTol(1).waitUntilSettled();
  chassis.turn(90, 127).withTol(5).waitUntilSettled();
  // scorer(40); //was 50, changed
  chassis.drive(1700, 100, 2).withTol(50).waitUntilSettled();
  chassis.turn(0, 100).withTol(5).waitUntilSettled();
  scorer(0);
  delay(100);
  roller(45); //intake so ball doesnt fall out
  //driving into second goal
  chassis.left(80);
  chassis.right(80);
  delay(400);
  roller(0);
  //score start
  chassis.turn(0, 100).withTol(5).waitUntilSettled(); //prob not needed
  roller(0);
  autonscore(9, 600, 750);
  // roller(0);
  // roller(63);
  //score finish
  roller(30);
  chassis.drive(-500, 90, 2).withTol(60).waitUntilSettled();
  afterscore();
  delay(250); //maybe not needed, could just reduce speed of 90 in previous line
  //second goal finished

  //turn to 3rd ball and drive
  // chassis.turn(90, 127).withTol(5).waitUntilSettled();
  // roller(0);
  scorer(30);
  chassis.strafexdrive(-88, 20, 100, 2).withGain(20).withAngle(90, 127, 4).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  chassis.drive(600, 100, 2).withTol(100).waitUntilSettled();                                                                                      //changed speed from 90 to 127
  //can combine previous 2 or 3 movements into 1!

  //3rd goal, turn and drive to
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  chassis.strafexdrive(-115, 40, 100, 2).withGain(20).withTol(1).waitUntilSettled();
  roller(-30);
  //can combine previous 2 movements into 1!

  //score start
  autonscore(3, 600, 700);
  chassis.drive(-300, 127, 2).withTol(60).waitUntilSettled();
  afterscore();
  //third goal finished

  //4th goal
  scorer(30);
  chassis.strafexdrive(-105, -11, 80, 2).withGain(20).withAngle(90, 127, 4).withRelative(false, 0.5).withTurnGain(6).withTol(2).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  //if turning too slow, make the second withRelative value higher, if too fast/jerky, make it less
  chassis.left(80);
  chassis.right(80);
  delay(600); //needs to be tuned
  roller(-30);
  //score start
  chassis.turn(90, 100).withTol(5).waitUntilSettled(); //prob not needed
  autonscore(6, 600, 650);
  //score finish
  roller(-30);
  chassis.drive(-300, 100, 2).withTol(100).waitUntilSettled();
  afterscore();
  roller(-30);
  // drivePooper(75);
  // delay(100);
  //score finish
  //4th goal finished

  //poop
  //-back 300
  //-111, -/31
  //forward 700
  //-118, -70
  //5th goal, turn to ball on the way
  roller(127);
  chassis.strafexdrive(-111, -36, 90, 2).withGain(20).withAngle(180, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  drivePooper(0);
  // chassis.turn(180, 127).withTol(5).waitUntilSettled();
  scorer(30);
  // chassis.drive(1000, 100, 2).withTol(100).waitUntilSettled(); //changed speed from 90 to 127
  chassis.strafexdrive(-120, -66, 80, 2).withGain(20).withAngle(135, 127, 4).withTurnGain(6).withTol(3).waitUntilSettled(); //the -75 value is guessed, add a withrelative, 4 might be 16
  chassis.turn(135, 127).withTol(3).waitUntilSettled();
  odom.calibrateGyro();
  autonscore(4.5, 600, 2000);
  roller(0);
  odom.reset();
  odom.zero();

  //PART TWO
  chassis.drive(-800, 127, 2).withTol(150).waitUntilSettled();
  roller(127);
  scorer(-127); //was -127
  // chassis.turn(135, 100).withTol(5).waitUntilSettled();
  chassis.strafexdrive(-19, -29, 80, 2).withGain(20).withAngle(135, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  roller(127);
  scorer(40);
  chassis.drive(850, 100, 2).withTol(150).waitUntilSettled();
  scorer(40);
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  delay(100);
  chassis.left(80);
  chassis.right(80);
  roller(-30);
  delay(300);
  // roller(0)
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  autonscore(6, 600, 900);
  chassis.drive(-300, 100, 2).withTol(60).waitUntilSettled();
  afterscore();
  // delay(200);
  scorer(30);

  //turn to mid goal
  chassis.turn(-140, 100).withTol(5).waitUntilSettled();
  roller(127);
  // chassis.strafexdrive(200, -200, 100, 2).withGain(20).withRelative(true).withTol(50).waitUntilSettled();
  //drive to mid goal
  // chassis.strafexdrive(-1200, -600, 127, 2).withGain(20).withTol(1).withRelative(true).waitUntilSettled();

  chassis.strafexdrive(-23, -65, 100, 2).withGain(20).withTol(1).waitUntilSettled();
  delay(200);
  chassis.turn(-140, 100).withTol(3).waitUntilSettled();

  chassis.left(90);
  chassis.right(90);
  delay(750);
  // chassis.drive(1200, 90, 2).withTol(60).waitUntilSettled();

  // scorer(0);
  // chassis.unlock();
  // chassis.left(0);
  // chassis.right(0);
  // delay(200);
  chassis.left(-80);
  chassis.right(-80);
  delay(500);
  chassis.strafexdrive(-32, -72, 100, 2).withGain(20).withAngle(-95, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();
  // chassis.strafexdrive(-14, -79, 80, 2).withGain(20).withAngle(-94, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();
  // delay(200);
  // chassis.left(60);
  // chassis.right(60);
  // delay(350);
  chassis.drive(450, 100).withTol(100).waitUntilSettled();
  // chassis.left(0);
  // chassis.right(0);
  // delay(100);
  // chassis.turn(250, 100).withTol(5).waitUntilSettled();
  autonscore(5, 310, 600);
  //finish mid goal, drive back out
  // chassis.lock();
  chassis.drive(-700, 127, 2).withTol(100).waitUntilSettled();
  afterscore();
  chassis.strafexdrive(-34, -78, 100, 2).withGain(20).withAngle(225, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();

  // chassis.strafexdrive(-34, -78, 80, 2).withGain(20).withTol(1).waitUntilSettled();
  // chassis.turn(180, 127).withTol(5).waitUntilSettled();

  //turn to next ball
  // chassis.turn(180, 100).withTol(5).waitUntilSettled();
  scorer(30);
  //drive to next ball
  chassis.drive(900, 100, 2).withTol(150).waitUntilSettled();

  // chassis.strafexdrive(-17, -91, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  //drive to 8th goal
  chassis.strafexdrive(-42, -105, 100, 2).withGain(20).withAngle(135, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  chassis.left(80);
  chassis.right(80);
  delay(300);
  chassis.turn(135, 127).withTol(5).waitUntilSettled();
  autonscore(6, 600, 400);
  //finish 8th goal

  //drive to next ball
  chassis.drive(-300, 100, 2).withTol(150).waitUntilSettled();
  afterscore();
  // drivePooper(127);
  // delay(100);
  roller(127);
  // chassis.strafexdrive(-111, -36, 90, 2).withGain(20).withAngle(180, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  // drivePooper(0);
  scorer(30);
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  chassis.drive(1300, 100, 2).withTol(100).waitUntilSettled();
  roller(30);
  chassis.strafexdrive(-80, -72, 100, 2).withGain(20).withAngle(90, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  autonscore(10, 600, 700);
  // roller(0);
  // RollerT.move(127);
  // RollerB.move(127);
}

void skills3()
{

  roller(-63);
  chassis.strafexdrive(-14, 0, 80, 2).withGain(20).withTol(.8).waitUntilSettled();
  delay(300);
  roller(127);
  scorer(-63);
  chassis.drive(550, 127).withTol(40).waitUntilSettled();
  scorer(25);
  chassis.strafexdrive(-7, 40, 80, 2).withGain(20).withAngle(-45, 127, 4).withTurnGain(6).withTol(1).waitUntilSettled();
  roller(-30);
  score(3, 500);
  delay(1300);

  // chassis.drive(-300, 127).withTol(40).waitUntilSettled();
  // chassis.strafexdrive(-16, 40, 80, 2).withGain(20).withAngle(45, 127, 4).withRelative(false, 0.7).withTurnGain(6).withTol(1).waitUntilSettled();
  // chassis.drive(-300, 127).withTol(40).waitUntilSettled();

  chassis.strafexdrive(-13, 34, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  chassis.strafexdrive(-20, 40, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  chassis.turn(90, 127).withTol(5).waitUntilSettled();
  chassis.strafexdrive(-40, 30, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  // chassis.strafexdrive(-40, 30, 80, 2).withGain(20).withAngle(90, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled();
  chassis.strafexdrive(0, 0, 127, 2).withGain(20).withTol(1).waitUntilSettled();
}

void skills2()
{
  chassis.lock();
  // chassis.strafexdrive(-300, 300, 100, 2).withGain(20).withRelative(true).withTol(60).waitUntilSettled();
  // chassis.turn(0, 127).withTol(5).waitUntilSettled();

  chassis.drive(-800, 127, 2).withTol(150).waitUntilSettled();
  roller(127);
  scorer(-127); //was -127
  // chassis.turn(135, 100).withTol(5).waitUntilSettled();
  chassis.strafexdrive(-19, -29, 80, 2).withGain(20).withAngle(135, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  roller(127);
  scorer(40);
  chassis.drive(850, 100, 2).withTol(150).waitUntilSettled();
  scorer(40);
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  delay(100);
  chassis.left(80);
  chassis.right(80);
  roller(-30);
  delay(300);
  // roller(0)
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  autonscore(6, 600, 900);
  chassis.drive(-300, 100, 2).withTol(60).waitUntilSettled();
  afterscore();
  // delay(200);
  scorer(30);

  //turn to mid goal
  chassis.turn(-140, 100).withTol(5).waitUntilSettled();
  roller(127);
  // chassis.strafexdrive(200, -200, 100, 2).withGain(20).withRelative(true).withTol(50).waitUntilSettled();
  //drive to mid goal
  // chassis.strafexdrive(-1200, -600, 127, 2).withGain(20).withTol(1).withRelative(true).waitUntilSettled();

  chassis.strafexdrive(-25, -64, 100, 2).withGain(20).withTol(1).waitUntilSettled();
  delay(200);
  chassis.turn(-140, 100).withTol(3).waitUntilSettled();

  chassis.left(90);
  chassis.right(90);
  delay(750);
  // chassis.drive(1200, 90, 2).withTol(60).waitUntilSettled();

  // scorer(0);
  // chassis.unlock();
  // chassis.left(0);
  // chassis.right(0);
  // delay(200);
  chassis.left(-80);
  chassis.right(-80);
  delay(500);
  chassis.strafexdrive(-34, -75, 100, 2).withGain(20).withAngle(-95, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();
  // chassis.strafexdrive(-14, -79, 80, 2).withGain(20).withAngle(-94, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();
  // delay(200);
  // chassis.left(60);
  // chassis.right(60);
  // delay(400);
  // chassis.left(0);
  // chassis.right(0);
  chassis.drive(350, 100).withTol(100).waitUntilSettled();
  // chassis.turn(250, 100).withTol(5).waitUntilSettled();
  autonscore(5, 295, 500);
  //finish mid goal, drive back out
  // chassis.lock();
  chassis.drive(-700, 127, 2).withTol(100).waitUntilSettled();
  afterscore();
  chassis.strafexdrive(-40, -76, 100, 2).withGain(20).withAngle(-135, 127, 4).withTurnGain(6).withRelative(false, 0.5).withTol(1).waitUntilSettled();

  // chassis.strafexdrive(-34, -78, 80, 2).withGain(20).withTol(1).waitUntilSettled();
  // chassis.turn(180, 127).withTol(5).waitUntilSettled();

  //turn to next ball
  // chassis.turn(180, 100).withTol(5).waitUntilSettled();
  scorer(30);
  //drive to next ball
  chassis.turn(-135, 127).withTol(5).waitUntilSettled();
  chassis.drive(900, 100, 2).withTol(100).waitUntilSettled();

  // chassis.strafexdrive(-17, -91, 127, 2).withGain(20).withTol(1).waitUntilSettled();
  //drive to 8th goal
  chassis.strafexdrive(-38, -104, 100, 2).withGain(20).withAngle(135, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  chassis.left(80);
  chassis.right(80);
  delay(400);
  chassis.turn(135, 127).withTol(5).waitUntilSettled();
  autonscore(6, 600, 400);
  //finish 8th goal

  //drive to next ball
  chassis.drive(-300, 100, 2).withTol(150).waitUntilSettled();
  afterscore();
  // drivePooper(127);
  // delay(100);
  roller(127);
  // chassis.strafexdrive(-111, -36, 90, 2).withGain(20).withAngle(180, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  // drivePooper(0);
  scorer(30);
  chassis.turn(45, 127).withTol(5).waitUntilSettled();
  chassis.drive(1300, 100, 2).withTol(100).waitUntilSettled();
  roller(30);
  chassis.strafexdrive(-80, -75, 100, 2).withGain(20).withAngle(90, 127, 4).withTurnGain(6).withRelative(false, 0.3).withTol(1).waitUntilSettled();
  // autonscore(3, 600, 700);
  roller(0);
  RollerT.move(127);
  RollerB.move(127);

  //drive to ball
  // chassis.strafexdrive(-54, -82, 80, 2).withGain(20).withAngle(135, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4
  //drive to 6th goal
  // chassis.strafexdrive(-83, -76, 80, 2).withGain(20).withAngle(90, 127, 16).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled(); //untested values, attempted withangle(), maybe easier to just do .turn and then .strafexdrive or .strafe, 16 might be 4

  // chassis.turn(90, 127).withTol(5).waitUntilSettled();
  // chassis.drive(1200, 100, 2).withTol(60).waitUntilSettled();
  // chassis.turn(90, 127).withTol(5).waitUntilSettled();
}

void skills1()
{
  chassis.lock();
  odom.zero();

  chassis.strafexdrive(20, 20, 80, 2).withGain(20).withAngle(-90, 100, 4).withRelative(false, 0.5).withTurnGain(6).withTol(1).waitUntilSettled();
  delay(500);

  chassis.strafexdrive(-10, 10, 80, 2).withGain(20).withAngle(45, 127, 2).withRelative(false, 0.3).withTurnGain(6).withTol(1).waitUntilSettled();
  delay(500);
  
  chassis.strafexdrive(0, 0, 100, 2).withGain(20).withAngle(0, 100, 2).withRelative(false, 0.3).withTurnGain(6).withTol(1).waitUntilSettled();

}