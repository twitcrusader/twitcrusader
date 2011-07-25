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

#include "include/WindowVersion.h"

namespace std {

WindowVersion::WindowVersion() {
	window =  gtk_dialog_new ();
	lastVersionMSG = gtk_label_new ("Last Version: ");
	lastVersionCheck= gtk_label_new (WindowVersion::downloadVersion().c_str());
	currentVersionMSG = gtk_label_new ("Current Version: ");
	currentVersionCheck = gtk_label_new (TWC_VERSION""TWC_VERSION_STATUS);
	table = gtk_table_new (8, 10, TRUE);
	button = gtk_dialog_add_button (GTK_DIALOG (window), GTK_STOCK_OK, GTK_RESPONSE_OK);
	error = NULL;
}



WindowVersion::~WindowVersion() {
	// TODO Auto-generated destructor stub
}

gboolean WindowVersion::UpdateWindow()
{
	return true;
}

gboolean WindowVersion::destroyWindow()
{
	gtk_widget_destroy(GTK_WIDGET(this->window));
	return true;
}

gboolean WindowVersion::ShowWindow()
{
	declaration();

	gtk_widget_show_all (window);
	return true;
}

gboolean WindowVersion::declaration()
{
	/* Set all window options (color, size, position, etc) */

	gtk_window_set_default_size (GTK_WINDOW(window), 300, 200);
	gtk_widget_set_size_request (window, 300, 200);
	gtk_window_set_title (GTK_WINDOW(window), "Check Updates");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_UPGRADE, &error);

	/* Attach All Widget */
	gtk_table_attach (GTK_TABLE (table), currentVersionMSG, 0, 6, 1, 2, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_table_attach (GTK_TABLE (table), currentVersionCheck, 6, 9, 1, 2, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionMSG, 0, 5, 3, 4, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionCheck, 6, 9, 3, 4, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 0, 0);

	/* Attach tabke at window container */
	gtk_container_add (GTK_CONTAINER ( gtk_dialog_get_content_area (GTK_DIALOG (window))), table);

	g_signal_connect_swapped (window, "response", G_CALLBACK (gtk_widget_destroy), window);


	return true;
}

string WindowVersion::downloadVersion(){

	string LatestVersion=string();

	/* Check Online Version From WebSite and Download File To /tmp/ directory */

	GetHTTP::getSingleCURL(VERSION_URL, FILE_VERSION);

	LatestVersion.assign(Functions::readRawTextFile(FILE_VERSION));

	/* Remove tmp file */
	remove(FILE_VERSION);

	return LatestVersion;
}

}
