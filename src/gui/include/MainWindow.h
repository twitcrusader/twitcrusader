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
#include <gtkmm/stock.h>

#include "Icons.h"
//#include "OptionWindow.h"
#include "WindowVersion.h"
#include "AboutWindow.h"
#include "RegWindow.h"

#include "../../core/include/Functions.h"
#include "../../core/include/TwitterObject.h"
#include "../../core/include/Version.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

#define CONNECTED "Connected"
#define DISCONNECTED "Disconnected"
#define NO_ONLINE "Off-Line"

#define FILE_MENU_ITEMS 3
#define HELP_MENU_ITEMS 2
#define NUM_BUTTON 7

class MainWindow : public Window{

private:

	bool connected;

	MenuItem file_menu_items[FILE_MENU_ITEMS];
	MenuItem file_menu_root;
	Menu file_menu;


	MenuItem helps_menu_items[HELP_MENU_ITEMS];
	MenuItem helps_menu_root;
	Menu helps_menu;

	ToolButton button[NUM_BUTTON];
	Image icon_menu[NUM_BUTTON];


	Table table;
	Table table_into;
	ScrolledWindow scrolled_window;
	ScrolledWindow scroll_text;
	TextView text;
	Glib::RefPtr<TextBuffer> tweet_buffer;
	VBox layout;
	MenuBar menu_bar;

	Statusbar status_bar;
	Statusbar charbar;
	Toolbar tool_bar;

	string status_label;

	int selected_timeline;
	int timeline_mode;

protected:
	void init_window();

	void init_menu();
	void init_statusbar();
	void init_toolbar();
	void init_charbar();
	void init_text_area();
	void init_menu_bar();
	void init_scrolled_window();

	void on_submit_text();
	void on_writing();
	void updateStatusBar();

	void loadWindowCredits();
	void loadWindowVersion();
	void loadWindowOptions();
	void loadRegWindow();

	void is_connected();

public:
	MainWindow();
	virtual ~MainWindow();

	void foo();
	void gtkConnect();
	void refresh_timeline();
	void refresh();

	void on_quit();
};

#endif /* MAINWINDOW_H_ */
