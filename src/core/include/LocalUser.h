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
#include <glibmm.h>

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
	ustring *id;
	ustring *screenName;
	ustring *token;
	ustring *secretToken;
	ustring *consumerKey;
	ustring *consumerSecretKey;

protected:



public:
	LocalUser();
	virtual ~LocalUser();

	void setId(ustring id);
	void setScreenName(ustring secretName);
	void setToken(ustring Token);
	void setSecretToken(ustring secretToken);
	void setConsumerKey(ustring consumerKey);
	void setConsumerSecretKey(ustring secretConsumerKey);

	bool readUserFile(ustring filename);
	void writeUserFile(ustring filename);
	void clear();

	ustring getId();
	ustring getScreenName();
	ustring getToken();
	ustring getSecretToken();
	ustring getConsumerKey();
	ustring getConsumerSecretKey();
};
}
#endif /* LOCALUSER_H_ */
