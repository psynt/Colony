/*
 * Radio.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */

#include "Radio.h"
#include "Constants.h"
#include <sstream>
#include <string>
using namespace std;

Radio::Radio() {
	r=new super(RADIO);

}

Radio::~Radio() {
	//important destrictor
}

void Radio::reset(){
	delete r;
	giveRadio();
}

Radio* Radio::giveRadio(){
	if(r==0){
		this();
	}
	return r;
}

string Project::toString(){
	ostringstream os;
	os << *name;
	if(isFinished){
		os << " repair finished.";
	}else{
		os << " repair in progress.";
	}
	return os.str();
}
