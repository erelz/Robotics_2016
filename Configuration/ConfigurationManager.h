/*
 * ConfigurationManager.h
 *
 *  Created on: Jan 21, 2016
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */


#include "../Objects/Location.h"

using namespace std;

namespace std {

class ConfigurationManager {

private:
	string mMapLocation;
	Location mRobotStartLocation;
	float mRobotSize;
	float mMapResolution;

	void ReadMapResolutionConfig(ifstream& confFile);
	void ReadRobotSizeConfig(ifstream& confFile);
	void ReadRobotStartLocationConfig(ifstream& confFile);
	void ReadMapLocationConfig(ifstream& confFile);

public:
	ConfigurationManager();
	void init(const char* configFilePath);
	void printConfig();
	virtual ~ConfigurationManager();
	
	const string& getMapLocation() const {
			return mMapLocation;
		}

		float getMapResolution() const {
			return mMapResolution;
		}

		float getRobotSize() const {
			return mRobotSize;
		}

		const Location& getRobotStartLocation() const {
			return mRobotStartLocation;
		}
};

} /* namespace std */

#endif /* CONFIGURATIONMANAGER_H_ */
