
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Commons/RobotLocation.h"

class RobotLocation;
class Location;

using namespace std;

class ConfigurationsManager {
private :
	static string _mapPath;
	static RobotLocation _robotInitialLocation;
	static Location _destination;
	static unsigned _robotSize; // in Cm
	static unsigned _pixel2Centimeter;
	static unsigned _gridCell2Centimeter;
public:

	//
	// Read the parameters file
	//
	static void initializeFromFile(string filePath);

	static const string& getMapPath(){
		return _mapPath;
	}

	static void setMapPath(string& mapPath) {
		_mapPath = mapPath;
	}

	static const RobotLocation getRobotInitialLocation(){
		return _robotInitialLocation;
	}

	static void setRobotInitialLocation(RobotLocation& robotInitialLocation) {
		_robotInitialLocation = robotInitialLocation;
	}

	static const Location getDestination() {
		return _destination;
	}

	static void setDestination(Location& destination) {
		_destination = destination;
	}

	static unsigned getRobotSize() {
		return _robotSize;
	}

	static void setRobotSize(unsigned robotSize) {
		_robotSize = robotSize;
	}

	static unsigned getPixel2Centimeter(){
		return _pixel2Centimeter;
	}

	static void setPixel2Centimeter(unsigned pixel2Centimeter) {
		_pixel2Centimeter = pixel2Centimeter;
	}

	static unsigned getGridCell2Centimeter() {
		return _gridCell2Centimeter;
	}

	static void setGridCell2Centimeter( unsigned gridCell2Centimeter) {
		_gridCell2Centimeter = gridCell2Centimeter;
	}

private:


	//	Parse map location
	static void parseMapLocation(string mapLocation){
		setMapPath(mapLocation);
	}

	
	// Parse robot's initial location

	static void parseInitialLocation(string strX, string strY, string strYaw){
		unsigned x = atoi(strX.c_str());
		unsigned y = atoi(strY.c_str());
		unsigned yaw = atoi(strYaw.c_str());
		RobotLocation cLoc = RobotLocation(x,y,yaw);
		setRobotInitialLocation(cLoc);
	}

	
	 // Parse target's location
	 
	static void parseTargetLocation(string strX, string strY){
		unsigned x = atoi(strX.c_str());
		unsigned y = atoi(strY.c_str());

		Location loc = Location(x,y);
		setDestination(loc);
	}

	
	 // Parse the robot's size
	 
	static void parseRobotSize(string strXSize, string strYSize){
		unsigned x = atoi(strXSize.c_str());
		unsigned y = atoi(strYSize.c_str());

		setRobotSize(std::max(x,y));
	}

	
	 // Parse the map's resolution
	
	static void parseMapResolution(string strCell2Cm){
		float cell2Cm = atof(strCell2Cm.c_str());
		setPixel2Centimeter(cell2Cm);
	}


	static void parseNavigationResolution(string strNavRes){
		float navRes = atof(strNavRes.c_str());
		setGridCell2Centimeter(navRes);
	}
};


#endif
