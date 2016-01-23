/*
 * STC.h
 *
 *  Created on: Dec 10, 2015
 *      Author: colman
 */

#ifndef STC_H_
#define STC_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

#include "../Objects/Node.h"
#include "../Map/Map.h"
#include "../Objects/Location.h"

using namespace std;

typedef pair<int, int> Position;

class STC {
private:
	Map &mMap;
	Location mInitialRobotPos;
	vector<vector<Node *> > mGraph;
	vector<Location * > mPath;
	int mGraphHeight;
	int mGraphWidth;
	Node* mDFSStartNode;

	void printDFS(Node* node);
	void buildGraph();
	void printGraph();
	Node* DFS(int x, int y);
	void drawSpanningTree(vector<unsigned char> &image, Node* node, int mapWidth);
	void drawLine(vector<unsigned char> &image, Node* nodeA, Node* nodeB, int mapWidth);

	void buildSpanningTree(Node* node);

public:
	STC(Map &map, Location initialRobotPos);
	void saveSpanningTreeToFile(const char* filePath);
	virtual ~STC();
};

#endif /* STC_H_ */
