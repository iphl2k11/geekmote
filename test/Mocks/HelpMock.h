/*
 * HelpMock.h
 *
 *  Created on: Oct 22, 2013
 *      Author: filipfranczyk
 */

#ifndef HELPMOCK_H_
#define HELPMOCK_H_

#include "IHelp.h"
#include <gmock/gmock.h>

class HelpMock : public IHelp
{
public:
	MOCK_METHOD0(BasicInfo, void());
	MOCK_METHOD0(UnknownParameter, void());
};


#endif /* HELPMOCK_H_ */
