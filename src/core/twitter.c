/*
 *	TwitCrusader - Twitter Client For Linux Desktop
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

#include "include/twitter.h"
#include "include/config.h"

/*
 * This function generate a 2 Twitter-Temp-Key
 * Use this Temp-keys for generate a PIN
 * Use PIN and Twitter-Temp-Keys for validate a correct PIN
 *
 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
 *
 */

char* tokenRequest(const char *consumerKey, const char *consumerKeySecret){
	char *postarg = NULL;
	char *tempKeyParameters = NULL;
	char *twitterRequestURL=REQUEST_URL;

	if(debug==1) printf("\ntokenRequest()");

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
int tokenTempBrowser(){
	int rc;
	char *cmd,
	*tempKeyURL,
	*tempKey;
	char **rv=NULL;

	if(debug==1) printf("\ntokenTempBrowser()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = tokenRequest(TWITTER_KEY, TWITTER_KEY_SECRET);
	if(debug==1)printf("\ntempKeyURL= %s", tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = getParameters(rv, rc, "oauth_token"); 

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
int tokenTemp(){
	int rc;
	char *tempKeyURL, *tempKey;
	char **rv=NULL;

	if(debug==1) printf("\ntokenTemp()");
	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = tokenRequest(TWITTER_KEY, TWITTER_KEY_SECRET);

	if(debug==1) printf("\ntempKeyURL= %s", tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = getParameters(rv, rc, "oauth_token");

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
int tokenAccess(const char *pin){

	int rc;
	char *verifyPIN;

	char *twitterUserKey,
	*postarg,
	*tempKey,
	*tempKeySecret,
	*accessURL = TOKENACCESS_URL;

	char **rv=NULL;

	puts("\ntokenAccess()");
	printf("\ntmp_token: %s\n",tmp_token);

	if(tmp_token==NULL) return 1;

	printf("\nrc = oauth_split_url_parameters(tmp_token, &rv);");
	rc = oauth_split_url_parameters(tmp_token, &rv);

	puts("\ngetParameters(rv, rc, \"oauth_token\");");
	tempKey = getParameters(rv, rc, "oauth_token");
	printf("\ntempKey: %s\n", tempKey);

	tempKeySecret = getParameters(rv, rc, "oauth_token_secret");
	printf("\ntempKeySecret: %s\n", tempKeySecret);

	strcpy(user.consumerKey, getParameters(rv, rc, "c_key"));
	printf("\nuser.consumerKey: %s\n", user.consumerKey);

	strcpy(user.consumerSecretKey, getParameters(rv, rc, "c_key_secret"));
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
	if (strcmp(twitterUserKey," ") == 0)
		return 1;

	/* Split all parameters and get User-ID, Username, and User-Keys */
	rc = oauth_split_url_parameters(twitterUserKey, &rv);
	strcpy(user.token, getParameters(rv, rc, "oauth_token"));
	strcpy(user.secretToken, getParameters(rv, rc, "oauth_token_secret"));
	strcpy(user.id, getParameters(rv, rc, "user_id"));
	strcpy(user.screenName, getParameters(rv, rc, "screen_name"));

	if(debug==1){
		printf("\nint tokenAccess(const char *pin)");
		printf("\nuser.screenName= %s",user.screenName);
		printf("\nuser.id= %s", user.id);
		printf("\nuser.consumerKey= %s", user.consumerKey);
		printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
		printf("\nuser.Token= %s", user.token);
		printf("\nuser.secretToken= %s", user.secretToken);
	}

	return writeUserFile();

}

/*
 * Send a tweet with User-Keys (token) and TwitCrusader-Keys (token)
 *
 */
int SendTweet(char *msg){

	char	*twitterStatusURL = STATUS_URL,
			*sendTweet,
			*error;

	char *postarg = NULL;

	if(debug==1) printf("\nint SendTweet(char *msg)");

	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, oauth_url_escape(msg)); 

	if(debug==1) printf("\nwitterStatusURL= %s",twitterStatusURL);

	if(debug==1){
		printf("\nuser.screenName= %s",user.screenName);
		printf("\nuser.id= %s", user.id);
		printf("\nuser.consumerKey= %s", user.consumerKey);
		printf("\nuser.consumerSecretKey= %s", user.consumerSecretKey);
		printf("\nuser.Token= %s", user.token);
		printf("\nuser.secretToken= %s", user.secretToken);
	}

	if(strcmp(user.id, " ") != 0 &&
			strcmp(user.screenName, " ") != 0 &&
			strcmp(user.consumerKey, " ") != 0 && 
			strcmp(user.consumerSecretKey, " ") != 0 && 
			strcmp(user.token, " ") != 0 &&
			strcmp(user.secretToken, " ") != 0){

		sendTweet = oauth_sign_url2(twitterStatusURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, user.token, user.secretToken);
		error = oauth_http_post(sendTweet, postarg);

		if(!error)
			return 1;

		return 3;
	}

	return 0;
}


int switchTimeLine(int xmlSwitch){

	FILE *fp;

	char *timelineURL=NULL,
			*timeline, *cmd=NULL;
	char *postarg=NULL,
			*tmpFile = NULL;

	if(debug==1) printf("\nint switchTimeLine()");
	if(debug==1) printf("\nxmlSwitch = %d\n",xmlSwitch);

	if(xmlSwitch == 1){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "home_timeline.xml");
		timelineURL=HOME_TIMELINE_URL;
	}

	if(xmlSwitch == 2){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "public_timeline.xml");
		timelineURL=PUBLIC_TIMELINE_URL;
	}

	if(xmlSwitch == 3){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "mentions.xml");
		timelineURL=MENTIONS_TIMELINE_URL;
	}

	if(xmlSwitch == 4){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "friends_timeline.xml");
		timelineURL=FRIENDS_TIMELINE_URL;
	}

	if(xmlSwitch == 5){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "user_timeline.xml");
		timelineURL=USER_TIMELINE_URL;
	}

	if(xmlSwitch == 6){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_by_me.xml");
		timelineURL=RT_BY_ME_TIMELINE_URL;
	}

	if(xmlSwitch == 7){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_to_me.xml");
		timelineURL=RT_TO_ME_TIMELINE_URL;
	}

	if(xmlSwitch == 8){
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_of_me.xml");
		timelineURL=RT_OF_ME_TIMELINE_URL;
	}

	timeline= oauth_sign_url2(timelineURL, NULL, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, user.token, user.secretToken);
	timeline= oauth_http_get(timeline, postarg);
	if(debug==1) printf("\ntimeline= %s", timeline);

	fp=fopen(tmpFile, "w");

	if(timeline!=NULL){
		if(fp!=NULL){

			printf("\nfputs(timeline, fp)");

			fprintf(fp, "%s",timeline);
			fclose(fp);
			system("echo \"Downloading Twitter Files...\"");
			readTimeLine(tmpFile);

			asprintf(&cmd,"rm -f %s", tmpFile);
			if(debug==1) printf("\ncmd= %s",cmd);

			system(cmd);
			free(timeline);
			return 0;
		}
	}
	free(timeline);
	return 1;
}
