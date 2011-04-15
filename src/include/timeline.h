/*
 * timeline.h
 *
 *  Created on: Apr 15, 2011
 *      Author: darkstar
 */

#ifndef TIMELINE_H_
#define TIMELINE_H_

typedef struct timeline_user{
	char *id,
	*name,
	*screen_name,
	*location,
	*description,
	*profile_image_url,
	*url,
	*protected,
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
	statuses_count, listed_coun;
};

typedef struct public_timeline{
	timeline_user pub_user;
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


#endif /* TIMELINE_H_ */
