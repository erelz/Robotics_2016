
#include "MapObject.h"

MapObject::MapObject() {
	this->_cell2Cm = 1;
	this->_height = 0;
	this->_width = 0;
	this->defineDimensions(0,0);
}

MapObject::MapObject(vector<vector<GridCell> > cellMatrix, unsigned width, unsigned height, float cell2cm){
	this->_cellMatrix = cellMatrix;
	this->_width = width;
	this->_height = height;
	this->_cell2Cm = cell2cm;
}

MapObject::~MapObject(){
	this->_cellMatrix.clear();
}

void MapObject::defineDimensions(unsigned width, unsigned height){

	this->_width = width;
	this->_height = height;


	this->_cellMatrix.resize(height);


	for (unsigned y = 0; y < height; y++){
		this->_cellMatrix[y].resize(width);
	}
}

void MapObject::clearMatrix(){
	unsigned width, height;
	height = this->getHeight();
	width  = this->getWidth();

	for (unsigned y = 0; y < height; y++) {
		for (unsigned x = 0; x < width ; x++){
			this->_cellMatrix[y][x] = Clear;
		}
	}
}

