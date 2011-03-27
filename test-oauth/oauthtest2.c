#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>


//Richiesta twitter
char* request_token(const char *c_key, const char *c_secret)
{
	char *req_url = NULL, 
		 *postarg = NULL, 
		 *reply = NULL;
	const char *request_token_uri = "https://api.twitter.com/oauth/request_token";
	c_key         = "df4eyJjVngL2HWtaS8GcQ"; //< consumer key TwitCrusader
	c_secret      = "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU"; //< consumer secret TwitCrusader
	req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
	reply = oauth_http_get(req_url,postarg);
	return reply;
}

//pin= 9598723
int main (int argc, char **argv) {
  system("clear");

	char *tw_url, *oauth_url, *token_url; 
    const char c_key, c_secret;
    GError *error = NULL;
    
	tw_url = "xdg-open http://twitter.com/oauth/authorize?";
	token_url = request_token(&c_key,&c_secret);
	oauth_url = malloc(sizeof(tw_url)+sizeof(token_url));
	sprintf(oauth_url,"%s%s",tw_url,token_url);
	system(oauth_url);
  return 0;
}
