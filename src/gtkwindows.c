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
*/

#include "gtkwindows.h"

gboolean on_key_press (GtkWidget * window, GdkEventKey* pKey, gpointer userdata){

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

char* access_token_gtk(GtkButton *button, AuthWidget *DataInput){
	const char *pin = gtk_entry_get_text (GTK_ENTRY (DataInput->pin));

	return access_token(pin);
}

gboolean send_tweet_gtk(GtkWidget *textarea, GdkEventKey *pKey, GtkTextBuffer *tweetbuffer){

	GtkTextIter start;
	GtkTextIter end;

	gtk_text_buffer_get_start_iter (tweetbuffer, &start);
	gtk_text_buffer_get_end_iter (tweetbuffer, &end);
	char *msg = gtk_text_buffer_get_text(tweetbuffer, &start, &end, TRUE);

	if(pKey->keyval == GDK_Return){
		send_tweet(msg);
	}

	return 0;

}

void update_statusbar(GtkTextBuffer *buffer,GtkStatusbar  *statusbar){
	gchar *msg;
	gint tot_char;
	GtkTextIter iter;

	gtk_statusbar_pop(statusbar, 0);

	gtk_text_buffer_get_iter_at_mark(buffer,&iter, gtk_text_buffer_get_insert(buffer));

	tot_char = 139 - gtk_text_iter_get_line_offset(&iter);
	tot_char = tot_char - gtk_text_iter_get_line(&iter);
	msg = g_strdup_printf("%d", tot_char+1);

	gtk_statusbar_push(statusbar, 0, msg);

	g_free(msg);
}

void switch_page (GtkButton *button, GtkNotebook *notebook){
	if (gtk_notebook_get_current_page (notebook) == 0)
	{
		gtk_notebook_set_current_page (notebook, 1);
	}else{
		gtk_notebook_set_current_page (notebook, 0);
	}
}

// Setting
void windows_setting(){
	// Variables
	GtkWidget *window, *notebook, *setting_menu, *table, *label, *entry_nick,*button;
	GError *error = NULL;

	// Standard GTK Windows Declaration
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 300);
	gtk_widget_set_size_request (window, 310, 300);
	gtk_window_set_title (GTK_WINDOW(window), "Opzioni");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_SETTINGS, &error);

	//Add Switch GTKNotebook
	notebook = gtk_notebook_new ();
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

	// GTK Windows Declaration: Account
	setting_menu = gtk_label_new ("Account");
	// GTK Windows Declaration: Content
	table = gtk_table_new (7, 10, TRUE);
	label = gtk_label_new ("Account Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_account = NULL;
	items_account = g_list_append (items_account, "@user1");
	items_account = g_list_append (items_account, "@user2");
	items_account = g_list_append (items_account, "@user3");
	items_account = g_list_append (items_account, "@user4");
	items_account = g_list_append (items_account, "@user5");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_account);

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			0, 1, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			1, 2, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);


	button = gtk_button_new_with_label ("Salva");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
			5, 6, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);

	// GTK Windows Declaration: Services
	setting_menu = gtk_label_new ("Servizi");
	// GTK Windows Declaration: Content
	table = gtk_table_new (11, 10, TRUE);
	label = gtk_label_new ("Host Immagini:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_img = NULL;
	items_img = g_list_append (items_img, "twitpic");
	items_img = g_list_append (items_img, "yfrog");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_img);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			0, 1, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			1, 2, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	label = gtk_label_new ("Host Video:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_vid = NULL;
	items_vid = g_list_append (items_vid, "twitvid");
	items_vid = g_list_append (items_vid, "yfrog");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_vid);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			2, 3, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			3, 4, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	label = gtk_label_new ("Text Shortener:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_txt = NULL;
	items_txt = g_list_append (items_txt, "twitlonger");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_txt);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			4, 5, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			5, 6, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	label = gtk_label_new ("URL Shortener:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_link = NULL;
	items_link = g_list_append (items_link, "bit.ly");
	items_link = g_list_append (items_link, "ow.ly");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_link);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			6, 7, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			7, 8, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	button = gtk_button_new_with_label ("Salva");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
			9, 10, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);

	// GTK Windows Declaration: Skin
	setting_menu = gtk_label_new ("Aspetto");
	// GTK Windows Declaration: Content
	table = gtk_table_new (7, 10, TRUE);
	label = gtk_label_new ("Tema Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_skin = NULL;
	items_skin = g_list_append (items_skin, "default");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_skin);

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			0, 1, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			1, 2, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	label = gtk_label_new ("Lingua Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_lang = NULL;
	items_lang = g_list_append (items_lang, "italian");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_lang);

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			2, 3, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			3, 4, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	button = gtk_button_new_with_label ("Salva");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
			5, 6, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);

	// GTK Windows Declaration: Notify
	setting_menu = gtk_label_new ("Notifiche");
	// GTK Windows Declaration: Content
	table = gtk_table_new (7, 10, TRUE);
	label = gtk_label_new ("Aggiorna Ogni...");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_notify = NULL;
	items_notify = g_list_append (items_notify, "5min");
	items_notify = g_list_append (items_notify, "10min");
	items_notify = g_list_append (items_notify, "15min");
	items_notify = g_list_append (items_notify, "30min");
	items_notify = g_list_append (items_notify, "60min");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_notify);

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			0, 1, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			1, 2, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	label = gtk_label_new ("Tipo Di Notifiche:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_ntype = NULL;
	items_ntype = g_list_append (items_ntype, "Tutto");
	items_ntype = g_list_append (items_ntype, "Timeline");
	items_ntype = g_list_append (items_ntype, "Mentions");
	items_ntype = g_list_append (items_ntype, "Mentions + DM");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_ntype);

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			2, 3, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
			3, 4, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	button = gtk_button_new_with_label ("Salva");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
			5, 6, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);

	gtk_container_add (GTK_CONTAINER (window), notebook);

	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);

	// Widget Show
	gtk_widget_show_all (window);

}

