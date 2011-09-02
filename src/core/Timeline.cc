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

#include "include/TimeLine.h"
namespace TwitCrusader {
TimeLine::TimeLine()
{
	timelineURL=string();
	timelineFile=string();
	timeline=vector<Tweet>();


}

TimeLine::~TimeLine()
{

}

string TimeLine::getTimelineURL()
{
	return this->timelineURL;
}

string TimeLine::getTimelineFile()
{
	return this->timelineFile;
}

vector<Tweet> TimeLine::getTimeline()
{
	return this->timeline;
}
void TimeLine::setTimelineURL(string timelineURL)
{
	this->timelineURL=timelineURL;
}

void TimeLine::setTimelineFile(string timelineFile)
{
	this->timelineFile=timelineFile;
}

void TimeLine::setTimeline(vector<Tweet> timeline)
{
	this->timeline=timeline;
}

bool TimeLine::readTimeLine(string docname)
{

	xmlDocPtr doc;
	xmlNodePtr cur;
	int i=0;

	doc = xmlParseFile(docname.c_str());

	if (doc == NULL ) {
		return 1;
	}

	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		xmlFreeDoc(doc);
		return 1;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "statuses")) {
		xmlFreeDoc(doc);
		return 1;
	}

	cur = cur->xmlChildrenNode;

	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "status"))){
			getStatus (doc, cur, i);
			i++;
		}

		cur = cur->next;
	}

	xmlFreeDoc(doc);

	return true;

}

