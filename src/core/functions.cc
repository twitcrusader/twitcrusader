/*
 *	 TwitCrusader-GUI is part of TwitCrusader - Twitter Client For Linux Desktop
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

#include "include/functions.h"

namespace std {

string Functions::readRawTextFile(string fileName){
	FILE *fp;
	char ch;
	string buffer=string();

	fp = fopen ( fileName.c_str(), "r" ) ;
	if(fp==NULL) return buffer;

	while(1){

		ch=fgetc(fp);

		if (ch==EOF)
			break ;
		else{
			buffer.push_back(ch);
		}
	}
	fclose (fp) ;
	return buffer;
}

bool Functions::shellParameters (int argc, char **argv){

	if (argc > 1){
		for (int count = 1; count < argc; count++){

			if(strcmp(argv[count],"--help")==0){
				printf("--help		print this page\n");
				printf("--debug		debug\n\n");

				return true;
			}else if(strcmp(argv[count], "--debug")==0){
				printf ("This program was called with \"%s\".\n",argv[0]);
				//debug=1;
			}else{
				printf("\ntry \"%s\" --help for help\n",argv[0]);
				return true;
			}
		}
	}
	return false;
}

}
