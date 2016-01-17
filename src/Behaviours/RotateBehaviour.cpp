
#include "RotateBehaviour.h"
#include <math.h>

RotateBehaviour::RotateBehaviour(Robot* robot) : Behaviour(robot){
	// TODO Auto-generated constructor stub

}

bool RotateBehaviour::startCond()
{
	cout << "Started Action_Rotate" << endl;
	cout << "Rotating towards target : " << _robot->getTargetLocation().getX() << ", " << _robot->getTargetLocation().getY() << endl;
	cout << "My current Location is : " << _robot->getCurrentLocation().getX() << ", " << _robot->getCurrentLocation().getY() << endl;
	return true;
}
bool RotateBehaviour::stopCond()
{
	Location direction_unit_vector = (_robot->getTargetLocation() - _robot->getCurrentLocation());//.Normalize();
	float rad_angle = atan2(direction_unit_vector.getY(), direction_unit_vector.getX());

	if (fabs(rad_angle - _robot->getYaw()) <= 0.01f) // it is less than 1 degree diffrence.
	{
		_robot->setSpeed(0.0f,0.0f); // stop moving for now.
		return true;
	}

	return false;
}
void RotateBehaviour::action()
{
	Location direction_unit_vector = (_robot->getTargetLocation() - _robot->getCurrentLocation());//.Normalize();
	float rad_angle = atan2(direction_unit_vector.getY(), direction_unit_vector.getX());

	// rotate slowly to target angle
	if (_robot->getYaw() > rad_angle)
	{
	    _robot->setSpeed(0.0f, -0.15f);
	}
	else
	{
		_robot->setSpeed(0.0f, 0.15f);
	}
}
