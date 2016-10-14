/*
 * Project.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */

#include "Project.h"

Project::Project(std::string* t, int dur,int ty) {
	name = t;
	duration = dur;
	time = 0;
	type=ty;

}

Project::~Project() {
	// TODO Auto-generated destructor stub
}

