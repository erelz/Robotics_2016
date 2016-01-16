
#include <iostream>
#include "Map.h"
#include "PngUtils/PngUtil.h"
#include "PathFinder.h"
#include "WayPointsManager.h"

#include "Robot.h"
#include "Behaviours/Manager.h"
#include "Behaviours/Plans/PlanDrive.h"

using namespace std;

void fitInitialLocationOfRealWorld(RobotLocation &initialSimulationLocation)
{
    float cell2cm = ConfigurationsManager::getPixel2Centimeter();
    initialSimulationLocation.setX(Utils::locationFromActualPosition(initialSimulationLocation.getX(), cell2cm));
    initialSimulationLocation.setY(Utils::locationFromActualPosition(initialSimulationLocation.getY(), cell2cm));

	initialSimulationLocation.setX(1.975f);
	initialSimulationLocation.setY(-2.6375f);
	initialSimulationLocation.setYaw(20.0f * 3.14159f / 180.0f);
}

Map readFromPng()
{
	string mapPath = "roboticLabMap.png";

	Map map;
	map.readMapFromPng(mapPath);

	return map;
}

	// GEtting the parameters from configuration
void getParametersFromConfig()
{
	string confFilePath ="parameters.txt" ;
	ConfigurationsManager::initializeFromFile(confFilePath);

}

int main() {

	//
	// Reading the parameters file
	//
	getParametersFromConfig();

	//
	// Reading the PNG to the map
	//
	Map map = readFromPng();

	//
	// Find a path using A*
	//
	PathFinder pathFinder(map.getBlownMap());
	RobotLocation initialSimulationLocation = ConfigurationsManager::getRobotInitialLocation();
	pathFinder.findPath(initialSimulationLocation.getLocation(),
						ConfigurationsManager::getDestination());

	//
	// Print it to PNG File
	//
	pathFinder.saveFullPathToPng("fullPath.png");

	//
	// Getting the Way Points
	//
	WayPointsManager wpManager(pathFinder.getChosenPath(),map.getBlownMap());

	cout << "Way-Points number: " << wpManager.getNumberOfWayPoints() << endl;

	//
	// Printing Way Points
	//
	wpManager.savePointsOnMap("waypoints.png");

	cout << "Way-Points are ready, start moving.." << endl;

	fitInitialLocationOfRealWorld(initialSimulationLocation);

	//
	// Connecting to the robot
	//
	Robot* robot = new Robot("localhost",6665, initialSimulationLocation);

	cout << "initial Robot location (in simulation) :" << robot->getCurrentLocation().getX() << ", " << robot->getCurrentLocation().getY() << endl;
	PlanDrive plnOA(robot, &wpManager);
	Manager manager(robot, &plnOA);
	manager.run();
	cout << "Finished :)" << endl;


	return 0;
}


