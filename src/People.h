/*
 * People.h
 *
 *  Created on: Oct 8, 2016
 *      Author: nichita
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

//#include "Skillset.h"


class People {
//	Skillset s;
	int people;
	int sick;
public:
	People();
	~People();
	void search();
	void cook();
	void prepare();
	void defend();

};

#endif /* PEOPLE_H_ */
