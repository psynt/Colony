/*
 * Project.h
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */
#include <string>
#ifndef SRC_PROJECT_H_
#define SRC_PROJECT_H_


class Project {
	int type;
	std::string* name;
	int time;
	int duration;
public:
	Project(std::string*,int,int);
	virtual ~Project();
};

#endif /* SRC_PROJECT_H_ */
