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
 * 		IRC: chat.freenode.net at #teamtwc
 */

#ifndef TIMELINE_H_
#define TIMELINE_H_

#define _GNU_SOURCE
#include <stdio.h>

#include <libxml/xmlreader.h>
#include <pthread.h>

#include "twitter.h"
#include "functions.h"

struct user_timeline{
	char *id,
	*name,
	*screen_name,
	*location,
	*description,
	*profile_image_url,
	*profile_image,
	*url,
	*protectedtw,
	*profile_background_color,
	*profile_text_color,
	*profile_link_color,
	*profile_sidebar_fill_color,
	*profile_sidebar_border_color,
	*created_at,
	*utc_offset,
	*time_zone,
	*profile_background_image_url,
	*profile_background_tile,
	*profile_use_background_image,
	*notifications,
	*geo_enabled,
	*verified,
	*following,
	*lang,
	*contributors_enabled,
	*follow_request_sent,
	*show_all_inline_media,
	*default_profile,
	*default_profile_image,
	*is_translator,
	*followers_count,
	*friends_count,
	*favourites_count,
	*statuses_count,
	*listed_count;
};

struct timeLine{
	struct user_timeline user;
	char *created_at,
	*id,
	*text,
	*source,
	*truncated,
	*favorited,
	*in_reply_to_status_id,
	*in_reply_to_user_id,
	*in_reply_to_screen_name,
	*retweet_count,
	*retweeted,
	*geo,
	*coordinates,
	*place,
	*contributors;
};

struct timeLine timeline[30];

void getStatus (xmlDocPtr doc, xmlNodePtr cur, int i);
void readDoc(char *docname);
int readTimeLine(char *docname);

#endif /* TIMELINE_H_ */
