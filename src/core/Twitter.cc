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
	tmp_token=string();
}

Twitter::~Twitter()
{

}

LocalUser Twitter::getLocalUser()
{
	return this->localUser;
}

TimeLine Twitter::getTimeLine()
{
	return this->timeLine;
}

Config Twitter::getConfig()
{
	return this->config;
}

void Twitter::setlocalUser(LocalUser localUser)
{
	this->localUser=localUser;
}

void Twitter::setTimeLine(TimeLine timeLine)
{
	this->timeLine=timeLine;
}

void Twitter::setConfig(Config config)
{
	this->config=config;
}

bool Twitter::writeUserFile()
{
	//config.createConfigDir();

	xmlTextWriterPtr writer;
	xmlDocPtr doc;
	xmlNodePtr node;
	doc = xmlNewDoc((xmlChar*)(XML_DEFAULT_VERSION));
	node = xmlNewDocNode(doc, NULL, (xmlChar*) "CONFIG", NULL);
	xmlDocSetRootElement(doc, node);
	writer = xmlNewTextWriterTree(doc, node, 0);
	xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	xmlTextWriterStartElement(writer, (xmlChar*)("USER"));
	xmlTextWriterWriteElement(writer, (xmlChar*)("screen_name"), (xmlChar*)(localUser.getScreenName().c_str()));
	xmlTextWriterWriteElement(writer, (xmlChar*)("id"), (xmlChar*)(localUser.getId().c_str()));
	xmlTextWriterWriteElement(writer, (xmlChar*)("consumerKey"), (xmlChar*)(localUser.getConsumerKey().c_str()));
	xmlTextWriterWriteElement(writer, (xmlChar*)("consumerSecretKey"), (xmlChar*)(localUser.getConsumerSecretKey().c_str()));
	xmlTextWriterWriteElement(writer, (xmlChar*)("token"), (xmlChar*)(localUser.getToken().c_str()));
	xmlTextWriterWriteElement(writer, (xmlChar*)("secretToken"), (xmlChar*)(localUser.getSecretToken().c_str()));
	xmlTextWriterEndElement(writer);
	xmlTextWriterEndElement(writer);
	xmlFreeTextWriter(writer);
	xmlSaveFileEnc(config.getConfigFile().c_str(), doc, MY_ENCODING);
	xmlFreeDoc(doc);
	return true;
}

bool Twitter::readUserFile()
{
	string keys = string();
	xmlDocPtr doc;
	xmlNodePtr cur;
	if(Functions::readRawTextFile(config.getConfigFile().c_str()).empty()){
		cout<<"\n no file!";
		return false;
	}else{

		doc=xmlParseFile(config.getConfigFile().c_str());

		cur = xmlDocGetRootElement(doc);

		if (cur == NULL) {
			cout<<"\n no RootElement";
			xmlFreeDoc(doc);
			return false;
		}

		if (xmlStrcmp(cur->name, (const xmlChar *) "CONFIG")) {
			cout<<"\n no CONFIG";
			xmlFreeDoc(doc);
			return false;
		}

		cur = cur->xmlChildrenNode;

		while (cur != NULL) {


			if ((!xmlStrcmp(cur->name, (const xmlChar *) "USER"))){

				cur = cur->xmlChildrenNode;

				localUser.setScreenName(Twitter::getElement(doc, cur, "screen_name"));
				cout<<"\n"<<Twitter::getElement(doc, cur, "screen_name");
				cout<<"\n"<<localUser.getScreenName();
				cur = cur->next;


				localUser.setId(Twitter::getElement(doc, cur, "id"));
				cout<<"\n"<<localUser.getId();
				cur = cur->next;


				localUser.setConsumerKey(Twitter::getElement(doc, cur, "consumerKey"));
				cout<<"\n"<<localUser.getConsumerKey();
				cur = cur->next;


				localUser.setConsumerSecretKey(Twitter::getElement(doc, cur, "consumerSecretKey"));
				cout<<"\n"<<localUser.getConsumerSecretKey();
				cur = cur->next;


				localUser.setToken(Twitter::getElement(doc, cur, "token"));
				cout<<"\n"<<localUser.getToken();
				cur = cur->next;


				localUser.setSecretToken(getElement(doc, cur, "secretToken"));
				cout<<"\n"<<localUser.getSecretToken();
				cur = cur->next;
			}
		}

		xmlFreeDoc(doc);
	}
	return true;
}

