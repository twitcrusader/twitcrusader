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

#include "inc/functions.h"

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
char *get_parameters(char **argv,int argc,const char *param) //Improved by freddy
{
	debug_f_start("get_parameters");

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
int shell_parameters (int argc, char **argv){
	debug_f_start("shell_parameters");
	int count;

	if (argc > 1){
		for (count = 1; count < argc; count++){

			if(strcmp(argv[count],"--help")==0){
				printf("--help		print this page\n");
				printf("--debug		debug\n\n");

				return 1;
			}else if(strcmp(argv[count], "--debug")==0){
				debug_var_char("Program_name", argv[0]);
				set_debug(1);
			}else{
				printf("\ntry \"%s\" --help for help\n",argv[0]);
				return 1;
			}
		}
	}
	return 0;
}

void create_dir(){

	debug_f_start("create_dir");

	char *cmd;

	prog_path.configDir =  (char*) malloc(sizeof(char) * 80);
	prog_path.configFile =  (char*) malloc(sizeof(char) * 80);
	prog_path.preferenceFile= (char*) malloc(sizeof(char)* 80);
	/* User-Directory Path */

	//Avatar Dir
	int error=asprintf(&prog_path.avatarDir , "%s%s", g_get_home_dir(), "/.twc/avatar/");
	debug_var_char("prog_path.avatarDir",prog_path.avatarDir);

	error=asprintf(&cmd, "%s %s", "rm -rf ", prog_path.avatarDir);
	debug_var_char("cmd",cmd);
	error=system(cmd);



	//mkdir(prog_path.avatarDir, 0777);  //not work with «user», work with sudo/su WTF???
	error=asprintf(&cmd, "%s %s", "mkdir -p", prog_path.avatarDir);
	debug_var_char("cmd",cmd);
	error=system(cmd);

	//Configuration File
	error=asprintf(&prog_path.configDir , "%s%s", g_get_home_dir(), "/.twc/config/");
	debug_var_char("prog_path.configDir",prog_path.configDir);

	error=asprintf(&cmd, "%s %s", "mkdir -p", prog_path.configDir);
	debug_var_char("cmd",cmd);
	error=system(cmd);

	// Timeline File
	error=asprintf(&prog_path.timelineDir , "%s%s", g_get_home_dir(), "/.twc/timeline/");
	debug_var_char("prog_path.timelineDir",prog_path.timelineDir);

	error=asprintf(&cmd, "%s %s", "mkdir -p", prog_path.timelineDir);
	debug_var_char("cmd",cmd);
	error=system(cmd);

	error=asprintf(&prog_path.configFile , "%s%s", prog_path.configDir, CONFIG_FILENAME);
	debug_var_char("prog_path.configFile",prog_path.configFile);

	error=asprintf(&prog_path.preferenceFile , "%s%s", prog_path.configDir, CONFIG_PREFERENCE_FILENAME);
	debug_var_char("prog_path.preferenceFile",prog_path.preferenceFile);

}

char* download_version(){

	debug_f_start("download_version");

	FILE* checkLatesVersion;
	char *bufferLatesVersion=malloc(sizeof(char)*20);


	/* Check Online Version From WebSite and Download File To /tmp/ directory */
	get_single_CURL(TWC_UPDATES_URL, FILE_VERSION);

	/* Check version with downloaded file */
	checkLatesVersion = fopen (FILE_VERSION, "r");
	char* pointer=fgets(bufferLatesVersion, 15, checkLatesVersion);
	/* Remove tmp file */
	remove(FILE_VERSION);

	debug_var_char("bufferLatesVersion",bufferLatesVersion);

	return bufferLatesVersion;
}


char* read_raw_text_file(char* fileName){

	debug_f_start("read_raw_text_file");

	FILE *fp;
	char *buffer=malloc(sizeof(char)*20);

	strcpy(buffer,"");

	debug_var_char("fileName", fileName);
	fp = fopen ( fileName, "r" ) ;
	if(fp==NULL) return NULL;
	char* pointer=fgets(buffer, 20, fp);

	fclose (fp) ;
	return buffer;
}

char* get_element(xmlDocPtr doc, xmlNodePtr cur, char *keyword){
	debug_f_start("get_element");

	xmlChar *key;
	char *empty = "error";

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		//if(debug==1) printf("\n%s: %s", keyword, key);

		return (char *)key;
	}

	return empty;

}
