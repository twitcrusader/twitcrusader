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

#include "include/timeline.h"


char* getTimeLineElement(xmlDocPtr doc, xmlNodePtr cur, char *keyword){

	xmlChar *key = NULL;
	char *empty = "error";

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		//if(debug==1) printf("\n%s: %s", keyword, key);
		
		return (char *)key;
	}
	
	return empty;
	
}

void getStatus (xmlDocPtr doc, xmlNodePtr cur, int i) {

	char *keys;

	//xmlNodePtr cur2;
		cur = cur->xmlChildrenNode;
		while (cur != NULL) {
			
			//char *created_at,
			keys=getTimeLineElement(doc, cur, "created_at");
			 timeline[i].created_at=keys;

			// *id,
			keys=getTimeLineElement(doc, cur, "id");
			 timeline[i].id=keys;
			  if(debug==1) printf("\n%s: %s -- %d", "id", keys, i);

			// *text,
			keys=getTimeLineElement(doc, cur, "text");
			 timeline[i].text=keys;

			// *source,
			keys=getTimeLineElement(doc, cur, "source");
			 timeline[i].source=keys;
			 
			// *truncated,
			keys=getTimeLineElement(doc, cur, "truncated");
			 timeline[i].truncated=keys;

			// *favorited,
			keys=getTimeLineElement(doc, cur, "favorited");
			 timeline[i].favorited=keys;

			// *in_reply_to_status_id,
			keys=getTimeLineElement(doc, cur, "in_reply_to_status_id");
			 timeline[i].in_reply_to_status_id=keys;

			// *in_reply_to_user_id,
			keys=getTimeLineElement(doc, cur, "in_reply_to_user_id");
			 timeline[i].in_reply_to_user_id=keys;

			// *in_reply_to_screen_name,
			keys=getTimeLineElement(doc, cur, "in_reply_to_screen_name");
			 timeline[i].in_reply_to_screen_name=keys;

			// *retweet_count,
			keys=getTimeLineElement(doc, cur, "retweet_count");
			 timeline[i].retweet_count=keys;

			// *retweeted,
			keys=getTimeLineElement(doc, cur, "retweeted");
			 timeline[i].retweeted=keys;
			

			// *geo,
			keys=getTimeLineElement(doc, cur, "geo");
			 timeline[i].geo=keys;

			// *coordinates,
			keys=getTimeLineElement(doc, cur, "coordinates");
			 timeline[i].coordinates=keys;

			// *place,
			keys=getTimeLineElement(doc, cur, "place");
			 timeline[i].place=keys;

			// *contributors;
			keys=getTimeLineElement(doc, cur, "contributors");
			 timeline[i].contributors=keys;

			cur = cur->next;
		}
}

void readDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;
	int i=0;

	doc = xmlParseFile(docname);

	if (doc == NULL ) {
		if(debug==1) printf("Document not parsed successfully. \n");
		return;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		if(debug==1) printf("empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "statuses")) {
		if(debug==1) printf("root node != statuses");
		xmlFreeDoc(doc);
		return;
	}

	cur = cur->xmlChildrenNode;
	
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"status"))){
			getStatus (doc, cur, i);
			i++;
		}

		cur = cur->next;
	}

	xmlFreeDoc(doc);

	return;
}

int readtimeline(char *docname) {

	readDoc (docname);

	return (1);
}
