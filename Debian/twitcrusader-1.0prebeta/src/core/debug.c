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

#include "inc/debug.h"

void set_debug(int value){
	debug=value;
}

void debug_f_start(char* functionName){
	if(debug==1) fprintf(stderr,"%s - Function: %s\n",timestamp(), functionName);
}

void debug_var_char(const char* varName, const char* varValue){
	if(debug==1){
		if(varValue!=NULL){

			fprintf(stderr,"%s - %s: %s\n",timestamp(), varName, varValue);

		}else{

			fprintf(stderr,"%s - %s: %s\n", timestamp(), varName, "NULL");
		}
	}
}

void debug_var_int(char* varName, int varValue){
	if(debug==1) fprintf(stderr,"%s - %s= %i\n",timestamp(), varName, varValue);
}

char* timestamp(){

	char* out;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	asprintf(&out,"[\t%i.%i]",(int)tv.tv_sec,(int)tv.tv_usec);
	return out;
}



