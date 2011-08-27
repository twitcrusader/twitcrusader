/*
 *	 	Twitter Client For Linux Desktop
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

#ifndef TWITTER_H_
#define TWITTER_H_

/*
 *
 */
#include <iostream>
#include <vector>
#include <string.h>
#include "twitter_URL.h"
#include "time_line.h"
#include "local_user.h"

#include "twitter_URL.h"

using  namespace std;

class Twitter {

private:
	LocalUser localUser;
	TimeLine timeLine;
	Config config;

public:
	string tmp_token;

	Twitter();
	virtual ~Twitter();

	LocalUser getLocalUser();
	TimeLine getTimeLine();
	Config getConfig();

	void setlocalUser(LocalUser localUser);
	void setTimeLine(TimeLine timeLine);
	void setConfig(Config config);

	bool readUserFile();
	bool writeUserFile();
	char* getElement(xmlDocPtr doc, xmlNodePtr cur, const char *keyword);

	bool switchTimeLine(int xmlSwitch);
	bool downloadTimeLine();

	bool tokenTemp();
	bool tokenTempBrowser();
	bool tokenAccess(const string pin);
	string tokenRequest(const string consumerKey, const string consumerKeySecret);
	char *getParameters(char **argv,int argc,const char *param);
	string getParameters2(vector<string> rv, string param);
	bool SendTweet(string msg);

};

#endif /* TWITTER_H_ */
