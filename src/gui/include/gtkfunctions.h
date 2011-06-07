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

#ifndef GTKWINDOWS_H_
#define GTKWINDOWS_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <pthread.h>
#include <gdk/gdkkeysyms.h>

#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "windows.h"

#include "../../core/include/functions.h"
#include "../../core/include/twitter.h"
#include "../../core/include/gethttp.h"
#include "../../core/include/config.h"

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

void destroyGtk(GtkButton *button, gpointer widget);
void updateGtk(GtkButton *button, gpointer window);
gboolean gtkOnKeyPress (GtkWidget * window, GdkEventKey* pKey, gpointer userdata);
gboolean gtkSendTweet(GtkWidget *TextArea, GdkEventKey *pKey, GtkTextBuffer *tweetBuffer);
void updateStatusBar(GtkTextBuffer *buffer, GtkStatusbar  *statusbar);
void gtkSwitchPage (GtkButton *button, GtkNotebook *notebook);
void gtkAccessToken(GtkButton *button, AuthWidget *DataInput);
void gtkDeleteAccount(GtkButton *button, gpointer widget);
void gtkConnect(GtkButton *button, gpointer window);
void gtkDisconnect(GtkButton *button, gpointer window);
void gtkAddUser(GtkButton *button, gpointer window);
void gtkRefreshswitchTimeLine(GtkWidget *table_into, gpointer window);

#endif /* GTKWINDOWS_H_ */
