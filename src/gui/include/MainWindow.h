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

/*
 *
 */
#include <iostream>
#include <gtk/gtk.h>
#include <vector>
#include <gdk/gdkkeysyms.h>

#include "Menu.h"
#include "StatusBar.h"
#include "Button.h"

#include "../../core/include/TwitterObject.h"

#include "icons.h"
#include "WindowAddUsers.h"
#include "WindowCredits.h"
#include "WindowOptions.h"
#include "WindowVersion.h"

#define PROG_NAME "TwitCrusader"


namespace std {

class MainWindow {

private:


protected:

	//Other Functions
	static gboolean initSkeleton(GtkWidget*, gchar*, GError*);
	static gboolean initMenu(string, vector<Menu>, GtkWidget*, GtkWidget*, GtkWidget*);
	static gboolean initToolBar(vector<Button>, GtkWidget*, GtkWidget*);
	static gboolean initInputBar(GtkWidget*, GtkWidget*, GtkTextBuffer*, GtkWidget*, GtkWidget*);
	static gboolean initScrolledWindow(GtkWidget*, GtkWidget*, GtkWidget*);

	//loading windows function!

	gboolean loadWindowCredits();
	gboolean loadWindowVersion();
	gboolean loadWindowOptions();
	gboolean loadWindowAdduser();

public:

	static gboolean declaration(); //protected method to setup graphic structure of the window
	static gboolean UpdateWindow(GtkWidget*); //protected method to Refresh the window
	static gboolean destroyWindow(GtkWidget*); //protected To Destroy the Drawn window
	static gboolean ShowWindow(); //public method to Start graphic Drawing

	gboolean gtkSendTweet(GtkWidget*, GdkEventKey*, GtkTextBuffer*, StatusBar);
	static gboolean gtkConnect(GtkWidget*);
	static gboolean gtkRefreshSwitchTimeLine();
	gboolean foo();
};

}

#endif /* MAINWINDOW_H_ */
