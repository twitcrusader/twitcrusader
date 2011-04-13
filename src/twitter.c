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
	char *cmd;
	char *data_file;

	asprintf(&cmd, "%s %s", "mkdir -p", progPath.configDir);

	if(debug==1){
		printf("\nwriteUserFile()");
		printf("\nuser.screenName= %s",user.screenName);
		printf("\nuser.id= %s", user.id);
		printf("\nuser.consumerKey= %s", user.consumerKey);
		printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
		printf("\nuser.Token= %s", user.Token);
		printf("\nuser.secretToken= %s", user.secretToken);
	}

	//	if(user.id!=NULL && user.screenName!=NULL && user.Token!=NULL && user.secretToken!=NULL){
	/* Save all personal keys and info of twitter-user at ~/.twc/config/user file */
	system(cmd);
	fp=fopen(progPath.configFile, "w+");

	if(fp!=NULL){

		asprintf(&data_file, "%s||", user.screenName);
		asprintf(&data_file, "%s%s||", data_file, user.id);
		asprintf(&data_file, "%s%s||", data_file, user.consumerKey);
		asprintf(&data_file, "%s%s||", data_file, user.consumerSecretKey);
		asprintf(&data_file, "%s%s||", data_file, user.Token);
		asprintf(&data_file, "%s%s||", data_file, user.secretToken);


		if(debug==1) printf("data_file= %s",data_file);

		fputs(data_file, fp);
		fclose(fp);

		if(debug==1) printf("\nfp Scritto corretamente!");

		return 0;
	}else{

		if(debug==1) printf("\nnon risco ad aprire il file: %s !", progPath.configFile);
	}
	//}

	return 1;
}

