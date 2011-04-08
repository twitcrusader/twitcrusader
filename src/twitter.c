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

char* request_token(const char *c_key, const char *c_key_secret){
	char *postarg = NULL;

	const char *oauth_sign = oauth_sign_url2(REQUEST_URL, NULL, OA_HMAC, NULL, c_key, c_key_secret, NULL, NULL);
	char *oauth_http_access = oauth_http_get(oauth_sign,postarg);

	return oauth_http_access;
}

