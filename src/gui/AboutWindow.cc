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

#include "include/AboutWindow.h"

namespace TwitCrusader {

AboutWindow::AboutWindow()
{
	Glib::RefPtr<Gdk::Pixbuf> logo;
		logo=Gdk::Pixbuf::create_from_file(ICON_ABOUT);


		set_name(PROG_NAME);
		set_copyright(COPYRIGHT);
		set_comments(COMMENT""TWC_VERSION""TWC_VERSION_STATUS);
		set_website(WEBSITE);
		//set_license()set_license_type(LICENSE_GPL_3_0);
		set_license(Functions::readRawTextFile(PROG_DIR"/GPL3"));
		set_logo(logo);
		set_authors(Functions::readTextFileLinebyLine(PROG_DIR"/AUTHORS"));

		set_default_response( Gtk::RESPONSE_OK ) ;

		run();

}

AboutWindow::~AboutWindow() {
	// TODO Auto-generated destructor stub
}

}
