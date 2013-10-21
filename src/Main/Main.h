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
class Main
{
public:
	Main(INavigation &navigation):m_navigation(navigation)
	{

	}

	~Main();
	void Execute(int argc, char** argv);

private:
	INavigation & m_navigation;
};


#endif /* MAIN_H_ */
