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

#include "include/User.h"

User::User()
{
	id=string();
	name=string();
	screen_name=string();
	location=string();
	description=string();
	profile_image_url=string();
	profile_image=string();
	url=string();
	protectedtw=string();
	profile_background_color=string();
	profile_text_color=string();
	profile_link_color=string();
	profile_sidebar_fill_color=string();
	profile_sidebar_border_color=string();
	created_at=string();
	utc_offset=string();
	time_zone=string();
	profile_background_image_url=string();
	profile_background_tile=string();
	profile_use_background_image=string();
	notifications=string();
	geo_enabled=string();
	verified=string();
	following=string();
	lang=string();
	contributors_enabled=string();
	follow_request_sent=string();
	show_all_inline_media=string();
	default_profile=string();
	default_profile_image=string();
	is_translator=string();
	followers_count=string();
	friends_count=string();
	favourites_count=string();
	statuses_count=string();
	listed_count=string();
}

User::~User()
{
	// TODO Auto-generated destructor stub
}

string User::getName()
{
	return this->name;
}

string User::getScreen_name()
{
	return this->screen_name;
}

string User::getNotifications()
{
	return this->notifications;
}


string User::getFollowing()
{
	return this->following;
}

string User::getProfile_use_background_image()
{
	return this->profile_use_background_image;
}

string User::getProfile_background_color()
{
	return this->profile_background_color;
}

string User::getProfile_sidebar_fill_color()
{
	return this->profile_sidebar_fill_color;
}

string User::getVerified()
{
	return this->verified;
}

string User::getProfile_text_color()
{
	return this->profile_text_color;
}

string User::getDescription()
{
	return this->description;
}

string User::getUrl()
{
	return this->url;
}

string User::getProfile_image()
{
	return this->profile_image;
}

string User::getProfile_sidebar_border_color()
{
	return this->profile_sidebar_border_color;
}

string User::getCreated_at()
{
	return this->created_at;
}

string User::getProfile_link_color()
{
	return this->profile_link_color;
}

string User::getProtectedtw()
{
	return this->protectedtw;
}

string User::getUtc_offset()
{
	return this->utc_offset;
}

string User::getProfile_image_url()
{
	return this->profile_background_image_url;
}

string User::getLang()
{
	return this->lang;
}

string User::getTime_zone()
{
	return this->time_zone;
}

string User::getProfile_background_tile()
{
	return this->profile_background_tile;
}

string User::getLocation()
{
	return this->location;
}

string User::getGeo_enabled()
{
	return this->geo_enabled;
}

string User::getProfile_background_image_url()
{
	return this->profile_background_image_url;
}

string User::getId()
{
	return this->id;
}

string User::getStatuses_count()
{
	return this->statuses_count;
}

string User::getFollow_request_sent()
{
	return this->follow_request_sent;
}

string User::getFollowers_count()
{
	return this->followers_count;
}

string User::getFriends_count()
{
	return this->friends_count;
}

string User::getShow_all_inline_media()
{
	return this->show_all_inline_media;
}

string User::getListed_count()
{
	return this->listed_count;
}

string User::getContributors_enabled()
{
	return this->contributors_enabled;
}

string User::getDefault_profile()
{
	return this->default_profile;
}

string User::getFavourites_count()
{
	return this->favourites_count;
}

string User::getDefault_profile_image()
{
	return this->default_profile_image;
}

string User::getIs_translator()
{
	return this->is_translator;
}

void User::setProfile_background_color(string profile_background_color)
{
	this->profile_background_color.assign(profile_background_color);
}

void User::setName(string name)
{
	this->name.assign(name);
}

void User::setUrl(string url)
{
	this->url.assign(url);
}

void User::setProtectedtw(string protectedtw)
{
	this->protectedtw.assign(protectedtw);
}

void User::setLocation(string location)
{
	this->location.assign(location);
}

void User::setProfile_image(string profile_image)
{
	this->profile_image.assign(profile_image);
}

void User::setId(string id)
{
	this->id.assign(id);
}

void User::setScreen_name(string screen_name)
{
	this->screen_name.assign(screen_name);
}

void User::setProfile_image_url(string profile_image_url)
{
	this->profile_image_url.assign(profile_image_url);
}

void User::setDescription(string description)
{
	this->description.assign(description);
}

void User::setProfile_text_color(string profile_text_color)
{
	this->profile_text_color.assign(profile_text_color);
}

void User::setProfile_link_color(string profile_link_color)
{
	this->profile_link_color.assign(profile_link_color);
}

void User::setTime_zone(string time_zone)
{
	this->time_zone.assign(time_zone);
}

void User::setProfile_sidebar_border_color(string profile_sidebar_border_color)
{
	this->profile_sidebar_border_color.assign(profile_sidebar_border_color);
}

void User::setCreated_at(string created_at)
{
	this->created_at.assign(created_at);
}

void User::setUtc_offset(string utc_offset)
{
	this->utc_offset.assign(utc_offset);
}

void User::setProfile_sidebar_fill_color(string profile_sidebar_fill_color)
{
	this->profile_sidebar_fill_color.assign(profile_sidebar_fill_color);
}

void User::setNotifications(string notifications)
{
	this->notifications.assign(notifications);
}

void User::setProfile_background_tile(string profile_background_tile)
{
	this->profile_background_tile.assign(profile_background_tile);
}

void User::setVerified(string verified)
{
	this->verified.assign(verified);
}

void User::setFollow_request_sent(string follow_request_sent)
{
	this->follow_request_sent.assign(follow_request_sent);
}

void User::setFavourites_count(string favourites_count)
{
	this->favourites_count.assign(favourites_count);
}

void User::setShow_all_inline_media(string show_all_inline_media)
{
	this->show_all_inline_media.assign(show_all_inline_media);
}

void User::setFollowing(string following)
{
	this->following.assign(following);
}

void User::setProfile_background_image_url(string profile_background_image_url)
{
	this->profile_background_image_url.assign(profile_background_image_url);
}

void User::setDefault_profile(string default_profile)
{
	this->default_profile.assign(default_profile);
}

void User::setLang(string lang)
{
	this->lang.assign(lang);
}

void User::setIs_translator(string is_translator)
{
	this->is_translator.assign(is_translator);
}

void User::setFriends_count(string friends_count)
{
	this->friends_count.assign(friends_count);
}

void User::setStatuses_count(string statuses_count)
{
	this->statuses_count.assign(statuses_count);
}

void User::setListed_count(string listed_count)
{
	this->listed_count.assign(listed_count);
}

void User::setGeo_enabled(string geo_enabled)
{
	this->geo_enabled.assign(geo_enabled);
}

void User::setProfile_use_background_image(string profile_use_background_image)
{
	this->profile_use_background_image.assign(profile_use_background_image);
}

void User::setFollowers_count(string followers_count)
{
	this->followers_count.assign(followers_count);
}

void User::setContributors_enabled(string contributors_enabled)
{
	this->contributors_enabled.assign(contributors_enabled);
}

void User::setDefault_profile_image(string default_profile_image)
{
	this->default_profile_image.assign(default_profile_image);
}
