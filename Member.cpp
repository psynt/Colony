/*
 * Member.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Member.h"
#include<string>
using namespace std;

Member::Member(string n) {
	name=n;
}

Member::~Member() {
	// important
}

string* Member::getName(){
	return &name;
}

