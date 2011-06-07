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
 * 		IRC: chat.freenode.net at #teamtwc
 */

#include "include/gethttp.h"


size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream){
	fwrite(ptr, size, nmemb, (FILE *)stream);
	return nmemb*size;
};

void *pull_one_url(void *argv){
	CURL *curl;
	FILE *destFile;

	char **argv2=(char **)argv;
	char *url=(char *)argv2[0];
	char *file=(char *)argv2[1];

	if(debug==1) fprintf(stderr,"*pull_one_url(void *argv)");
	if(debug==1) fprintf(stderr,"\nurl= %s",url);
	if(debug==1) fprintf(stderr,"\nfile= %s",file);
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

	return 0;
}

int getCURL(char *url, char *file){

	pthread_t tid[NUMT];
	int i;
	int error;

	char *argv[2];
	argv[0]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[0],url);
	argv[1]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[1],file);

	if(debug==1) fprintf(stderr,"getMultiCURL(char *url, char *file)");
	if(debug==1) fprintf(stderr,"\nurl= %d", *argv[0]);
	if(debug==1) fprintf(stderr,"\nfile= %d", *argv[1]);

	/* Must initialize libcurl before any threads are started */
	curl_global_init(CURL_GLOBAL_ALL);

	for(i=0; i< NUMT; i++) {
		error = pthread_create(&tid[i],
				NULL, /* default attributes please */
				pull_one_url,
				(void *)argv);
		if(debug==1){
			if(0 != error)
				fprintf(stderr, "Couldn't run thread number %d, errno %d\n", i, error);
			else
				fprintf(stderr, "Thread %d, gets %s\n", i, url);
		}
	}

	/* now wait for all threads to terminate */
	for(i=0; i< NUMT; i++) {
		error = pthread_join(tid[i], NULL);
		if(debug==1) fprintf(stderr, "Thread %d terminated\n", i);
	}

	return 0;
}

//Alternative at cURL
int getWGET(char *url, char *file){

	char* wget = NULL;

	// Tell wget where to write the file
	asprintf(&wget, "%s %s %s", "wget -O", file, url);
	if(debug==1) fprintf(stderr, "wget -> %s\n", wget);
	system (wget);

	return 0;
}
