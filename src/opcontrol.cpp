#include "main.h"

#include "kari/control/chassis.h"
#include "kari/control/rack.h"
#include "kari/control/arm.h"
#include "kari/util/odometry.h"
#include "kari/util/misc.h"
#include "kari/displayController.h"

#include "api.h"

void opcontrol()
{
	Odom odom;

	Chassis chassis(odom.getL(), odom.getR(), odom.getM(), odom.getThetaDeg(), odom.getX(), odom.getY(), odom.getXInch(), odom.getYInch());

	using namespace io;

	int towerMode = 0, lastPos = 0;
	bool isTrack = false;

	double kP = 0.12, kP_rev = 0.2;

	bool rel = false;

	macro::Slew roller(10, 2); // Accel, Decel
	macro::Slew topScorer(4);
	macro::Slew botScorer(9);

	LF.set_brake_mode(MOTOR_BRAKE_COAST);
	LB.set_brake_mode(MOTOR_BRAKE_COAST);
	RF.set_brake_mode(MOTOR_BRAKE_COAST);
	RB.set_brake_mode(MOTOR_BRAKE_COAST);

	bool pressedIntake = false;

	while (true)
	{
		// printf("%lf", LEncoder.get_value());
		// std::cout << master.get_analog(ANALOG_LEFT_Y) << std::endl;
		// std::cout << LEncoder.get_value() << std::endl;

		LF.move_velocity(master.get_analog(ANALOG_LEFT_Y) * 1.1 + master.get_analog(ANALOG_LEFT_X) * 1.1 + master.get_analog(ANALOG_RIGHT_X) * 0.6);
		LB.move_velocity(master.get_analog(ANALOG_LEFT_Y) * 1.1 - master.get_analog(ANALOG_LEFT_X) * 1.1 + master.get_analog(ANALOG_RIGHT_X) * 0.6);
		RF.move_velocity(-master.get_analog(ANALOG_LEFT_Y) * 1.1 + master.get_analog(ANALOG_LEFT_X) * 1.1 + master.get_analog(ANALOG_RIGHT_X) * 0.6);
		RB.move_velocity(-master.get_analog(ANALOG_LEFT_Y) * 1.1 - master.get_analog(ANALOG_LEFT_X) * 1.1 + master.get_analog(ANALOG_RIGHT_X) * 0.6);

		/*--------------------------------
				ROLLERS
		--------------------------------*/
		if (master.get_digital(DIGITAL_R1))
		{
			// roller.calculate(127);
			io::driveRoller(127);
			// io::driveTScorer(50);
			// io::driveBScorer(50);
			pressedIntake = true;
		}
		else if (master.get_digital(DIGITAL_R2))
		{

			// roller.calculate(-127);
			io::driveRoller(-127);
		}
		else
		{

			// roller.calculate(0);
			io::driveRoller(0);
			pressedIntake = false;
			// io::driveTScorer(0);
			// io::driveBScorer(0);
		}

		// io::driveRoller(roller.getOutput());

		if (master.get_digital(DIGITAL_L1)) //both up
		{
			// topScorer.calculate(127);
			// botScorer.calculate(127);
			io::driveTScorer(127);
			io::driveBScorer(127);
		}
		else if (master.get_digital(DIGITAL_L2)) //pooping
		{
			// topScorer.calculate(127);
			// botScorer.calculate(-127);
			io::driveTScorer(127);
			io::driveBScorer(-75);
		}
		else if (master.get_digital(DIGITAL_RIGHT)) //outake
		{
			// topScorer.calculate(-127);
			// botScorer.calculate(-127);
			io::driveTScorer(-127);
			io::driveBScorer(-127);
		}
		else if (master.get_digital(DIGITAL_X))
		{
			io::driveTScorer(80);
			io::driveBScorer(80);
		}
		else if (master.get_digital(DIGITAL_Y) || pressedIntake)
		{
			io::driveTScorer(50);
			io::driveBScorer(50);
		}
		else
		{
			// topScorer.calculate(0);
			// botScorer.calculate(0);
			// io::driveRoller(0);
			io::driveTScorer(0);
			io::driveBScorer(0);
		}

		std::cout << "X Position" << odom.getX() << std::endl;
		std::cout << "Y Position" << odom.getY() << std::endl;
		std::cout << "Heading" << odom.getThetaDeg() << std::endl;

		// io::driveTScorer(topScorer.getOutput());
		// io::driveBScorer(botScorer.getOutput());

		// std::cout << "Rack: " << RackMotor.get_current_draw() << "mA, Arm: " << ArmMotor.get_current_draw() << "mA, RollerL: " << RollerL.get_current_draw() << "mA, RollerR: " << RollerR.get_current_draw() << "mA" << std::endl;
		// std::cout << "Rack Output: " << rackSlew.getOutput() << ", Rack PID Output: " << rackPID.getOutput() << std::endl;

		// std::cout << "Rack: " << *rack.getPot() << ", Rack Output: " << rackSlew.getOutput() << std::endl;

		pros::delay(10);
	}
}
