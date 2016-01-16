
#include "Map.h"

Map::Map() {
}

Map::~Map(){

}

// Reading map from PNG file
void Map::readMapFromPng(std::string path) {
	cout << LOG_FINE << "Reading grid from PNG file." << endl;
	this->rawMap = PngUtil::mapObjectFromPng(path.c_str());

	this->makeBlownMap();
	this->makeResulotionizedMapFromRawGrid();
}

//*******************************
//		Private logic methods
//*******************************
void Map::makeBlownMap(){
	unsigned blowSize = this->calculateAmountOfPixelesToBlow();
	cout << LOG_INFO << "Amount of pixels to blow is " << blowSize << endl;

	// Getting the height and width
	unsigned height = rawMap.getHeight();
	unsigned width = rawMap.getWidth();

	// Creating a copy of the raw map
	MapObject newMap;
	newMap.defineDimensions(width,height);
	newMap.setCell2Cm(ConfigurationsManager::getPixel2Centimeter());

	for (unsigned y = 0; y < height; y ++){
		for (unsigned x = 0 ; x < width; x++){
			if(rawMap.getCellAtPosition(x,y) == Occupied){
				this->blowAreaInMap(newMap,x,y,blowSize);
			}
		}
	}

	this->blownMap = newMap;
}

void Map::makeResulotionizedMapFromRawGrid(){

	// Finding the dimensions of the navigation map
	float navigationres = ConfigurationsManager::getGridCell2Centimeter();
	float originalRes = ConfigurationsManager::getPixel2Centimeter();
	unsigned reductionRatio = ceil((navigationres / originalRes));

	cout << LOG_INFO << " reduction ratio is " << reductionRatio << endl;

	unsigned navWidth =  ceil(((float)rawMap.getWidth()) / reductionRatio);
	unsigned navHeight =  ceil(((float)rawMap.getHeight()) / reductionRatio);

	cout << LOG_INFO << "Navigation map dimensions are X=" << navWidth << " and Y=" << navHeight << endl;

	MapObject newMap;
	newMap.defineDimensions(navWidth,navHeight);
	newMap.setCell2Cm(navigationres);
	// Reduction from rawMap to navMap
	for (unsigned y = 0; y < navHeight ; y++){
		for (unsigned x = 0; x < navWidth; x++){
			newMap.setCellAtPosition(x,y,reductArea(rawMap,x,y,reductionRatio));
		}
	}

	// Assigning the new map
	this->navigationMap = newMap;
}


