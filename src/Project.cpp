/*
 * Project.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */

#include "Project.h"
#include<sstream>
using namespace std;

Project::Project(string* t, int dur,int ty) {
	name = t;
	duration = dur;
	time = 0;
	type=ty;

}

Project::~Project() {
	// TODO Auto-generated destructor stub
}

void Project::advance(int a){
	if(a>0)
		time+=a;
}
int Project::timeLeft(){
	return duration-time;
}
bool Project::isFinished(){
	return duration-time<=0;
}

string Project::toString(){
	ostringstream os;
	if(type != 0){
		os << *name;
		if(isFinished){
			os << " is finished.";
		}else{
			os << " should take " << timeLeft() << "longer.";
		}
	}
	return os.str();

}
