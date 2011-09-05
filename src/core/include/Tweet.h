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

#ifndef TWEET_H_
#define TWEET_H_

/*
 *
 */
#include <iostream>
#include <gtkmm.h>

#include "User.h"

using  namespace std;
using namespace Glib;

#define MAX_NUM_TWEETS 20

namespace TwitCrusader {

class Tweet {

public:

	User user;

	ustring created_at,
	id,
	text,
	source,
	truncated,
	favorited,
	in_reply_to_status_id,
	in_reply_to_user_id,
	in_reply_to_screen_name,
	retweet_count,
	retweeted,
	geo,
	coordinates,
	place,
	contributors;

	Tweet();
	virtual ~Tweet();

};


}
#endif /* TWEET_H_ */
