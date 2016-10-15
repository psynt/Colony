/*
 * Project.h
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */
#include <string>
using namespace std;
#ifndef SRC_PROJECT_H_
#define SRC_PROJECT_H_


class Project {
protected:
	int type;
	string name;
	int time;
	int duration;
public:
//	Project();
	Project(string,int,int);
	virtual ~Project();
	void advance(int);
	int timeLeft();
	bool isFinished();
	std::string toString();
};

#endif /* SRC_PROJECT_H_ */
