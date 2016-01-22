/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: colman
 */

#include "Configuration/ConfigurationManager.h"
#include "Map/Map.h"
#include <iostream>

#define PARAMS_FILE_PATH "parameters.txt";
using namespace std;

int main() {

	ConfigurationManager* config = new ConfigurationManager();
	const char *filePath = PARAMS_FILE_PATH;
	config->init(filePath);
	config->printConfig();

	// Map Init
	Map map(config->getMapResolution(), config->getRobotSize());
	map.loadMapFromFile(config->getMapLocation().c_str());

	map.inflateObstacles();
	map.printMap();

	//cout << "FineGrid";
	map.buildFineGrid();
	//map.printGrid(map.getFineGrid());

	cout << "CoarseGrid";
	map.buildCoarseGrid();
	map.printGrid(map.getCoarseGrid());

	return 0;
}
