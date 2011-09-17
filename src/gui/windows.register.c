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

#include "inc/windows.register.h"

void gtk_window_register(){
	GtkWidget *table = gtk_table_new (10, 10, TRUE),
			*label,
			*button,
			*twitterLogin,
			*tw_login_imgevent;
	GError *error = NULL;

	/* allocate space for struct */
	DataInput = g_slice_new (AuthWidget);

	/* Set all window options (color, size, position, logo, icon, etc) */
	DataInput->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(DataInput->window), 200, 210);
	gtk_widget_set_size_request (DataInput->window, 200, 210);
	gtk_window_set_title (GTK_WINDOW(DataInput->window), "Nuovo Utente");
	gtk_container_set_border_width (GTK_CONTAINER (DataInput->window), 0);
	gtk_window_set_position(GTK_WINDOW(DataInput->window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(DataInput->window), ICON_ADDUSER, &error);

	/* Attach twitter-login image */
	twitterLogin = gtk_image_new_from_file (ICON_SIGNIN);
	tw_login_imgevent = gtk_event_box_new ();
	gtk_container_add (GTK_CONTAINER (tw_login_imgevent), twitterLogin);
	gtk_table_attach (GTK_TABLE (table), tw_login_imgevent, 0, 10, 1, 3, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);

	/* Call oAuth function */
	g_signal_connect (G_OBJECT (tw_login_imgevent), "button_press_event", G_CALLBACK(tokenTempBrowser), NULL);

	/* Attach Box for PIN */
	label = gtk_label_new ("Inserisci PIN");
	DataInput->pin = gtk_entry_new ();
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	gtk_entry_set_text (GTK_ENTRY (DataInput->pin), "");
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 3, 5, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), DataInput->pin, 1, 9, 5, 6, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);

	/* Press Button and call function for verify PIN */
	button = gtk_button_new_with_label ("Crea Account");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,7, 9, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_container_add (GTK_CONTAINER (DataInput->window), table);
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(gtkAccessToken), G_OBJECT(DataInput));

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (DataInput->window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (DataInput->window);
}

/*
 * Get PIN from GTK_ENTRY
 * And call Validate PIN function
 *
 */
void gtkAccessToken(){

	int correctVerify;

	/* Get text from GTK_Entry*/
	const char *pin = gtk_entry_get_text (GTK_ENTRY (DataInput->pin));

	//Validate PIN
	correctVerify = tokenAccess(pin);

	printf("\ncorrectVerify= %i",correctVerify);
	if(correctVerify == 1) gtk_window_error("Error: bad Input!");


	if(correctVerify == 0)gtk_widget_destroy(GTK_WIDGET (DataInput->window));

}
