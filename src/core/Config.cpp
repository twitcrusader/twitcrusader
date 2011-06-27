/*
 *	 TwitCrusader-GUI is part of TwitCrusader - Twitter Client For Linux Desktop
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

#include "include/Config.h"

namespace std {

Config::Config() {
	avatarDir=string();
	configDir=string();
	configFile=string();
	timelineDir=string();
	homeDir=string();

	homeDir.assign(g_get_home_dir());
	setAvatarDir();
	setConfigDir();
	setConfigFile();
	setTimelineDir();

	//	cout<<"config: \n";
	//	cout<<getAvatarDir()<<"\n";
	//	cout<<getConfigDir()<<"\n";
	//	cout<<getConfigFile()<<"\n";
	//	cout<<getTimeLineDir()<<"\n";

}

Config::~Config() {

}

void Config::setAvatarDir(){

	avatarDir.assign(homeDir);
	avatarDir.append("/.twc/avatar/");
}

bool Config::createAvatarDir(){


	/* User-Directory Path */

	//Avatar Dir
	if(!avatarDir.empty()){
		remove(avatarDir.c_str());
		//mkdir( avatarDir.c_str(), 0777);

		string cmd=string();
		cmd.assign("mkdir -p ");
		cmd.append(avatarDir);
		cout<<cmd;
		system(cmd.c_str());

		return true;
	}

	return false;
}

void Config::setConfigDir(){

	//Configuration File
	configDir.assign(homeDir);
	configDir.append("/.twc/config/");
}

bool Config::createConfigDir(){

	if(!configDir.empty()){
		//mkdir( configDir.c_str(), 0777);
		string cmd=string();
		cmd.assign("mkdir -p ");
		cmd.append(configDir);
		system(cmd.c_str());
		return true;
	}
	return false;

}

void Config::setTimelineDir(){
	timelineDir.assign(homeDir);
	timelineDir.append("/.twc/timeline/");

}

bool Config::createTimelineDir(){

	if(!timelineDir.empty()){
		//mkdir(timelineDir.c_str(), 0777);
		string cmd=string();
		cmd.assign("mkdir -p ");
		cmd.append(timelineDir);
		system(cmd.c_str());
		return true;
	}

	return false;

}

void Config::setConfigFile(){
	configFile.assign(configDir);
	configFile.append(CONFIG_FILENAME);
}


string Config::getAvatarDir(){
	return avatarDir;
}

string Config::getConfigDir(){
	return configDir;
}

string Config::getConfigFile(){
	return configFile;
}


string Config::getTimeLineDir(){
	return timelineDir;
}


bool Config::deleteConfigFile(){
	string cmd=string();

	cmd.assign("rm ");
	cmd.append(configFile);
	system(cmd.c_str());

	return true;
}

}
