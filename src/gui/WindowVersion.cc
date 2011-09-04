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

#include "include/WindowVersion.h"
namespace TwitCrusader {
WindowVersion::WindowVersion() {

	string last_Version_Check;
	last_Version_Check.assign(Functions::DownloadVersion());
	string current_Version_Check;
	current_Version_Check.assign(Functions::readRawTextFile(TWC_VERSION_PATH) );

	string info(CURRENT_VERSION_MSG+current_Version_Check+"\n"+LAST_VERSION_MSG+last_Version_Check);

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
