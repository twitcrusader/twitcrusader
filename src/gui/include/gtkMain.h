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
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */

#ifndef GTKMAIN_H_
#define GTKMAIN_H_

#include <gtk/gtk.h>
#include <glib.h>
#include <pthread.h>
#include <gdk/gdkkeysyms.h>

#include "icons.h"

#include "../../core/include/functions.h"
#include "../../core/include/twitter.h"
#include "../../core/include/gethttp.h"

struct main_window{
	char *statusLabel;

	GError *error;
	GtkWidget *window,
	*table,
	*scroll,
	*icon_menu,
	*table_into,
	*scrolled_window,
	*menu_bar,
	*layout,
	*toolbar,
	*statusbar,
	*statusbar_char,
	*new_button,
	*text,
	*file_menu_obj,
	*file_menu_root,
	*file_menu_items,
	*aiuto_menu_obj,
	*aiuto_menu_root,
	*aiuto_menu_items,
	*nick,
	*tweet,
	*avatar,
	*align;

	GtkTextBuffer *tweetBuffer;

}mainWindow;

struct menu{
	char *name;
	char *icon;
	void *function;

};

typedef struct
{
	GtkWidget *pin;
	GtkWidget *window;

} AuthWidget;

struct StatusBars
{
	GtkStatusbar *message;

} StatusBar;

typedef struct configuration {
	char* default_user;
}config;

int windowMain();
void destroyGtk();
int updateGtk();
gboolean gtkOnKeyPress (GtkWidget * window, GdkEventKey* pKey, gpointer userdata);
gboolean gtkSendTweet(GtkWidget *TextArea, GdkEventKey *pKey, GtkTextBuffer *tweetBuffer);
void updateStatusBar(GtkTextBuffer *buffer, GtkStatusbar  *statusbar);
void gtkSwitchPage (GtkNotebook *notebook);
void gtkAccessToken(AuthWidget *DataInput);
void gtkDeleteAccount();
void gtkConnect();
void gtkDisconnect();
void gtkAddUser();
int gtkRefreshSwitchTimeLine();
void downloadsAvatars();
void destroyGtk();


#endif /* GTKMAIN_H_ */
