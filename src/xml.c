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

int parse_file(char *docname, char *root){

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);

	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return 1;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return 1;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) root)) {
		fprintf(stderr,"document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return 1;
	}

	return 0;
}