// About
void windows_about(){
	// Variables
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(ICON_ABOUT, NULL);
	GtkWidget *dialog = gtk_about_dialog_new();
	GError *error = NULL;

	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), ICON_STAR, &error);

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

//Sum String
//TwitCrusader - Twitter Key
//TwitCrusader - Twitter SecretKey
//Parser Url
//Twitter Access Token: Authorize TwitCrusader
//Twitter Request Token: Generate URL For PIN
//Twitter oAuth
void windows_adduser()
{
	// Variables
	GtkWidget *window, *table, *label, *button,*twitter_login,*tw_login_imgevent;
	GError *error = NULL;
	AuthWidget *DataInput;

	// allocate space for struct
	DataInput = g_slice_new (AuthWidget);

	// Standard GTK Windows Declaration
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 240);
	gtk_widget_set_size_request (window, 310, 240);
	gtk_window_set_title (GTK_WINDOW(window), "Nuovo Utente");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_ADDUSER, &error);

	// Table Content Input
	table = gtk_table_new (10, 10, TRUE);

	twitter_login = gtk_image_new_from_file (ICON_SIGNIN);
	tw_login_imgevent = gtk_event_box_new ();
	gtk_container_add (GTK_CONTAINER (tw_login_imgevent), twitter_login);
	gtk_table_attach (GTK_TABLE (table), tw_login_imgevent, 2, 8,
			1, 3, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (tw_login_imgevent), "button_press_event", G_CALLBACK(oauth_start), NULL);

	label = gtk_label_new ("Inserisci PIN");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	DataInput->pin = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (DataInput->pin), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
			4, 5, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), DataInput->pin, 1, 9,
			5, 6, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);

	button = gtk_button_new_with_label ("Crea Account");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
			7, 9, GTK_FILL | GTK_EXPAND,
			GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_container_add (GTK_CONTAINER (window), table);
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(access_token), DataInput);

	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);

	// Widget Show
	gtk_widget_show_all (window);
}

