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

	xmlChar *key;

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if(debug==1) printf("%s: %s\n", keyword, key);
		xmlFree(key);
	}
	return (char *)key;
}

void getStatus (xmlDocPtr doc, xmlNodePtr cur) {

	char *keys;
	int i;

	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;
	for(i=0; i<40;i++){
		while (cur != NULL) {

			//char *created_at,
			keys=getTimeLineElement(doc, cur, "created_at");
			strcpy(timeline[i].created_at,keys);

			// *id,
			keys=getTimeLineElement(doc, cur, "id");
			strcpy(timeline[i].id,keys);

			// *text,
			keys=getTimeLineElement(doc, cur, "text");
			strcpy(timeline[i].text,keys);

			// *source,
			keys=getTimeLineElement(doc, cur, "source");
			strcpy(timeline[i].source,keys);
			// *truncated,

			keys=getTimeLineElement(doc, cur, "truncated");
			strcpy(timeline[i].truncated,keys);

			// *favorited,
			keys=getTimeLineElement(doc, cur, "favorited");
			strcpy(timeline[i].favorited,keys);

			// *in_reply_to_status_id,
			keys=getTimeLineElement(doc, cur, "in_reply_to_status_id");
			strcpy(timeline[i].in_reply_to_status_id,keys);

			// *in_reply_to_user_id,
			keys=getTimeLineElement(doc, cur, "in_reply_to_user_id");
			strcpy(timeline[i].in_reply_to_user_id,keys);

			// *in_reply_to_screen_name,
			keys=getTimeLineElement(doc, cur, "in_reply_to_screen_name");
			strcpy(timeline[i].in_reply_to_screen_name,keys);

			// *retweet_count,
			keys=getTimeLineElement(doc, cur, "retweet_count");
			strcpy(timeline[i].retweet_count,keys);

			// *retweeted,
			keys=getTimeLineElement(doc, cur, "retweeted");
			strcpy(timeline[i].retweeted,keys);

			// *geo,
			keys=getTimeLineElement(doc, cur, "geo");
			strcpy(timeline[i].geo,keys);

			// *coordinates,
			keys=getTimeLineElement(doc, cur, "coordinates");
			strcpy(timeline[i].coordinates, keys);

			// *place,
			keys=getTimeLineElement(doc, cur, "place");
			strcpy(timeline[i].place, keys);

			// *contributors;
			keys=getTimeLineElement(doc, cur, "contributors");
			strcpy(timeline[i].contributors, keys);

			//struct user_timeline pub_user;
			if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

				cur2 = cur->xmlChildrenNode;

				while (cur2!=NULL){

					// char *id,
					keys=getTimeLineElement(doc, cur, "id");
					strcpy(timeline[i].user.id, keys);

					// *name,
					keys=getTimeLineElement(doc, cur, "name");
					strcpy(timeline[i].user.name, keys);

					// *screen_name,
					keys=getTimeLineElement(doc, cur, "screen_name");
					strcpy(timeline[i].user.screen_name, keys);

					// *location,
					keys=getTimeLineElement(doc, cur, "location");
					strcpy(timeline[i].user.location, keys);

					//		*description,
					keys=getTimeLineElement(doc, cur, "description");
					strcpy(timeline[i].user.description, keys);

					// *profile_image_url,
					keys=getTimeLineElement(doc, cur, "profile_image_url");
					strcpy(timeline[i].user.profile_image_url, keys);

					// *url,
					keys=getTimeLineElement(doc, cur, "url");
					strcpy(timeline[i].user.url, keys);

					// *protectedtw,
					keys=getTimeLineElement(doc, cur, "protected");
					strcpy(timeline[i].user.protectedtw, keys);

					// *profile_background_color,
					keys=getTimeLineElement(doc, cur, "profile_background_color");
					strcpy(timeline[i].user.profile_background_color, keys);

					// *profile_text_color,
					keys=getTimeLineElement(doc, cur, "profile_text_color");
					strcpy(timeline[i].user.profile_text_color, keys);

					// *profile_link_color,
					keys=getTimeLineElement(doc, cur, "profile_link_color");
					strcpy(timeline[i].user.profile_link_color, keys);

					// *profile_sidebar_fill_color,
					keys=getTimeLineElement(doc, cur, "profile_sidebar_fill_color");
					strcpy(timeline[i].user.profile_sidebar_fill_color, keys);

					// *profile_sidebar_border_color,
					keys=getTimeLineElement(doc, cur, "profile_sidebar_border_color");
					strcpy(timeline[i].user.profile_sidebar_border_color, keys);

					// *created_at,
					keys=getTimeLineElement(doc, cur, "created_at");
					strcpy(timeline[i].user.created_at, keys);

					// *utc_offset,
					keys=getTimeLineElement(doc, cur, "utc_offset");
					strcpy(timeline[i].user.utc_offset, keys);

					// *time_zone,
					keys=getTimeLineElement(doc, cur, "time_zone");
					strcpy(timeline[i].user.time_zone, keys);

					// *profile_background_image_url,
					keys=getTimeLineElement(doc, cur, "profile_background_image_url");
					strcpy(timeline[i].user.profile_background_image_url, keys);

					// *profile_background_tile,
					keys=getTimeLineElement(doc, cur, "profile_background_tile");
					strcpy(timeline[i].user.profile_background_tile, keys);

					// *profile_use_background_image,
					keys=getTimeLineElement(doc, cur, "profile_use_background_image");
					strcpy(timeline[i].user.profile_use_background_image, keys);

					// *notifications,
					keys=getTimeLineElement(doc, cur, "notifications");
					strcpy(timeline[i].user.notifications, keys);

					// *geo_enabled,
					keys=getTimeLineElement(doc, cur, "geo_enabled");
					strcpy(timeline[i].user.geo_enabled, keys);

					// *verified,
					keys=getTimeLineElement(doc, cur, "verified");
					strcpy(timeline[i].user.verified, keys);

					// *following,
					keys=getTimeLineElement(doc, cur, "following");
					strcpy(timeline[i].user.following, keys);

					// *lang,
					keys=getTimeLineElement(doc, cur, "lang");
					strcpy(timeline[i].user.lang, keys);

					// *contributors_enabled,
					keys=getTimeLineElement(doc, cur, "contributors_enabled");
					strcpy(timeline[i].user.contributors_enabled, keys);

					// *follow_request_sent,
					keys=getTimeLineElement(doc, cur, "follow_request_sent");
					strcpy(timeline[i].user.follow_request_sent, keys);

					// *show_all_inline_media,
					keys=getTimeLineElement(doc, cur, "show_all_inline_media");
					strcpy(timeline[i].user.show_all_inline_media, keys);

					// *default_profile,
					keys=getTimeLineElement(doc, cur, "default_profile");
					strcpy(timeline[i].user.default_profile, keys);

					// *default_profile_image,
					keys=getTimeLineElement(doc, cur, "default_profile_image");
					strcpy(timeline[i].user.default_profile_image, keys);

					// *is_translator,
					keys=getTimeLineElement(doc, cur, "is_translator");
					strcpy(timeline[i].user.is_translator, keys);

					// *followers_count,
					keys=getTimeLineElement(doc, cur, "followers_count");
					strcpy(timeline[i].user.followers_count, keys);

					// *friends_count,
					keys=getTimeLineElement(doc, cur, "friends_count");
					strcpy(timeline[i].user.friends_count, keys);

					// *favourites_count,
					keys=getTimeLineElement(doc, cur, "favourites_count");
					strcpy(timeline[i].user.favourites_count, keys);

					// statuses_count, ;
					keys=getTimeLineElement(doc, cur, "statuses_count");
					strcpy(timeline[i].user.statuses_count, keys);

					// listed_count
					keys=getTimeLineElement(doc, cur, "listed_count");
					strcpy(timeline[i].user.listed_count, keys);

					cur2 = cur2->next;
				}
			}

			cur = cur->next;
		}
	}

	return;
}

void readDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

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
			getStatus (doc, cur);
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
