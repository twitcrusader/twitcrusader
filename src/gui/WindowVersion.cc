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

#include "include/WindowVersion.h"
namespace TwitCrusader {
WindowVersion::WindowVersion() {
	string current_Version_MSG("Current Version:\t");
	string last_Version_MSG("Last Version:\t\t");

	string last_Version_Check(Functions::DownloadVersion());
	string current_Version_Check(TWC_VERSION""TWC_VERSION_STATUS);

	string info(current_Version_MSG+current_Version_Check+"\n"+last_Version_MSG+last_Version_Check);

	MessageDialog version(info);
	version.set_title("Check Updates");
	version.set_border_width(0);
	version.set_position(WIN_POS_CENTER);
	version.set_default_icon_from_file(ICON_UPGRADE);

	version.run();


}

WindowVersion::~WindowVersion() {
	// TODO Auto-generated destructor stub
}
}
