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

typedef char* charPtr;

TEST_F(CommandLineParsingTestSuite, TestPlay)
{
	ASSERT_TRUE(true);
	charPtr testArguments[2];
	testArguments[1] = static_cast<charPtr>("Play");
	EXPECT_CALL(*navigationMock, Play()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, TestPause)
{
	ASSERT_TRUE(true);
	charPtr testArguments[2];
	testArguments[1] = static_cast<charPtr>("Pause");
	EXPECT_CALL(*navigationMock, Pause()).Times(1);
	main->Execute(2, testArguments);
}
