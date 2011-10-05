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

#include "inc/config.h"

void malloc_users(){
	debug_f_start("malloc_users");

	user.id =  (char*) malloc(sizeof(char) * 15);
	user.screenName =  (char*) malloc(sizeof(char) * 140);
	user.token =  (char*) malloc(sizeof(char) * 160);
	user.secretToken =  (char*) malloc(sizeof(char) * 160);
	user.consumerKey =  (char*) malloc(sizeof(char) * 160);
	user.consumerSecretKey =  (char*) malloc(sizeof(char) * 160);

	/*Fix Disconnect Message*/
	strcpy(user.token, " ");
	strcpy(user.consumerKey, " ");
	strcpy(user.consumerSecretKey, " ");
	strcpy(user.id, " ");
	strcpy(user.screenName, " ");
	strcpy(user.secretToken, " ");
}

/* Free Allocated Structs */
void free_size_users(){
	debug_f_start("free_size_users");

	free(user.id);
	free(user.screenName);
	free(user.token);
	free(user.secretToken);
	free(user.consumerKey);
	free(user.consumerSecretKey);
}

int write_user_file(){
	debug_f_start("write_user_file");

	xmlTextWriterPtr writer;
	xmlDocPtr doc;
	xmlNodePtr node;

	/*DEBUG*/
	debug_var_char("user.screenName",user.screenName);
	debug_var_char("user.id",user.id);
	debug_var_char("user.consumerKey",user.consumerKey);
	debug_var_char("user.consumerSecretKey",user.consumerSecretKey);
	debug_var_char("user.token",user.token);
	debug_var_char("user.secretToken",user.secretToken);

	doc = xmlNewDoc((xmlChar*) XML_DEFAULT_VERSION);
	node = xmlNewDocNode(doc, NULL, (xmlChar*) "CONFIG", NULL);

	xmlDocSetRootElement(doc, node);
	writer = xmlNewTextWriterTree(doc, node, 0);

	xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	xmlTextWriterStartElement(writer, (xmlChar*) "USER");

	xmlTextWriterWriteElement(writer, (xmlChar*)"screen_name", (xmlChar*)user.screenName);
	xmlTextWriterWriteElement(writer, (xmlChar*)"id", (xmlChar*)user.id);
	xmlTextWriterWriteElement(writer, (xmlChar*)"consumerKey", (xmlChar*)user.consumerKey);
	xmlTextWriterWriteElement(writer, (xmlChar*)"consumerSecretKey", (xmlChar*)user.consumerSecretKey);
	xmlTextWriterWriteElement(writer, (xmlChar*)"token", (xmlChar*)user.token);
	xmlTextWriterWriteElement(writer, (xmlChar*)"secretToken", (xmlChar*)user.secretToken);
	xmlTextWriterEndElement(writer);
	xmlTextWriterEndElement(writer);

	xmlFreeTextWriter(writer);

	xmlSaveFileEnc(progPath.configFile, doc, MY_ENCODING);

	xmlFreeDoc(doc);

	return 0;
}

int read_user_file(){
	debug_f_start("read_user_file");

	char *keys;

	xmlDocPtr doc;
	xmlNodePtr cur;

	debug_var_char("progPath.configFile", progPath.configFile);

	doc=xmlParseFile(progPath.configFile);

	if (doc == NULL ){

		return 1;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		debug_var_char("cur (ROOT-ELEMENT)", "NULL");

		xmlFreeDoc(doc);
		return 1;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "CONFIG")) {
		debug_var_char("cur->name (CONFIG)", "NULL");

		xmlFreeDoc(doc);
		return 1;
	}

	cur = cur->xmlChildrenNode;

	while (cur != NULL) {


		if ((!xmlStrcmp(cur->name, (const xmlChar *) "USER"))){

			cur = cur->xmlChildrenNode;

			keys=get_element(doc, cur, "screen_name");
			user.screenName=keys;
			cur = cur->next;


			keys=get_element(doc, cur, "id");
			user.id=keys;
			cur = cur->next;


			keys=get_element(doc, cur, "consumerKey");
			user.consumerKey=keys;
			cur = cur->next;


			keys=get_element(doc, cur, "consumerSecretKey");
			user.consumerSecretKey=keys;
			cur = cur->next;


			keys=get_element(doc, cur, "token");
			user.token=keys;
			cur = cur->next;


			keys=get_element(doc, cur, "secretToken");
			user.secretToken=keys;
			cur = cur->next;
		}
	}

	xmlFreeDoc(doc);

	/*DEBUG*/
	debug_var_char("user.screenName",user.screenName);
	debug_var_char("user.id",user.id);
	debug_var_char("user.consumerKey",user.consumerKey);
	debug_var_char("user.consumerSecretKey",user.consumerSecretKey);
	debug_var_char("user.token",user.token);
	debug_var_char("user.secretToken",user.secretToken);


	return 0;
}

void disconnect(){
	debug_f_start("disconnect");

	user.id="";
	user.screenName="";
	user.token="";
	user.secretToken="";
	user.consumerKey="";
	user.consumerSecretKey="";

}

int delete_account(){
	debug_f_start("delete_account");

	char *cmd;

	debug_var_char("cmd",cmd);
	asprintf(&cmd, "%s %s", "rm -f ", progPath.configFile);

	if(system(cmd)==0){
		disconnect();
		return 0;
	}

	return 1;
}
