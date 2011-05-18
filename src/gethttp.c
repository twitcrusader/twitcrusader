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

int getCURL(char *url, char *file){
	CURL *curl;
	FILE *destFile;

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

//Alternative at cURL
int getWGET(char *url, char *file){
	
	char* wget = NULL;

		// Tell wget where to write the file
		asprintf(&wget, "%s %s %s", "wget -O", file, url);
		if(debug==1) printf("Wget -> %s\n", wget);
		system (wget);

	return 0;
}

