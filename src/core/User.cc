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

#include "include/User.h"
namespace TwitCrusader {
User::User()
{
	id=NULL;
	name=NULL;
	screen_name=NULL;
	location=NULL;
	description=NULL;
	profile_image_url=NULL;
	url=NULL;
	protectedtw=NULL;
	profile_background_color=NULL;
	profile_text_color=NULL;
	profile_link_color=NULL;
	profile_sidebar_fill_color=NULL;
	profile_sidebar_border_color=NULL;
	created_at=NULL;
	utc_offset=NULL;
	time_zone=NULL;
	profile_background_image_url=NULL;
	profile_background_tile=NULL;
	profile_use_background_image=NULL;
	notifications=NULL;
	geo_enabled=NULL;
	verified=NULL;
	following=NULL;
	lang=NULL;
	contributors_enabled=NULL;
	follow_request_sent=NULL;
	show_all_inline_media=NULL;
	default_profile=NULL;
	default_profile_image=NULL;
	is_translator=NULL;
	followers_count=NULL;
	friends_count=NULL;
	favourites_count=NULL;
	statuses_count=NULL;
	listed_count=NULL;
}

User::~User()
{
	// TODO Auto-generated destructor stub
}


}
