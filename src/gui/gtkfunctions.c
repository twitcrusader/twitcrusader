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
void gtkAccessToken(AuthWidget *DataInput){

	int correctVerify;

	/* Get text from GTK_Entry*/
	const char *pin = gtk_entry_get_text (GTK_ENTRY (DataInput->pin));

	//Validate PIN
	correctVerify = tokenAccess(pin);

	printf("\ncorrectVerify= %i",correctVerify);
	if(correctVerify == 1) windowError("Error: bad Input!");


	if(correctVerify == 0)destroyGtk(mainWindow.new_button, DataInput->window);

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
void gtkSwitchPage (GtkNotebook *notebook){
	if (gtk_notebook_get_current_page (notebook) == 0){

		gtk_notebook_set_current_page (notebook, 1);
	}else{

		gtk_notebook_set_current_page (notebook, 0);
	}
}

/*
 * Setting GTK Window
 * 
 */

void gtkDeleteAccount(){

		deleteAccount();

		disconnect();

		destroyGtk();

		windowOption();

}

void gtkConnect(GtkButton *button, gpointer window){

	if(readUserFile()==0){
		updateGtk(button, window);
	}
}

void gtkDisconnect(){

	disconnect();

	updateGtk();
}

void gtkAddUser(){
	if(windowAddUser()==0){
		destroyGtk();
	}
}

void gtkRefreshswitchTimeLine(){

	int i, error=0;

	pthread_t tid;

	if(debug==1) puts("gtkRefreshswitchTimeLine(GtkWidget *table_into, gpointer window)");

	if(strcmp(user.screenName, " ") != 0 && strcmp(user.id, " ") != 0 ){
		error=switchTimeLine(1);
	}else {
		error=switchTimeLine(2);
	}

	if(error==0){
		for(i=0; i<MAX_NUM_TWEETS; i++){
			char *argv[2];
			argv[0]=timeline[i].user.profile_image_url;
			argv[1]=timeline[i].user.profile_image;

			error = pthread_create(&tid, NULL, pull_one_url, (void *)argv);

			if(debug==1){
				if(0 != error)
					fprintf(stderr, "\nCouldn't run thread number %d, errno %d\n", i, error);
				else
					fprintf(stderr, "\nThread %d, gets %s\n", i, argv[0]);
			}

			error = pthread_join(tid, NULL);
			if(debug==1) fprintf(stderr, "\nThread %d terminated\n", i);

		}
	}

}

void updateGtk()
{
	// Read Timeline

		gtkRefreshswitchTimeLine(mainWindow.table_into, mainWindow.window);


	/* Destroy the widget */
	destroyGtk();
	windowMain(0, NULL);
}

/*
 * Delete widget for button-event
 */
void destroyGtk()
{
	/* Destroy the widget */
	gtk_widget_destroy (GTK_WIDGET (mainWindow.window));
}

