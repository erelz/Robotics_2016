
#include "RobotLocation.h"

void RobotLocation::construct(float yaw){
	this->_yaw = yaw;
}

RobotLocation::RobotLocation():Location() {
	this->construct(0);
}
RobotLocation::RobotLocation(float yaw):Location(){
	this->construct(yaw);
}
RobotLocation::RobotLocation(float x, float y):Location(x,y){
	this->construct(0);
}
RobotLocation::RobotLocation(float x, float y, float yaw):Location(x,y){
	this->construct(yaw);
}

