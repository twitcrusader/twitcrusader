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
 */

#include "twitter.h"

int oauth_start(){
	int rc;
	char *cmd;
	char **rv = NULL;

	const char *c_key    = TWITTER_KEY;
	const char *c_key_secret = TWITTER_KEY_SECRET;

	char *twitter_oauth = request_token(c_key, c_key_secret);
	rc = oauth_split_url_parameters(twitter_oauth, &rv);
	char* t_key = get_param(rv, rc, "oauth_token");

	asprintf(&cmd, "xdg-open \"%s?oauth_token=%s\"", AUTHORIZE_URL, t_key);
	system(cmd);

	asprintf(&twitter_oauth, "%s%s%s%s%s", twitter_oauth, "&c_key=", c_key, "&c_key_secret=", c_key_secret);
	FILE *fp;
	fp=fopen("/tmp/token", "w+");
	fprintf(fp, twitter_oauth);
	fclose(fp);

	return 0;
}

char* access_token(const char *pin){
	const char *req_url = NULL;

	char 	*oauth_request = NULL,
			*data_file = NULL,
			*postarg = NULL,
			*t_key =  NULL,
			*t_key_secret =  NULL,
			*c_key =  NULL,
			*c_key_secret = NULL;

	int rc;
	char **rv = NULL;
	char buffer[256];

	FILE *fp;
	char *homeFile = NULL;
	asprintf(&homeFile, "%s%s", getenv("HOME"), "/user");

	fp = fopen ("/tmp/token", "r");
	fgets(buffer, 250, fp);
	rc = oauth_split_url_parameters(buffer, &rv);
	t_key = get_param(rv, rc, "oauth_token");
	t_key_secret = get_param(rv, rc, "oauth_token_secret");
	c_key = get_param(rv, rc, "c_key");
	c_key_secret = get_param(rv, rc, "c_key_secret");
	fclose (fp);

	asprintf(ACCESS_TOKEN_URL, "%s?oauth_verifier=%s", ACCESS_TOKEN_URL, pin);
	req_url = oauth_sign_url2(ACCESS_TOKEN_URL, &postarg, OA_HMAC, NULL, c_key, c_key_secret, t_key, t_key_secret);
	oauth_request = oauth_http_post(req_url,postarg);

	rc = oauth_split_url_parameters(oauth_request, &rv);
	char *user_token = get_param(rv, rc, "oauth_token");
	char *user_token_secret = get_param(rv, rc, "oauth_token_secret");
	char *user_id = get_param(rv, rc, "user_id");
	char *screen_name = get_param(rv, rc, "screen_name");

	fp=fopen(homeFile, "w+");
	asprintf(&data_file, "%s||%s||%s||%s||%s||%s", screen_name, user_id, c_key, c_key_secret, user_token, user_token_secret);
	fprintf(fp, data_file);
	fclose(fp);

	remove("/tmp/token");

	return oauth_request;
}

char* request_token(const char *c_key, const char *c_key_secret){
	char *postarg = NULL;

	const char *oauth_sign = oauth_sign_url2(REQUEST_URL, NULL, OA_HMAC, NULL, c_key, c_key_secret, NULL, NULL);
	char *oauth_http_access = oauth_http_get(oauth_sign,postarg);

	return oauth_http_access;
}

void send_tweet(char *msg){

		FILE *fp;
		//*user = NULL,
		//*user_id = NULL,
		char *c_token = NULL,
				*c_token_secret = NULL,
				*user_token = NULL,
				*user_token_secret = NULL;
		char buffer[256];
		char *postarg = NULL;

		char *homeFile = NULL;
		asprintf(&homeFile, "%s%s", getenv("HOME"), "/user");

		fp = fopen (homeFile, "r");
		fgets(buffer, 250, fp);
		char delims[] = "||";
		char *result = NULL;

		result = strtok( buffer, delims);
		//user = result;

		result = strtok( NULL, delims );
		//user_id = result;

		result = strtok( NULL, delims );
		c_token = result;

		result = strtok( NULL, delims );
		c_token_secret = result;

		result = strtok( NULL, delims );
		user_token = result;

		result = strtok( NULL, delims );
		user_token_secret = result;
		fclose (fp);

		asprintf(STATUS_URL, "%s%s", STATUS_URL, msg);
		char *req_url = oauth_sign_url2(STATUS_URL, &postarg, OA_HMAC, NULL, c_token, c_token_secret, user_token, user_token_secret);
		oauth_http_post(req_url, postarg);

}
