/*
 * SimpleNavigation.h
 *
 *  Created on: Oct 21, 2013
 *      Author: filipfranczyk
 */

#ifndef SIMPLENAVIGATION_H_
#define SIMPLENAVIGATION_H_

#include "INavigation.h"
#include <string>

class SimpleNavigation : INavigation {
public:
	SimpleNavigation();
	virtual ~SimpleNavigation();

	virtual std::string NowPlaying();
	virtual void Play();
	virtual void Pause();
	virtual void Stop();
};

#endif /* SIMPLENAVIGATION_H_ */
