/*
 * NavigationMock.h
 *
 *  Created on: Oct 21, 2013
 *      Author: filipfranczyk
 */

#ifndef NAVIGATIONMOCK_H_
#define NAVIGATIONMOCK_H_

#include "INavigation.h"
#include <gmock/gmock.h>

class NavigationMock : public INavigation
{
public:
	MOCK_METHOD0(NowPlaying, std::string());
	MOCK_METHOD0(Play, void());
	MOCK_METHOD0(Pause, void());
	MOCK_METHOD0(Stop, void());
};

#endif /* NAVIGATIONMOCK_H_ */
