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

#include "include/windows.h"

void windowError(char* error_msg){

	GtkWidget *window,
	*label,
	*table = gtk_table_new (5, 10, TRUE),
	*button = gtk_button_new_with_label ("Close");
	GError *error = NULL;

	/* Set all window options (color, size, position, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 200, 150);
	gtk_widget_set_size_request (window, 200, 150);
	gtk_window_set_title (GTK_WINDOW(window), "Error!");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_CLOSE , &error);

	/* Error Message */
	label = gtk_label_new (error_msg);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 1, 3, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), button, 0, 10, 4, 5, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (button), "clicked",  G_CALLBACK (destroyGtk), G_OBJECT (window));

	/* Attach tabke at window container */
	gtk_container_add (GTK_CONTAINER (window), table);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (window);

}

void windowOption(){

	GtkWidget *window,
	*notebook = gtk_notebook_new (),
	*settingMenu = NULL,
	*table = gtk_table_new (7, 10, TRUE),
	*label = NULL,
	*combo = NULL,
	*button = NULL;
	GList *itemsAccount = NULL;
	GError *error = NULL;

	readUserFile();

	/* Set all window options (color, size, position, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 300);
	gtk_widget_set_size_request (window, 310, 300);
	gtk_window_set_title (GTK_WINDOW(window), "Opzioni");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_SETTINGS, &error);
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

	/* Set all functions of Account TAB */
	table = gtk_table_new (7, 10, TRUE);
	combo = gtk_combo_new ();
	settingMenu = gtk_label_new ("Account");


	label = gtk_label_new ("Twitter's Account:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	itemsAccount = g_list_append (itemsAccount, user.screenName); //Non  stampa il nome!
	gtk_combo_set_popdown_strings (GTK_COMBO (combo), itemsAccount);

	/* Attach all gtk-widget at table */
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 0, 1, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), combo, 1, 9, 1, 2, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);

	if(readUserFile()==0){
		button = gtk_button_new_with_label ("Elimina");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
		g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtkDeleteAccount), G_OBJECT (window));
	}else{
		button = gtk_button_new_with_label ("Nuovo");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
		g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtkAddUser), G_OBJECT (window));
	}

	/* Set switch-TAB signal */
	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (gtkSwitchPage), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, settingMenu);


	/* Attach tab-notebook at window container */
	gtk_container_add (GTK_CONTAINER (window), notebook);

	/* CALLBACK: exit event and Widget Show */
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (window);

}

/*
 * About window
 *
 */
void windowCredits(){

	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(ICON_ABOUT, NULL);
	GtkWidget *dialog = gtk_about_dialog_new();
	GError *error = NULL;

	/* Set all window options (color, size, position, logo, icon, etc) */
	gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "TwitCrusader");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) PTKDev, RoxShannon, freddy_156");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Basato su librerie GTK e semplicità!\n\nVersion: "TWC_VERSION""TWC_VERSION_STATUS);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://www.twitcrusader.org/");
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), ICON_STAR, &error);
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
	g_object_unref(pixbuf), pixbuf = NULL;

	/* CALLBACK: exit event and Widget Show */
	gtk_dialog_run(GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);

}

/*
 * Upgrade Window
 * Check Updates from vebsite http://www.twitcrusader.org and get file version.php
 *
 */
