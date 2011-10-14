/*
 *	TwitCrusader - Twitter Client For Linux Desktop
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
 * 
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 * 
 */

/* Define */
#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include "icons.h"

#include "threads.h"

#include "../../core/inc/externlibs.h"

#include "../../core/inc/debug.h"
#include "../../core/inc/lang.h"
#include "../../core/inc/functions.h"
#include "../../core/inc/twitter.h"
#include "../../core/inc/gethttp.h"
#include "../../core/inc/twitter.h"

#include "windows.properties.h"
#include "windows.credits.h"
#include "windows.updates.h"
#include "windows.register.h"



#define AVATAR_SIZE 70

/* Define Structure */

struct main_window{
	char *statusLabel;

	GError *error;


	//Tray Icon
	GtkStatusIcon *trayIcon;
	GtkWidget *trayMenu,
	*trayMainMenu,
	*trayMenuItems[3],
	*trayIconMenu[3];

	gboolean iconified;

	//Window
	GtkWidget *window,
	*table,
	*scroll,
	*table_into,
	*scrolled_window,
	*menu_bar,
	*layout,
	*toolbar,
	*statusbar,
	*char_bar,
	*tool_bar[7],
	*tool_icon_menu[7],
	*text,
	*file_menu_obj,
	*file_menu_root,
	*file_menu_items[4],
	*file_icon_menu[4],
	*aiuto_menu_obj,
	*aiuto_menu_root,
	*aiuto_menu_items[3],
	*aiuto_icon_menu[3],
	*tweet,
	*avatar,
	*align;

	GtkTextBuffer *tweetBuffer;

	int selected_timeline;
	int logged;

}mainWindow;

struct menu{
	char *name;
	char *icon;
	void *function;

};

struct StatusBars
{
	GtkStatusbar *message;

} StatusBar;


/* VARIABLES*/
struct menu menuTrayIcon[2];
struct menu menuFile[4];
struct menu menuAiuto[3];
struct menu tool_button[7];

typedef struct configuration {
	char* default_user;
}config;

/* Define Function */

/* Main Window */
void* gtk_window_main(void* );

/* Init */
void gtk_init_tray_icon();
void gtk_init_window();
void gtk_init_menu();
void gtk_refresh_menu();
void gtk_init_statusbar();
void gtk_init_toolbar();
void gtk_init_toolbar_items();
void gtk_init_charbar();
void gtk_init_text_area();
void gtk_init_menu_bar();
void gtk_init_scrolled_window();
void gtk_init_timer();

/* Refresh */
void gtk_refresh_toolbar_items();
void* gtk_refresh_timeline(void*);
void gtk_refresh_timeline_thread();
void gtk_refresh();
void gtk_clear_statusbar();

/* Load Dialog */
void loadAboutDialog();
void loadVersionDialog();
void loadWindowProperties();
void loadRegDialog();

/* Actions */
void foo();
void gtk_connect();
void gtk_disconnect();
void show_home_timeline();
void mentions_timeline();
void show_private_message();

void window_state_event (GtkWidget* , GdkEventWindowState* , gpointer);
void gtk_tray_icon_popup_menu(GtkStatusIcon*, guint , guint32 , gpointer );
void gtk_tray_icon_activated();

void updateStatusBar(GtkTextBuffer* ,GtkStatusbar* );
gboolean gtkSendTweet(GtkWidget* , GdkEventKey* , GtkTextBuffer* );

/* Quit */
void on_quit();
int Quit_Dialog();

#endif
