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

#include "include/WindowOptions.h"

namespace std {

WindowOptions::WindowOptions() {
	window=gtk_dialog_new ();
	notebook=gtk_notebook_new ();
	table = gtk_table_new (7, 10, TRUE);
	ok_button = gtk_dialog_add_button (GTK_DIALOG (window), GTK_STOCK_CLOSE, GTK_RESPONSE_CLOSE);
	itemsAccount=NULL;
}

WindowOptions::~WindowOptions() {

}

gboolean WindowOptions::declaration()
{

	// Set all window options (color, size, position, etc)
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 300);
	gtk_widget_set_size_request (window, 310, 300);
	gtk_window_set_title (GTK_WINDOW(window), "Opzioni");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_SETTINGS, &error);
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

	// Set all functions of Account TAB
	table = gtk_table_new (7, 10, TRUE);
	combo = gtk_combo_new ();
	settingMenu = gtk_label_new ("Account");


	label = gtk_label_new ("Twitter's Account:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	if(!user.getScreenName().empty()){
		itemsAccount = g_list_append (itemsAccount, (void*)user.getScreenName().c_str());
	}else{
		itemsAccount = g_list_append (itemsAccount, (void*)string().c_str());
	}
	gtk_combo_set_popdown_strings (GTK_COMBO (combo), itemsAccount);

	// Attach all gtk-widget at table
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 0, 1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_table_attach (GTK_TABLE (table), combo, 1, 9, 1, 2, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);

	if(user.getId().empty() || user.getScreenName().empty()){
		button = gtk_button_new_with_label ("Nuovo");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
		g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (&WindowOptions::loadWindowAdduser), NULL);
	}else{
		button = gtk_button_new_with_label ("Elimina");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
		//g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtkDeleteAccount), G_OBJECT (window));
	}

	// Set switch-TAB signal
	//g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (gtkSwitchPage), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, settingMenu);


	// Attach tab-notebook at window container
	gtk_container_add (GTK_CONTAINER (gtk_dialog_get_content_area (GTK_DIALOG (window))), notebook);

	g_signal_connect_swapped (window, "response", G_CALLBACK (gtk_widget_destroy), window);

	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);

	return true;
}

gboolean WindowOptions::UpdateWindow()
{
	return true;
}

gboolean WindowOptions::ShowWindow()
{
	declaration();

	// Widget Show
	gtk_widget_show_all (window);

	return true;
}

gboolean WindowOptions::destroyWindow()
{
	return true;
}

gboolean WindowOptions::loadWindowAdduser(){
	WindowAddUsers windowAddUsers=WindowAddUsers();
	windowAddUsers.ShowWindow();

	return true;
}

}
