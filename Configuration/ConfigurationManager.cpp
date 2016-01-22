/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: colman
 */

#include "ConfigurationManager.h"

namespace std {

ConfigurationManager::ConfigurationManager() {
	// TODO Auto-generated constructor stub
}

void ConfigurationManager::init(const char* configFilePath) {


	ifstream confFile(configFilePath);

	ReadMapLocationConfig(confFile);
	ReadRobotStartLocationConfig(confFile);
	ReadRobotSizeConfig(confFile);
	ReadMapResolutionConfig(confFile);
}


void ConfigurationManager::ReadRobotSizeConfig(ifstream& confFile) {
	string parameterName;
	string line;
	string robotSizeCMStr;
	getline(confFile, line);
	istringstream robotSizeStream(line);
	robotSizeStream >> parameterName >> robotSizeCMStr;
	mRobotSize = atof(robotSizeCMStr.c_str());
}

void ConfigurationManager::ReadRobotStartLocationConfig(ifstream& confFile) {
	string parameterName;
	string line;
	string initXStr, initYStr, initYawStr;
	getline(confFile, line);
	istringstream initPositionStream(line);
	initPositionStream >> parameterName >> initYStr >> initXStr >> initYawStr;
	int initX = atoi(initXStr.c_str());
	int initY = atoi(initYStr.c_str());
	int initYaw = atoi(initYawStr.c_str());
	mRobotStartLocation = Location(initX, initY, initYaw);
}

void ConfigurationManager::ReadMapLocationConfig(ifstream& confFile) {
	string parameterName;
	string line;
	string mapLocation;
	getline(confFile, line);
	istringstream mapLoactionStream(line);
	mapLoactionStream >> parameterName >> mapLocation;
	this->mMapLocation = mapLocation;
}

void ConfigurationManager::ReadMapResolutionConfig(ifstream& confFile) {
	string parameterName;
	string line;
	string mapResolutionCMStr;
	getline(confFile, line);
	istringstream mapResolutionStream(line);
	mapResolutionStream >> parameterName >> mapResolutionCMStr;
	mMapResolution = atof(mapResolutionCMStr.c_str());
}

void ConfigurationManager::printConfig() {

	cout << "Map Location: " << mMapLocation << endl;
	cout << "initial robot position: (" << mRobotStartLocation.getX() << "," << mRobotStartLocation.getY() << "," << mRobotStartLocation.getYaw() << ")" << endl;
	cout << "robot size: " << mRobotSize << endl;
	cout << "map resolution: " << mMapResolution << endl;


}


ConfigurationManager::~ConfigurationManager() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
