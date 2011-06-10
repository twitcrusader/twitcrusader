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

#include "include/functions.h"

/*  
 * This function add string1 + string2 = string3
 * Exemple: "AL" + "EX" = "ALEX"
 * 
 */
char *sumStrings(char *parm1, char *parm2 ){

	/* molloc function return a number of bytes of parm1 + parm2 */
	char *parm = malloc(strlen(parm1) + strlen(parm2) + 1);
	if (parm != NULL )
	{
		/* Add parm1 + parm2 for return sum of 2 variables */
		strcpy(parm, parm1);
		strcat(parm, parm2);
	}

	return parm;
}



/*  
 * This function split url-parameters with delimiter char
 * WARINING: use it with oauth_split_url_parameters() for variables rv
 * 
 * Exemple: 
 * param = oauth_token
 * rc = 1
 * rv = oauth=XXXXXXXXXX&token=ZZZZZZZZZ
 * Return = XXXXXXXXXX
 * 
 */
char *getParameters(char **argv,int argc,const char *param) //Improved by freddy
{
	int i;
	for(i = 0;i < argc;i++)
	{
		if(strncmp(argv[i],param,strlen(param)) == 0)
		{
			return argv[i] + strcspn(argv[i],"=") + 1;
		}
	}
	return NULL;
}

/*  
 * Debug Function
 * 
 */
int shellParameters (int argc, char **argv){
	int count;

	system("clear");

	printf("\nTwitCrusader - Twitter Client For Linux Desktop\n");
	printf("Copyright (C) 2011  TwitCrusader Team\n\n");

	if (argc > 1){
		for (count = 1; count < argc; count++){

			if(strcmp(argv[count],"--help")==0){
				printf("--help		print this page\n");
				printf("--debug		debug\n\n");

				return 1;
			}else if(strcmp(argv[count], "--debug")==0){
				printf ("This program was called with \"%s\".\n",argv[0]);
				debug=1;
			}else{
				printf("\ntry \"%s\" --help for help\n",argv[0]);
				return 1;
			}
		}
	}
	return 0;
}

void createDir(){

	char *cmd;

	progPath.configDir =  (char*) malloc(sizeof(char) * 80);
	progPath.configFile =  (char*) malloc(sizeof(char) * 80);

	/* User-Directory Path */

	//Avatar Dir
	asprintf(&progPath.avatarDir , "%s%s", g_get_home_dir(), "/.twc/avatar/");

	asprintf(&cmd, "%s %s", "rm -rf ", progPath.avatarDir);
	system(cmd);

	//mkdir(progPath.avatarDir, 0777);  //not work with «user», work with sudo/su WTF???
	asprintf(&cmd, "%s %s", "mkdir -p", progPath.avatarDir);
	system(cmd);

	//Configuration File
	asprintf(&progPath.configDir , "%s%s", g_get_home_dir(), "/.twc/config/");
	asprintf(&cmd, "%s %s", "mkdir -p", progPath.configDir);
	system(cmd);

	// Timeline File
	asprintf(&progPath.timelineDir , "%s%s", g_get_home_dir(), "/.twc/timeline/");
	asprintf(&cmd, "%s %s", "mkdir -p", progPath.timelineDir);
	system(cmd);

	asprintf(&progPath.configFile , "%s%s", progPath.configDir, CONFIG_FILENAME);

}

char* downloadVersion(){

#define FILE_VERSION "/tmp/version.twc"
#define VERSION_URL TWC_UPDATES_URL"?current="TWC_VERSION

	FILE* checkLatesVersion;
	char *bufferLatesVersion=malloc(sizeof(char)*10);


	/* Check Online Version From WebSite and Download File To /tmp/ directory */
	//system ("wget -O  "TWC_UPDATES_URL"?current="TWC_VERSION);
	getSingleCURL(VERSION_URL, FILE_VERSION);

	/* Check version with downloaded file */
	checkLatesVersion = fopen (FILE_VERSION, "r");
	fgets(bufferLatesVersion, 15, checkLatesVersion);
	/* Remove tmp file */
	remove(FILE_VERSION);

	if(debug==1) printf("\nversion: %s", bufferLatesVersion);
	return bufferLatesVersion;
}
