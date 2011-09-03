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

}


}
