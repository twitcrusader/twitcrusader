/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
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
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/Twitter.h"
namespace TwitCrusader {
Twitter::Twitter()
{
	localUser = LocalUser();
	timeLine = TimeLine();
	config = Config();
	tmp_token=ustring();
}

Twitter::~Twitter()
{

}

/*
 * Casting of the Function writeUserFile into the Class LocalUser
 */

bool Twitter::writeUserFile()
{
	localUser.writeUserFile(config.getConfigFile());
	return true;

}

/*
 * Casting of the Function readUserFile into the Class LocalUser
 */

bool Twitter::readUserFile()
{
	localUser.readUserFile(config.getConfigFile());
	return true;
}

/*
 *  Switch the timelineURL and download the corrispondent timeline - XML
 */

bool Twitter::switchTimeLine(int xmlSwitch)
{
	switch(xmlSwitch){

	case 1:
		this->timeLine.timelineURL.assign(PUBLIC_TIMELINE_URL);
		break;


	case 2:
		this->timeLine.timelineURL.assign(HOME_TIMELINE_URL);
		break;


	case 3:
		this->timeLine.timelineURL.assign(MENTIONS_TIMELINE_URL);
		break;


	case 4:
		this->timeLine.timelineURL.assign(FRIENDS_TIMELINE_URL);
		break;


	case 5:
		this->timeLine.timelineURL.assign(USER_TIMELINE_URL);
		break;


	case 6:
		this->timeLine.timelineURL.assign(RT_BY_ME_TIMELINE_URL);
		break;


	case 7:
		this->timeLine.timelineURL.assign(RT_TO_ME_TIMELINE_URL);
		break;


	case 8:
		this->timeLine.timelineURL.assign(RT_OF_ME_TIMELINE_URL);
		break;


	default:
		this->timeLine.timelineURL.assign(PUBLIC_TIMELINE_URL);
		break;

	}

	downloadTimeLine();

	return true;
}

/*
 * Download and Read the timeline - XML
 */

bool Twitter::downloadTimeLine()
{
	ustring postarg=ustring();
	char* tml_rt;
	ustring tml(oauth_sign_url2(timeLine.timelineURL.c_str(), NULL, OA_HMAC, NULL, localUser.getConsumerKey().c_str(), localUser.getConsumerSecretKey().c_str(), localUser.getToken().c_str(), localUser.getSecretToken().c_str()));
	tml_rt=oauth_http_get(tml.c_str(), postarg.c_str());
	if(tml_rt!=NULL){
		tml.assign(tml_rt);

		if(!tml.empty()){

			timeLine.readTimeLineFromString(tml);
			return true;
		}

	}

	return false;
}

/*
 * To Download the avatars of Tweets that you show
 */

void Twitter::downloadAvatars()
{

	Glib::Thread *thread;
	this->config.createAvatarDir();
	ustring path=ustring();

	for(vector<Tweet>::iterator it =  timeLine.timeline->begin(); it!=timeLine.timeline->end(); it++){
		sigc::slot<void> my_slot=sigc::bind<0>(sigc::mem_fun(*this, &Twitter::downloadAvatar),*it);
		thread=Glib::Thread::create(my_slot,true);
		thread->join();
		//Twitter::downloadAvata(*it);

	}


}

void Twitter::downloadAvatar(Tweet &it)
{
	ustring path=ustring();

	path.assign(this->config.getAvatarDir()+"/"+it.user.screen_name);
	GetHTTP::getSingleCURL(it.user.profile_image_url, path);

}

/*
 * Send your Tweet
 */

bool Twitter::SendTweet(ustring msg)
{

	ustring twitterStatusURL=ustring();
	ustring sendTweet=ustring();
	char* error;

	char* postarg = NULL;

	/* Send Tweet with oAuth functions */
	twitterStatusURL.assign(STATUS_URL);
	twitterStatusURL.append(oauth_url_escape(msg.c_str()));

	if(!localUser.getId().empty()&&
			!localUser.getScreenName().empty()&&
			!localUser.getConsumerKey().empty()&&
			!localUser.getConsumerSecretKey().empty() &&
			!localUser.getToken().empty()&&
			!localUser.getSecretToken().empty()){

		sendTweet = oauth_sign_url2(twitterStatusURL.c_str(), &postarg, OA_HMAC, NULL, localUser.getConsumerKey().c_str(), localUser.getConsumerSecretKey().c_str(), localUser.getToken().c_str(), localUser.getSecretToken().c_str());
		error = oauth_http_post(sendTweet.c_str(), postarg);

		if(error!=NULL)
			return true;

		return false;
	}

	return false;
}

/*
 * Generate the temporary Token
 */

bool Twitter::tokenTemp()
{

	int rc;
	ustring tempKeyURL=ustring();
	ustring tempKey=ustring();
	char **rv=NULL;

	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL.assign(tokenRequest(CONSUMER_KEY, CONSUMER_SECRET_KEY));

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL.c_str(), &rv);
	tempKey.assign(getParameters(rv, rc, "oauth_token"));

	/*
	 * Save all Twitter-Key at /tmp folder
	 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
	 */
	tmp_token.assign(tempKeyURL);
	tmp_token.append("&c_key=");
	tmp_token.append(CONSUMER_KEY);
	tmp_token.append("&c_key_secret=");
	tmp_token.append(CONSUMER_SECRET_KEY);

