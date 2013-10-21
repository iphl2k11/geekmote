/*
 * SimpleTest.cpp
 *
 *  Created on: Oct 17, 2013
 *      Author: filipfranczyk
 */

#include <gtest/gtest.h>
#include "NavigationMock.h"
#include "Main.h"

using ::testing::Test;

class CommandLineParsingTestSuite : public ::testing::Test
{
public:
	CommandLineParsingTestSuite():navigationMock(new NavigationMock()),
								  main(new Main(*navigationMock))
	{

	}

	~CommandLineParsingTestSuite()
	{
		delete navigationMock;
		delete main;

	}

protected:
	NavigationMock *navigationMock;
	Main *main;



};

TEST_F(CommandLineParsingTestSuite, TestPlay)
{
	ASSERT_TRUE(true);
//	EXPECT_CALL(*navigationMock, Play()).Times(1);
//	main->Execute(2,)
}
