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

#include "include/twitter.h"

/*
 * This function generate a 2 Twitter-Temp-Key
 * Use this Temp-keys for generate a PIN
 * Use PIN and Twitter-Temp-Keys for validate a correct PIN
 *
 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
 *
 */
int writeUserFile(){

	FILE *fp;
	char *data_file;
	char *configFile;

	asprintf(&configFile, "%s%s", g_get_home_dir(), "/.twc/config/user.twc");

	if(user.id!=NULL && user.screenName!=NULL && user.Token!=NULL && user.secretToken!=NULL){
		/* Save all personal keys and info of twitter-user at ~/.twc/config/user file */
		fp=fopen(configFile, "w+");
		if(fp!=NULL){
			asprintf(&data_file, "%s||%s||%s||%s||%s||%s", user.screenName, user.id, user.consumerKey, user.consumerSecretKey, user.Token, user.secretToken);
			fprintf(fp, "%s", data_file);
			fclose(fp);

			return 0;
		}
		return 1;
	}

	return 1;
}

int readUserFile(){

	FILE *fp;
	char *configFile;

	char buffer[256];

	const char delims[] = "||";

	/* Generate a Local-URL for get all user-info */
	asprintf(&configFile, "%s%s", g_get_home_dir(), "/.twc/config/user.twc");

	/* Get all user-info and user token */
	fp = fopen (configFile, "r");

	if(fp!=NULL){
		fgets(buffer, 250, fp);


		// asprintf(&data_file, "%s||%s||%s||%s||%s||%s", user.screenName, user.id, user.consumerKey, user.consumerSecretKey, user.key, user.secretKey);

		/* Username */
		user.screenName = strtok( buffer, delims);

		/* User-ID */
		user.id = strtok( NULL, delims );

		/* Get TwitCrusader Token */
		user.consumerKey = strtok( NULL, delims );

		/* Get TwitCrusader Secret Token */
		user.consumerSecretKey = strtok( NULL, delims );

		/* Get User Token */
		user.Token = strtok( NULL, delims );

		/* Get TwitCrusader Secret Token */
		user.secretToken = strtok( NULL, delims );

		fclose (fp);
		if(user.id!=NULL &&
				user.screenName!=NULL &&
				user.consumerKey!=NULL &&
				user.consumerSecretKey!=NULL &&
				user.Token!=NULL &&
				user.secretToken!=NULL) return 0;
	}

	return 1;

}


char* request_token(const char *consumerKey, const char *consumerKeySecret){
	char *postarg = NULL;;
	char *tempKeyParameters;
	char *twitterRequestURL;

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL = oauth_sign_url2(REQUEST_URL, NULL, OA_HMAC, NULL, consumerKey, consumerKeySecret, NULL, NULL);
	tempKeyParameters = oauth_http_get(twitterRequestURL, postarg);

	return tempKeyParameters;
}

/*
 * Main function for oAuth access
 *
 * Authorize Twitter Account
 *
 */
void temp_token(){
	int rc;
	char *cmd,
	*tempKeyURL,
	*tempKey,
	*tmp_token;
	char **rv;
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = request_token(TWITTER_KEY, TWITTER_KEY_SECRET);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_param(rv, rc, "oauth_token");

	/* Generate a Twitter-URL for get user-PIN */
	asprintf(&cmd, "xdg-open \"%s?oauth_token=%s\"", AUTHORIZE_URL, tempKey);
	/* Open URL and user get PIN */
	system(cmd);

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);
	puts (tmp_token);

}

/*
 * Validate a PIN with Temp-Key and save all user-info
 * 
 * @Return User-Key, User-Secret-Key, Username, User-ID and other
 * All info is saved at ~/.twc/config/user file
 * 
 */
int access_token(const char *pin){


	int rc;
	const char *verifyPIN;

	char 	*twitterUserKey,
	*postarg,
	*tempKey,
	*tempKeySecret,
	*accessURL = ACCESS_TOKEN_URL;

	char **rv;
	puts(tmp_token);
	rc = oauth_split_url_parameters(tmp_token, &rv);
	tempKey = get_param(rv, rc, "oauth_token");
	tempKeySecret = get_param(rv, rc, "oauth_token_secret");
	user.consumerKey = get_param(rv, rc, "c_key");
	user.consumerSecretKey = get_param(rv, rc, "c_key_secret");

	/* Generate a URL, this verify a PIN
	 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
	 * All keys are saved in /tmp/token file
	 */
	asprintf(&accessURL, "%s?oauth_verifier=%s", accessURL, pin);
	verifyPIN = oauth_sign_url2(accessURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, tempKey, tempKeySecret);
	twitterUserKey = oauth_http_post(verifyPIN,postarg);

	/* Split all parameters and get User-ID, Username, and User-Keys */
	rc = oauth_split_url_parameters(twitterUserKey, &rv);
	user.Token = get_param(rv, rc, "oauth_token");
	user.secretToken = get_param(rv, rc, "oauth_token_secret");
	user.id = get_param(rv, rc, "user_id");
	user.screenName = get_param(rv, rc, "screen_name");

	/* Check Correct Input */

	if(writeUserFile()==0) return 0;

	return 1;
}

/*
 * Send a tweet with User-Keys (token) and TwitCrusader-Keys (token)
 * 
 */
int send_tweet(char *msg){

	char	*twitterStatusURL = STATUS_URL,
			*sendTweet;

	char *postarg = NULL;

	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, msg);

	if(user.consumerKey!=NULL &&
			user.consumerSecretKey!=NULL &&
			user.Token!=NULL &&
			user.secretToken!=NULL){

		sendTweet = oauth_sign_url2(twitterStatusURL, &postarg, OA_HMAC, "POST", user.consumerKey, user.consumerSecretKey, user.Token, user.secretToken);
		oauth_http_post(sendTweet, postarg);

		return 0;
	}

	return 1;
}
