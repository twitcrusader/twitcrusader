/*
 *	TwitCrusader - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  PTKDev, RoxShannon
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
 *		Author: Patryk Rzucidlo (PTKDev)
 *		Twitter: @ptkdev / @twitcrusader_en
 *		WebSite: http://www.twitcrusader.org
 */

#ifndef TWITTER_H_
#define TWITTER_H_

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>
#include <glib.h>
#include <libxml/xmlreader.h>

#include "twitcrusader.h"
#include "function.h"

#define TWITTER_KEY "3Y0iGu8KBpyNFaiWsIZPw"
#define TWITTER_KEY_SECRET "nNTvX1wvaEaHqz7Am4DYFFpkBN4vTFSWv3CYGOFk"

#define AUTHORIZE_URL "http://api.twitter.com/oauth/authorize"
#define REQUEST_URL "https://api.twitter.com/oauth/request_token"
#define ACCESS_TOKEN_URL "http://api.twitter.com/oauth/access_token"
#define STATUS_URL "http://api.twitter.com/1/statuses/update.xml?status="

struct users{
  char *id;
  char *screenName;
  char *Token;
  char *secretToken;
  char *consumerKey;
  char *consumerSecretKey;
} user;


char *tmp_token;

int writeUserFile();
int readUserFile();
int temp_token();
int temp_token_browser();
int access_token(const char *pin);
char* request_token(const char *consumerKey, const char *consumerKeySecret);
int send_tweet(char*);

#endif /* TWITTER_H_ */
