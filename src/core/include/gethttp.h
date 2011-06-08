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
#ifndef GETHTTP_H_
#define GETHTTP_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <curl/curl.h>
#include <pthread.h>

#include "functions.h"
#include "timeline.h"

#define NUMT 4

size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream);
int getCURL(char *url, char *file);
void *pull_one_url(void *argv);
int getWGET(char *url, char *file);

#endif /* GETHTTP_H_ */
