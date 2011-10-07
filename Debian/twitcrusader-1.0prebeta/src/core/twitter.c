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

#include "inc/twitter.h"
#include "inc/config.h"

/*
 * This function generate a 2 Twitter-Temp-Key
 * Use this Temp-keys for generate a PIN
 * Use PIN and Twitter-Temp-Keys for validate a correct PIN
 *
 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
 *
 */

char* token_request(const char *consumerKey, const char *consumerKeySecret){

	debug_f_start("token_request");

	char *postarg = NULL;
	char *tempKeyParameters = NULL;
	char *twitterRequestURL=tw_URLS.request_url;

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL = oauth_sign_url2(twitterRequestURL, NULL, OA_HMAC, NULL, consumerKey, consumerKeySecret, NULL, NULL);
	debug_var_char("twitterRequestURL",twitterRequestURL);

	tempKeyParameters = oauth_http_get(twitterRequestURL, postarg);
	debug_var_char("tempKeyParameters",tempKeyParameters);

	return tempKeyParameters;
}

/*
 * Main function for oAuth access
 *
 * Authorize Twitter Account
 *
 */
int token_temp_browser(){

	debug_f_start("token_temp_browser");

	int rc;
	char *cmd,
	*tempKeyURL,
	*tempKey;
	char **rv=NULL;

	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = token_request(TWITTER_KEY, TWITTER_KEY_SECRET);
	debug_var_char("tempKeyURL",tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_parameters(rv, rc, "oauth_token");

	debug_var_char("tempKey",tempKey);

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);

	debug_var_char("tmp_token",tmp_token);

	/* Generate a Twitter-URL for get user-PIN */
	asprintf(&cmd, "xdg-open \"%s?oauth_token=%s\"", tw_URLS.authorize_url, tempKey);

	debug_var_char("cmd", cmd);

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
int token_temp(){

	debug_f_start("token_temp");

	int rc;
	char *tempKeyURL, *tempKey;
	char **rv=NULL;

	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL = token_request(TWITTER_KEY, TWITTER_KEY_SECRET);

	debug_var_char("tempKeyURL", tempKeyURL);

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL, &rv);
	tempKey = get_parameters(rv, rc, "oauth_token");

	debug_var_char("tempKey", tempKey);


	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	asprintf(&tmp_token, "%s%s%s%s%s", tempKeyURL, "&c_key=", TWITTER_KEY, "&c_key_secret=", TWITTER_KEY_SECRET);
	debug_var_char("tmp_token", tmp_token);

	return 0;
}

/*
 * Validate a PIN with Temp-Key and save all user-info
 *
 * @Return User-Key, User-Secret-Key, Username, User-ID and other
 * All info is saved at ~/.twc/config/user file
 *
 */
int token_access(const char *pin){

	debug_f_start("token_access");

	int rc;
	char *verifyPIN;

	char *twitterUserKey,
	*postarg,
	*tempKey,
	*tempKeySecret,
	*accessURL = tw_URLS.tokenaccess_url;

	char **rv=NULL;

	debug_var_char("tmp_token", tmp_token);

	if(tmp_token==NULL) return 1;

	rc = oauth_split_url_parameters(tmp_token, &rv);

	tempKey = get_parameters(rv, rc, "oauth_token");
	debug_var_char("tempKey", tempKey);

	tempKeySecret = get_parameters(rv, rc, "oauth_token_secret");
	debug_var_char("tempKeySecret", tempKeySecret);

	strcpy(user.consumerKey, get_parameters(rv, rc, "c_key"));
	debug_var_char("user.consumerKey", user.consumerKey);

	strcpy(user.consumerSecretKey, get_parameters(rv, rc, "c_key_secret"));
	debug_var_char("user.consumerSecretKey", user.consumerSecretKey);

	/* Generate a URL, this verify a PIN
	 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
	 * All keys are saved in /tmp/token file
	 */
	asprintf(&accessURL, "%s?oauth_verifier=%s", accessURL, pin);

	debug_var_char("pin", pin);
	debug_var_char("accessURL", accessURL);

	verifyPIN = oauth_sign_url2(accessURL, &postarg, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, tempKey, tempKeySecret);
	twitterUserKey = oauth_http_post(verifyPIN,postarg);
	if (strcmp(twitterUserKey," ") == 0)
		return 1;

	/* Split all parameters and get User-ID, Username, and User-Keys */
	rc = oauth_split_url_parameters(twitterUserKey, &rv);
	strcpy(user.token, get_parameters(rv, rc, "oauth_token"));
	strcpy(user.secretToken, get_parameters(rv, rc, "oauth_token_secret"));
	strcpy(user.id, get_parameters(rv, rc, "user_id"));
	strcpy(user.screenName, get_parameters(rv, rc, "screen_name"));


	/*DEBUG*/
	debug_var_char("user.screenName",user.screenName);
	debug_var_char("user.id",user.id);
	debug_var_char("user.consumerKey",user.consumerKey);
	debug_var_char("user.consumerSecretKey",user.consumerSecretKey);
	debug_var_char("user.token",user.token);
	debug_var_char("user.secretToken",user.secretToken);

	return write_user_file();

}

