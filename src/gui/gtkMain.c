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

#include "include/gtkMain.h"

/*
 * Windows Main
 * Twitter TimeLine Content
 *
 */

int windowMain(){
	g_thread_init (NULL);
	gdk_threads_init ();
	gtk_init (0, NULL);

	int rows=0, cols, i;

	struct menu menu1[4];
	menu1[0].name="Connetti";
	menu1[0].icon=ICON_ADDUSER;
	menu1[0].function=G_CALLBACK (gtkConnect);

	menu1[1].name="Disconnetti";
	menu1[1].icon=ICON_ADDUSER;
	menu1[1].function=G_CALLBACK (gtkDisconnect);

	menu1[2].name="Opzioni";
	menu1[2].icon=ICON_SETTINGS;
	menu1[2].function=G_CALLBACK (windowOption);

	menu1[3].name="Esci";
	menu1[3].icon=ICON_CLOSE;
	menu1[3].function=G_CALLBACK (gtk_main_quit);

	struct menu menu2[2];

	menu2[0].name="Updates";
	menu2[0].icon=ICON_UPGRADE;
	menu2[0].function=G_CALLBACK (windowUpgrade);

	menu2[1].name="Informazioni";
	menu2[1].icon=ICON_STAR;
	menu2[1].function=G_CALLBACK (windowCredits);



	/* Set all window options (color, size, position, logo, icon, etc) */
	mainWindow.window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(mainWindow.window), 315, 650);
	gtk_widget_set_size_request (mainWindow.window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(mainWindow.window), "TwitCrusader");
	gtk_container_set_border_width (GTK_CONTAINER (mainWindow.window), 0);
	gtk_window_set_position(GTK_WINDOW(mainWindow.window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(mainWindow.window), ICON_FAVICON, &mainWindow.error);

	/* GTK Widget: Menu */
	mainWindow.file_menu_obj = gtk_menu_new();
	mainWindow.aiuto_menu_obj = gtk_menu_new();

	/* SuBMenu File
	 * Fix Icons Linux
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
	 * */

	for(i=0;i<4;i++){
		mainWindow.file_menu_items = gtk_image_menu_item_new_with_label(menu1[i].name);
		mainWindow.icon_menu = gtk_image_new_from_file(menu1[i].icon);
		gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (mainWindow.file_menu_items), mainWindow.icon_menu);
		g_signal_connect (G_OBJECT (mainWindow.file_menu_items), "activate", menu1[i].function, NULL);
		gtk_menu_shell_append(GTK_MENU_SHELL(mainWindow.file_menu_obj), mainWindow.file_menu_items);
		if(i==2){
			mainWindow.file_menu_items = gtk_separator_menu_item_new();
			gtk_menu_shell_append(GTK_MENU_SHELL(mainWindow.file_menu_obj), mainWindow.file_menu_items);
		}
	}

	/* SubMenu: Help */
	for(i=0;i<2;i++){
		mainWindow.aiuto_menu_items = gtk_image_menu_item_new_with_label(menu2[i].name);
		mainWindow.icon_menu = gtk_image_new_from_file(menu2[i].icon);
		gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (mainWindow.aiuto_menu_items), mainWindow.icon_menu);
		g_signal_connect (G_OBJECT (mainWindow.aiuto_menu_items), "activate", menu2[i].function, NULL);
		gtk_menu_shell_append(GTK_MENU_SHELL(mainWindow.aiuto_menu_obj), mainWindow.aiuto_menu_items);

	}

	mainWindow.file_menu_root = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (mainWindow.file_menu_root), mainWindow.file_menu_obj);
	mainWindow.aiuto_menu_root = gtk_menu_item_new_with_label("Aiuto");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (mainWindow.aiuto_menu_root), mainWindow.aiuto_menu_obj);

	/* Set Layout Position */
	mainWindow.layout = gtk_vbox_new(0, 1);
	gtk_container_add(GTK_CONTAINER(mainWindow.window), mainWindow.layout);
	mainWindow.menu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(mainWindow.layout), mainWindow.menu_bar, FALSE, FALSE, 0);
	gtk_menu_bar_append(GTK_MENU_BAR (mainWindow.menu_bar), mainWindow.file_menu_root);
	gtk_menu_bar_append(GTK_MENU_BAR (mainWindow.menu_bar), mainWindow.aiuto_menu_root);

	/* Status Bar */
	mainWindow.statusbar = gtk_statusbar_new ();
	StatusBar.message = GTK_STATUSBAR(mainWindow.statusbar);
	gtk_statusbar_set_has_resize_grip (StatusBar.message, TRUE);


	if(strcmp(user.screenName, " ") == 0 && strcmp(user.id, " ") == 0 ){
		mainWindow.statusLabel="Disconnect..";
	}else{
		mainWindow.statusLabel="Connect..";
	}

	gtk_statusbar_push (StatusBar.message, 0, mainWindow.statusLabel);

	gtk_box_pack_end (GTK_BOX (mainWindow.layout), mainWindow.statusbar, FALSE, FALSE, 0);

	/* GTK Widget: Twitter Menu */
	mainWindow.toolbar = gtk_toolbar_new ();
	gtk_box_pack_end (GTK_BOX (mainWindow.layout), mainWindow.toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (mainWindow.toolbar), GTK_TOOLBAR_ICONS);
	gtk_toolbar_get_icon_size (GTK_TOOLBAR (mainWindow.toolbar));

	/* Twitter Menu: Buttons */
	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_UPDATE);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);
	gdk_threads_enter ();
	gtk_signal_connect_object (GTK_OBJECT (mainWindow.new_button), "clicked", GTK_SIGNAL_FUNC(updateGtk), NULL);
	gdk_threads_leave ();

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_HOME);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button), mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_MENTION);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_DM);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_FAVORITES);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_LINK);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	mainWindow.new_button = gtk_button_new();
	mainWindow.icon_menu = gtk_image_new_from_file(ICON_PHOTO);
	gtk_button_set_image(GTK_BUTTON(mainWindow.new_button),mainWindow.icon_menu);
	gtk_container_add (GTK_CONTAINER (mainWindow.toolbar), mainWindow.new_button);

	/* Status Bar: Twitter 140char */
	mainWindow.statusbar_char = gtk_statusbar_new ();
	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(mainWindow.statusbar_char), FALSE);
	gtk_statusbar_push (GTK_STATUSBAR(mainWindow.statusbar_char), 0, "140");
	gtk_box_pack_end (GTK_BOX (mainWindow.layout), mainWindow.statusbar_char, FALSE, FALSE, 0);

	/* Table Content Tweet/Mentions */
	mainWindow.table = gtk_table_new (9, 3, TRUE);
	gtk_container_add(GTK_CONTAINER(mainWindow.layout), mainWindow.table);

	/* Scrolled */
	mainWindow.table_into = gtk_table_new (1, 3, TRUE);
	mainWindow.scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (mainWindow.scrolled_window),GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
	gtk_table_attach (GTK_TABLE (mainWindow.table), mainWindow.scrolled_window, 0, 3, 0, 8, GTK_FILL,GTK_FILL, 0, 0);
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (mainWindow.scrolled_window), mainWindow.table_into);

	for (cols=0; cols < 20; rows = rows + 4, cols++) {
		mainWindow.avatar = gtk_image_new_from_file (timeline[cols].user.profile_image);
		mainWindow.nick = gtk_label_new (timeline[cols].user.screen_name);
		mainWindow.tweet = gtk_label_new (timeline[cols].text);

		gtk_table_attach (GTK_TABLE (mainWindow.table_into), mainWindow.avatar, 0, 1,rows, rows + 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);
		gtk_label_set_justify(GTK_LABEL(mainWindow.nick),GTK_JUSTIFY_LEFT);
		mainWindow.align = gtk_alignment_new(0.0, 0.5, 0.0, 0.0);
		gtk_container_add(GTK_CONTAINER(mainWindow.align), mainWindow.nick);
		gtk_table_attach (GTK_TABLE (mainWindow.table_into), mainWindow.align, 1, 10,rows, rows + 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);


		gtk_label_set_justify(GTK_LABEL(mainWindow.tweet),GTK_JUSTIFY_LEFT);
		gtk_label_set_line_wrap(GTK_LABEL(mainWindow.tweet), TRUE);
		mainWindow.align = gtk_alignment_new(0.0, 0.5, 0.0, 0.0);
		gtk_container_add(GTK_CONTAINER(mainWindow.align), mainWindow.tweet);
		gtk_table_attach (GTK_TABLE (mainWindow.table_into ), mainWindow.align, 1, 10,rows + 1, rows + 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 0, 0);
	}

	// TextArea + Scrollbar
	mainWindow.scroll = gtk_scrolled_window_new(NULL,NULL);
	gtk_table_attach (GTK_TABLE (mainWindow.table), mainWindow.scroll, 0, 3,8, 9, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(mainWindow.scroll),GTK_POLICY_NEVER,GTK_POLICY_AUTOMATIC);
	mainWindow.text = gtk_text_view_new();
	gtk_text_view_set_editable(GTK_TEXT_VIEW(mainWindow.text), TRUE);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(mainWindow.text), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(mainWindow.text), GTK_WRAP_WORD_CHAR);
	mainWindow.tweetBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (mainWindow.text));
	gtk_text_buffer_set_text (mainWindow.tweetBuffer, "", -1);
	g_signal_connect(mainWindow.tweetBuffer, "changed", G_CALLBACK(updateStatusBar), mainWindow.statusbar_char);
	g_signal_connect(mainWindow.text, "key-press-event", G_CALLBACK(gtkSendTweet), mainWindow.tweetBuffer);
	gtk_container_add(GTK_CONTAINER(mainWindow.scroll), mainWindow.text);


	/* CALLBACK: exit event */
	g_signal_connect (mainWindow.window, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (mainWindow.window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	// Widget Show
	gtk_widget_show_all (mainWindow.window);

	//Exist Config File?
	if(fopen (progPath.configFile, "r")==NULL) windowAddUser();

	//Show GTK Main
	gdk_threads_enter();
	gtk_main ();
	gdk_threads_leave ();

	return 0;
}


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


	if(correctVerify == 0)destroyGtk(DataInput->window);

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

		destroyGtk(mainWindow.window);

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
		destroyGtk(mainWindow.window);
	}
}

void gtkRefreshSwitchTimeLine(){

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

		gtkRefreshSwitchTimeLine(mainWindow.table_into, mainWindow.window);


	/* Destroy the widget */
	destroyGtk(mainWindow.window);
	windowMain();
}

/*
 * Delete widget for button-event
 */
void destroyGtk(){
	/* Destroy the widget */
	gtk_widget_destroy (GTK_WIDGET (mainWindow.window));
}


