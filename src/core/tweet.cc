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

#include "include/tweet.h"

Tweet::Tweet()
{
	created_at=string();
	id=string();
	text=string();
	source=string();
	truncated=string();
	favorited=string();
	in_reply_to_status_id=string();
	in_reply_to_user_id=string();
	in_reply_to_screen_name=string();
	retweet_count=string();
	retweeted=string();
	geo=string();
	coordinates=string();
	place=string();
	contributors=string();

	user=User();
}

Tweet::~Tweet()
{
	user.~User();
}

void Tweet::setGeo(string geo)
{
	this->geo.assign(geo);
}

string Tweet::getIn_reply_to_screen_name()
{
	return this->in_reply_to_screen_name;
}

void Tweet::setText(string text)
{
	this->text.assign(text);
}

void Tweet::setFavorited(string favorited)
{
	this->favorited.assign(favorited);
}

void Tweet::setIn_reply_to_user_id(string in_reply_to_user_id)
{
	this->in_reply_to_user_id.assign(in_reply_to_user_id);
}

void Tweet::setPlace(string place)
{
	this->place.assign(place);
}

string Tweet::getFavorited()
{
	return this->favorited;
}

string Tweet::getCreated_at()
{
	return this->created_at;
}

void Tweet::setRetweet_count(string retweet_count)
{
	this->retweet_count.assign(retweet_count);
}

void Tweet::setRetweeted(string retweeted)
{
	this->retweeted.assign(retweeted);
}

string Tweet::getContributors()
{
	return this->contributors;
}

string Tweet::getSource()
{
	return this->source;
}

string Tweet::getGeo()
{
	return this->geo;
}

void Tweet::setSource(string source)
{
	this->source.assign(source);
}

string Tweet::getCoordinates()
{
	return this->coordinates;
}

string Tweet::getIn_reply_to_status_id()
{
	return this->in_reply_to_status_id;
}

string Tweet::getRetweet_count()
{
	return this->retweet_count;
}

void Tweet::setTruncated(string truncated)
{
	this->truncated.assign(truncated);
}

string Tweet::getText()
{
	return this->text;
}

void Tweet::setCoordinates(string coordinates)
{
	this->coordinates.assign(coordinates);
}

string Tweet::getRetweeted()
{
	return this->retweeted;
}

void Tweet::setIn_reply_to_screen_name(string in_reply_to_screen_name)
{
	this->in_reply_to_screen_name.assign(in_reply_to_screen_name);
}

void Tweet::setCreated_at(string created_at)
{
	this->created_at.assign(created_at);
}

string Tweet::getTruncated()
{
	return this->truncated;
}

string Tweet::getId()
{
	return this->id;
}

void Tweet::setIn_reply_to_status_id(string in_reply_to_status_id)
{
	this->in_reply_to_status_id.assign(in_reply_to_status_id);
}

void Tweet::setContributors(string contributors)
{
	this->contributors.assign(contributors);
}

void Tweet::setId(string id)
{
	this->id.assign(id);
}

string Tweet::getPlace()
{
	return this->place;
}

User Tweet::getUser()
{
	return this->user;
}

string Tweet::getIn_reply_to_user_id()
{
	return this->in_reply_to_user_id;
}

void Tweet::setUser(User user){
	this->user=user;
}
