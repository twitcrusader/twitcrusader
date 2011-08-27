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

#ifndef USER_H_
#define USER_H_

/*
 *
 */
#include <iostream>

using  namespace std;

class User {

private:

	string id,
	name,
	screen_name,
	location,
	description,
	profile_image_url,
	profile_image,
	url,
	protectedtw,
	profile_background_color,
	profile_text_color,
	profile_link_color,
	profile_sidebar_fill_color,
	profile_sidebar_border_color,
	created_at,
	utc_offset,
	time_zone,
	profile_background_image_url,
	profile_background_tile,
	profile_use_background_image,
	notifications,
	geo_enabled,
	verified,
	following,
	lang,
	contributors_enabled,
	follow_request_sent,
	show_all_inline_media,
	default_profile,
	default_profile_image,
	is_translator,
	followers_count,
	friends_count,
	favourites_count,
	statuses_count,
	listed_count;

public:
	User();
	virtual ~User();

	string getId();
	string getName();
	string getScreen_name();
	string getLocation();
	string getDescription();
	string getProfile_image_url();
	string getProfile_image();
	string getUrl();
	string getProtectedtw();
	string getProfile_background_color();
	string getProfile_text_color();
	string getProfile_link_color();
	string getProfile_sidebar_fill_color();
	string getProfile_sidebar_border_color();
	string getCreated_at();
	string getUtc_offset();
	string getTime_zone();
	string getProfile_background_image_url();
	string getProfile_background_tile();
	string getProfile_use_background_image();
	string getNotifications();
	string getGeo_enabled();
	string getVerified();
	string getFollowing();
	string getLang();
	string getContributors_enabled();
	string getFollow_request_sent();
	string getShow_all_inline_media();
	string getDefault_profile();
	string getDefault_profile_image();
	string getIs_translator();
	string getFollowers_count();
	string getFriends_count();
	string getFavourites_count();
	string getStatuses_count();
	string getListed_count();

	void setId(string id);
	void setName(string name);
	void setScreen_name(string screen_name);
	void setLocation(string location);
	void setDescription(string description);
	void setProfile_image_url(string profile_image_url);
	void setProfile_image(string profile_image);
	void setUrl(string url);
	void setProtectedtw(string protectedtw);
	void setProfile_background_color(string profile_background_color);
	void setProfile_text_color(string profile_text_color);
	void setProfile_link_color(string profile_link_color);
	void setProfile_sidebar_fill_color(string profile_sidebar_fill_color);
	void setProfile_sidebar_border_color(string profile_sidebar_border_color);
	void setCreated_at(string created_at);
	void setUtc_offset(string utc_offset);
	void setTime_zone(string time_zone);
	void setProfile_background_image_url(string profile_background_image_url);
	void setProfile_background_tile(string profile_background_tile);
	void setProfile_use_background_image(string profile_use_background_image);
	void setNotifications(string notifications);
	void setGeo_enabled(string geo_enabled);
	void setVerified(string verified);
	void setFollowing(string following);
	void setLang(string lang);
	void setContributors_enabled(string contributors_enabled);
	void setFollow_request_sent(string follow_request_sent);
	void setShow_all_inline_media(string show_all_inline_media);
	void setDefault_profile(string default_profile);
	void setDefault_profile_image(string default_profile_image);
	void setIs_translator(string is_translator);
	void setFollowers_count(string followers_count);
	void setFriends_count(string friends_count);
	void setFavourites_count(string favourites_count);
	void setStatuses_count(string statuses_count);
	void setListed_count(string listed_count);

};

#endif /* USER_H_ */
