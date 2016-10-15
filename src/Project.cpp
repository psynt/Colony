#include "Project.h"
#include <sstream>
#include "Radio.h"
using namespace std;

Project::Project(string t, int dur,int ty) {
	name = t;
	duration = dur;
	time = 0;
	type=ty;

}
//Project::Project(){}

Project::~Project() {
	// important destructor
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
	if(type == 0) return Radio::toString();
	ostringstream os;
	os << name;
	if(isFinished()){
		os << " has been completed.";
	}else{
		os << " should take " << timeLeft() << " work units longer.";
	}
	return os.str();

}
