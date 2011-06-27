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

#ifndef TWEET_H_
#define TWEET_H_

/*
 *
 */
#include <iostream>
#include <libxml/xmlreader.h>

#include "User.h"

#define MAX_NUM_TWEETS 20

namespace std {

class Tweet {

private:

	User user;

	string created_at,
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

public:
	Tweet();
	virtual ~Tweet();

	User getUser();
	void setUser(User user);

	string getCreated_at();
	string getId();
	string getText();
	string getSource();
	string getTruncated();
	string getFavorited();
	string getIn_reply_to_status_id();
	string getIn_reply_to_user_id();
	string getIn_reply_to_screen_name();
	string getRetweet_count();
	string getRetweeted();
	string getGeo();
	string getCoordinates();
	string getPlace();
	string getContributors();

	void setCreated_at(string created_at);
	void setId(string id);
	void setText(string text);
	void setSource(string source);
	void setTruncated(string truncated);
	void setFavorited(string favorited);
	void setIn_reply_to_status_id(string in_reply_to_status_id);
	void setIn_reply_to_user_id(string in_reply_to_user_id);
	void setIn_reply_to_screen_name(string in_reply_to_screen_name);
	void setRetweet_count(string retweet_count);
	void setRetweeted(string retweeted);
	void setGeo(string geo);
	void setCoordinates(string coordinates);
	void setPlace(string place);
	void setContributors(string contributors);

};

}

#endif /* TWEET_H_ */
