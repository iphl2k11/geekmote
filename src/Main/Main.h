/*
 * Main.h
 *
 *  Created on: Oct 21, 2013
 *      Author: filipfranczyk
 */

#ifndef MAIN_H_
#define MAIN_H_

//TODO  make it bost noncopyable
//

#include "INavigation.h"
#include "IHelp.h"

class Main
{
public:
	Main(INavigation &navigation, IHelp &help):m_navigation(navigation), m_help(help)
	{

	}

	~Main();
	void Execute(int argc, char** argv);

private:
	INavigation & m_navigation;
	IHelp		& m_help;
};


#endif /* MAIN_H_ */
