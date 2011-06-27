/*
 *	 	TwitCrusader - Twitter Client For Linux Desktop
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

#include "include/LocalUser.h"

namespace std {

LocalUser::LocalUser() {
	id=string();
	screenName=string();
	token=string();
	secretToken=string();
	consumerKey=string();
	consumerSecretKey=string();
}

LocalUser::~LocalUser() {

}

void  LocalUser::setId(string id){
	this->id.assign(id);
}

void  LocalUser::setScreenName(string secretName){
	this->screenName.assign(screenName);
}

void  LocalUser::setToken(string Token){
	this->token.assign(token);
}

void  LocalUser::setSecretToken(string secretToken){
	this->secretToken.assign(secretToken);
}

void  LocalUser::setConsumerKey(string consumerKey){
	this->consumerKey.assign(consumerKey);
}

void  LocalUser::setConsumerSecretKey(string secretConsumerKey){
	this->consumerSecretKey.assign(consumerSecretKey);
}

string LocalUser::getId(){
	return id;
}

string LocalUser::getScreenName(){
	return screenName;
}

string LocalUser::getToken(){
	return token;
}

string LocalUser::getSecretToken(){
	return secretToken;
}

string LocalUser::getConsumerKey(){
	return consumerKey;
}

string LocalUser::getConsumerSecretKey(){
	return consumerSecretKey;
}

}