	return true;

}

/*
 * Generate the Token to grant access from Browser
 */

bool Twitter::tokenTempBrowser()
{
	int rc;
	ustring cmd=ustring();
	ustring tempKeyURL=ustring();
	ustring tempKey=ustring();
	char **rv=NULL;

	/*
	 * @Input: TwitCrusader Consumer-Key
	 * @Return Url-Parameters with Consumer-Temp-Key and Consumer-Temp-Key-Secret
	 *
	 */
	tempKeyURL.assign(tokenRequest(CONSUMER_KEY, CONSUMER_SECRET_KEY));

	/* split url and get Temp-Key */
	rc = oauth_split_url_parameters(tempKeyURL.c_str(), &rv);
	char *tmpKey=getParameters(rv, rc, "oauth_token");
	if(tmpKey!=NULL){
		tempKey.assign(tmpKey);

		/*
		 * Save all Twitter-Key at /tmp folder
		 * Temp-Key + Temp-Key-Secret + TwitCrusader Key + TwitCrusader Key Secret
		 */

		tmp_token.assign(tempKeyURL);
		tmp_token.append("&c_key=");
		tmp_token.append(CONSUMER_KEY);
		tmp_token.append("&c_key_secret=");
		tmp_token.append(CONSUMER_SECRET_KEY);
		cout<<"\n"<<tmp_token;

		/* Generate a Twitter-URL for get user-PIN */

		cmd.assign(AUTHORIZE_URL);
		cmd.append("?oauth_token=");
		cmd.append(tempKey);

		/* Open URL and user get PIN */
		gtk_show_uri(NULL,cmd.c_str(),GDK_CURRENT_TIME,NULL);

		return true;
	}

	return false;
}

/*
 * Generate the Access Token
 */

bool Twitter::tokenAccess(const ustring pin)
{
	int rc;
	ustring buffer=ustring();
	ustring verifyPIN=ustring();

	ustring twitterUserKey=ustring();

	ustring tempKey=ustring();
	ustring tempKeySecret=ustring();
	ustring accessURL=ustring();

	accessURL.assign(TOKENACCESS_URL);
	char *postarg;

	char **rv=NULL;

	cout<<"\n"<<tmp_token;

	if(tmp_token.empty()) return false;

	rc = oauth_split_url_parameters(tmp_token.c_str(), &rv);


	tempKey.assign(getParameters(rv, rc, "oauth_token"));


	tempKeySecret.assign(getParameters(rv, rc, "oauth_token_secret"));

	localUser.setConsumerKey(getParameters(rv, rc, "c_key") );

	localUser.setConsumerSecretKey(getParameters(rv, rc, "c_key_secret"));

	/* Generate a URL, this verify a PIN
	 * For validate PIN is necessary: TwitCrusader consumer key (and secret) with a 2 Temp-Keys
	 * All keys are saved in /tmp/token file
	 */
	accessURL.append("?oauth_verifier=");
	accessURL.append(pin);

	cout<<"\naccessURL:"<<accessURL;

	verifyPIN.assign(oauth_sign_url2(accessURL.c_str(), &postarg, OA_HMAC, NULL, localUser.getConsumerKey().c_str(), localUser.getConsumerSecretKey().c_str(), tempKey.c_str(), tempKeySecret.c_str()) );
	twitterUserKey.assign(oauth_http_post(verifyPIN.c_str(),postarg));

	if (twitterUserKey.empty() || twitterUserKey.size()<=1) return false;

	/* Split all parameters and get User-ID, Username, and User-Keys */
	cout<<"\ntwitterUserKey: "<<twitterUserKey;
	rc = oauth_split_url_parameters(twitterUserKey.c_str(), &rv);

	cout<<"\n"<<rv;

	localUser.setToken(getParameters(rv, rc, "oauth_token"));
	localUser.setSecretToken(getParameters(rv, rc, "oauth_token_secret"));
	localUser.setId(getParameters(rv, rc, "user_id"));
	localUser.setScreenName(getParameters(rv, rc, "screen_name"));

	return writeUserFile();
}

/*
 * Generate the Request Token
 */

ustring Twitter::tokenRequest(const ustring consumerKey, const ustring consumerKeySecret)
{

	char *postarg = NULL;
	ustring tempKeyParameters=ustring();
	ustring twitterRequestURL=ustring();
	twitterRequestURL.assign(REQUEST_URL);

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL.assign(oauth_sign_url2(twitterRequestURL.c_str(), NULL, OA_HMAC, NULL, consumerKey.c_str(), consumerKeySecret.c_str(), NULL, NULL) );

	char *tmpPar=oauth_http_get(twitterRequestURL.c_str(), postarg);
	if(tmpPar!=NULL)tempKeyParameters.assign(tmpPar);
	else tempKeyParameters.assign("");

	return tempKeyParameters;

}

/*
 * Get the http parameters
 */

char* Twitter::getParameters(char **argv,int argc,const char *param)
{
	int i;
	for(i = 0;i < argc;i++)
	{
		if(strncmp(argv[i],param,strlen(param)) == 0)
		{
			return argv[i] + strcspn(argv[i],"=") + 1;
		}
	}
	return NULL;
}
}
