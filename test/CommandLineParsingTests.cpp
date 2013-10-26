/*
 * SimpleTest.cpp
 *
 *  Created on: Oct 17, 2013
 *      Author: filipfranczyk
 */

#include <gtest/gtest.h>
#include "NavigationMock.h"
#include "HelpMock.h"
#include "Main.h"

using ::testing::Test;
using ::testing::Return;

//TODO move all those "play, pause,stop " words to constants
//Just a comment to test if everything works fine

class CommandLineParsingTestSuite : public ::testing::Test
{
public:
	CommandLineParsingTestSuite():navigationMock(new NavigationMock()),
							      helpMock(new HelpMock()),
								  main(new Main(*navigationMock, *helpMock))
	{

	}

	~CommandLineParsingTestSuite()
	{
		delete navigationMock;
		delete helpMock;
		delete main;

	}

protected:
	NavigationMock* navigationMock;
	HelpMock* helpMock;
	Main* main;
};

typedef char* charPtr;

TEST_F(CommandLineParsingTestSuite, Play)
{
	charPtr testArguments[2];
    testArguments[1] = "Play";
	EXPECT_CALL(*navigationMock, Play()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, Pause)
{
	charPtr testArguments[2];
    testArguments[1] = "Pause";
	EXPECT_CALL(*navigationMock, Pause()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, Stop)
{
	charPtr testArguments[2];
    testArguments[1] = "Stop";
	EXPECT_CALL(*navigationMock, Stop()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, NowPlaying)
{
	charPtr testArguments[2];
    testArguments[1] = "NowPlaying";
	EXPECT_CALL(*navigationMock, NowPlaying()).Times(1).WillOnce(Return("Test"));
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, EmptyParametersList)
{
	charPtr testArguments[1]; //empty meaning there is only one parameter - program name
	EXPECT_CALL(*helpMock, BasicInfo()).Times(1);
	main->Execute(1, testArguments);
}

TEST_F(CommandLineParsingTestSuite, UnknownParameter)
{
	charPtr testArguments[2];
    testArguments[1] = "Unknown";
	EXPECT_CALL(*helpMock, UnknownParameter()).Times(1);
	main->Execute(2, testArguments);
}
