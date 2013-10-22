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
		std::string argv1 = std::string(argv[1]);
	    //Map with string and boost function goes here
		//Add boost support
		if(argv1 == "Play")
		{
			this->m_navigation.Play();
		}
		else if(argv1== "Pause")
		{
			this->m_navigation.Pause();
		}
	}
}