void TimeLine::getStatus(xmlDocPtr doc, xmlNodePtr cur, int i)
{
	Tweet *tweet=new Tweet();

	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;
	cur = cur->next;
	tweet->created_at=getTimeLineElement(doc, cur, "created_at");
	cur = cur->next;
	cur = cur->next;

	// *id,
	tweet->id=getTimeLineElement(doc, cur, "id");
	cur = cur->next;
	cur = cur->next;

	// *text,
	tweet->text=getTimeLineElement(doc, cur, "text");
	cur = cur->next;
	cur = cur->next;

	// *source,
	tweet->source=getTimeLineElement(doc, cur, "source");
	cur = cur->next;
	cur = cur->next;

	// *truncated,
	tweet->truncated=getTimeLineElement(doc, cur, "truncated");
	cur = cur->next;
	cur = cur->next;

	// *favorited,
	tweet->favorited=getTimeLineElement(doc, cur, "favorited");
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_status_id,
	tweet->in_reply_to_status_id=getTimeLineElement(doc, cur, "in_reply_to_status_id");
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_user_id,
	tweet->in_reply_to_user_id=getTimeLineElement(doc, cur, "in_reply_to_user_id");
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_screen_name,
	tweet->in_reply_to_screen_name=getTimeLineElement(doc, cur, "in_reply_to_screen_name");
	cur = cur->next;
	cur = cur->next;

	// *retweet_count,
	tweet->retweet_count=getTimeLineElement(doc, cur, "retweet_count");
	cur = cur->next;
	cur = cur->next;

	// *retweeted,
	tweet->retweeted=getTimeLineElement(doc, cur, "retweeted");
	cur = cur->next;
	cur = cur->next;

	if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

		cur2 = cur->xmlChildrenNode;
		cur2 = cur2->next;

		// char *id,
		tweet->user.id=getTimeLineElement(doc, cur2, "id");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *name,
		tweet->user.name=getTimeLineElement(doc, cur2, "name");

		cur2 = cur2->next;
		cur2 = cur2->next;

		// *screen_name,
		tweet->user.screen_name=getTimeLineElement(doc, cur2, "screen_name");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *location,
		tweet->user.location=getTimeLineElement(doc, cur2, "location");
		cur2 = cur2->next;
		cur2 = cur2->next;

		//		*description,
		tweet->user.description=getTimeLineElement(doc, cur2, "description");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image_url,
		tweet->user.profile_image_url=getTimeLineElement(doc, cur2, "profile_image_url");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *url,
		tweet->user.url=getTimeLineElement(doc, cur2, "url");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *protectedtw,
		tweet->user.protectedtw=getTimeLineElement(doc, cur2, "protected");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_color,
		tweet->user.profile_background_color=getTimeLineElement(doc, cur2, "profile_background_color");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_text_color,
		tweet->user.profile_text_color=getTimeLineElement(doc, cur2, "profile_text_color");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_link_color,
		tweet->user.profile_link_color=getTimeLineElement(doc, cur2, "profile_link_color");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_fill_color,
		tweet->user.profile_sidebar_fill_color=getTimeLineElement(doc, cur2, "profile_sidebar_fill_color");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_border_color,
		tweet->user.profile_sidebar_border_color=getTimeLineElement(doc, cur2, "profile_sidebar_border_color");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *created_at,
		tweet->user.created_at=getTimeLineElement(doc, cur2, "created_at");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *utc_offset,
		tweet->user.utc_offset=getTimeLineElement(doc, cur2, "utc_offset");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *time_zone,
		tweet->user.time_zone=getTimeLineElement(doc, cur2, "time_zone");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_image_url,
		tweet->user.profile_background_image_url=getTimeLineElement(doc, cur2, "profile_background_image_url");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_tile,
		tweet->user.profile_background_tile=getTimeLineElement(doc, cur2, "profile_background_tile");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_use_background_image,
		tweet->user.profile_use_background_image=getTimeLineElement(doc, cur2, "profile_use_background_image");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *notifications,
		tweet->user.notifications=getTimeLineElement(doc, cur2, "notifications");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *geo_enabled,
		tweet->user.geo_enabled=getTimeLineElement(doc, cur2, "geo_enabled");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *verified,
		tweet->user.verified=getTimeLineElement(doc, cur2, "verified");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *following,
		tweet->user.following=getTimeLineElement(doc, cur2, "following");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *lang,
		tweet->user.lang=getTimeLineElement(doc, cur2, "lang");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *contributors_enabled,
		tweet->user.contributors_enabled=getTimeLineElement(doc, cur2, "contributors_enabled");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *follow_request_sent,
		tweet->user.follow_request_sent=getTimeLineElement(doc, cur2, "follow_request_sent");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *show_all_inline_media,
		tweet->user.show_all_inline_media=getTimeLineElement(doc, cur2, "show_all_inline_media");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile,
		tweet->user.default_profile=getTimeLineElement(doc, cur2, "default_profile");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile_image,
		tweet->user.default_profile_image=getTimeLineElement(doc, cur2, "default_profile_image");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *is_translator,
		tweet->user.is_translator=getTimeLineElement(doc, cur2, "is_translator");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *followers_count,
		tweet->user.followers_count=getTimeLineElement(doc, cur2, "followers_count");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *friends_count,
		tweet->user.friends_count=getTimeLineElement(doc, cur2, "friends_count");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *favourites_count,
		tweet->user.favourites_count=getTimeLineElement(doc, cur2, "favourites_count");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// statuses_count, ;
		tweet->user.statuses_count=getTimeLineElement(doc, cur2, "statuses_count");
		cur2 = cur2->next;
		cur2 = cur2->next;

		// listed_count
		tweet->user.listed_count=getTimeLineElement(doc, cur2, "listed_count");
		cur2 = cur2->next;
		cur2 = cur2->next;
	}


	// *geo,
	tweet->geo=getTimeLineElement(doc, cur, "geo");
	cur = cur->next;
	cur = cur->next;

	// *coordinates,
	tweet->coordinates=getTimeLineElement(doc, cur, "coordinates");

	cur = cur->next;
	cur = cur->next;

	// *place,
	tweet->place=getTimeLineElement(doc, cur, "place");
	cur = cur->next;
	cur = cur->next;

	// *contributors;
	tweet->contributors=getTimeLineElement(doc, cur, "contributors");
	cur = cur->next;
	cur = cur->next;

	timeline.push_back(*tweet);
}

char* TimeLine::getTimeLineElement(xmlDocPtr doc, xmlNodePtr cur, string keyword)
{
	xmlChar *key = NULL;
	char *empty="";

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword.c_str()))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

		if(key!=NULL){
			return (char *)key;
		}
	}

	return empty;

}
}
