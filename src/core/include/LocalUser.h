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

#ifndef LOCALUSER_H_
#define LOCALUSER_H_

/*
 *
 */
#include <iostream>

#include <libxml/xmlreader.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#include <libxml++/libxml++.h>
#include "Config.h"
#include "Functions.h"

using namespace xmlpp;
using namespace std;
using namespace Glib;

#define MY_ENCODING "ISO-8859-1"

#define CONFIG_FILENAME "config.xml"

namespace TwitCrusader {

class LocalUser {
private:
	string id;
	string screenName;
	string token;
	string secretToken;
	string consumerKey;
	string consumerSecretKey;

protected:



public:
	LocalUser();
	virtual ~LocalUser();

	void setId(string id);
	void setScreenName(string secretName);
	void setToken(string Token);
	void setSecretToken(string secretToken);
	void setConsumerKey(string consumerKey);
	void setConsumerSecretKey(string secretConsumerKey);

	bool readUserFile(string filename);
	bool writeUserFile(string filename);
	void clear();

	string getId();
	string getScreenName();
	string getToken();
	string getSecretToken();
	string getConsumerKey();
	string getConsumerSecretKey();
};
}
#endif /* LOCALUSER_H_ */