void windowUpgrade(){

	FILE* checkLatesVersion = NULL;
	char bufferLatesVersion[10];
	GtkWidget *window,
	*lastVersionMSG = gtk_label_new ("Last Version: "),
	*lastVersionCheck,
	*currentVersionMSG = gtk_label_new ("Current Version: "),
	*currentVersionCheck = gtk_label_new (TWC_VERSION""TWC_VERSION_STATUS),
	*table = gtk_table_new (8, 10, TRUE),
	*button = gtk_button_new_with_label ("Close");
	GError *error = NULL;

	/* Check version with downloaded file */
	strcpy(bufferLatesVersion, downloadVersion());


	/* Set all window options (color, size, position, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 300, 200);
	gtk_widget_set_size_request (window, 300, 200);
	gtk_window_set_title (GTK_WINDOW(window), "Check Updates");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_UPGRADE, &error);

	/* Attach All Widget */
	lastVersionCheck = gtk_label_new (bufferLatesVersion);
	gtk_table_attach (GTK_TABLE (table), currentVersionMSG, 0, 6, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), currentVersionCheck, 6, 9, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionMSG, 0, 5, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionCheck, 6, 9, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), button, 1, 9, 5, 7, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (button), "clicked",  G_CALLBACK (destroyGtk), G_OBJECT (window));

	/* Attach tabke at window container */
	gtk_container_add (GTK_CONTAINER (window), table);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (window);

}

