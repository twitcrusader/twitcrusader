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

#include "externlibs.h"

#include "debug.h"
#include "functions.h"
#include "timeline.h"
#include "gethttp.h"
#include "config.h"
#include "preference.h"

#define TWITTER_KEY "0xdBqXjFX4LBTLyoc5Dg"
#define TWITTER_KEY_SECRET "VIr57NPcgxxpJ2esI7brKGhth06EslbH0UDD3ImFB8"

char *tmp_token;

int token_temp();
int token_temp_browser();
int token_access(const char *pin);
char* token_request(const char *consumerKey, const char *consumerKeySecret);
int send_tweet(char*);
int switch_timeline(int xmlSwitch);
int delete_account();
void downloads_avatars();

#endif /* TWITTER_H_ */
