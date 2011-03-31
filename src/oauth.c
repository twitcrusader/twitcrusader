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

#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

//TwitCrusader Header File
#include "twc.h"

//Richiesta twitter
char* access_token(const gchar *pin)
{
        const char *req_url = NULL; 
        const char *c_key    = "df4eyJjVngL2HWtaS8GcQ";
        const char *c_secret = "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU";
        char *access_token_uri = "http://api.twitter.com/oauth/access_token?";
		char *pin_parm = "oauth_verifier=";	
		char *url_pin= NULL;	
		char *pin_url = malloc(strlen(pin_parm) + strlen(pin) + 1);
		if (pin_url != NULL )
		{
		 strcpy(pin_url, pin_parm);
		 strcat(pin_url, pin);
		}

        req_url = oauth_sign_url2(access_token_uri, &pin_url, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
        printf(req_url);
        url_pin = oauth_http_post(req_url,pin_url);
		printf(url_pin);
		
        return url_pin;
}

//Richiesta twitter
char* request_token(const char* c_key, const char* c_secret)
{
        const char *req_url = NULL; 
        const char *postarg = NULL;
        char *reply = NULL;

        const char *request_token_uri = "https://api.twitter.com/oauth/request_token";

        req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
        reply = oauth_http_get(req_url,postarg);
        return reply;
}

//Request PIN
int oauth_start()
{
        const char *c_key    = "df4eyJjVngL2HWtaS8GcQ";
        const char *c_secret = "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU";

        const char *tw_url = "xdg-open http://twitter.com/oauth/authorize?";
        const char *token_url = request_token(c_key, c_secret);

		char *oauth_url = malloc(strlen(tw_url) + strlen(token_url) + 1);
		if (oauth_url != NULL )
		{
		 strcpy(oauth_url, tw_url);
		 strcat(oauth_url, token_url);
		}
        system(oauth_url);
        
        return 0;
}
