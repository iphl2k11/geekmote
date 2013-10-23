/*
 * Main.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: filipfranczyk
 */
#include "Main.h"

Main::~Main()
{

}

void Main::Execute(int argc, char** argv)
{
	if (argc == 1)
	{
		this->m_help.BasicInfo();
		return;
	}

	if (argc == 2)
	{
		std::string cmd = std::string(argv[1]);
		if (cmd == std::string("NowPlaying"))
		{
			this->m_navigation.NowPlaying();
			return;
		}

		Commands::iterator found = commands.find(cmd);
		if (found == commands.end())
		{
			m_help.UnknownParameter();
			return;
		}

		found->second();
	}
}
