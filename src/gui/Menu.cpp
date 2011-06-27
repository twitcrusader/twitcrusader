/*
 *	 TwitCrusader-GUI is part of TwitCrusader - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader Team
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *		WebSite: http://www.twitcrusader.org/
 * 		Development Guidelines: http://dev.twitcrusader.org/
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */

#include "include/Menu.h"

namespace std {

Menu::Menu() {
	name=string();
	icon=string();
	function=NULL;
	separator=false;

}

Menu::~Menu() {

}

void Menu::setName(string name)
{
	this->name=(gchar *)name.c_str();
}

void Menu::setFunction(GCallback function)
{
	this->function=function;
}



void Menu::setIcon(string icon)
{
	this->icon=(gchar *)icon.c_str();
}

void Menu::setSeparator(bool separator)
{
	this->separator=separator;
}

GCallback Menu::getFunction()
{
	return function;
}

string Menu::getIcon()
{
	return icon;
}

string Menu::getName()
{
	return name;
}

bool Menu::getSeparator()
{

	return &separator;
}

}
