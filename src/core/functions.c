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

	progPath.configDir =  (char*) malloc(sizeof(char) * 80);
	progPath.configFile =  (char*) malloc(sizeof(char) * 80);
	progPath.preferenceFile= (char*) malloc(sizeof(char)* 80);
	/* User-Directory Path */

	//Avatar Dir
	asprintf(&progPath.avatarDir , "%s%s", g_get_home_dir(), "/.twc/avatar/");
	debug_var_char("progPath.avatarDir",progPath.avatarDir);

	asprintf(&cmd, "%s %s", "rm -rf ", progPath.avatarDir);
	debug_var_char("cmd",cmd);
	system(cmd);



	//mkdir(progPath.avatarDir, 0777);  //not work with «user», work with sudo/su WTF???
	asprintf(&cmd, "%s %s", "mkdir -p", progPath.avatarDir);
	debug_var_char("cmd",cmd);
	system(cmd);

	//Configuration File
	asprintf(&progPath.configDir , "%s%s", g_get_home_dir(), "/.twc/config/");
	debug_var_char("progPath.configDir",progPath.configDir);

	asprintf(&cmd, "%s %s", "mkdir -p", progPath.configDir);
	debug_var_char("cmd",cmd);
	system(cmd);

	// Timeline File
	asprintf(&progPath.timelineDir , "%s%s", g_get_home_dir(), "/.twc/timeline/");
	debug_var_char("progPath.timelineDir",progPath.timelineDir);

	asprintf(&cmd, "%s %s", "mkdir -p", progPath.timelineDir);
	debug_var_char("cmd",cmd);
	system(cmd);

	asprintf(&progPath.configFile , "%s%s", progPath.configDir, CONFIG_FILENAME);
	debug_var_char("progPath.configFile",progPath.configFile);

	asprintf(&progPath.preferenceFile , "%s%s", progPath.configDir, CONFIG_PREFERENCE_FILENAME);
		debug_var_char("progPath.preferenceFile",progPath.preferenceFile);

}

char* download_version(){

	debug_f_start("download_version");

	FILE* checkLatesVersion;
	char *bufferLatesVersion=malloc(sizeof(char)*10);


	/* Check Online Version From WebSite and Download File To /tmp/ directory */
	get_single_CURL(VERSION_URL, FILE_VERSION);

	/* Check version with downloaded file */
	checkLatesVersion = fopen (FILE_VERSION, "r");
	fgets(bufferLatesVersion, 15, checkLatesVersion);
	/* Remove tmp file */
	remove(FILE_VERSION);

	debug_var_char("bufferLatesVersion",bufferLatesVersion);

	return bufferLatesVersion;
}


char* read_raw_text_file(char* fileName){

	debug_f_start("read_raw_text_file");

	FILE *fp;
	char ch, *b1, *b2 ;

	fp = fopen ( fileName, "r" ) ;
	if(fp==NULL) return NULL;

	while(1){

		ch=fgetc(fp);

		if (ch==EOF)
			break ;
		else{
			b2=b1;
			b1=malloc(sizeof(b2)+sizeof(char));
			asprintf(&b1,"%s%c",b2,ch);
		}
	}
	free(b2);
	fclose (fp) ;
	return b1;
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
