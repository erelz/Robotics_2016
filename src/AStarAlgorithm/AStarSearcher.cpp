
#include "AStarSearcher.h"

AStarSearcher::AStarSearcher() {
}

void AStarSearcher::aStarSearch(MapGraphObject mapGraph,
		GridPosition start, GridPosition target,
		Matrix<GridPosition>& parentsMap,
		Matrix<int>& costMap){
	MyPq frontier;

	cout << "Search From: " ;
	start.printString();
	cout << endl;



	cout << "Search To : " ;
	target.printString();
	cout << endl;


	// initialize the start node
	frontier.put(start, 0);
	parentsMap.setValueAtPosition(start,start);
	costMap.setValueAtPosition(start,0);

	// Perform the search
	while (!frontier.empty()){
		GridPosition current = frontier.get();
		//cout << LOG_DEBUG << "Cur is node X=" << current.getX() << " and Y=" << current.getY() << endl;

		if (current == target){
			cout << LOG_INFO << "Reached target" << endl;
			break;
		}
		vector<GridPosition> neighbors = mapGraph.neighbors(current);
		for (GridPosition next : neighbors){

			int newCost = costMap[current] + mapGraph.cost(current,next);

			// Is the next node was not reached yet ? or dose the new cost is lower than
			// the cast it had so far ?
			if ((costMap.isPositionDefault(next)) || (newCost < costMap[next])){

				cout << LOG_DEBUG << "Best chosen X=" << next.getX() << " and Y=" << next.getY() << " Because : ";
				if (costMap.isPositionDefault(next)){
					cout << "Cost : " << newCost << endl;
				} else {
					cout << newCost <<  " better than " << costMap[next] << endl;
				}

				costMap[next] = newCost;

				// Get the new priority of the node
				int priority = newCost + heuristic(next, target);

				frontier.put(next, priority);
				parentsMap[next] = current;

			}
		}
	}
	cout << LOG_DEBUG << "A* Completed "  << endl;
	if (parentsMap.isPositionDefault(target)){
		cout << "Failed to find the best path" << endl;
	}
}

