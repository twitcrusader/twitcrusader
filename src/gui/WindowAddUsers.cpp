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

#include "include/WindowAddUsers.h"

namespace std {

WindowAddUsers::WindowAddUsers() {

	table = gtk_table_new (10, 10, TRUE);
	error=NULL;
	label = gtk_label_new ("Inserisci PIN");
	window=gtk_dialog_new ();
	pin= gtk_entry_new ();
	button = gtk_button_new_with_label ("Crea Account");
	cancel_button = gtk_dialog_add_button (GTK_DIALOG (window), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);

	tw_login_imgevent = gtk_button_new();

}

WindowAddUsers::~WindowAddUsers() {
	// TODO Auto-generated destructor stub
}

gboolean WindowAddUsers::declaration()
{

	/* Set all window options (color, size, position, logo, icon, etc) */
	gtk_window_set_default_size (GTK_WINDOW(window), 200, 210);
	gtk_widget_set_size_request (window, 200, 210);
	gtk_window_set_title (GTK_WINDOW(window), "Nuovo Utente");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_ADDUSER, &error);

	/* Attach twitter-login image */
	gtk_table_attach (GTK_TABLE (table), tw_login_imgevent, 0, 10, 1, 3, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	 gtk_button_set_image (GTK_BUTTON (tw_login_imgevent), gtk_image_new_from_file (ICON_SIGNIN));

	/* Call oAuth function */
	g_signal_connect (G_OBJECT (tw_login_imgevent), "button_press_event", G_CALLBACK(&WindowAddUsers::gtkBrowserAuthorization),NULL);

	/* Attach Box for PIN */
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	gtk_entry_set_text (GTK_ENTRY (pin), "");
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 3, 5, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_table_attach (GTK_TABLE (table), pin, 1, 9, 5, 6, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);

	/* Press Button and call function for verify PIN */
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,7, 9, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_container_add (GTK_CONTAINER (window), table);
	//g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(gtkAccessToken), pin);

	gtk_container_add (GTK_CONTAINER ( gtk_dialog_get_content_area (GTK_DIALOG (window))), table);

	return true;
}

gboolean WindowAddUsers::ShowWindow(){

	declaration();

	/* Exit event and Widget Show */
	g_signal_connect_swapped (window, "response", G_CALLBACK (gtk_widget_destroy), window);
	gtk_widget_show_all (window);

	return true;
}

gboolean WindowAddUsers::destroyWindow()
{
	return true;
}

gboolean WindowAddUsers::UpdateWindow()
{
	return true;
}

gboolean WindowAddUsers::gtkBrowserAuthorization(){

	twitterStruct.twitter.tokenTempBrowser();

return true;
}

}
