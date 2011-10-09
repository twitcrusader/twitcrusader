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

#include "inc/preference.h"

int read_preference_file(){
	debug_f_start("read_preference");

	xmlDocPtr doc;


	debug_var_char("progPath.preferenceFile", progPath.preferenceFile);

	doc=xmlParseFile(progPath.preferenceFile);

	if (doc != NULL ){
		if(get_preference(doc)==1){

			xmlFreeDoc(doc);
			return 1;
		}


	}else{

			xmlFreeDoc(doc);

			write_default_preference_file();
			return 1;

	}

	debug_var_char("prog_preference.aouth_api_url", prog_preference.aouth_api_url);
	debug_var_char("prog_preference.https_api_url", prog_preference.https_api_url);

	init_URLS();

	return 0;
}

int get_preference(xmlDocPtr doc){

	debug_f_start("get_preference");

	char* keys;

	xmlNodePtr node;

	node= xmlDocGetRootElement(doc);

	if (node == NULL) {

		debug_var_char("cur (ROOT-ELEMENT)", "NULL");
		return 1;
	}

	if (xmlStrcmp(node->name, (const xmlChar *) "preferences")) {

		debug_var_char("cur->name (preference)", "NULL");
		return 1;
	}

	node = node->xmlChildrenNode;

	while (node != NULL) {


		if ((!xmlStrcmp(node->name, (const xmlChar *) "preference"))){


			node = node->xmlChildrenNode;

			keys=get_element(doc, node, "aouth_api_url");
			debug_var_char("keys", keys);
			prog_preference.aouth_api_url=keys;
			node = node->next;


			keys=get_element(doc, node, "https_api_url");
			debug_var_char("keys", keys);
			prog_preference.https_api_url=keys;
			node = node->next;


		}
	}

	return 0;
}

void write_preference_file(){
	debug_f_start("write_preference_file");

	xmlTextWriterPtr writer;
	xmlDocPtr doc;
	xmlNodePtr node;

	doc = xmlNewDoc((xmlChar*) XML_DEFAULT_VERSION);
	node = xmlNewDocNode(doc, NULL, (xmlChar*) "preferences", NULL);

	xmlDocSetRootElement(doc, node);
	writer = xmlNewTextWriterTree(doc, node, 0);

	xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	xmlTextWriterStartElement(writer, (xmlChar*) "preference");

	debug_var_char("prog_preference.aouth_api_url", prog_preference.aouth_api_url);
	xmlTextWriterWriteElement(writer, (xmlChar*)"aouth_api_url", (xmlChar*)prog_preference.aouth_api_url);

	debug_var_char("prog_preference.https_api_url", prog_preference.https_api_url);
	xmlTextWriterWriteElement(writer, (xmlChar*)"https_api_url", (xmlChar*)prog_preference.https_api_url);

	xmlTextWriterEndElement(writer);
	xmlTextWriterEndElement(writer);

	xmlFreeTextWriter(writer);

	debug_var_char("progPath.preferenceFile", progPath.preferenceFile);
	xmlSaveFileEnc(progPath.preferenceFile, doc, MY_ENCODING);

	xmlFreeDoc(doc);
}


void write_default_preference_file(){
	debug_f_start("write_default_preference_file");

	prog_preference.aouth_api_url=OAUTH_API_URL_DEFAULT;
	debug_var_char("prog_preference.aouth_api_url", prog_preference.aouth_api_url);

	prog_preference.https_api_url=HTTPS_API_URL_DEFAULT;
	debug_var_char("prog_preference.https_api_url", prog_preference.https_api_url);

	write_preference_file();

}


void check_URLS(){
	debug_f_start("check_URLS");

	if(prog_preference.aouth_api_url==NULL || strcmp(prog_preference.aouth_api_url,"error")){
		prog_preference.aouth_api_url=OAUTH_API_URL_DEFAULT;
	}

	if(prog_preference.https_api_url==NULL ||strcmp(prog_preference.https_api_url,"error")){
		prog_preference.https_api_url=HTTPS_API_URL_DEFAULT;
	}

}

void init_URLS(){

	debug_f_start("init_URLS");

	check_URLS();

	asprintf(&tw_URLS.authorize_url,"%s%s",prog_preference.aouth_api_url,"authorize");
	debug_var_char("tw_URLS.authorize_url", tw_URLS.authorize_url);

	asprintf(&tw_URLS.request_url,"%s%s",prog_preference.aouth_api_url,"request_token");
	debug_var_char("tw_URLS.request_url", tw_URLS.request_url);

	asprintf(&tw_URLS.tokenaccess_url,"%s%s",prog_preference.aouth_api_url, "access_token");
	debug_var_char("tw_URLS.tokenaccess_url", tw_URLS.tokenaccess_url);


	asprintf(&tw_URLS.status_url,"%s%s",prog_preference.https_api_url,"statuses/update.xml?status=");
	debug_var_char("tw_URLS.status_url", tw_URLS.status_url);

	asprintf(&tw_URLS.home_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/home_timeline.xml");
	debug_var_char("tw_URLS.home_timeline_url", tw_URLS.home_timeline_url);

	asprintf(&tw_URLS.public_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/public_timeline.xml");
	debug_var_char("tw_URLS.public_timeline_url", tw_URLS.public_timeline_url);

	asprintf(&tw_URLS.mentions_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/mentions.xml");
	debug_var_char("tw_URLS.mentions_timeline_url", tw_URLS.mentions_timeline_url);

	asprintf(&tw_URLS.friends_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/friends_timeline.xml");
	debug_var_char("tw_URLS.friends_timeline_url", tw_URLS.friends_timeline_url);

	asprintf(&tw_URLS.user_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/user_timeline.xml");
	debug_var_char("tw_URLS.user_timeline_url", tw_URLS.user_timeline_url);

	asprintf(&tw_URLS.rt_by_me_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/retweeted_by_me.xml");
	debug_var_char("tw_URLS.rt_by_me_timeline_url", tw_URLS.rt_by_me_timeline_url);

	asprintf(&tw_URLS.rt_to_me_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/retweeted_to_me.xml");
	debug_var_char("tw_URLS.rt_to_me_timeline_url", tw_URLS.rt_to_me_timeline_url);

	asprintf(&tw_URLS.rt_of_me_timeline_url,"%s%s",prog_preference.https_api_url,"statuses/retweeted_of_me.xml");
	debug_var_char("tw_URLS.rt_of_me_timeline_url", tw_URLS.rt_of_me_timeline_url);

}

void free_size_preference(){

	debug_f_start("free_size_preference");

	free(tw_URLS.authorize_url);
	free(tw_URLS.request_url);
	free(tw_URLS.tokenaccess_url);

	free(tw_URLS.status_url);
	free(tw_URLS.home_timeline_url);
	free(tw_URLS.public_timeline_url);
	free(tw_URLS.mentions_timeline_url);
	free(tw_URLS.friends_timeline_url);
	free(tw_URLS.user_timeline_url);
	free(tw_URLS.rt_by_me_timeline_url);
	free(tw_URLS.rt_to_me_timeline_url);
	free(tw_URLS.rt_of_me_timeline_url);
}
