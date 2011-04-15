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

void parseElement (xmlDocPtr doc, xmlNodePtr cur, char* keyword) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("%s: %s\n", keyword, key);

			//TO DO
			//bisogna passare i valori al vettore di struct..
			//NOTA: forse vanno cambiati i cicli nelle funzioni...

			xmlFree(key);
		}
		cur = cur->next;
	}
	return;
}

void parseDocument(char *docname, char *root, char *children,char *keyword) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);

	if (doc == NULL ) {
		if(debug==1) fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		if(debug==1) fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) root)) {
		if(debug==1) fprintf(stderr,"document of the wrong type, root node != %s", root);
		xmlFreeDoc(doc);
		return;
	}

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)children))){
			parseElement (doc, cur, keyword);
		}

		cur = cur->next;
	}

	xmlFreeDoc(doc);
	return;
}
