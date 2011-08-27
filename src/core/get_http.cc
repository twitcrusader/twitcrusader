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

#include "include/get_http.h"

size_t GetHTTP::writeFunction( void *ptr, size_t size, size_t nmemb, void *stream)
{
	fwrite(ptr, size, nmemb, (FILE *)stream);
	return nmemb*size;
};

void GetHTTP::getSingleCURL(string url, string file)
{
	string argv[2];
	argv[0]=string();
	argv[0].assign(url);
	argv[1]=string();
	argv[1].assign(file);

	pull_one_url((void *)argv);
}

void GetHTTP::pull_one_url(void* argv)
{

	CURL *curl;
	FILE *destFile;

	char **argv2=(char **)argv;
	char *url=(char *)argv2[0];
	char *file=(char *)argv2[1];

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
}
