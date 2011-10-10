/*
 *      TwitCrusader - Twitter Client For Linux Desktop
 *              Copyright (C) 2011  TwitCrusader Team
 *
 *              This program is free software: you can redistribute it and/or modify
 *              it under the terms of the GNU General Public License as published by
 *              the Free Software Foundation, either version 3 of the License, or
 *              (at your option) any later version.
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *              GNU General Public License for more details.
 *
 *              You should have received a copy of the GNU General Public License
 *              along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *              WebSite: http://www.twitcrusader.org/
 *              Development Guidelines: http://dev.twitcrusader.org/
 *              Follow on Twitter: @teamtwc
 *              IRC: chat.freenode.net at #teamtwc
 *              E-mail: teamtwc@twitcrusader.org
 *
 */

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

#include "externlibs.h"

#include "debug.h"
#include "config.h"

#define OAUTH_API_URL_DEFAULT "https://api.twitter.com/oauth/"
#define HTTPS_API_URL_DEFAULT "https://api.twitter.com/1/"

struct preference{
	char* aouth_api_url;
	char* https_api_url;

} prog_preference;


struct twitter_URLS{
char* authorize_url;
char* request_url;
char* tokenaccess_url;

char* status_url;
char* home_timeline_url;
char* public_timeline_url;
char* mentions_timeline_url;
char* friends_timeline_url;
char* user_timeline_url;
char* rt_by_me_timeline_url;
char* rt_to_me_timeline_url;
char* rt_of_me_timeline_url;
}tw_URLS;


int read_preference_file();
int get_preference(xmlDocPtr doc);
void write_default_preference_file();
void write_preference_file();
void check_URLS();
void init_URLS();
void free_size_preference();


#endif /* PREFERENCE_H_ */
