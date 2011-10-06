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

#ifndef USER_H_
#define USER_H_

/*
 *
 */
#include <iostream>
#include <gtkmm.h>

using  namespace std;
using  namespace Glib;

namespace TwitCrusader {

class User {

public:

	ustring id,
	name,
	screen_name,
	location,
	description,
	profile_image_url,
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

	User();
	virtual ~User();

};
}
#endif /* USER_H_ */
