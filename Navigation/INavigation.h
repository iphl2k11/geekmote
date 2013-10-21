/*
 * INavigation.h
 *
 *  Created on: Oct 21, 2013
 *      Author: filipfranczyk
 */

#ifndef INAVIGATION_H_
#define INAVIGATION_H_
#include <string>

struct INavigation
{
	virtual std::string NowPlaying() = 0;
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;

	virtual ~INavigation()
	{

	}
};



#endif /* INAVIGATION_H_ */
