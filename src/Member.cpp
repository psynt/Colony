/*
 * Member.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Member.h"
#include<string>
using namespace std;

Player::Member(string n) {
	// TODO Auto-generated constructor stub
	name=n;
}

Player::~Member() {
	// TODO Auto-generated destructor stub

}

string* Member::getName(){
	return &name;
}

