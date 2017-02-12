/*
 * cShootPID.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: s-2505674
 */
#include "Subsystems/cShooter.h"
#include "cShootPID.h"
#include <cmath>
#include "RobotMap.h"


cShootPID::cShootPID(double leftSpeed, double rightSpeed, float timeout) :
		leftSpeed(leftSpeed), rightSpeed(rightSpeed), timeout(timeout)
{

}

void cShootPID::Initialize()
{
	s_shooter->getLeft()->EnablePID();
	s_shooter->getRight()->EnablePID();

	s_shooter->getLeft()->setPID(p, i, d);
	s_shooter->getRight()->setPID(p, i, d);

	left_setpoint = fmax(5.0, s_shooter->getLeft()->PIDGet());
	right_setpoint = fmax(5.0, s_shooter->getRight()->PIDGet());

	s_shooter->getRight()->setSetpoint(right_setpoint);
	s_shooter->getLeft()->setSetpoint(left_setpoint);

	leftRamped = false;
	rightRamped = false;

	if (timeout != 0)
	{
		SetTimeout(timeout);
	}
}

void cShootPID::Execute()
{
	if (!s_shooter->getLeft()->isPIDEnabled()) {
		s_shooter->getLeft()->EnablePID();
	}

	if (!s_shooter->getRight()->isPIDEnabled()) {
		s_shooter->getRight()->EnablePID();
	}

	if (left_setpoint < leftSpeed) {
		left_setpoint += 2;
	} else {
		left_setpoint = leftSpeed;
		s_shooter->getLeft()->setSetpoint(left_setpoint);
		leftRamped = true;
	}

	if (right_setpoint < rightSpeed) {
		right_setpoint += 2;
	} else {
		right_setpoint = rightSpeed;
		s_shooter->getRight()->setSetpoint(right_setpoint);
		rightRamped = true;
	}

	if(leftRamped && rightRamped)
	{
		/* .                                                .
.             `/oyyyyso+:.                       .
.           -ohdmmmmdmmmhyo.                     .
.         -ohddmdddddddddhyh+                    .
.        :hddmmmddmdddddddhyho                   .
.        smmmmmmdmmmmmddddhyy+                   .
.       `sdmmmmmmmmmmmhosddhhs                   .
.       `+-sdmmmmmdds/--.sdddy                   .
.        /-//+osso/------+ddd+--                 .
.       `/:::::::::::----:ods//+sydh:`           .
.        .:++/:::::/oo+/-..s/:/ymmdsyy+.         .
.         `/oyho/+sysoo+:-.o+/+mmhhddhhhs+-      .
.          -////:-:::::::--so/hddmmmmdhyyyys/-`  .
.          .::+/:--:++//:::++hdddmdhhhdddhyyssyyo/
.           ./o+/////+o+///odddddhmmmmdddddddhyshd
.            ./oo+////:///smmmdddmmmmmddddddddhhsh
.             `:////::::/ymdddddmmmmmdddddddddhhhs
.              `:::--::/hdydddhmmmmmmddddddddddhhd
.               `-::::smdosyhymdmmmmmddddddddddhhd
.                     smd/sysdmdmdmmmddddddddddhhd
.                     -msyysymmhdddmmddddddddddhdy
.                     `h+s++mmmddddmmddddddddddhsh
. `````               `so+/sdmmddddmmdddddddddyydm
/:----`               `/o+/yshmmhhdmmddddddddddddm
/-...`                 .s++yhhysyhdmdddddddddddddm
		 *  */
	}

}

bool cShootPID::IsFinished()
{
	return IsTimedOut();
}

void cShootPID::End()
{
	s_shooter->getLeft()->DisablePID();
	s_shooter->getRight()->DisablePID();
	s_shooter->getRight()->ResetPID();
	s_shooter->getLeft()->ResetPID();
}

void cShootPID::Interrupted()
{
	End();
}
