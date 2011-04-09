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


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

#include "twitcrusader.h"

#define TWITTER_KEY "3Y0iGu8KBpyNFaiWsIZPw"
#define TWITTER_KEY_SECRET "nNTvX1wvaEaHqz7Am4DYFFpkBN4vTFSWv3CYGOFk"
#define AUTHORIZE_URL "http://api.twitter.com/oauth/authorize"
#define REQUEST_URL "https://api.twitter.com/oauth/request_token"

int oauth_start();
char* request_token(const char *c_key, const char *c_key_secret);
char* access_token(GtkButton *button, AuthWidget *DataInput);

#endif /* TWITTER_H_ */
