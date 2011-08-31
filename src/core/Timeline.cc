/*
 *	 	Twitter Client For Linux Desktop
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
	timeline.~vector();

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
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"status"))){
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
	Tweet tweet=Tweet();

	xmlNodePtr cur2;
	cur = cur->xmlChildrenNode;
	cur = cur->next;

	tweet.setCreated_at(getTimeLineElement(doc, cur, "created_at"));
	cur = cur->next;
	cur = cur->next;

	// *id,
	tweet.setId(getTimeLineElement(doc, cur, "id"));
	cur = cur->next;
	cur = cur->next;

	// *text,
	tweet.setText(getTimeLineElement(doc, cur, "text"));
	cur = cur->next;
	cur = cur->next;

	// *source,
	tweet.setSource(getTimeLineElement(doc, cur, "source"));
	cur = cur->next;
	cur = cur->next;

	// *truncated,
	tweet.setTruncated(getTimeLineElement(doc, cur, "truncated"));
	cur = cur->next;
	cur = cur->next;

	// *favorited,
	tweet.setFavorited(getTimeLineElement(doc, cur, "favorited"));
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_status_id,
	tweet.setIn_reply_to_status_id(getTimeLineElement(doc, cur, "in_reply_to_status_id"));
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_user_id,
	tweet.setIn_reply_to_user_id(getTimeLineElement(doc, cur, "in_reply_to_user_id"));
	cur = cur->next;
	cur = cur->next;

	// *in_reply_to_screen_name,
	tweet.setIn_reply_to_screen_name(getTimeLineElement(doc, cur, "in_reply_to_screen_name"));
	cur = cur->next;
	cur = cur->next;

	// *retweet_count,
	tweet.setRetweet_count(getTimeLineElement(doc, cur, "retweet_count"));
	cur = cur->next;
	cur = cur->next;

	// *retweeted,
	tweet.setRetweeted(getTimeLineElement(doc, cur, "retweeted"));
	cur = cur->next;
	cur = cur->next;

	if ((!xmlStrcmp(cur->name, (const xmlChar *)"user"))) {

		User tUser=User();

		cur2 = cur->xmlChildrenNode;
		cur2 = cur2->next;

		// char *id,
		tUser.setId(getTimeLineElement(doc, cur2, "id"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *name,
		tUser.setName(getTimeLineElement(doc, cur2, "name"));

		cur2 = cur2->next;
		cur2 = cur2->next;

		// *screen_name,
		tUser.setScreen_name(getTimeLineElement(doc, cur2, "screen_name"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *location,
		tUser.setLocation(getTimeLineElement(doc, cur2, "location"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		//		*description,
		tUser.setDescription(getTimeLineElement(doc, cur2, "description"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image_url,
		tUser.setProfile_image_url(getTimeLineElement(doc, cur2, "profile_image_url"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_image,
		Config config=Config();
		string profileImage;
		profileImage.assign(config.getAvatarDir());
		profileImage.append(tUser.getScreen_name());
		tUser.setProfile_image(profileImage);

		// *url,
		tUser.setUrl(getTimeLineElement(doc, cur2, "url"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *protectedtw,
		tUser.setProtectedtw(getTimeLineElement(doc, cur2, "protected"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_color,
		tUser.setProfile_background_color(getTimeLineElement(doc, cur2, "profile_background_color"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_text_color,
		tUser.setProfile_text_color(getTimeLineElement(doc, cur2, "profile_text_color"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_link_color,
		tUser.setProfile_link_color(getTimeLineElement(doc, cur2, "profile_link_color"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_fill_color,
		tUser.setProfile_sidebar_fill_color(getTimeLineElement(doc, cur2, "profile_sidebar_fill_color"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_sidebar_border_color,
		tUser.setProfile_sidebar_border_color(getTimeLineElement(doc, cur2, "profile_sidebar_border_color"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *created_at,
		tUser.setCreated_at(getTimeLineElement(doc, cur2, "created_at"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *utc_offset,
		tUser.setUtc_offset(getTimeLineElement(doc, cur2, "utc_offset"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *time_zone,
		tUser.setTime_zone(getTimeLineElement(doc, cur2, "time_zone"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_image_url,
		tUser.setProfile_background_image_url(getTimeLineElement(doc, cur2, "profile_background_image_url"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_background_tile,
		tUser.setProfile_background_tile(getTimeLineElement(doc, cur2, "profile_background_tile"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *profile_use_background_image,
		tUser.setProfile_use_background_image(getTimeLineElement(doc, cur2, "profile_use_background_image"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *notifications,
		tUser.setNotifications(getTimeLineElement(doc, cur2, "notifications"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *geo_enabled,
		tUser.setGeo_enabled(getTimeLineElement(doc, cur2, "geo_enabled"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *verified,
		tUser.setVerified(getTimeLineElement(doc, cur2, "verified"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *following,
		tUser.setFollowing(getTimeLineElement(doc, cur2, "following"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *lang,
		tUser.setLang(getTimeLineElement(doc, cur2, "lang"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *contributors_enabled,
		tUser.setContributors_enabled(getTimeLineElement(doc, cur2, "contributors_enabled"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *follow_request_sent,
		tUser.setFollow_request_sent(getTimeLineElement(doc, cur2, "follow_request_sent"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *show_all_inline_media,
		tUser.setShow_all_inline_media(getTimeLineElement(doc, cur2, "show_all_inline_media"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile,
		tUser.setDefault_profile(getTimeLineElement(doc, cur2, "default_profile"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *default_profile_image,
		tUser.setDefault_profile_image(getTimeLineElement(doc, cur2, "default_profile_image"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *is_translator,
		tUser.setIs_translator(getTimeLineElement(doc, cur2, "is_translator"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *followers_count,
		tUser.setFollowers_count(getTimeLineElement(doc, cur2, "followers_count"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *friends_count,
		tUser.setFriends_count(getTimeLineElement(doc, cur2, "friends_count"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// *favourites_count,
		tUser.setFavourites_count(getTimeLineElement(doc, cur2, "favourites_count"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// statuses_count, ;
		tUser.setStatuses_count(getTimeLineElement(doc, cur2, "statuses_count"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		// listed_count
		tUser.setListed_count(getTimeLineElement(doc, cur2, "listed_count"));
		cur2 = cur2->next;
		cur2 = cur2->next;

		tweet.setUser(tUser);

	}


	// *geo,
	tweet.setGeo(getTimeLineElement(doc, cur, "geo"));
	cur = cur->next;
	cur = cur->next;

	// *coordinates,
	tweet.setCoordinates(getTimeLineElement(doc, cur, "coordinates"));

	cur = cur->next;
	cur = cur->next;

	// *place,
	tweet.setPlace(getTimeLineElement(doc, cur, "place"));
	cur = cur->next;
	cur = cur->next;

	// *contributors;
	tweet.setContributors(getTimeLineElement(doc, cur, "contributors"));
	cur = cur->next;
	cur = cur->next;

	timeline.push_back(tweet);

}

string TimeLine::getTimeLineElement(xmlDocPtr doc, xmlNodePtr cur, string keyword)
{
	xmlChar *key = NULL;
	string empty = "error";

	if ((!xmlStrcmp(cur->name, (const xmlChar *)keyword.c_str()))) {
		key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

		return string().assign((char *)key);
	}

	return empty;

}
}