/*
 * Send a tweet with User-Keys (token) and TwitCrusader-Keys (token)
 *
 */
int send_tweet(char *msg){

	debug_f_start("send_tweet");

	char	*twitterStatusURL = tw_URLS.status_url,
			*sendTweet,
			*error;

	char *postarg = NULL;

	/* Send Tweet with oAuth functions */
	asprintf(&twitterStatusURL, "%s%s", twitterStatusURL, oauth_url_escape(msg)); 

	debug_var_char("twitterStatusURL", twitterStatusURL);

	/*DEBUG*/
	debug_var_char("user.screenName",user.screenName);
	debug_var_char("user.id",user.id);
	debug_var_char("user.consumerKey",user.consumerKey);
	debug_var_char("user.consumerSecretKey",user.consumerSecretKey);
	debug_var_char("user.token",user.token);
	debug_var_char("user.secretToken",user.secretToken);

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


int switch_timeline(int xmlSwitch){

	debug_f_start("switch_timeline");

	FILE *fp;

	char *timelineURL, *timeline, *cmd;
	char *postarg=NULL, *tmpFile;

	debug_var_int("xmlSwitch",xmlSwitch);

	switch(xmlSwitch){

	case 0:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "public_timeline.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.public_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;
	case 1:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "home_timeline.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.home_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 2:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "mentions.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.mentions_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 3:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "friends_timeline.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.friends_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 4:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "user_timeline.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.user_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 5:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_by_me.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.rt_by_me_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 6:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_to_me.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.rt_to_me_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	case 7:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "retweeted_of_me.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.rt_of_me_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;

	default:
		asprintf(&tmpFile , "%s%s", progPath.timelineDir, "public_timeline.xml");
		debug_var_char("tmpFile",tmpFile);

		timelineURL=tw_URLS.public_timeline_url;
		debug_var_char("timelineURL",timelineURL);

		break;
	}

	debug_var_int("xmlSwitch",xmlSwitch);

	timeline= oauth_sign_url2(timelineURL, NULL, OA_HMAC, NULL, user.consumerKey, user.consumerSecretKey, user.token, user.secretToken);
	debug_var_char("timeline", timeline);
	timeline= oauth_http_get(timeline, postarg);
	debug_var_char("timeline",timeline);

	fp=fopen(tmpFile, "w");

	if(timeline!=NULL){
		if(fp!=NULL){

			fprintf(fp, "%s",timeline);
			fclose(fp);
			read_time_line(tmpFile);

			asprintf(&cmd,"rm -f %s", tmpFile);
			debug_var_char("cmd",cmd);
			system(cmd);

			free(timeline);
			return 0;
		}
	}

	free(timeline);
	return 1;
}

void downloads_avatars(){

	debug_f_start("downloadsAvatars");


	pthread_t tid;
	int i, error=0;

	for(i=0; i<MAX_NUM_TWEETS; i++){
		char *argv[2];
		argv[0]=timeline[i].user.profile_image_url;
		argv[1]=timeline[i].user.profile_image;

		error = pthread_create(&tid, NULL, pull_one_url, (void *)argv);


			if(0 != error){
				debug_var_int("Can't Start Thread Number",i);
			}
			else{
				debug_var_int("Start Thread Number",i);
				debug_var_char("Thread argument",argv[0]);
		}

		error = pthread_join(tid, NULL);
		debug_var_int("Stop Thread Number",i);

	}
}
