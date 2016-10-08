//============================================================================
// Name        : T1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Player.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!\n"; // prints !!!Hello World!!!
	Player *p=new Player("Bob");
	cout<<"I am "<<*(p->getName())<<"\n";
	return 0;
}
