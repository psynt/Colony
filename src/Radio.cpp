#include "Radio.h"
#include "Constants.h"
#include <sstream>
#include <string>
using namespace std;

Radio::Radio() : Project(RADIO){
	//important constructor
	completed=false;
}

Radio Radio::r;

Radio::~Radio() {
	//important destructor
}
bool Radio::isCompleted(){
	if(!completed){
		completed=this->isFinished();
	}
	return completed;
}

void Radio::reset(){
	r=Radio();
	giveRadio();
}

Radio Radio::giveRadio(){
	return r;
}


string Radio::toString(){
	ostringstream os;
	os << r.name;
	if(r.isFinished()){
		os << " repair finished.";
	}else{
		os << " repair in progress.";
	}
	return os.str();
}
