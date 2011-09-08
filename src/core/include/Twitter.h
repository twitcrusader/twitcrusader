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

#ifndef TWITTER_H_
#define TWITTER_H_

/*
 *
 */
#include <iostream>
#include <vector>
#include <glibmm.h>
extern "C"{
#include <oauth.h>
}

#include "TwitterURL.h"
#include "TimeLine.h"
#include "LocalUser.h"

using  namespace std;

namespace TwitCrusader {

class Twitter {

private:


public:
	LocalUser localUser;
	TimeLine timeLine;
	Config config;

	ustring tmp_token;

	Twitter();
	virtual ~Twitter();

	bool readUserFile();
	bool writeUserFile();

	bool switchTimeLine(int xmlSwitch);
	bool downloadTimeLine();

	bool tokenTemp();
	bool tokenTempBrowser();
	bool tokenAccess(const ustring pin);
	ustring tokenRequest(const ustring consumerKey, const ustring consumerKeySecret);
	char *getParameters(char **argv,int argc,const char *param);
	ustring getParameters2(vector<string> rv, ustring param);
	bool SendTweet(ustring msg);

};
}
#endif /* TWITTER_H_ */