// New User oAuth Request
int windows_main(int argc, char **argv){
	gtk_init (&argc, &argv);

	// Variables

	char *homeFile = getenv("HOME");

	GError *error = NULL;
	GtkWidget *window,
	*table,
	*scroll,
	*icon_menu,
	*table_into,
	//*tweet,
	//*avatar,
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
	GtkTextBuffer *buffer;

	homeFile=strcat(homeFile, "/.twc/config");

	// Standard GTK Windows Declaration


	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 315, 650);
	gtk_widget_set_size_request (window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(window), "TwitCrusader");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_FAVICON, &error);

	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",
			G_CALLBACK (gtk_main_quit), NULL);

	// GTK Widget: Menu
	file_menu_obj = gtk_menu_new();
	aiuto_menu_obj = gtk_menu_new();

	// SuBMenu File
	/* Fix Icons Linux
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
	 *  */
	file_menu_items = gtk_image_menu_item_new_with_label("Nuovo Utente");
	icon_menu = gtk_image_new_from_file(ICON_ADDUSER);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_adduser), NULL);
	gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);

	file_menu_items = gtk_image_menu_item_new_with_label("Opzioni");
	icon_menu = gtk_image_new_from_file(ICON_SETTINGS);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_setting), NULL);
	gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);

	file_menu_items = gtk_image_menu_item_new_with_label("Esci");
	icon_menu = gtk_image_new_from_file(ICON_CLOSE);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtk_main_quit), NULL);
	gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);

	file_menu_root = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (file_menu_root), file_menu_obj);

	// SubMenu: Help
	aiuto_menu_items = gtk_image_menu_item_new_with_label("Informazioni");
	icon_menu = gtk_image_new_from_file(ICON_STAR);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (aiuto_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (aiuto_menu_items), "activate", G_CALLBACK (windows_about), NULL);
	gtk_menu_append(GTK_MENU (aiuto_menu_obj), aiuto_menu_items);


	aiuto_menu_root = gtk_menu_item_new_with_label("Aiuto");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (aiuto_menu_root), aiuto_menu_obj);

	// Set Layout Position
	layout = gtk_vbox_new(0, 1);
	gtk_container_add(GTK_CONTAINER(window), layout);
	menu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(layout), menu_bar, FALSE, FALSE, 0);
	gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), file_menu_root);
	gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), aiuto_menu_root);

	// Status Bar
	statusbar = gtk_statusbar_new ();
	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(statusbar), TRUE);
	gtk_statusbar_push (GTK_STATUSBAR(statusbar), 0, "TwitCrusader...");
	gtk_box_pack_end (GTK_BOX (layout), statusbar, FALSE, FALSE, 0);

	// GTK Widget: Twitter Menu
	toolbar = gtk_toolbar_new ();
	gtk_box_pack_end (GTK_BOX (layout), toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

	// Twitter Menu: Buttons
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_HOME);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(ICON_UPDATE);
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);

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

	// Status Bar: Twitter 140char
	statusbar_char = gtk_statusbar_new ();
	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(statusbar_char), FALSE);
	gtk_statusbar_push (GTK_STATUSBAR(statusbar_char), 0, "140");
	gtk_box_pack_end (GTK_BOX (layout), statusbar_char, FALSE, FALSE, 0);

	// Table Content Tweet/Mentions
	table = gtk_table_new (9, 3, TRUE);
	gtk_container_add(GTK_CONTAINER(layout), table);

	// Scrolled
	table_into = gtk_table_new (1, 3, TRUE);
	//int rows, cols;
	scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_table_attach (GTK_TABLE (table), scrolled_window, 0, 3, 0, 8, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolled_window), table_into);
	/*for ( rows = 0; rows < 40; rows = rows + 4 ) {
       for ( cols = 0; cols < 3; cols++ ) {
            avatar = gtk_image_new_from_file ("");
		   	tweet = gtk_label_new ("");
		   	gtk_label_set_justify (GTK_LABEL(tweet),GTK_JUSTIFY_LEFT);
		   	gtk_label_set_line_wrap_mode (GTK_LABEL(tweet), GTK_WRAP_WORD_CHAR);
           gtk_table_attach (GTK_TABLE (table_into ), tweet, 0, 1,rows, rows + 4, GTK_FILL | GTK_EXPAND,GTK_FILL, 0, 0);
            gtk_table_attach (GTK_TABLE (table_into ), tweet, 1, 3,rows, rows + 1, GTK_FILL | GTK_EXPAND,GTK_FILL, 0, 0);
            tweet = gtk_label_new ("");
            gtk_table_attach (GTK_TABLE (table_into ), tweet, 1, 3,rows + 1, rows + 4, GTK_FILL | GTK_EXPAND,GTK_FILL, 0, 0);
       }
	}*/

	// TextArea + Scrollbar
	scroll = gtk_scrolled_window_new(NULL,NULL);
	gtk_table_attach (GTK_TABLE (table), scroll, 0, 3,8, 9, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
	text = gtk_text_view_new();
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(text), GTK_WRAP_WORD_CHAR);
	buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));
	gtk_text_buffer_set_text (buffer, "", -1);
	g_signal_connect(buffer, "changed", G_CALLBACK(update_statusbar), statusbar_char);
	g_signal_connect(text, "key-press-event", G_CALLBACK(send_tweet), buffer);
	gtk_container_add(GTK_CONTAINER(scroll), text);

	// Widget Show
	gtk_widget_show_all (window);

	if(fopen(homeFile,"r")==NULL) windows_adduser();

	gtk_main ();


	return 0;
}
