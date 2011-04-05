/* 
*	TwitCrusader - Twitter Client For Linux Desktop
*		Copyright (C) 2011  PTKDev
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
*		Author: Patryk Rzucidlo (PTKDev)
*		Twitter: @ptkdev / @twitcrusader_en
*		WebSite: http://www.twitcrusader.org
*/

#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

//TwitCrusader Header File
#include "twc.h"


// About
void windows_about()
{
	// Variables
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(PACKAGE_PIXMAP_DIR"/tw_about.png", NULL);
	GtkWidget *dialog = gtk_about_dialog_new();
	GError *error = NULL;
	
	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), PACKAGE_PIXMAP_DIR"/star.png", &error);
	
	// GTK Windows Declaration: All info
	gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "TwitCrusader");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), ""); 
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) PTKDev, RoxShannon");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Basato su librerie GTK e semplicità!\n\nVersion: 0.1.80");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://www.twitcrusader.org/");
	
	// GTK Windows Declaration: logo
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
	g_object_unref(pixbuf), pixbuf = NULL;
	
	// Widget Show
	gtk_dialog_run(GTK_DIALOG (dialog));
	
	// CALLBACK: exit event
	gtk_widget_destroy(dialog);

}
