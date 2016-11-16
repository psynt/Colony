#include "Project.h"
#include <sstream>
#include "Radio.h"
#include "Constants.h"
using namespace std;

Project::Project(string t, int dur,int ty) {
	name = t;
	duration = dur;
	time = 0;
	type=ty;
}

Project::~Project() {
	// important destructor
}

int Project::getSCost(int type){
	int c;
	if(type == RAD_TYPE) c=RADIO_C_SCRAP;
	if(type == TUR_TYPE) c=TUR_C_SCRAP;
	if(type == HOB_TYPE) c=HOB_C_SCRAP;
	return c;
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
		os << " should take " << timeLeft() << " more work units.";
	}
	return os.str();

}
