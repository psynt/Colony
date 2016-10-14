/*
 * Skillset.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#include "Skillset.h"

Skillset::Skillset(int g,int c, int f) {
	gathering=g;
	cooking=c;
	fighting=f;
}

Skillset::~Skillset() {
	// important destructor
}
