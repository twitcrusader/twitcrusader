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

#ifndef DEBUG_H_
#define DEBUG_H_

/* Fix: GCC Linux Compiler */
#define _GNU_SOURCE

#include <stdio.h>
#include <sys/time.h>


/* Initialize Debugger */
int debug;

void set_debug(int value); // to intialize debug value
void debug_f_start(char* functionName); //to print the Function Name
void debug_var_char(const char* varName, const char* varValue); //to print String variable
void debug_var_int(char* varName, int varValue); //to print Integer variable
char* timestamp();


#endif /* DEBUG_H_ */
