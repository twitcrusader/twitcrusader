/*
 * getimage.c
 *
 *  Created on: Apr 26, 2011
 *      Author: darkstar
 */
#include "include/gethttp.h"

size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream){
	fwrite(ptr, size, nmemb, (FILE *)stream);
	return nmemb*size;
};

int get_http(char *url, char *file){
	CURL *curl;
	CURLcode res;
	FILE *destFile;

	curl = curl_easy_init();

	if(curl) {

		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

		// Open the file to write the copied file to
		destFile = fopen(file,"wb");

		// Tell libcurl where to write the file
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writeFunction);
		curl_easy_setopt(curl,CURLOPT_WRITEDATA,destFile);
		res = curl_easy_perform(curl);

		/* always cleanup */
		fclose(destFile);
		curl_easy_cleanup(curl);
	}

	return 0;
}
