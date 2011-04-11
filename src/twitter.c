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

	puts("writeUserFile");

	asprintf(&configFile, "%s%s", g_get_home_dir(), "/.twc/config/user.twc");

	if(user.screenName==NULL) puts("user.screenName==NULL");
	else puts(user.screenName);
	if(user.id==NULL) puts("user.id==NULL");
	else puts(user.id);
	if(user.consumerKey==NULL) puts("user.consumerKey==NULL");
	else puts(user.consumerKey);
	if(user.consumerSecretKey==NULL) puts("user.consumerSecretKey==NULL");
	else puts(user.consumerSecretKey);
	if(user.Token==NULL) puts("user.Token==NULL");
	else puts(user.Token);
	if(user.secretToken==NULL) puts("user.secretToken==NULL");
	else puts(user.secretToken);

	if(user.id!=NULL && user.screenName!=NULL && user.Token!=NULL && user.secretToken!=NULL){
		/* Save all personal keys and info of twitter-user at ~/.twc/config/user file */

		puts(configFile);
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

	puts("readUserFile");

	/* Generate a Local-URL for get all user-info */
	asprintf(&configFile, "%s%s", g_get_home_dir(), "/.twc/config/user.twc");

	puts(configFile);
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

		if(user.screenName==NULL) puts("user.screenName==NULL");
		else puts(user.screenName);
		if(user.id==NULL) puts("user.id==NULL");
		else puts(user.id);
		if(user.consumerKey==NULL) puts("user.consumerKey==NULL");
		else puts(user.consumerKey);
		if(user.consumerSecretKey==NULL) puts("user.consumerSecretKey==NULL");
		else puts(user.consumerSecretKey);
		if(user.Token==NULL) puts("user.Token==NULL");
		else puts(user.Token);
		if(user.secretToken==NULL) puts("user.secretToken==NULL");
		else puts(user.secretToken);

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
	char *twitterRequestURL=REQUEST_URL;

	puts("request_token");

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL = oauth_sign_url2(twitterRequestURL, NULL, OA_HMAC, NULL, consumerKey, consumerKeySecret, NULL, NULL);
	puts(twitterRequestURL);
	tempKeyParameters = oauth_http_get(twitterRequestURL, postarg);
	puts(tempKeyParameters);

	return tempKeyParameters;
}

/*
 * Main function for oAuth access
 *
 * Authorize Twitter Account
 *
 */
int temp_token_browser(){
	int rc;
	char *cmd,
	*tempKeyURL,
	*tempKey;
	char **rv=NULL;

	puts("temp_token_browser()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = request_token(TWITTER_KEY, TWITTER_KEY_SECRET);
	puts("tempKeyURL");
	puts(tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_param(rv, rc, "oauth_token");
	puts("tempKey");
	puts(tempKey);

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);
	puts (tmp_token);

	/* Generate a Twitter-URL for get user-PIN */
	asprintf(&cmd, "xdg-open \"%s?oauth_token=%s\"", AUTHORIZE_URL, tempKey);
	/* Open URL and user get PIN */
	system(cmd);

	return 0;
}

/*
 * Main function for oAuth access
 *
 * Authorize Twitter Account
 *
 */
int temp_token(){
	int rc;
	char *cmd,
	*tempKeyURL,
	*tempKey;
	char **rv=NULL;

	puts("temp_token()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = request_token(TWITTER_KEY, TWITTER_KEY_SECRET);
	puts("tempKeyURL");
	puts(tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_param(rv, rc, "oauth_token");
	puts("tempKey");
	puts(tempKey);

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);
	puts (tmp_token);

	return 0;
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

	char *twitterUserKey,
	*postarg,
	*tempKey,
	*tempKeySecret,
	*accessURL = ACCESS_TOKEN_URL;

	char **rv=NULL;

	puts("access_token()");
	printf("tmp_token: %s\n",tmp_token);

	// if(tmp_token==NULL) temp_token(); futura implementazione...

	printf("rc = oauth_split_url_parameters(tmp_token, &rv);");
	rc = oauth_split_url_parameters(tmp_token, &rv);

	puts("tempKey = get_param(rv, rc, \"oauth_token\");");
	tempKey = get_param(rv, rc, "oauth_token");
	printf("tempKey: %s\n", tempKey);

	tempKeySecret = get_param(rv, rc, "oauth_token_secret");
	printf("tempKeySecret: %s\n", tempKeySecret);

	user.consumerKey = get_param(rv, rc, "c_key");
	printf("user.consumerKey: %s\n", user.consumerKey);

	user.consumerSecretKey = get_param(rv, rc, "c_key_secret");
	printf("user.consumerSecretKey: %s\n", user.consumerSecretKey);

	/* Generate a URL, this verify a PIN
	 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
	 * All keys are saved in /tmp/token file
	 */
	asprintf(&accessURL, "%s?oauth_verifier=%s", accessURL, pin);
	puts("accessURL");
	verifyPIN = oauth_sign_url2(accessURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, tempKey, tempKeySecret);
	twitterUserKey = oauth_http_post(verifyPIN,postarg);

	/* Split all parameters and get User-ID, Username, and User-Keys */
	rc = oauth_split_url_parameters(twitterUserKey, &rv);
	user.Token = get_param(rv, rc, "oauth_token");
	user.secretToken = get_param(rv, rc, "oauth_token_secret");
	user.id = get_param(rv, rc, "user_id");
	user.screenName = get_param(rv, rc, "screen_name");

	if(user.screenName==NULL) puts("user.screenName==NULL");
	else puts(user.screenName);
	if(user.id==NULL) puts("user.id==NULL");
	else puts(user.id);
	if(user.consumerKey==NULL) puts("user.consumerKey==NULL");
	else puts(user.consumerKey);
	if(user.consumerSecretKey==NULL) puts("user.consumerSecretKey==NULL");
	else puts(user.consumerSecretKey);
	if(user.Token==NULL) puts("user.Token==NULL");
	else puts(user.Token);
	if(user.secretToken==NULL) puts("user.secretToken==NULL");
	else puts(user.secretToken);

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

	puts("send_tweet");

	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, msg);

	if(user.screenName==NULL) puts("user.screenName==NULL");
	else puts(user.screenName);
	if(user.id==NULL) puts("user.id==NULL");
	else puts(user.id);
	if(user.consumerKey==NULL) puts("user.consumerKey==NULL");
	else puts(user.consumerKey);
	if(user.consumerSecretKey==NULL) puts("user.consumerSecretKey==NULL");
	else puts(user.consumerSecretKey);
	if(user.Token==NULL) puts("user.Token==NULL");
	else puts(user.Token);
	if(user.secretToken==NULL) puts("user.secretToken==NULL");
	else puts(user.secretToken);

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
