#include "kari/util/odometry.h"
#include "kari/control/chassis.h"
#include "api.h"

// extern pros::Motor LF, LB, RF, RB;

pros::ADIEncoder LEncoder(1, 2, true),
                 REncoder(7, 8, true),
                 MEncoder(3, 4);

pros::Imu Imu_L(20), Imu_R(3);

bool Odom::isRunning = false;

int Odom::currentL = 0, Odom::currentR = 0, Odom::currentM = 0;
int Odom::deltaL = 0, Odom::deltaR = 0, Odom::deltaM = 0, Odom::lastDeltaL = 0, Odom::lastDeltaR = 0, Odom::lastDeltaM = 0;
double Odom::currentLF = 0, Odom::currentRF = 0, Odom::currentLB = 0, Odom::currentRB = 0;

double Odom::inertL = 0, Odom::inertR = 0, Odom::inertT = 0;
double Odom::thetaRad = 0, Odom::thetaDeg = 0, Odom::offset = 0, Odom::posX = 0, Odom::posY = 0;

double Odom::output = 0, Odom::Desiredtheta = 0, Odom::DesiredX = 0, Odom::DesiredY = 0;

double * Odom::getLF() {
  return &currentLF;
}

double * Odom::getRF() {
  return &currentRF;
}

double * Odom::getLB() {
  return &currentLB;
}

double * Odom::getRB() {
  return &currentRB;
}

int * Odom::getL() {
  return &currentL;
}

int * Odom::getR() {
  return &currentR;
}

int * Odom::getM() {
  return &currentM;
}

int * Odom::getDL() {
  return &deltaL;
}

int * Odom::getDR() {
  return &deltaR;
}

int * Odom::getDM() {
  return &deltaM;
}

double * Odom::getThetaRad() {
  return &thetaRad;
}

double * Odom::getThetaDeg() {
  return &thetaDeg;
}

double * Odom::getX() {
  return &posX;
}

double * Odom::getY() {
  return &posY;
}

Odom& Odom::calibrateGyro() {
  // Imu_T.reset();
  Imu_L.reset();
  Imu_R.reset();

  while( Imu_L.is_calibrating() || Imu_R.is_calibrating() ) { pros::delay(20); }
  io::master.rumble(" . .");
  return *this;
}

Odom& Odom::zero() {
  float left = abs( Imu_L.get_heading() - 360 ) * PI / 180;
  float right = abs( Imu_R.get_heading() - 360 ) * PI / 180;

  float x = ( cos( left + PI ) + cos( right + PI ) ) / 2;
  float y = ( sin( left + PI ) + sin( right + PI ) ) / 2;

  offset = abs( atan2f(y, x) + PI );
  return *this;
}

Odom& Odom::reset() {
  posX = posY = 0;
  return *this;
}

void Odom::start(void *ignore) {
  if(!isRunning) {
    pros::delay(500);
    Odom *that = static_cast<Odom*>(ignore);
    that -> run();
  }
}

extern double LB_get_position();
extern double LF_get_position();
extern double RB_get_position();
extern double RF_get_position();

void Odom::run() {
  isRunning = true;

  while(isRunning) {
    inertL = abs( Imu_L.get_heading() - 360 ) * PI / 180;
    inertR = abs( Imu_R.get_heading() - 360 ) * PI / 180;

    float x = ( cos( inertL - offset + PI ) + cos( inertR - offset + PI ) ) / 2;
    float y = ( sin( inertL - offset + PI ) + sin( inertR - offset + PI ) ) / 2;

    thetaRad = abs( atan2f(y, x) + PI );
    thetaDeg = thetaRad * 180 / PI;

    currentL = LEncoder.get_value();
    currentR = REncoder.get_value();
    currentM = MEncoder.get_value();

    deltaL = currentL - lastDeltaL;
    deltaR = currentR - lastDeltaR;
    deltaM = currentM - lastDeltaM;

    posX = posX + (( deltaL + deltaR ) / 2) * cos( thetaRad );
    posY = posY + (( deltaL + deltaR ) / 2) * sin( thetaRad );

    lastDeltaL = LEncoder.get_value();
    lastDeltaR = REncoder.get_value();
    lastDeltaM = MEncoder.get_value();

    currentLB = LB_get_position();
    currentLF = LF_get_position();
    currentRB = RB_get_position();
    currentRF = RF_get_position();

    pros::delay(10);
  }
}

void Odom::stop() {
  isRunning = false;
}
