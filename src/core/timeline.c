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

#include "include/timeline.h"
#include "include/config.h"

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

	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;
	cur = cur->next;

	keys=getTimeLineElement(doc, cur, "created_at");
	timeline[i].created_at=keys;
	cur = cur->next;
	cur = cur->next;

	// *id,
	keys=getTimeLineElement(doc, cur, "id");
	timeline[i].id=keys;
	cur = cur->next;
	cur = cur->next;

	// *text,
	keys=getTimeLineElement(doc, cur, "text");
	timeline[i].text=keys;
	cur = cur->next;
	cur = cur->next;

	// *source,
	keys=getTimeLineElement(doc, cur, "source");
	timeline[i].source=keys;
	cur = cur->next;
	cur = cur->next;

	// *truncated,
	keys=getTimeLineElement(doc, cur, "truncated");
	timeline[i].truncated=keys;
	cur = cur->next;
	cur = cur->next;

	// *favorited,
	keys=getTimeLineElement(doc, cur, "favorited");
	timeline[i].favorited=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_status_id,
	keys=getTimeLineElement(doc, cur, "in_reply_to_status_id");
	timeline[i].in_reply_to_status_id=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_user_id,
	keys=getTimeLineElement(doc, cur, "in_reply_to_user_id");
	timeline[i].in_reply_to_user_id=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_screen_name,
	keys=getTimeLineElement(doc, cur, "in_reply_to_screen_name");
	timeline[i].in_reply_to_screen_name=keys;
	cur = cur->next;
	cur = cur->next;

	// *retweet_count,
	keys=getTimeLineElement(doc, cur, "retweet_count");
	timeline[i].retweet_count=keys;
	cur = cur->next;
	cur = cur->next;

	// *retweeted,
	keys=getTimeLineElement(doc, cur, "retweeted");
	timeline[i].retweeted=keys;
	cur = cur->next;
	cur = cur->next;

	//struct user_timeline pub_user;
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

		cur2 = cur->xmlChildrenNode;
		cur2 = cur2->next;

		// char *id,
		keys=getTimeLineElement(doc, cur2, "id");
		timeline[i].user.id=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *name,
		keys=getTimeLineElement(doc, cur2, "name");
		timeline[i].user.name=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *screen_name,
		keys=getTimeLineElement(doc, cur2, "screen_name");
		timeline[i].user.screen_name=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *location,
		keys=getTimeLineElement(doc, cur2, "location");
		timeline[i].user.location=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		//		*description,
		keys=getTimeLineElement(doc, cur2, "description");
		timeline[i].user.description=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image_url,
			keys=getTimeLineElement(doc, cur2, "profile_image_url");
			timeline[i].user.profile_image_url=keys;
			cur2 = cur2->next;
			cur2 = cur2->next;

		// *profile_image,
		asprintf(&timeline[i].user.profile_image, "%s%s", progPath.avatarDir, timeline[i].user.screen_name);
		getCURL(timeline[i].user.profile_image_url, timeline[i].user.profile_image);

		// *url,
		keys=getTimeLineElement(doc, cur2, "url");
		timeline[i].user.url=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *protectedtw,
		keys=getTimeLineElement(doc, cur2, "protected");
		timeline[i].user.protectedtw=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_color,
		keys=getTimeLineElement(doc, cur2, "profile_background_color");
		timeline[i].user.profile_background_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_text_color,
		keys=getTimeLineElement(doc, cur2, "profile_text_color");
		timeline[i].user.profile_text_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_link_color,
		keys=getTimeLineElement(doc, cur2, "profile_link_color");
		timeline[i].user.profile_link_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_fill_color,
		keys=getTimeLineElement(doc, cur2, "profile_sidebar_fill_color");
		timeline[i].user.profile_sidebar_fill_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_border_color,
		keys=getTimeLineElement(doc, cur2, "profile_sidebar_border_color");
		timeline[i].user.profile_sidebar_border_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *created_at,
		keys=getTimeLineElement(doc, cur2, "created_at");
		timeline[i].user.created_at=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *utc_offset,
		keys=getTimeLineElement(doc, cur2, "utc_offset");
		timeline[i].user.utc_offset=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *time_zone,
		keys=getTimeLineElement(doc, cur2, "time_zone");
		timeline[i].user.time_zone=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_image_url,
		keys=getTimeLineElement(doc, cur2, "profile_background_image_url");
		timeline[i].user.profile_background_image_url=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_tile,
		keys=getTimeLineElement(doc, cur2, "profile_background_tile");
		timeline[i].user.profile_background_tile=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_use_background_image,
		keys=getTimeLineElement(doc, cur2, "profile_use_background_image");
		timeline[i].user.profile_use_background_image=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *notifications,
		keys=getTimeLineElement(doc, cur2, "notifications");
		timeline[i].user.notifications=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *geo_enabled,
		keys=getTimeLineElement(doc, cur2, "geo_enabled");
		timeline[i].user.geo_enabled=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *verified,
		keys=getTimeLineElement(doc, cur2, "verified");
		timeline[i].user.verified=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *following,
		keys=getTimeLineElement(doc, cur2, "following");
		timeline[i].user.following=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *lang,
		keys=getTimeLineElement(doc, cur2, "lang");
		timeline[i].user.lang=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *contributors_enabled,
		keys=getTimeLineElement(doc, cur2, "contributors_enabled");
		timeline[i].user.contributors_enabled=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *follow_request_sent,
		keys=getTimeLineElement(doc, cur2, "follow_request_sent");
		timeline[i].user.follow_request_sent=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *show_all_inline_media,
		keys=getTimeLineElement(doc, cur2, "show_all_inline_media");
		timeline[i].user.show_all_inline_media=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile,
		keys=getTimeLineElement(doc, cur2, "default_profile");
		timeline[i].user.default_profile=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile_image,
		keys=getTimeLineElement(doc, cur2, "default_profile_image");
		timeline[i].user.default_profile_image=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *is_translator,
		keys=getTimeLineElement(doc, cur2, "is_translator");
		timeline[i].user.is_translator=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *followers_count,
		keys=getTimeLineElement(doc, cur2, "followers_count");
		timeline[i].user.followers_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *friends_count,
		keys=getTimeLineElement(doc, cur2, "friends_count");
		timeline[i].user.friends_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *favourites_count,
		keys=getTimeLineElement(doc, cur2, "favourites_count");
		timeline[i].user.favourites_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// statuses_count, ;
		keys=getTimeLineElement(doc, cur2, "statuses_count");
		timeline[i].user.statuses_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// listed_count
		keys=getTimeLineElement(doc, cur2, "listed_count");
		timeline[i].user.listed_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;
	}


	// *geo,
	keys=getTimeLineElement(doc, cur, "geo");
	timeline[i].geo=keys;
	cur = cur->next;
	cur = cur->next;

	// *coordinates,
	keys=getTimeLineElement(doc, cur, "coordinates");
	timeline[i].coordinates=keys;
	cur = cur->next;
	cur = cur->next;

	// *place,
	keys=getTimeLineElement(doc, cur, "place");
	timeline[i].place=keys;
	cur = cur->next;
	cur = cur->next;

	// *contributors;
	keys=getTimeLineElement(doc, cur, "contributors");
	timeline[i].contributors=keys;
	cur = cur->next;
	cur = cur->next;
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

	int getAvatarCURL();

	return;
}

int readTimeLine(char *docname) {

	readDoc (docname);

	return (1);
}

