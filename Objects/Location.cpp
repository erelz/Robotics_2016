
#include "Location.h"

void Location::construct(float x, float y, float yaw){
	this->_x = x;
	this->_y = y;
	this->_yaw = yaw;
}

Location::Location() {
	this->construct(0,0,0);
}

Location::Location(float x, float y, float yaw){
	this->construct(x,y, yaw);
}