char* Twitter::getElement(xmlDocPtr doc, xmlNodePtr cur, const char *keyword)
{
	xmlChar *key = NULL;
	string buffer = string();
	buffer.assign("error");

	if((!xmlStrcmp(cur->name, (const xmlChar*)(keyword)))){
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		return (char*)key;
	}
	return (char*)"";
}

bool Twitter::switchTimeLine(int xmlSwitch)
{
	this->config.createTimelineDir();

	string path(config.getTimeLineDir());

	switch(xmlSwitch){

	case 1:
		path.append(path+"public_timeline.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(PUBLIC_TIMELINE_URL);
		break;


	case 2:
		path.append("home_timeline.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(HOME_TIMELINE_URL);
		break;


	case 3:
		path.append("mentions.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(MENTIONS_TIMELINE_URL);
		break;


	case 4:
		path.append("friends_timeline.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(FRIENDS_TIMELINE_URL);
		break;


	case 5:
		path.append("user_timeline.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(USER_TIMELINE_URL);
		break;


	case 6:
		path.append("retweeted_by_me.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(RT_BY_ME_TIMELINE_URL);
		break;


	case 7:
		path.append("retweeted_to_me.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(RT_TO_ME_TIMELINE_URL);
		break;


	case 8:
		path.append("retweeted_of_me.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(RT_OF_ME_TIMELINE_URL);
		break;


	default:
		path.append("public_timeline.xml");
		this->timeLine.timelineFile.assign(path);
		this->timeLine.timelineURL.assign(PUBLIC_TIMELINE_URL);
		break;

	}

	downloadTimeLine();

	return true;
}

bool Twitter::downloadTimeLine()
{
	string postarg=string();
	string tml(oauth_sign_url2(timeLine.timelineURL.c_str(), NULL, OA_HMAC, NULL, localUser.getConsumerKey().c_str(), localUser.getConsumerSecretKey().c_str(), localUser.getToken().c_str(), localUser.getSecretToken().c_str()));
	tml.assign(oauth_http_get(tml.c_str(), postarg.c_str()));

	if(!timeLine.timelineFile.empty()){

			if(!tml.empty()){
				Functions::writeRawTextFile(timeLine.timelineFile, tml);
				cout<<"timeLine.timelineFile.c_str()="+timeLine.timelineFile<<endl;
				timeLine.readTimeLine(timeLine.timelineFile);

				remove(timeLine.timelineFile.c_str());

				return true;
			}

	}
	return false;
}

bool Twitter::SendTweet(string msg)
{

	string twitterStatusURL=string();
	string sendTweet=string();
	string error=string();

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

		if(!error.empty())
			return true;

		return false;
	}

	return false;
}

bool Twitter::tokenTemp()
{

	int rc;
	string tempKeyURL=string();
	string tempKey=string();
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

bool Twitter::tokenTempBrowser()
{
	int rc;
	string cmd=string();
	string tempKeyURL=string();
	string tempKey=string();
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
	cout<<"\n"<<tmp_token;

	/* Generate a Twitter-URL for get user-PIN */

	cmd.assign(AUTHORIZE_URL);
	cmd.append("?oauth_token=");
	cmd.append(tempKey);

	/* Open URL and user get PIN */
	gtk_show_uri(NULL,cmd.c_str(),GDK_CURRENT_TIME,NULL);

	return true;

}

bool Twitter::tokenAccess(const string pin)
{
	int rc;
	string buffer=string();
	string verifyPIN=string();

	string twitterUserKey=string();

	string tempKey=string();
	string tempKeySecret=string();
	string accessURL=string();

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

string Twitter::tokenRequest(const string consumerKey, const string consumerKeySecret)
{

	char *postarg = NULL;
	string tempKeyParameters=string();
	string twitterRequestURL=string();
	twitterRequestURL.assign(REQUEST_URL);

	/* Generate a request url, this url have Temp-Key */
	twitterRequestURL.assign(oauth_sign_url2(twitterRequestURL.c_str(), NULL, OA_HMAC, NULL, consumerKey.c_str(), consumerKeySecret.c_str(), NULL, NULL) );

	tempKeyParameters.assign(oauth_http_get(twitterRequestURL.c_str(), postarg));

	return tempKeyParameters;

}

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