int readUserFile(){

	FILE *fp;

	char buffer[256];

	const char delims[] = "||";

	if(debug==1) printf("\nreadUserFile()");

	if(debug==1) printf("\nconfigFile= %s", progPath.configFile);
	/* Get all user-info and user token */
	fp = fopen (progPath.configFile, "r");

	if(fp!=NULL){
		fgets(buffer, 250, fp);

		/* Username */
		user.screenName = strtok(buffer, delims);

		/* User-ID */
		user.id = strtok(NULL, delims);

		/* Get TwitCrusader Token */
		user.consumerKey = strtok(NULL, delims);

		/* Get TwitCrusader Secret Token */
		user.consumerSecretKey = strtok(NULL, delims);

		/* Get User Token */
		user.Token = strtok(NULL, delims);

		/* Get TwitCrusader Secret Token */
		user.secretToken = strtok(NULL, delims);

		if(debug==1){
			printf("\nwriteUserFile()");
			printf("\nuser.screenName= %s",user.screenName);
			printf("\nuser.id= %s", user.id);
			printf("\nuser.consumerKey= %s", user.consumerKey);
			printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
			printf("\nuser.Token= %s", user.Token);
			printf("\nuser.secretToken= %s", user.secretToken);
		}

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

	if(debug==1) printf("\nrequest_token");

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL = oauth_sign_url2(twitterRequestURL, NULL, OA_HMAC, NULL, consumerKey, consumerKeySecret, NULL, NULL);
	if(debug==1) printf("\ntwitterRequestURL= %s",twitterRequestURL);

	tempKeyParameters = oauth_http_get(twitterRequestURL, postarg);
	if(debug==1) printf("\ntempKeyParameters= %s",tempKeyParameters);

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

	if(debug==1) printf("\ntemp_token_browser()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = request_token(TWITTER_KEY, TWITTER_KEY_SECRET);
	if(debug==1)printf("\ntempKeyURL= %s", tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_param(rv, rc, "oauth_token");

	if(debug==1) printf("\ntempKey= %s", tempKey);
	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);

	if(debug==1) printf("tmp_token= %s",tmp_token);

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
	char *tempKeyURL, *tempKey;
	char **rv=NULL;

	if(debug==1) printf("\ntemp_token()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = request_token(TWITTER_KEY, TWITTER_KEY_SECRET);

	if(debug==1) printf("\ntempKeyURL= %s", tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_param(rv, rc, "oauth_token");

	if(debug==1) printf("\ntempKey= %s", tempKey);

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);
	printf ("\ntmp_token= %s",tmp_token);

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
	char *verifyPIN;

	char *twitterUserKey,
	*postarg,
	*tempKey,
	*tempKeySecret,
	*accessURL = ACCESS_TOKEN_URL;

	char **rv=NULL;

	puts("\naccess_token()");
	printf("\ntmp_token: %s\n",tmp_token);

	// if(tmp_token==NULL) temp_token(); futura implementazione...

	printf("\nrc = oauth_split_url_parameters(tmp_token, &rv);");
	rc = oauth_split_url_parameters(tmp_token, &rv);

	puts("\ntempKey = get_param(rv, rc, \"oauth_token\");");
	tempKey = get_param(rv, rc, "oauth_token");
	printf("\ntempKey: %s\n", tempKey);

	tempKeySecret = get_param(rv, rc, "oauth_token_secret");
	printf("\ntempKeySecret: %s\n", tempKeySecret);

	user.consumerKey = get_param(rv, rc, "c_key");
	printf("\nuser.consumerKey: %s\n", user.consumerKey);

	user.consumerSecretKey = get_param(rv, rc, "c_key_secret");
	printf("\nuser.consumerSecretKey: %s\n", user.consumerSecretKey);

	/* Generate a URL, this verify a PIN
	 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
	 * All keys are saved in /tmp/token file
	 */
	asprintf(&accessURL, "%s?oauth_verifier=%s", accessURL, pin);

	if(debug==1){
		printf("pin= %s",pin);
		printf("accessURL= %s",accessURL);
	}

	verifyPIN = oauth_sign_url2(accessURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, tempKey, tempKeySecret);
	twitterUserKey = oauth_http_post(verifyPIN,postarg);

	/* Split all parameters and get User-ID, Username, and User-Keys */
	rc = oauth_split_url_parameters(twitterUserKey, &rv);
	user.Token = get_param(rv, rc, "oauth_token");
	user.secretToken = get_param(rv, rc, "oauth_token_secret");
	user.id = get_param(rv, rc, "user_id");
	user.screenName = get_param(rv, rc, "screen_name");

	if(debug==1){
		printf("\nwriteUserFile()");
		printf("\nuser.screenName= %s",user.screenName);
		printf("\nuser.id= %s", user.id);
		printf("\nuser.consumerKey= %s", user.consumerKey);
		printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
		printf("\nuser.Token= %s", user.Token);
		printf("\nuser.secretToken= %s", user.secretToken);
	}

	return writeUserFile();
}

/*
 * Send a tweet with User-Keys (token) and TwitCrusader-Keys (token)
 *
 */
int send_tweet(char *msg){

	char	*twitterStatusURL = STATUS_URL,
			*sendTweet;

	char *postarg = NULL;

	if(debug==1) printf("send_tweet()");

	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, msg);

	if(debug==1){
		printf("\nwriteUserFile()");
		printf("\nuser.screenName= %s",user.screenName);
		printf("\nuser.id= %s", user.id);
		printf("\nuser.consumerKey= %s", user.consumerKey);
		printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
		printf("\nuser.Token= %s", user.Token);
		printf("\nuser.secretToken= %s", user.secretToken);
	}

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

int homeTimeline(){
	int count=20;
	char *timelineURL=HOME_TIMELINE_URL,
			*timeline1, *timeline2;
	char *postarg=NULL;

	asprintf(&timelineURL, "%s?count=%i",timelineURL, count);

	timeline1 = oauth_sign_url2(timelineURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, user.Token, user.secretToken);
	timeline2= oauth_http_get(timelineURL, postarg);
	printf("timeline1= %s",timeline1); //momentaneo..
	printf("timeline2= %s",timeline1); //momentaneo..

	return 0;
}

int deleteAccount(){

	char *cmd,
	*configDir,
	*configFile;

	asprintf(&configDir, "%s%s", g_get_home_dir(), "/.twc/config/");
	asprintf(&configFile, "%s%s", configDir, "user.twc");
	asprintf(&cmd, "%s %s", "rm ", configFile);

	if(system(cmd)==0){
		user.Token=NULL;
		user.consumerKey=NULL;
		user.consumerSecretKey=NULL;
		user.id=NULL;
		user.screenName=NULL;
		user.secretToken=NULL;

		return 0;
	}

	return 1;
}

void disconnect(){
	user.Token=NULL;
	user.consumerKey=NULL;
	user.consumerSecretKey=NULL;
	user.id=NULL;
	user.screenName=NULL;
	user.secretToken=NULL;
}
