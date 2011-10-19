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

#include "inc/timeline.h"


char* get_time_line_element(xmlDocPtr doc, xmlNodePtr cur, char *keyword){

	debug_f_start("get_time_line_element");

	xmlChar *key = NULL;
	char *empty = "error";

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

		debug_var_char(keyword, (char*)key);

		return (char *)key;
	}

	return empty;

}

void get_status (xmlDocPtr doc, xmlNodePtr cur, int i) {

	debug_f_start("get_status");

	char *keys;

	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;
	cur = cur->next;

	keys=get_time_line_element(doc, cur, "created_at");
	timeline[i].created_at=keys;
	cur = cur->next;
	cur = cur->next;

	// *id,
	keys=get_time_line_element(doc, cur, "id");
	timeline[i].id=keys;
	cur = cur->next;
	cur = cur->next;

	// *text,
	keys=get_time_line_element(doc, cur, "text");
	timeline[i].text=keys;
	cur = cur->next;
	cur = cur->next;

	// *source,
	keys=get_time_line_element(doc, cur, "source");
	timeline[i].source=keys;
	cur = cur->next;
	cur = cur->next;

	// *truncated,
	keys=get_time_line_element(doc, cur, "truncated");
	timeline[i].truncated=keys;
	cur = cur->next;
	cur = cur->next;

	// *favorited,
	keys=get_time_line_element(doc, cur, "favorited");
	timeline[i].favorited=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_status_id,
	keys=get_time_line_element(doc, cur, "in_reply_to_status_id");
	timeline[i].in_reply_to_status_id=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_user_id,
	keys=get_time_line_element(doc, cur, "in_reply_to_user_id");
	timeline[i].in_reply_to_user_id=keys;
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_screen_name,
	keys=get_time_line_element(doc, cur, "in_reply_to_screen_name");
	timeline[i].in_reply_to_screen_name=keys;
	cur = cur->next;
	cur = cur->next;

	// *retweet_count,
	keys=get_time_line_element(doc, cur, "retweet_count");
	timeline[i].retweet_count=keys;
	cur = cur->next;
	cur = cur->next;

	// *retweeted,
	keys=get_time_line_element(doc, cur, "retweeted");
	timeline[i].retweeted=keys;
	cur = cur->next;
	cur = cur->next;

	//struct user_timeline pub_user;
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

		cur2 = cur->xmlChildrenNode;
		cur2 = cur2->next;

		// char *id,
		keys=get_time_line_element(doc, cur2, "id");
		timeline[i].user.id=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *name,
		keys=get_time_line_element(doc, cur2, "name");
		timeline[i].user.name=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *screen_name,
		keys=get_time_line_element(doc, cur2, "screen_name");
		timeline[i].user.screen_name=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *location,
		keys=get_time_line_element(doc, cur2, "location");
		timeline[i].user.location=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		//		*description,
		keys=get_time_line_element(doc, cur2, "description");
		timeline[i].user.description=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image_url,
		keys=get_time_line_element(doc, cur2, "profile_image_url");
		timeline[i].user.profile_image_url=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image,
		asprintf(&timeline[i].user.profile_image, "%s%s", prog_path.avatarDir, timeline[i].user.screen_name);

		// *url,
		keys=get_time_line_element(doc, cur2, "url");
		timeline[i].user.url=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *protectedtw,
		keys=get_time_line_element(doc, cur2, "protected");
		timeline[i].user.protectedtw=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_color,
		keys=get_time_line_element(doc, cur2, "profile_background_color");
		timeline[i].user.profile_background_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_text_color,
		keys=get_time_line_element(doc, cur2, "profile_text_color");
		timeline[i].user.profile_text_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_link_color,
		keys=get_time_line_element(doc, cur2, "profile_link_color");
		timeline[i].user.profile_link_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_fill_color,
		keys=get_time_line_element(doc, cur2, "profile_sidebar_fill_color");
		timeline[i].user.profile_sidebar_fill_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_border_color,
		keys=get_time_line_element(doc, cur2, "profile_sidebar_border_color");
		timeline[i].user.profile_sidebar_border_color=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *created_at,
		keys=get_time_line_element(doc, cur2, "created_at");
		timeline[i].user.created_at=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *utc_offset,
		keys=get_time_line_element(doc, cur2, "utc_offset");
		timeline[i].user.utc_offset=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *time_zone,
		keys=get_time_line_element(doc, cur2, "time_zone");
		timeline[i].user.time_zone=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_image_url,
		keys=get_time_line_element(doc, cur2, "profile_background_image_url");
		timeline[i].user.profile_background_image_url=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_tile,
		keys=get_time_line_element(doc, cur2, "profile_background_tile");
		timeline[i].user.profile_background_tile=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_use_background_image,
		keys=get_time_line_element(doc, cur2, "profile_use_background_image");
		timeline[i].user.profile_use_background_image=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *notifications,
		keys=get_time_line_element(doc, cur2, "notifications");
		timeline[i].user.notifications=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *geo_enabled,
		keys=get_time_line_element(doc, cur2, "geo_enabled");
		timeline[i].user.geo_enabled=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *verified,
		keys=get_time_line_element(doc, cur2, "verified");
		timeline[i].user.verified=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *following,
		keys=get_time_line_element(doc, cur2, "following");
		timeline[i].user.following=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *lang,
		keys=get_time_line_element(doc, cur2, "lang");
		timeline[i].user.lang=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *contributors_enabled,
		keys=get_time_line_element(doc, cur2, "contributors_enabled");
		timeline[i].user.contributors_enabled=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *follow_request_sent,
		keys=get_time_line_element(doc, cur2, "follow_request_sent");
		timeline[i].user.follow_request_sent=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *show_all_inline_media,
		keys=get_time_line_element(doc, cur2, "show_all_inline_media");
		timeline[i].user.show_all_inline_media=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile,
		keys=get_time_line_element(doc, cur2, "default_profile");
		timeline[i].user.default_profile=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile_image,
		keys=get_time_line_element(doc, cur2, "default_profile_image");
		timeline[i].user.default_profile_image=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *is_translator,
		keys=get_time_line_element(doc, cur2, "is_translator");
		timeline[i].user.is_translator=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *followers_count,
		keys=get_time_line_element(doc, cur2, "followers_count");
		timeline[i].user.followers_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *friends_count,
		keys=get_time_line_element(doc, cur2, "friends_count");
		timeline[i].user.friends_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *favourites_count,
		keys=get_time_line_element(doc, cur2, "favourites_count");
		timeline[i].user.favourites_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// statuses_count, ;
		keys=get_time_line_element(doc, cur2, "statuses_count");
		timeline[i].user.statuses_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;

		// listed_count
		keys=get_time_line_element(doc, cur2, "listed_count");
		timeline[i].user.listed_count=keys;
		cur2 = cur2->next;
		cur2 = cur2->next;
	}


	// *geo,
	keys=get_time_line_element(doc, cur, "geo");
	timeline[i].geo=keys;
	cur = cur->next;
	cur = cur->next;

	// *coordinates,
	keys=get_time_line_element(doc, cur, "coordinates");
	timeline[i].coordinates=keys;
	cur = cur->next;
	cur = cur->next;

	// *place,
	keys=get_time_line_element(doc, cur, "place");
	timeline[i].place=keys;
	cur = cur->next;
	cur = cur->next;

	// *contributors;
	keys=get_time_line_element(doc, cur, "contributors");
	timeline[i].contributors=keys;
	cur = cur->next;
	cur = cur->next;
}

int read_time_line(char *docname) {

	debug_f_start("read_time_line");

	xmlDocPtr doc;
	xmlNodePtr cur;
	int i=0;

	doc = xmlParseFile(docname);

	debug_var_char("doc", docname);

	if (doc == NULL ) {
		debug_var_char("doc", NULL);
		return 1;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		debug_var_char("cur", "NULL");
		xmlFreeDoc(doc);
		return 1;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "statuses")) {

		debug_var_char("cur->name (statuses)", "NULL");

		xmlFreeDoc(doc);
		return 1;
	}

	cur = cur->xmlChildrenNode;

	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"status"))){
			get_status (doc, cur, i);
			i++;
		}else{
			debug_var_char("cur->name (status)", "NULL");
		}

		cur = cur->next;
	}

	xmlFreeDoc(doc);

	return 0;
}

