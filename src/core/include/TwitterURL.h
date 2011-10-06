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

#ifndef TWITTERURL_H_
#define TWITTERURL_H_

#define CONSUMER_KEY "1c0wHFXtyVkbzoC1MJQdA"
#define CONSUMER_SECRET_KEY "ZV3ogdCeDBxX3tRv7CzcFrtRVBEQ71cH1cOUmB8KGg"

#define HTTP_API_URL "http://api.twitter.com"
#define HTTPS_API_URL "https://api.twitter.com"

#define AUTHORIZE_URL HTTP_API_URL"/oauth/authorize"
#define REQUEST_URL HTTP_API_URL"/oauth/request_token"
#define TOKENACCESS_URL HTTP_API_URL"/oauth/access_token"
#define STATUS_URL HTTP_API_URL"/1/statuses/update.xml?status="

#define HOME_TIMELINE_URL HTTP_API_URL"/1/statuses/home_timeline.xml"
#define PUBLIC_TIMELINE_URL HTTP_API_URL"/1/statuses/public_timeline.xml"
#define MENTIONS_TIMELINE_URL HTTP_API_URL"/1/statuses/mentions.xml"
#define FRIENDS_TIMELINE_URL HTTP_API_URL"/1/statuses/friends_timeline.xml"
#define USER_TIMELINE_URL HTTP_API_URL"/1/statuses/user_timeline.xml"
#define RT_BY_ME_TIMELINE_URL HTTP_API_URL"/1/statuses/retweeted_by_me.xml"
#define RT_TO_ME_TIMELINE_URL HTTP_API_URL"/1/statuses/retweeted_to_me.xml"
#define RT_OF_ME_TIMELINE_URL HTTP_API_URL"/1/statuses/retweeted_of_me.xml"


#endif /* TWITTERURL_H_ */
