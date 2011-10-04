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

#ifndef USER_H_
#define USER_H_

#define _GNU_SOURCE
#include <stdio.h>

#include <string.h>

#include <libxml/xmlreader.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#include "debug.h"
#include "../../main.h"

#define MY_ENCODING "ISO-8859-1"

#define CONFIG_FILENAME "config.xml"
#define CONFIG_PREFERENCE_FILENAME "preference.xml"


struct users{
	char* id;
	char* screenName;
	char* token;
	char* secretToken;
	char* consumerKey;
	char* consumerSecretKey;
} user;

struct programPath{
	char *avatarDir;
	char *configDir;
	char *configFile;
	char *preferenceFile;
	char *timelineDir;
} progPath;

int writeUserFile();
int readUserFile();
void disconnect();
int deleteAccount();
void mallocUsers();
void freeSizeUsers();


#endif /* USER_H_ */
