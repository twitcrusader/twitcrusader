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
#include "inc/windows.updates.h"

/* GtkUpdatesDialogCreate() Function 
 *
 * Developer Guide (Italian): http://dev.it.twitcrusader.org/sourcecode-guide-gtk_updates_window_create-function/
 * 
 */
void gtk_window_update()
{
	
	//FILE* checkLatesVersion = NULL;
	char bufferLatesVersion[10];
	GtkWidget *window,
	*lastVersionMSG = gtk_label_new ("Last Version: "),
	*lastVersionCheck,
	*currentVersionMSG = gtk_label_new ("Current Version: "),
	*currentVersionCheck = gtk_label_new (TWC_VERSION""TWC_VERSION_STATUS),
	*table = gtk_table_new (8, 10, TRUE),
	*button = gtk_button_new_with_label ("Close");
	GError *error = NULL;

	/* Check version with downloaded file */
	strcpy(bufferLatesVersion, downloadVersion());


	/* Set all window options (color, size, position, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 300, 200);
	gtk_widget_set_size_request (window, 300, 200);
	gtk_window_set_title (GTK_WINDOW(window), "Check Updates");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_UPGRADE, &error);

	/* Attach All Widget */
	lastVersionCheck = gtk_label_new (bufferLatesVersion);
	gtk_table_attach (GTK_TABLE (table), currentVersionMSG, 0, 6, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), currentVersionCheck, 6, 9, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionMSG, 0, 5, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionCheck, 6, 9, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), button, 1, 9, 5, 7, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (button), "clicked",  G_CALLBACK (CloseWindow), G_OBJECT (window));

	/* Attach tabke at window container */
	gtk_container_add (GTK_CONTAINER (window), table);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (window);
}
