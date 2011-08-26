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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <vector>

#include <gtkmm.h>

#include "icons.h"
#include "../../core/include/twitter_object.h"


#define PROG_NAME "TwitCrusader"

namespace std {

class MainWindow : public Gtk::Window{

protected:

	Gtk::MenuItem file_menu_items[3];
	Gtk::MenuItem file_menu_root;
	Gtk::Menu file_menu;


	Gtk::MenuItem options_menu_items[1];
	Gtk::MenuItem options_menu_root;
	Gtk::Menu options_menu;


	Gtk::MenuItem helps_menu_items[2];
	Gtk::MenuItem helps_menu_root;
	Gtk::Menu helps_menu;

	Gtk::ToolButton button[7];
	Gtk::Image icon_menu[7];

	Gtk::Table table;
	Gtk::Table table_into;
	Gtk::ScrolledWindow scrolled_window;
	Gtk::ScrolledWindow scroll_text;
	Gtk::TextView text;
	  Glib::RefPtr<Gtk::TextBuffer> tweet_buffer;
	Gtk::VBox layout;
	Gtk::MenuBar menu_bar;

	Gtk::Statusbar status_bar;
	Gtk::Statusbar statusbar_char;
	Gtk::Toolbar tool_bar;

	string status_label;

	void updateStatusBar();

public:
	MainWindow();
	virtual ~MainWindow();

	void foo();
	void gtkConnect();
	void loadWindowCredits();
	void loadWindowVersion();
	void loadWindowOptions();
	void loadWindowAdduser();

	void on_quit();
};

} /* namespace std */
#endif /* MAINWINDOW_H_ */
