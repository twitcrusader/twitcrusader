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
#include "inc/windows.error.h"

void gtk_window_error(char* error_msg){

	GtkWidget *window,
	*label,
	*table = gtk_table_new (5, 10, TRUE),
	*button = gtk_button_new_with_label ("Close");
	GError *error = NULL;

	/* Set all window options (color, size, position, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 200, 150);
	gtk_widget_set_size_request (window, 200, 150);
	gtk_window_set_title (GTK_WINDOW(window), "Error!");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_CLOSE , &error);

	/* Error Message */
	label = gtk_label_new (error_msg);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 1, 3, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), button, 0, 10, 4, 5, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (button), "clicked",  G_CALLBACK (CloseWindow), G_OBJECT (window));

	/* Attach tabke at window container */
	gtk_container_add (GTK_CONTAINER (window), table);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (CloseWindow), G_OBJECT (window));

	gtk_widget_show_all (window);

}

void CloseWindow(gpointer *widget)
{
	/* Destroy the widget */
	gtk_widget_destroy (GTK_WIDGET (widget));
}
