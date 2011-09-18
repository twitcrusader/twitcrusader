/*
 *	TwitCrusader - Twitter Client For Linux Desktop
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

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>
#include <glib.h>
#include <curl/curl.h>

#include<sys/stat.h>
#include<sys/types.h>

#include "functions.h"
#include "timeline.h"
#include "gethttp.h"
#include "config.h"

#define TWITTER_KEY "3Y0iGu8KBpyNFaiWsIZPw"
#define TWITTER_KEY_SECRET "nNTvX1wvaEaHqz7Am4DYFFpkBN4vTFSWv3CYGOFk"

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

char *tmp_token;

int tokenTemp();
int tokenTempBrowser();
int tokenAccess(const char *pin);
char* tokenRequest(const char *consumerKey, const char *consumerKeySecret);
int SendTweet(char*);
int switchTimeLine(int xmlSwitch);
int deleteAccount();


#endif /* TWITTER_H_ */