int windowAddUser()
{
	GtkWidget *table = gtk_table_new (10, 10, TRUE),
			*label,
			*button,
			*twitterLogin,
			*tw_login_imgevent;
	GError *error = NULL;
	AuthWidget *DataInput;

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
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(gtkAccessToken), DataInput);

	/* Exit event and Widget Show */
	g_signal_connect (G_OBJECT (DataInput->window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (DataInput->window);
	return 0;
}


/*
 * Windows Main
 * Twitter TimeLine Content
 *
 */

int windowMain(int argc, char **argv){
	g_thread_init (NULL);
	gdk_threads_init ();
	gtk_init (&argc, &argv);

	char *statusLabel;

	GError *error = NULL;
	GtkWidget *window,
	*table,
	*scroll,
	*icon_menu,
	*table_into,
	*scrolled_window,
	*menu_bar,
	*layout,
	*toolbar,
	*statusbar,
	*statusbar_char,
	*new_button,
	*text,
	*file_menu_obj,
	*file_menu_root,
	*file_menu_items,
	*aiuto_menu_obj,
	*aiuto_menu_root,
	*aiuto_menu_items;

	GtkTextBuffer *tweetBuffer;

	createDir();

	/* Set all window options (color, size, position, logo, icon, etc) */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 315, 650);
	gtk_widget_set_size_request (window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(window), "TwitCrusader");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_FAVICON, &error);

	/* GTK Widget: Menu */
	file_menu_obj = gtk_menu_new();
	aiuto_menu_obj = gtk_menu_new();

	/* SuBMenu File
	 * Fix Icons Linux
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
	 * */
	file_menu_items = gtk_image_menu_item_new_with_label("Connetti");
	icon_menu = gtk_image_new_from_file(ICON_ADDUSER);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtkConnect), G_OBJECT (window));
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu_obj), file_menu_items);

	file_menu_items = gtk_image_menu_item_new_with_label("Disconnetti");
	icon_menu = gtk_image_new_from_file(ICON_ADDUSER);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtkDisconnect), G_OBJECT (window));
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu_obj), file_menu_items);

	file_menu_items = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu_obj), file_menu_items);

	file_menu_items = gtk_image_menu_item_new_with_label("Opzioni");
	icon_menu = gtk_image_new_from_file(ICON_SETTINGS);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windowOption), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu_obj), file_menu_items);

	file_menu_items = gtk_image_menu_item_new_with_label("Esci");
	icon_menu = gtk_image_new_from_file(ICON_CLOSE);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtk_main_quit), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu_obj), file_menu_items);

	file_menu_root = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (file_menu_root), file_menu_obj);

	/* SubMenu: Help */
	aiuto_menu_items = gtk_image_menu_item_new_with_label("Updates");
	icon_menu = gtk_image_new_from_file(ICON_UPGRADE);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (aiuto_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (aiuto_menu_items), "activate", G_CALLBACK (windowUpgrade), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(aiuto_menu_obj), aiuto_menu_items);

	aiuto_menu_items = gtk_image_menu_item_new_with_label("Informazioni");
	icon_menu = gtk_image_new_from_file(ICON_STAR);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (aiuto_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (aiuto_menu_items), "activate", G_CALLBACK (windowCredits), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(aiuto_menu_obj), aiuto_menu_items);

	aiuto_menu_root = gtk_menu_item_new_with_label("Aiuto");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (aiuto_menu_root), aiuto_menu_obj);

	/* Set Layout Position */
	layout = gtk_vbox_new(0, 1);
	gtk_container_add(GTK_CONTAINER(window), layout);
	menu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(layout), menu_bar, FALSE, FALSE, 0);
	gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), file_menu_root);
	gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), aiuto_menu_root);

	/* Status Bar */
	statusbar = gtk_statusbar_new ();
	StatusBar.message = GTK_STATUSBAR(statusbar);
	gtk_statusbar_set_has_resize_grip (StatusBar.message, TRUE);


	if(strcmp(user.screenName, " ") == 0 && strcmp(user.id, " ") == 0 ){
		statusLabel="Disconnect..";
	}else{
		statusLabel="Connect..";
	}

	gtk_statusbar_push (StatusBar.message, 0, statusLabel);

	gtk_box_pack_end (GTK_BOX (layout), statusbar, FALSE, FALSE, 0);

	/* GTK Widget: Twitter Menu */
	toolbar = gtk_toolbar_new ();
	gtk_box_pack_end (GTK_BOX (layout), toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

	/* Twitter Menu: Buttons */
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_HOME);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_UPDATE);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	gtk_signal_connect_object (GTK_OBJECT (new_button), "clicked",
	                               GTK_SIGNAL_FUNC(updateGtk),
	                               GTK_OBJECT (window));

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_MENTION);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_DM);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_FAVORITES);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_LINK);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_PHOTO);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	/* Status Bar: Twitter 140char */
	statusbar_char = gtk_statusbar_new ();
	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(statusbar_char), FALSE);
	gtk_statusbar_push (GTK_STATUSBAR(statusbar_char), 0, "140");
	gtk_box_pack_end (GTK_BOX (layout), statusbar_char, FALSE, FALSE, 0);

	/* Table Content Tweet/Mentions */
	table = gtk_table_new (9, 3, TRUE);
	gtk_container_add(GTK_CONTAINER(layout), table);

	/* Scrolled */
	table_into = gtk_table_new (1, 3, TRUE);
	scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
	gtk_table_attach (GTK_TABLE (table), scrolled_window, 0, 3, 0, 8, GTK_FILL,GTK_FILL, 0, 0);
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_window), table_into);

	// Read Timeline
	gdk_threads_enter ();
		gtkRefreshswitchTimeLine(table_into, window);
	gdk_threads_leave ();

	// TextArea + Scrollbar
	scroll = gtk_scrolled_window_new(NULL,NULL);
	gtk_table_attach (GTK_TABLE (table), scroll, 0, 3,8, 9, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),GTK_POLICY_NEVER,GTK_POLICY_AUTOMATIC);
	text = gtk_text_view_new();
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text), TRUE);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(text), GTK_WRAP_WORD_CHAR);
	tweetBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));
	gtk_text_buffer_set_text (tweetBuffer, "", -1);
	g_signal_connect(tweetBuffer, "changed", G_CALLBACK(updateStatusBar), statusbar_char);
	g_signal_connect(text, "key-press-event", G_CALLBACK(gtkSendTweet), tweetBuffer);
	gtk_container_add(GTK_CONTAINER(scroll), text);


	/* CALLBACK: exit event */
	g_signal_connect (window, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	// Widget Show
	gtk_widget_show_all (window);

	//Exist Config File?
	if(fopen (progPath.configFile, "r")==NULL) windowAddUser();

	//Show GTK Main
	gdk_threads_enter();
	gtk_main ();
	gdk_threads_leave ();

	return 0;
}
