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

#include "inc/gethttp.h"


size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream){

	debug_f_start("writeFunction");

	fwrite(ptr, size, nmemb, (FILE *)stream);
	return nmemb*size;
};

void getSingleCURL(char *url, char *file){

	debug_f_start("getSingleCURL");


	char *argv[2];
	argv[0]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[0],url);
	argv[1]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[1],file);

	pull_one_url(argv);
}


void *pull_one_url(void *argv){

	debug_f_start("pull_one_url");

	CURL *curl;
	FILE *destFile;

	char **argv2=(char **)argv;
	char *url=(char *)argv2[0];
	char *file=(char *)argv2[1];

	debug_var_char("url",url);
	debug_var_char("file",file);

	if(url!=NULL && file!=NULL){

		curl = curl_easy_init();

		if(curl) {

			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

			// Open the file to write the copied file to
			destFile = fopen(file,"w+b");

			// Tell libcurl where to write the file
			curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writeFunction);
			curl_easy_setopt(curl,CURLOPT_WRITEDATA,destFile);
			curl_easy_perform(curl);

			/* always cleanup */
			fclose(destFile);
			curl_easy_cleanup(curl);
		}
	}

	return 0;
}

int getMultiCURL(char **urls, char **files, int max_num_tid){

	debug_f_start("getMultiCURL");

	pthread_t tid[max_num_tid+1];
	int i;
	int error;

	char *argv[2];
	argv[0]=(char *)malloc(sizeof(char)*2038);
	argv[1]=(char *)malloc(sizeof(char)*255);

	if(debug==1) fprintf(stderr,"\ngetMultiCURL(char *url, char *file)");

	/* Must initialize libcurl before any threads are started */
	curl_global_init(CURL_GLOBAL_ALL);

	for(i=0; i< max_num_tid+1; i++) {


		strcpy(argv[0],urls[i]);
		strcpy(argv[1],files[i]);

		debug_var_char("argv[0]", argv[0]);
		debug_var_char("argv[1]", argv[1]);

		error = pthread_create(&tid[i],
				NULL, /* default attributes please */
				pull_one_url,
				(void *)argv);


		debug_var_int("Start Thread Number:",  i);
		debug_var_char("urls[i]", urls[i]);

	}

	/* now wait for all threads to terminate */
	for(i=0; i< max_num_tid+1; i++) {
		error = pthread_join(tid[i], NULL);
		debug_var_int("Stop Thread Number:", i);
	}

	return 0;
}

//Alternative at cURL
int getWGET(char *url, char *file){

	debug_f_start("getWGET");

	char* wget = NULL;

	// Tell wget where to write the file
	asprintf(&wget, "%s %s %s", "wget -O", file, url);

	debug_var_char(" wget",  wget);

	system (wget);

	return 0;
}
