/*
 *	TwitCrusader - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  PTKDev, RoxShannon
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
 * 		IRC: chat.freenode.net at #teamtwc
 */

#include "include/gtkfunctions.h"



/*
 * Return Pressed Key of Keyboard
 * Exemple if(pKey->keyval == GDK_Return) if you press ENTER key
 */

gboolean gtkOnKeyPress (GtkWidget * window, GdkEventKey* pKey, gpointer userdata){

	if (pKey->type == GDK_KEY_PRESS){

		g_print("%i\n", pKey->keyval);

		switch (pKey->keyval)
		{
		case GDK_Escape :
			gtk_main_quit ();
			break;
		}
	}

	return FALSE;
}

/*
 * Get PIN from GTK_ENTRY
 * And call Validate PIN function
 * 
 */
void gtkAccessToken(GtkButton *button, AuthWidget *DataInput){

	int correctVerify;

	/* Get text from GTK_Entry*/
	const char *pin = gtk_entry_get_text (GTK_ENTRY (DataInput->pin));

	//Validate PIN
	correctVerify = tokenAccess(pin);

	printf("\ncorrectVerify= %i",correctVerify);
	if(correctVerify == 1) windowError("Error: bad Input!");


	if(correctVerify == 0)destroyGtk(button, DataInput->window);

}

/*
 * Get Buffer from TextArea and send tweet if user press ENTER on keyboard
 * 
 */
gboolean gtkSendTweet(GtkWidget *TextArea, GdkEventKey *pKey, GtkTextBuffer *tweetBuffer){

	GtkTextIter start,
	end;
	char *msg = NULL;
	int send = 1;

	/* Get start position of cursor and final position */
	gtk_text_buffer_get_start_iter (tweetBuffer, &start);
	gtk_text_buffer_get_end_iter (tweetBuffer, &end);

	/* Casting buffer to char */
	msg = gtk_text_buffer_get_text(tweetBuffer, &start, &end, TRUE);

	/* If user press ENTER on keyboard Send Tweet and clean TextArea*/
	if(pKey->keyval == GDK_Return){

		gtk_statusbar_push (GTK_STATUSBAR(StatusBar.message), 0, "Invio In Corso...");

		//SendTweet
		send = SendTweet(msg);

		if(send == 0 || send == 1){ 
			gtk_statusbar_push (GTK_STATUSBAR(StatusBar.message), 0, "Tweet Non Inviato!");
		} else {
			gtk_statusbar_push (GTK_STATUSBAR(StatusBar.message), 0, "Tweet Inviato!");
			gtk_text_buffer_delete(tweetBuffer, &start, &end);
		}

		//Clean TextArea


		return 1; // fix cursor (return to previous line)
	}

	return 0;

}

/*
 * Count char from TextArea 
 * Tweet have 140 to 0 char
 * 
 */
void updateStatusBar(GtkTextBuffer *buffer,GtkStatusbar *statusbar){
	gchar *msg;
	gint tot_char;
	GtkTextIter iter;

	/* Get message from statusbar and position */
	gtk_statusbar_pop(statusbar, 0);
	gtk_text_buffer_get_iter_at_mark(buffer,&iter, gtk_text_buffer_get_insert(buffer));

	/*Count input char */
	tot_char = 139 - gtk_text_iter_get_line_offset(&iter);
	tot_char = tot_char - gtk_text_iter_get_line(&iter);
	msg = g_strdup_printf("%d", tot_char+1);
	if(tot_char <= 0){
		msg = g_strdup_printf("%d", 0);
		gtk_text_buffer_backspace(buffer, &iter, TRUE, TRUE);
	}

	/* Push numer of char to statusbar */
	gtk_statusbar_push(statusbar, 0, msg);
	g_free(msg);

}

/*
 * Change TAB (for setting window) 
 * 
 */
void gtkSwitchPage (GtkButton *button, GtkNotebook *notebook){
	if (gtk_notebook_get_current_page (notebook) == 0)
	{
		gtk_notebook_set_current_page (notebook, 1);
	}else{
		gtk_notebook_set_current_page (notebook, 0);
	}
}

/*
 * Setting GTK Window
 * 
 */

void gtkDeleteAccount(GtkButton *button, gpointer window){
	if(strcmp(user.consumerKey, " ") != 0 && 
			strcmp(user.consumerSecretKey, " ") != 0 && 
			strcmp(user.token, " ") != 0 &&
			strcmp(user.secretToken, " ") != 0){
		deleteAccount();
		destroyGtk(button,window);
		windowOption();
	}
}

void gtkConnect(GtkButton *button, gpointer window){

	if(readUserFile()==0){
		updateGtk(button, window);
	}
}

void gtkDisconnect(GtkButton *button, gpointer window){

	disconnect();

	updateGtk(button, window);
}

void gtkAddUser(GtkButton *button, gpointer window){
	if(windowAddUser()==0){
		destroyGtk(button, window);
	}
}

void gtkRefreshswitchTimeLine(GtkWidget *table_into, gpointer window){

	int rows = 0, cols;
	char *avatarFile;

	GtkWidget *nick,
	*tweet,
	*avatar,
	*align;

	if(strcmp(user.screenName, " ") != 0 && strcmp(user.id, " ") != 0 ){
		switchTimeLine(1);
	}else {
		switchTimeLine(2);
	}

	for (cols=0; cols < 20; rows = rows + 4, cols++) {
		asprintf(&avatarFile, "%s%s", progPath.avatarDir, timeline[cols].user.screen_name);
		getCURL(timeline[cols].user.profile_image_url,avatarFile);
		//getWGET(timeline[cols].user.profile_image_url,avatarFile);
		avatar = gtk_image_new_from_file (timeline[cols].user.profile_image);
		nick = gtk_label_new (timeline[cols].user.screen_name);
		tweet = gtk_label_new (timeline[cols].text);

		gtk_table_attach (GTK_TABLE (table_into), avatar, 0, 1,rows, rows + 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);
		gtk_label_set_justify(GTK_LABEL(nick),GTK_JUSTIFY_LEFT);
		align = gtk_alignment_new(0.0, 0.5, 0.0, 0.0);
		gtk_container_add(GTK_CONTAINER(align), nick);
		gtk_table_attach (GTK_TABLE (table_into), align, 1, 10,rows, rows + 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);


		gtk_label_set_justify(GTK_LABEL(tweet),GTK_JUSTIFY_LEFT);
		gtk_label_set_line_wrap(GTK_LABEL(tweet), TRUE);
		align = gtk_alignment_new(0.0, 0.5, 0.0, 0.0);
		gtk_container_add(GTK_CONTAINER(align), tweet);
		gtk_table_attach (GTK_TABLE (table_into ), align, 1, 10,rows + 1, rows + 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);
	}

}

void updateGtk(GtkButton *button, gpointer window)
{
	/* Destroy the widget */
	destroyGtk(button, window);
	windowMain(0, NULL);
}

/*
 * Delete widget for button-event
 */
void destroyGtk(GtkButton *button, gpointer widget)
{
	/* Destroy the widget */
	gtk_widget_destroy (GTK_WIDGET (widget));
}

