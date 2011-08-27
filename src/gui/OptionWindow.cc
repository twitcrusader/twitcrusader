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

#include "include/OptionWindow.h"

OptionWindow::OptionWindow()
{

	VBox box_option;
		Notebook notebook_option;
		Table table_option(7,10,true);
		Label account_label(twitterStruct.twitter.getLocalUser().getScreenName());

		set_title("Options");
		set_border_width(0);
		set_default_size(310,300);
		set_icon_from_file(ICON_SETTINGS);
		set_position(Gtk::WIN_POS_CENTER);
		set_size_request(310,300);

		if(twitterStruct.twitter.getLocalUser().getId().empty() || twitterStruct.twitter.getLocalUser().getScreenName().empty()){

		}else{

		}

		table_option.attach(account_label,1, 9, 0, 1);

		box_option.pack_start(table_option);

		add(box_option);

		show_all();
		Gtk::Main::run();

}

OptionWindow::~OptionWindow()
{
	hide();
}

