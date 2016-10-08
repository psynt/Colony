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
	// TODO Auto-generated constructor stub
	name=n;
}

Member::~Member() {
	// TODO Auto-generated destructor stub

}

string* Member::getName(){
	return &name;
}

