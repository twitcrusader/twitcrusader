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

#include "include/Tweet.h"
namespace TwitCrusader {
Tweet::Tweet()
{
	created_at=ustring();
	id=ustring();
	text=ustring();
	source=ustring();
	truncated=ustring();
	favorited=ustring();
	in_reply_to_status_id=ustring();
	in_reply_to_user_id=ustring();
	in_reply_to_screen_name=ustring();
	retweet_count=ustring();
	retweeted=ustring();
	geo=ustring();
	coordinates=ustring();
	place=ustring();
	contributors=ustring();

	user=User();
}

Tweet::~Tweet()
{
	user.~User();
}

void Tweet::setUser(const ContentNode *node)
{

	if(node->get_name().compare("id")==0){
		this->user.id.assign(node->get_content());
	}
	else if(node->get_name().compare("name")==0){
		this->user.name.assign(node->get_content());
	}
	else if(node->get_name().compare("screen_name")==0){
		this->user.screen_name.assign(node->get_content());
	}
	else if(node->get_name().compare("location")==0){
		this->user.location.assign(node->get_content());
	}
	else if(node->get_name().compare("description")==0){
		this->user.description.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_image_url")==0){
		this->user.profile_image_url.assign(node->get_content());
	}
	else if(node->get_name().compare("url")==0){
		this->user.url.assign(node->get_content());
	}
	else if(node->get_name().compare("protectedtw")==0){
		this->user.protectedtw.assign(node->get_content());
	}


	else if(node->get_name().compare("protectedtw")==0){
		this->user.protectedtw.assign(node->get_content());
	}
	else if(node->get_name().compare("protectedtw")==0){
		this->user.protectedtw.assign(node->get_content());
	}
	else if(node->get_name().compare("protectedtw")==0){
		this->user.protectedtw.assign(node->get_content());
	}

	else if(node->get_name().compare("profile_background_color")==0){
		this->user.profile_background_color.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_text_color")==0){
		this->user.profile_text_color.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_link_color")==0){
		this->user.profile_link_color.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_sidebar_fill_color")==0){
		this->user.profile_sidebar_fill_color.assign(node->get_content());
	}
	else if(node->get_name().compare("protectedtw")==0){
		this->user.protectedtw.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_sidebar_border_color")==0){
		this->user.profile_sidebar_border_color.assign(node->get_content());
	}
	else if(node->get_name().compare("created_at")==0){
		this->user.created_at.assign(node->get_content());
	}
	else if(node->get_name().compare("utc_offset")==0){
		this->user.utc_offset.assign(node->get_content());
	}
	else if(node->get_name().compare("time_zone")==0){
		this->user.time_zone.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_background_image_url")==0){
		this->user.profile_background_image_url.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_background_tile")==0){
		this->user.profile_background_tile.assign(node->get_content());
	}
	else if(node->get_name().compare("profile_use_background_image")==0){
		this->user.profile_use_background_image.assign(node->get_content());
	}
	else if(node->get_name().compare("notifications")==0){
		this->user.notifications.assign(node->get_content());
	}
	else if(node->get_name().compare("geo_enabled")==0){
		this->user.geo_enabled.assign(node->get_content());
	}
	else if(node->get_name().compare("verified")==0){
		this->user.verified.assign(node->get_content());
	}
	else if(node->get_name().compare("following")==0){
		this->user.following.assign(node->get_content());
	}
	else if(node->get_name().compare("lang")==0){
		this->user.lang.assign(node->get_content());
	}
	else if(node->get_name().compare("contributors_enabled")==0){
		this->user.contributors_enabled.assign(node->get_content());
	}
	else if(node->get_name().compare("follow_request_sent")==0){
		this->user.follow_request_sent.assign(node->get_content());
	}
	else if(node->get_name().compare("show_all_inline_media")==0){
		this->user.show_all_inline_media.assign(node->get_content());
	}
	else if(node->get_name().compare("default_profile")==0){
		this->user.default_profile.assign(node->get_content());
	}
	else if(node->get_name().compare("default_profile_image")==0){
		this->user.default_profile_image.assign(node->get_content());
	}
	else if(node->get_name().compare("is_translator")==0){
		this->user.default_profile_image.assign(node->get_content());
	}
	else if(node->get_name().compare("default_profile_image")==0){
		this->user.default_profile_image.assign(node->get_content());
	}
	else if(node->get_name().compare("followers_count")==0){
		this->user.followers_count.assign(node->get_content());
	}
	else if(node->get_name().compare("friends_count")==0){
		this->user.friends_count.assign(node->get_content());
	}
	else if(node->get_name().compare("favourites_count")==0){
		this->user.favourites_count.assign(node->get_content());
	}
	else if(node->get_name().compare("statuses_count")==0){
		this->user.statuses_count.assign(node->get_content());
	}
	else if(node->get_name().compare("listed_count")==0){
		this->user.listed_count.assign(node->get_content());
	}

}



}
