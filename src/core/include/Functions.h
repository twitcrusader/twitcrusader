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

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <libnotify/notify.h>

#include "GetHTTP.h"
#include "Version.h"
#include "../../gui/include/Icons.h"

using  namespace std;
using  namespace Glib;

namespace TwitCrusader {

class Functions {

public:

	static ustring readRawTextFile(ustring fileName);
	static bool writeRawTextFile(ustring fileName, ustring text);
	static vector<Glib::ustring> readTextFileLinebyLine(ustring fileName);
	static bool shellParameters (int argc, char **argv);
	static ustring DownloadVersion();
	static void notifySystem(ustring Message);

};
}
#endif /* FUNCTIONS_H_ */
