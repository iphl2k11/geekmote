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
	testArguments[1] = static_cast<charPtr>("Play");
	EXPECT_CALL(*navigationMock, Play()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, Pause)
{
	charPtr testArguments[2];
	testArguments[1] = static_cast<charPtr>("Pause");
	EXPECT_CALL(*navigationMock, Pause()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, Stop)
{
	charPtr testArguments[2];
	testArguments[1] = static_cast<charPtr>("Stop");
	EXPECT_CALL(*navigationMock, Stop()).Times(1);
	main->Execute(2, testArguments);
}

TEST_F(CommandLineParsingTestSuite, EmptyParametersList)
{
	charPtr testArguments[1]; //empty meaning there is only one parameter - program name
	EXPECT_CALL(*helpMock, BasicInfo()).Times(1);
	main->Execute(1, testArguments);
}
