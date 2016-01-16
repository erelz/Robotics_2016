
#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include "PngUtils/PngUtil.h"
#include "Commons/MapObject.h"
#include "Globals.h"
#include "Commons/Utils.h"
using namespace std;

class Map {
private:

	//*************************
	//	Private Members
	//*************************
	MapObject rawMap;	// Initial raw map
	MapObject blownMap;	// Raw map after blowing obstacles
	MapObject navigationMap; // Raw map after fixing the resolution

public:
	Map();
	~Map();
	/**
	 * Reads the map from the PNG file name, and creating the blown map for the a*
	 * and the scaled map for the localization manager
	 */
	void readMapFromPng(std::string path);

	//**********************
	//	Map objects accessors
	//**********************
	MapObject getNavMap(){
		return navigationMap;
	}

	MapObject& getBlownMap(){
		return blownMap;
	}

	//**********************
	//	Saving of the maps
	//**********************
	/**
	 * Taking the current raw map and save it as a PNG file with the file name.
	 */
	void saveRawMapAsPng(std::string fileName){
		Utils::writeMapToPng(fileName,this->rawMap);
	}

	/**
	 * Taking the current blown map and save it as a PNG file with the file name.
	 */
	void saveBlownMapAsPng(std::string fileName){
		Utils::writeMapToPng(fileName, this->blownMap);
	}

	/**
	 * Taking the current navigation map and save it as a PNG file with the file name.
	 */
	void saveNavigationMapAsPng(std::string fileName){
		Utils::writeMapToPng(fileName,this->navigationMap);
	}

	/**
	 * Printing the raw map.
	 */
	void printRawMap(){
		Utils::printMap(rawMap);
	}

	/**
	 *	Printing the blown map
	 */
	void printBlownMap(){
		Utils::printMap(blownMap);
	}

	/**
	 * Printing navigation Map;
	 */
	void printNavigationMap(){
		Utils::printMap(navigationMap);
	}

private :
	//******************************
	//		Private logic methods
	//******************************
	/**
	* Blowing the walls of the map 
	* by half the size of the robot.
	*/
	void makeBlownMap();

	void makeResulotionizedMapFromRawGrid();

	/**
	 * Returns the amount of pixels that should be blown from the
	 * raw pixel map in order to create the blown map.
	 */
	unsigned calculateAmountOfPixelesToBlow(){
		unsigned robotSize = ConfigurationsManager::getRobotSize();
		unsigned pixel2Cm = ConfigurationsManager::getPixel2Centimeter();

		// Returning half of the robot's size
		return ceil((robotSize / 2) / (float)pixel2Cm);
	}

	/**
	 * Takes the cell and mark the square around it as occupied
	 */
	void blowAreaInMap(MapObject& mapObject, unsigned x, unsigned y, unsigned blowSize){
		for (unsigned yModifier = y - blowSize; yModifier < y + blowSize;yModifier++){
			for (unsigned xModifier = x - blowSize; xModifier < x + blowSize; xModifier++){
				if(mapObject.isPositionValid(xModifier,yModifier)){
					mapObject.setCellAtPosition(xModifier,yModifier,Occupied);
				}
			}
		}
	}


	 // Gets a source map object and a location in the reducted map
	 // Scanning the area of the matching cells in the source map

	GridCell reductArea(MapObject& source, unsigned x, unsigned y, unsigned reductionSize){
		unsigned yBegin = y * reductionSize;
		unsigned xBegin = x * reductionSize;

	// Return true if the area is clear
		bool areaClear = true;

		for (unsigned yModifier = yBegin; yModifier < yBegin + reductionSize;yModifier++){
			for (unsigned xModifier = xBegin; xModifier < xBegin + reductionSize; xModifier++){
				// Checking that the source borders are not passed
				if(source.isPositionValid(xModifier,yModifier)){
					if (source.getCellAtPosition(xModifier,yModifier) == Occupied){
						areaClear = false;
						goto ScanQuickFailur;
					}
				}
			}
		}

		ScanQuickFailur:

		if (areaClear){
			return Clear;
		} else {
			return Occupied;
		}
	}
};

#endif
