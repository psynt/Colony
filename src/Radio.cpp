#include "Radio.h"
#include "Constants.h"
#include <sstream>
#include <string>
using namespace std;

Radio::Radio() : Project(RADIO){
	//important constructor
}

Radio Radio::r;

Radio::~Radio() {
	//important destructor
}


void Radio::reset(){
	r=Radio();
	giveRadio();
}

Radio Radio::giveRadio(){
//	if(r==0){
//		r=Radio();
//	}
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
