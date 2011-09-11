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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <iostream>
#include <vector>

#include <glibmm.h>
#include <gtkmm.h>
#include <gtkmm/stock.h>
#include <gdk/gdkkeysyms.h>

#include "Icons.h"
#include "VersionDialog.h"
#include "AboutDialog.h"
#include "PropertiesDialog.h"
#include "RegDialog.h"

#include "../../core/include/Functions.h"
#include "../../core/include/TwitterObject.h"
#include "../../core/include/Twitter.h"
#include "../../core/include/Version.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

#define CONNECTED "Profile: Loaded.."
#define DISCONNECTED "Profile: Not Loaded.."
#define NO_ONLINE "Off-Line"

#define LOGOUT "Logout"
#define LOGIN "Login"
#define REGISTER "Register"
#define PROPERTIES "Properties"
#define QUIT "Quit"
#define VERSION "Version"
#define ABOUT "About"
#define DELETE_CONFIRM "Do you want delete the Profile?"
#define SENDING_MSG "Sending Message.."
#define MSG_SENT "Message sent"
#define MSG_NOT_SENT "Message not sent"
#define QUIT_MESSAGE "Do you want really quit?"

#define FILE_MENU_ITEMS 5
#define HELP_MENU_ITEMS 2
#define NUM_BUTTON 7

namespace TwitCrusader {

class MainWindow : public Window{

private:

	bool connected;

	MenuItem file_menu_items[FILE_MENU_ITEMS];
	MenuItem file_menu_root;
	Menu file_menu;


	MenuItem helps_menu_items[HELP_MENU_ITEMS];
	MenuItem helps_menu_root;
	Menu helps_menu;

	ToolButton button[7];
	Image icon_menu[7];

	Image avatar;
	Label nick;



	Table table;
	Gtk::TextView tweets;
	Table table_into;
	ScrolledWindow scrolled_window;
	ScrolledWindow scroll_text;
	TextView text;
	RefPtr<Gtk::TextBuffer> tweet_buffer;
	VBox layout;
	MenuBar menu_bar;

	Statusbar status_bar;
	Statusbar charbar;
	Toolbar tool_bar;

	ustring status_label;
	ustring char_count;

	int selected_timeline;
	int timeline_mode;

	Glib::Thread *thread;


	unsigned counter;
	static const unsigned delayInMin = 2;

protected:
	void init_window();
	void init_menu();
	void init_statusbar();

	void init_toolbar();
	void init_toolbar_items();

	void init_charbar();
	void init_text_area();
	void init_menu_bar();
	void init_scrolled_window();
	void init_timer();

	void declare();
	void on_submit_text();
	void on_writing();
	bool on_timeout();

	void loadAboutDialog();
	void loadVersionDialog();
	void loadWindowProperties();
	void loadRegDialog();

	void clear_statusbar();

	void is_connected();

	void show_home_timeline();
	void mentions_timeline();
	void show_private_message();

	bool Quit_Dialog();

public:
	RefPtr<MainLoop> timeout;
	MainWindow();
	virtual ~MainWindow();

	void foo();
	void gtkConnect();
	void gtkDisconnect();
	void refresh_timeline_thread();
	void refresh_timeline();
	void refresh();

	void on_quit();
};
}

#endif /* MAINWINDOW_H_ */
