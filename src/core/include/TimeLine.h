/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
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
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#ifndef TIMELINE_H_
#define TIMELINE_H_

#include<iostream>
#include<vector>
#include <libxml/xmlreader.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>


#include "Tweet.h"
#include "Config.h"
#include "TwitterURL.h"

using  namespace std;

namespace TwitCrusader {

class TimeLine {
public:

	vector<Tweet> timeline;
	string timelineURL;
	string timelineFile;

	char* getTimeLineElement(xmlDocPtr, xmlNodePtr, string);
	void getStatus (xmlDocPtr, xmlNodePtr, int);
	bool readTimeLine(string);
};

} /* namespace TwitCrusader */
#endif /* TIMELINE_H_ */
