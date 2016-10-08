/*
 * Player.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include<string>
#ifndef PLAYER_H_
#define PLAYER_H_

using namespace std;

class Player {
	string name;
public:
	Player(string n);
	~Player();
	string* getName();
};

#endif /* PLAYER_H_ */
