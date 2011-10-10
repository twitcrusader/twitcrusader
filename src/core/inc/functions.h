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

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "externlibs.h"

#include "config.h"
#include "debug.h"

#define FILE_VERSION "/tmp/version.twc"
#define TWC_UPDATES_URL "http://www.twitcrusader.org/version-nightly.php"

void malloc_Size_of();
void free_size_of(void);
char* get_parameters(char** argv, int argc, const char* param);
int shell_parameters (int argc, char **argv);
void create_dir();
char* download_version();
char* read_raw_text_file(char* fileName);
char** read_raw_multiline_text_file(char* fileName);
char* get_element(xmlDocPtr doc, xmlNodePtr cur, char *keyword);


#endif /* FUNCTION_H_ */
