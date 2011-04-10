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
 
#define _GNU_SOURCE
#include "include/twitter.h"

/*
 * Main function for oAuth access
 * 
 * This function call other function for authorize Twitter Account
 * and save User Token & User Secret Token
 * 
 */
int oauth_start(){
	FILE *fp;
	int rc;
	char *cmd = NULL, 
		 *tempKeyURL = NULL,
		 *tempKey = NULL,
		 *tmp_token = NULL;
	char **rv = NULL;
	const char *consumerKey    	  = TWITTER_KEY;
	const char *consumerKeySecret = TWITTER_KEY_SECRET;

	/* 
	 * @Input: TwitCrusader Consumer-Key 
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *  	 
	 */
	tempKeyURL = request_token(consumerKey, consumerKeySecret);
	
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
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", consumerKey, "&c_key_secret=", consumerKeySecret);
	fp=fopen("/tmp/token", "w+");
		fprintf(fp, tmp_token);
	fclose(fp);

	return 0;
}

/* 
 * This function generate a 2 Twitter-Temp-Key
 * Use this Temp-keys for generate a PIN
 * Use PIN and Twitter-Temp-Keys for validate a correct PIN 
 * 
 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
 *  	 
 */
char* request_token(const char *consumerKey, const char *consumerKeySecret){
	char *postarg = NULL,
		 *tempKeyParameters = NULL;
	const char *twitterRequestURL = NULL;

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL = oauth_sign_url2(REQUEST_URL, NULL, OA_HMAC, NULL, consumerKey, consumerKeySecret, NULL, NULL);
	tempKeyParameters = oauth_http_get(twitterRequestURL,postarg);

	return tempKeyParameters;
}

/*
 * Validate a PIN with Temp-Key and save all user-info
 * 
 * @Return User-Key, User-Secret-Key, Username, User-ID and other
 * All info is saved at ~/.twc/config/user file
 * 
 */
int access_token(const char *pin){
	
	FILE *fp;
	int rc;
	const char *verifyPIN = NULL;
	int correctVerify = 1;

	char 	*twitterUserKey = NULL,
			*data_file = NULL,
			*postarg = NULL,
			*tempKey =  NULL,
			*tempKeySecret =  NULL,
			*consumerKey =  NULL,
			*consumerKeySecret = NULL,
			*configFile = NULL,
			*accessURL = ACCESS_TOKEN_URL,
			*userKey = NULL,
			*userKeySecret = NULL,
			*userID = NULL,
			*screenName = NULL;

	char **rv = NULL;
	char buffer[256];
	
	/*
	 *  Generate TwitCrusader Local-URL for save all info 
	 * ~/.twc/config/user
	 * 
	 */
	asprintf(&configFile, "%s%s", getenv("HOME"), "/user");
	
	/* Check Correct Input */
	if(fopen ("/tmp/token", "r") != NULL){
		/* Get all saved key: Temp-Keys and TwitCrusader consumerKeys */
		fp = fopen ("/tmp/token", "r");
			fgets(buffer, 250, fp);
			rc = oauth_split_url_parameters(buffer, &rv);
			tempKey = get_param(rv, rc, "oauth_token");
			tempKeySecret = get_param(rv, rc, "oauth_token_secret");
			consumerKey = get_param(rv, rc, "c_key");
			consumerKeySecret = get_param(rv, rc, "c_key_secret");
		fclose (fp);
		
		/* Generate a URL, this verify a PIN 
		 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
		 * All keys are saved in /tmp/token file
		 */
		asprintf(&accessURL, "%s?oauth_verifier=%s", accessURL, pin);
		verifyPIN = oauth_sign_url2(accessURL, &postarg, OA_HMAC, NULL, consumerKey, consumerKeySecret, tempKey, tempKeySecret);
		twitterUserKey = oauth_http_post(verifyPIN,postarg);
		
		/* Split all parameters and get User-ID, Username, and User-Keys */
		rc = oauth_split_url_parameters(twitterUserKey, &rv);
		userKey = get_param(rv, rc, "oauth_token");
		userKeySecret = get_param(rv, rc, "oauth_token_secret");
		userID = get_param(rv, rc, "user_id");
		screenName = get_param(rv, rc, "screen_name");
	
		/* Check Correct Input */
		if(userKey != NULL && screenName != NULL){
			/* Save all personal keys and info of twitter-user at ~/.twc/config/user file */
			fp=fopen(configFile, "w+");
				asprintf(&data_file, "%s||%s||%s||%s||%s||%s", screenName, userID, consumerKey, consumerKeySecret, userKey, userKeySecret);
				fprintf(fp, data_file);
			fclose(fp);
		
			/* Remove token file with all Temp-Keys saved */
			remove("/tmp/token");
		}else{
			correctVerify = 0;
			remove("/tmp/token");
		}
	}else{
		correctVerify = 0;
		remove("/tmp/token");
	}
	
	return correctVerify;
}

/*
 * Send a tweet with User-Keys (token) and TwitCrusader-Keys (token)
 * 
 */
void send_tweet(char *msg){

	FILE *fp;
	char *consumerToken = NULL,
		 *consumerTokenSecret = NULL,
		 *userToken = NULL,
		 *userTokenSecret = NULL,
		 *result = NULL,
		 *configFile = NULL,
		 *twitterStatusURL = STATUS_URL,
		 *sendTweet = NULL;
	char buffer[256];
	char *postarg = NULL;
	char delims[] = "||";

	/* Generate a Local-URL for get all user-info */
	asprintf(&configFile, "%s%s", getenv("HOME"), "/user");

	/* Get all user-info and user token */
	fp = fopen (configFile, "r");
		fgets(buffer, 250, fp);
		
		/* Username */
		result = strtok( buffer, delims);
		
		/* User-ID */
		result = strtok( NULL, delims );
		
		/* Get TwitCrusader Token */
		result = strtok( NULL, delims );
		consumerToken = result;

		/* Get TwitCrusader Secret Token */
		result = strtok( NULL, delims );
		consumerTokenSecret = result;
		
		/* Get User Token */
		result = strtok( NULL, delims );
		userToken = result;
		
		/* Get TwitCrusader Secret Token */
		result = strtok( NULL, delims );
		userTokenSecret = result;
	fclose (fp);
	
	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, msg);
	sendTweet = oauth_sign_url2(twitterStatusURL, &postarg, OA_HMAC, NULL, consumerToken, consumerTokenSecret, userToken, userTokenSecret);
	oauth_http_post(sendTweet, postarg);

}
