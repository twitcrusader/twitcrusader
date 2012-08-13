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

#include <twitc/twitc.h>

#include <twc/twc.h>
#include <twc/icons.h>

#include <twc/preference.h>

#include <twc/Registration.h>
#include <twc/ErrorWidget.h>

#include <gtk/gtk.h>

static GtkWidget *gpin=NULL;
static string_t tmpToken=NULL;
static twitterURLS_t *twURLS=NULL;
GtkWidget	*dialog=NULL;


void gtk_tokenTempBrowser()
{
	tmpToken=tokenTempBrowser(twURLS, TWITTER_KEY, TWITTER_KEY_SECRET);
}

gboolean gtk_oauth_access_token()
{

	/* Get text from GTK_Entry*/
	const gchar *pin = gtk_entry_get_text (GTK_ENTRY(gpin));

	if(pin)
	{

		//Validate PIN
		user_t *user=tokenAccess(twURLS, (string_t)pin, tmpToken);

		if(user)
		{
			ProgramPath_t *pp=initProgPath( PROG_PATH, AVATAR_DIR, CONFIG_DIR, CONFIG_FILE, PREFERENCE_FILE);

			if(pp)
			{

				createDirectory(pp->configDir);

				writeUserFile(user,pp->configFile);

				if(user)
					uninitUser(user);

				if(pp)
					uninitProgPath(pp);

				gtk_entry_set_text (GTK_ENTRY(gpin), "\0");

				gtk_widget_destroy(dialog);

			}
		}
		else{
			gtk_widget_show_all(dialog);
			startWindowError("You have insert a Bad PIN");
		}


	}

	return TRUE;
}

void startRegistrationWindow(GtkWidget *window)
{

	gtk_widget_destroy(dialog);

	twURLS=initURLS(OAUTH_API_URL_DEFAULT, HTTPS_API_URL_DEFAULT);

	/* Set all dialog options (color, size, position, logo, icon, etc) */
	dialog = gtk_dialog_new();
	gtk_window_set_title (GTK_WINDOW(dialog), "New User");
	gtk_container_set_border_width (GTK_CONTAINER (dialog), 0);
	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);

	 gtk_window_set_transient_for (GTK_WINDOW (dialog), GTK_WINDOW (window));

	GError *error = NULL;
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), ICONS_DIR""ICON_ADDUSER, &error);

	if(error)
	{
		error((string_t)error->message);
		g_error_free(error);
		error=NULL;
	}

	/* Attach twitter-login image */
	GtkWidget *twitterLogin = gtk_image_new_from_file (ICONS_DIR""ICON_SIGNIN);
	GtkWidget* tw_login_imgevent = gtk_event_box_new ();
	GtkWidget *table = gtk_table_new (10, 10, TRUE);
	gtk_container_add (GTK_CONTAINER (tw_login_imgevent), twitterLogin);
	gtk_table_attach (GTK_TABLE (table), tw_login_imgevent, 0, 10, 1, 3, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);

	/* Call oAuth function */
	g_signal_connect (G_OBJECT (tw_login_imgevent), "button_press_event", G_CALLBACK(gtk_tokenTempBrowser), NULL);

	/* Attach Box for PIN */
	GtkWidget *label = gtk_label_new ("Insert PIN");
	gpin = gtk_entry_new ();
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	gtk_entry_set_text (GTK_ENTRY(gpin), "\0");
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 3, 5, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), gpin, 1, 9, 5, 6, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);

	/* Press Button and call function for verify PIN */
	GtkWidget *button = gtk_button_new_with_label ("Create Accont");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,7, 9, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_dialog_add_action_widget (GTK_DIALOG (dialog), table, GTK_RESPONSE_CLOSE);
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(gtk_oauth_access_token), NULL);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (dialog), "delete_event", G_CALLBACK (gtk_widget_destroy), dialog);

	gtk_widget_show_all (dialog);
	gtk_dialog_run(GTK_DIALOG(dialog));

}
