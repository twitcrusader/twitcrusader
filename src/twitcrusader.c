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

#include "include/twitcrusader.h"
#include "include/gtkwindows.h"
#include "include/function.h"
#include "include/twitter.h"
/*
 * Main function and debug function
 * 
 */
int main(int argc, char **argv){

	/* debug */
	if(shellParameters (argc, argv)==1) return 0;


	// codice momentaneamente posto qui!
	user.id =  (char*) malloc(sizeof(char) * 50);
	user.screenName =  (char*) malloc(sizeof(char) * 140);
	user.Token =  (char*) malloc(sizeof(char) * 160);
	user.secretToken =  (char*) malloc(sizeof(char) * 160);
	user.consumerKey =  (char*) malloc(sizeof(char) * 160);
	user.consumerSecretKey =  (char*) malloc(sizeof(char) * 160);

	progPath.configFileName="user.twc";
	asprintf(&progPath.configDir , "%s%s", g_get_home_dir(), "/.twc/config/");
	asprintf(&progPath.configFile , "%s%s", progPath.configDir, progPath.configFileName);

	//

	windowMain(argc, argv);

	return 0;
}
