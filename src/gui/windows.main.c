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

/* Headers */
#include "inc/windows.main.h"
 
GtkWidget* CreateWindowMain(){
	/* Variables */
	GtkWidget *window,
			  *container;
	GError *error = NULL;
	
	/* Set Window Parameters */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 315, 650);
	gtk_widget_set_size_request (window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(window), "TwitCrusader");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "../../img/twc.favicon.png", &error);
	
	/* Create a Main Container*/
	container = gtk_vbox_new (FALSE, 8);
	
	
	/* Add Container to Window TopLevel */
	gtk_container_add (GTK_CONTAINER (window), container);
	
	/* Destroy WindowMain() */
	g_signal_connect_swapped(G_OBJECT(window), 
							"destroy",
							G_CALLBACK(gtk_main_quit), 
							G_OBJECT(window));
	
return window;
}

int GtkMainWindow(){
 	g_thread_init (NULL);
	gdk_threads_init ();
	gtk_init (0, NULL);
	
	gtk_widget_show(CreateWindowMain());
	
	gdk_threads_enter();
	gtk_main ();
	gdk_threads_leave ();
	
return 0;
}
