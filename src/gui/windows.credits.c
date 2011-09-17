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
#include "inc/windows.credits.h"
#include "inc/icons.h"
#include "../core/inc/lang.h"

/* gtk_credits_dialog_create() Function 
 *
 * Developer Guide (Italian): http://dev.it.twitcrusader.org/sourcecode-guide-gtk_credits_dialog_create-function/
 * 
 */
void gtk_credits_dialog()
{
	GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file (ICON_ABOUT, NULL);
	GtkWidget* dialog = gtk_about_dialog_new();

	GError* error = NULL;

	gtk_window_set_icon_from_file (GTK_WINDOW (dialog), ICON_FAVICON, &error);

	//gtk_about_dialog_set_name (GTK_ABOUT_DIALOG (dialog), TWC); deprecated gtk+-2.0
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "");
	gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog), "(c) "TWC" Team\nVersion: "TWC_VERSION_STATUS);
	gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG (dialog), "Twitter Client For Linux Desktop");
	gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog), "http://www.twitcrusader.org/");

	gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG (dialog), pixbuf);
	g_object_unref (pixbuf), pixbuf = NULL;

	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
