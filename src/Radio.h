/*
 * Radio.h
 *
 *  Created on: Oct 15, 2016
 *      Author: nichita
 */

#ifndef SRC_RADIO_H_
#define SRC_RADIO_H_

#include "Project.h"

class Radio: public Project { //gonna try a singleton pattern
	Radio* r;
	void reset();
	Radio();
	virtual ~Radio();
public:
	typedef Project super;
	std::string toString();
	static Radio* giveRadio();
};

#endif /* SRC_RADIO_H_ */
