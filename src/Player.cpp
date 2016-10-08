/*
 * Player.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Player.h"
#include<string>
using namespace std;

Player::Player(string n) {
	// TODO Auto-generated constructor stub
	name=n;
}

Player::~Player() {
	// TODO Auto-generated destructor stub

}

string* Player::getName(){
	return &name;
}

