
#include "Behaviour.h"

Behaviour::Behaviour() {
    cout << "BAD CTOR CALLED" << endl;
}
Behaviour::Behaviour(Robot* robot) {
	_robot = robot;

}

Behaviour::~Behaviour() {
	// TODO Auto-generated destructor stub
}
