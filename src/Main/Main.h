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

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <map>
#include <string>
#include "INavigation.h"
#include "IHelp.h"

class Main
{
public:
	Main(INavigation &navigation, IHelp &help):m_navigation(navigation), m_help(help)
	{
		commands["Play"]  = boost::bind(&INavigation::Play, boost::ref(m_navigation));
		commands["Pause"] = boost::bind(&INavigation::Pause, boost::ref(m_navigation));
		commands["Stop"]  = boost::bind(&INavigation::Stop, boost::ref(m_navigation));
	}

	~Main();
	void Execute(int argc, char** argv);

private:
	INavigation & m_navigation;
	IHelp		& m_help;
	std::map<std::string, boost::function<void()> > commands;
};


#endif /* MAIN_H_ */
