#ifndef PEOPLE_H_
#define PEOPLE_H_

//#include "Skillset.h"


class People {
//	Skillset s;
	int people,sick;
public:
	People();
	~People();
	void search();
	void cook();
	void prepare();
	void defend();
	int getPeople();
	int getSick();

};

#endif /* PEOPLE_H_ */
