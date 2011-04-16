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

void getStatus (xmlDocPtr doc, xmlNodePtr cur, struct user_timeline *timeline) {

	xmlChar *key;
	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;

	while (cur != NULL) {

		//char *created_at,
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"created_at"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("created_at: %s\n", key);
			xmlFree(key);
		}
		// *id,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"id"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("id: %s\n", key);
			xmlFree(key);
		}
		// *text,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"text"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("text: %s\n", key);
			xmlFree(key);
		}
		// *source,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"source"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("source: %s\n", key);
			xmlFree(key);
		}
		// *truncated,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"truncated"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("truncated: %s\n", key);
			xmlFree(key);
		}
		// *favorited,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"favorited"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("favorited: %s\n", key);
			xmlFree(key);
		}
		// *in_reply_to_status_id,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"in_reply_to_status_id"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("in_reply_to_status_id: %s\n", key);
			xmlFree(key);
		}
		// *in_reply_to_user_id,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"in_reply_to_user_id"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("in_reply_to_user_id: %s\n", key);
			xmlFree(key);
		}
		// *in_reply_to_screen_name,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"in_reply_to_screen_name"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("in_reply_to_screen_name: %s\n", key);
			xmlFree(key);
		}
		// *retweet_count,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"retweet_count"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("retweet_count: %s\n", key);
			xmlFree(key);
		}
		// *retweeted,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"retweeted"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("retweeted: %s\n", key);
			xmlFree(key);
		}
		// *geo,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"geo"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("geo: %s\n", key);
			xmlFree(key);
		}
		// *coordinates,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"coordinates"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("coordinates: %s\n", key);
			xmlFree(key);
		}
		// *place,
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"place"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("place: %s\n", key);
			xmlFree(key);
		}
		// *contributors;
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"contributors"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(debug==1) printf("contributors: %s\n", key);
			xmlFree(key);
		}

		//struct user_timeline pub_user;
		else if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

			cur2 = cur->xmlChildrenNode;
			while (cur2!=NULL){
				// char *id,
				if ((!xmlStrcmp(cur2->name, (const xmlChar *)"id"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("id: %s\n", key);
					xmlFree(key);
				}
				// *name,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"name"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("name: %s\n", key);
					xmlFree(key);
				}
				// *screen_name,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"screen_name"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("screen_name: %s\n", key);
					xmlFree(key);
				}
				// *location,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"location"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("location: %s\n", key);
					xmlFree(key);
				}

				//		*description,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"location"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("location: %s\n", key);
					xmlFree(key);
				}
				// *profile_image_url,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_image_url"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_image_url: %s\n", key);
					xmlFree(key);
				}
				// *url,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"url"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("url: %s\n", key);
					xmlFree(key);
				}
				// *protectedtw,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"protectedtw"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("protectedtw: %s\n", key);
					xmlFree(key);
				}
				// *profile_background_color,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_background_color"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_background_color: %s\n", key);
					xmlFree(key);
				}
				// *profile_text_color,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_text_color"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_text_color: %s\n", key);
					xmlFree(key);
				}
				// *profile_link_color,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_link_color"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_link_color: %s\n", key);
					xmlFree(key);
				}
				// *profile_sidebar_fill_color,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_sidebar_fill_color"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_sidebar_fill_color: %s\n", key);
					xmlFree(key);
				}
				// *profile_sidebar_border_color,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_sidebar_border_color"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_sidebar_border_color: %s\n", key);
					xmlFree(key);
				}
				// *created_at,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"created_at"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("created_at: %s\n", key);
					xmlFree(key);
				}
				// *utc_offset,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"utc_offset"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("utc_offset: %s\n", key);
					xmlFree(key);
				}
				// *time_zone,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"time_zone"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("time_zone: %s\n", key);
					xmlFree(key);
				}
				// *profile_background_image_url,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_background_image_url"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_background_image_url: %s\n", key);
					xmlFree(key);
				}
				// *profile_background_tile,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_background_tile"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_background_tile: %s\n", key);
					xmlFree(key);
				}
				// *profile_use_background_image,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"profile_use_background_image"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("profile_use_background_image: %s\n", key);
					xmlFree(key);
				}
				// *notifications,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"notifications"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("notifications: %s\n", key);
					xmlFree(key);
				}
				// *geo_enabled,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"geo_enabled"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("geo_enabled: %s\n", key);
					xmlFree(key);
				}
				// *verified,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"verified"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("verified: %s\n", key);
					xmlFree(key);
				}
				// *following,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"following"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("following: %s\n", key);
					xmlFree(key);
				}
				// *lang,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"lang"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("lang: %s\n", key);
					xmlFree(key);
				}
				// *contributors_enabled,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"contributors_enabled"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("contributors_enabled: %s\n", key);
					xmlFree(key);
				}
				// *follow_request_sent,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"follow_request_sent"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("follow_request_sent: %s\n", key);
					xmlFree(key);
				}
				// *show_all_inline_media,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"show_all_inline_media"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("show_all_inline_media: %s\n", key);
					xmlFree(key);
				}
				// *default_profile,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"default_profile"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("default_profile: %s\n", key);
					xmlFree(key);
				}
				// *default_profile_image,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"default_profile_image"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("default_profile_image: %s\n", key);
					xmlFree(key);
				}
				// *is_translator,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"is_translator"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("is_translator: %s\n", key);
					xmlFree(key);
				}
				// *followers_count,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"followers_count"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("followers_count: %s\n", key);
					xmlFree(key);
				}
				// *friends_count,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"friends_count"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("friends_count: %s\n", key);
					xmlFree(key);
				}
				// *favourites_count,
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"favourites_count"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("favourites_count: %s\n", key);
					xmlFree(key);
				}
				// statuses_count, listed_coun;
				else if ((!xmlStrcmp(cur2->name, (const xmlChar *)"statuses_count, listed_coun"))) {
					key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(debug==1) printf("statuses_count, listed_coun: %s\n", key);
					xmlFree(key);
				}

				cur2 = cur2->next;
			}
		}

		cur = cur->next;
	}

	return;
}

void readDoc(char *docname, struct user_timeline *timeline) {

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
			getStatus (doc, cur, timeline);
		}

		cur = cur->next;
	}

	xmlFreeDoc(doc);

	return;
}

int readtimeline(char *docname, struct user_timeline *timeline) {

	readDoc (docname, timeline);

	return (1);
}
