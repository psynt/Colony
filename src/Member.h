/*
 * Member.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include<string>
#ifndef MEMBER_H_
#define MEMBER_H_

using namespace std;

class Member {
	string name;
public:
	Member(string n);
	~Member();
	string* getName();
};

#endif /* MEMBER_H_ */
