#include "Member.h"
#include<string>
using namespace std;

Member::Member(string n) {
	name=n;
}

Member::~Member() {
	// important destructor
}

string* Member::getName(){
	return &name;
}
