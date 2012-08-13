/*
 *	TwitCrusader - Twitter Client For Linux Desktop
 *	Copyright (C) 2012 - Patryk Rzucidlo <ptkdev@gmail.com>
 *	Orazio Briante <orazio.briante@hotmail.it>
 *
 *
 * This Program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *		WebSite: http://www.twitcrusader.org/
 * 		Development Guidelines: http://dev.twitcrusader.org/
 * 
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 */

#include <twc/twc.h>

#include <twitc/twitc.h>

#include <twc/Version.h>
#include <twc/icons.h>

#include <gtk/gtk.h>

/* GtkUpdatesDialogCreate() Function 
 *
 * Developer Guide (Italian): http://dev.it.twitcrusader.org/sourcecode-guide-gtk_updates_window_create-function/
 * 
 */
void startVersionWindow()
{

	string_t last_version=getPageCURL(TWC_LATEST_VERSION_URL);
	string_t current_version=readRawTextFile(PROG_DIR"VERSION");

	if(!last_version)
		last_version=" ";

	if(!current_version)
		current_version=" ";

	string_t msg=NULL;
	asprintf(&msg,"%s:\t%s\n%s:\t%s", "Latest Version", last_version, "Current Version", current_version);

	if(msg){
		GtkWidget	*dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,msg);

		gtk_window_set_position(GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
		g_signal_connect_swapped (dialog, "response",G_CALLBACK (gtk_widget_destroy),dialog);

		gtk_widget_show_all (dialog);
		gtk_dialog_run(GTK_DIALOG(dialog));
	}
}
