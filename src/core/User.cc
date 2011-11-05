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
 *		Source: https://github.com/KernelMonkey/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/User.h"
namespace TwitCrusader {
User::User()
{
	id=ustring();
	name=ustring();
	screen_name=ustring();
	location=ustring();
	description=ustring();
	profile_image_url=ustring();
	url=ustring();
	protectedtw=ustring();
	profile_background_color=ustring();
	profile_text_color=ustring();
	profile_link_color=ustring();
	profile_sidebar_fill_color=ustring();
	profile_sidebar_border_color=ustring();
	created_at=ustring();
	utc_offset=ustring();
	time_zone=ustring();
	profile_background_image_url=ustring();
	profile_background_tile=ustring();
	profile_use_background_image=ustring();
	notifications=ustring();
	geo_enabled=ustring();
	verified=ustring();
	following=ustring();
	lang=ustring();
	contributors_enabled=ustring();
	follow_request_sent=ustring();
	show_all_inline_media=ustring();
	default_profile=ustring();
	default_profile_image=ustring();
	is_translator=ustring();
	followers_count=ustring();
	friends_count=ustring();
	favourites_count=ustring();
	statuses_count=ustring();
	listed_count=ustring();
}

User::~User()
{
	// TODO Auto-generated destructor stub
}


}
