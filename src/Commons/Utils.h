
#ifndef UTILS_H_
#define UTILS_H_

#include <ostream>

#include "MapObject.h"
#include "../PngUtils/PngUtil.h"

using namespace std;

class Utils {
public:


//******************
//	Printing method
//*******************

	//	Printing the given map to the console

	static void printMap(MapObject& mapObject){
		for (unsigned y = 0; y < mapObject.getHeight(); y++){
			for (unsigned x = 0; x <mapObject.getWidth(); x++){
				cout << static_cast<char>(mapObject.getCellAtPosition(x,y));
			}
			cout << endl;
		}

		cout << endl;
	}


	//  Saving the map as a png with the given name

	static void writeMapToPng(std::string path, MapObject& mapObject){

		PngUtil::mapObjectToPng(path.c_str(),mapObject);
	}


	//	Assigning the path to the map

	static void insertPathToMap(MapObject& map, vector<GridPosition> path){
		for (GridPosition pos : path){
			map.setCellAtPosition(pos, Path);
		}
	}
	static float locationFromActualPosition(unsigned position, float _cell2Cm){
		float aproximateLocation = (position * _cell2Cm) + (((float)_cell2Cm) / 2);
		return aproximateLocation;
	}
};

#endif
