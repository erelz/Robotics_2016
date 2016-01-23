///*
// * Manager.cpp
// *
// *  Created on: Jan 23, 2016
// *      Author: colman
// */
//
//#include "Manager.h"
//
//namespace std {
//
//Manager::Manager(Robot *robot, Behavior *startBehavior) :
//		mRobot(robot), mCurrBehavior(startBehavior) {
//}
//
//void Manager::run() {
//	mRobot->read();
//	if (!mCurrBehavior->startCond()) {
//		cout << "Cannot start the first behavior" << endl;
//		return;
//	}
//
//	while (mCurrBehavior != NULL) {
//		mCurrBehavior->action();
//		mRobot->read();
//
//		// Update particles...
//
//		if (mCurrBehavior->stopCond()) {
//			mCurrBehavior = mCurrBehavior->selectNext();
//		}
//	}
//	cout << "Manager stopped" << endl;
//}
//
//} /* namespace std */
