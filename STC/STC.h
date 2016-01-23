/*
 * STC.h
 *
 *  Created on: Dec 10, 2015
 *      Author: colman
 */

#ifndef STC_H_
#define STC_H_

#include <vector>
#include "../Objects/Node.h"
#include "../Map/Map.h"
#include "../Objects/Location.h"
#include <iostream>

using namespace std;

typedef pair<int, int> Position;

class STC {
private:
	Map &mMap;
	Location mInitialRobotPos;
	vector<vector<Node *> > mGraph;
	int mGraphHeight;
	int mGraphWidth;


	void printDFS();
	void buildGraph();
	void DFS(Node *node);
	Node* DFS(int x, int y);

public:
	STC(Map &map, Location initialRobotPos);
	void buildSpanningTree();
	void drawSpanningTree();
	virtual ~STC();
};

#endif /* STC_H_ */
