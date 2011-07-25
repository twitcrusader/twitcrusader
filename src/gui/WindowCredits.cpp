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

#include "include/WindowCredits.h"

namespace std {

WindowCredits::WindowCredits() {
	dialog=gtk_about_dialog_new();
}

WindowCredits::~WindowCredits() {

}

gboolean WindowCredits::ShowWindow()
{
	declaration();

	/* CALLBACK: exit event and Widget Show */
	gtk_dialog_run(GTK_DIALOG (dialog));

	return true;
}

gboolean WindowCredits::declaration()
{

	GdkPixbuf* pixbuf=gdk_pixbuf_new_from_file(ICON_ABOUT, NULL);

	string buffer=string();
	buffer=Functions::readRawTextFile(PROG_DIR"/GPL3");

	/* Set all window options (color, size, position, logo, icon, etc) */
	gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "TwitCrusader");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Team TwitCrusader, Follow @teamtwc");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Basato su librerie GTK e semplicità!\n\nVersion: "TWC_VERSION""TWC_VERSION_STATUS);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://www.twitcrusader.org/");
	gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(dialog), buffer.c_str());
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
	g_object_unref(pixbuf);


	g_signal_connect_swapped (dialog, "response", G_CALLBACK (gtk_widget_destroy), dialog);

	return true;
}

gboolean WindowCredits::UpdateWindow()
{
	return true;
}

gboolean WindowCredits::destroyWindow()
{
	gtk_widget_destroy(dialog);
	return true;
}

}
