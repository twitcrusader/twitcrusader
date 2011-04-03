/* 
*	TwitCrusader - Twitter Client For Linux Desktop
*		Copyright (C) 2011  PTKDev
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

#define _GNU_SOURCE
#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

//TwitCrusader Header File
#include "twc.h"


void send_tweet(char *tweet){

	FILE *fp;
	char *user = NULL, 
		 *user_id = NULL,
		 *c_token = NULL, 
		 *c_token_secret = NULL, 
		 *user_token = NULL, 
		 *user_token_secret = NULL;
	char buffer[256];
	char *postarg = NULL;
	
	fp = fopen ("user", "r");
	fgets(buffer, 250, fp);
		char delims[] = "||";
		char *result = NULL;
		
		result = strtok( buffer, delims);
		user = result;
		
		result = strtok( NULL, delims );
		user_id = result;
		
		result = strtok( NULL, delims );
		c_token = result;
		
		result = strtok( NULL, delims );
		c_token_secret = result;
		
		result = strtok( NULL, delims );
		user_token = result;
		
		result = strtok( NULL, delims );
		user_token_secret = result;
	fclose (fp);
	
	
	char *update_status = "http://api.twitter.com/1/statuses/update.xml?status=";
	asprintf(&update_status, "%s%s", update_status, tweet);
    char *req_url = oauth_sign_url2(update_status, &postarg, OA_HMAC, NULL, c_token, c_token_secret, user_token, user_token_secret);
	oauth_http_post(req_url, postarg);	
	
	
}
