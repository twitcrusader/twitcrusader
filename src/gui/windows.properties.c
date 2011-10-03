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
#include "inc/windows.properties.h"

void gtk_window_properties(){

	debug_f_start("gtk_window_properties");

	g_list_free (itemsAccount);
	table = gtk_table_new (7, 10, TRUE);
	notebook = gtk_notebook_new ();

	dialog=gtk_dialog_new();
	gtk_window_set_title (GTK_WINDOW(dialog), "Opzioni");
	gtk_container_set_border_width (GTK_CONTAINER (dialog), 0);
	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), ICON_SETTINGS, &error);
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

	/* Set all functions of Account TAB */
	table = gtk_table_new (7, 10, TRUE);
	combo = gtk_combo_new ();
	settingMenu = gtk_label_new ("Account");


	label = gtk_label_new ("Twitter's Account:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	gtk_table_attach (GTK_TABLE (table), label, 1, 9, 0, 1, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);


	if(readUserFile()==0){
		itemsAccount = g_list_append (itemsAccount, user.screenName);
		button = gtk_button_new_with_label ("Elimina");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
		g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtk_delete_account), NULL);

	}else{
		itemsAccount=g_list_alloc ();
		button = gtk_button_new_with_label ("Nuovo");
		gtk_table_attach (GTK_TABLE (table), button, 3, 7, 5, 6, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
		g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (gtk_register), NULL);

	}

	gtk_combo_set_popdown_strings (GTK_COMBO (combo), itemsAccount);
	gtk_table_attach (GTK_TABLE (table), combo, 1, 9, 1, 2, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);

	/* Set switch-TAB signal */
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, settingMenu);


	/* Attach tab-notebook at window container */
	gtk_dialog_add_action_widget(GTK_DIALOG(dialog ), notebook, GTK_RESPONSE_APPLY);

	g_signal_connect_swapped (dialog , "response",G_CALLBACK (gtk_widget_destroy),dialog );

	gtk_widget_show_all (dialog);

	gtk_dialog_run(GTK_DIALOG(dialog));

}

void gtk_delete_account(){

	debug_f_start("gtk_delete_account");

	deleteAccount();

	disconnect();

	gtk_widget_destroy(dialog);

	gtk_window_properties();
}

void gtk_register(){

	debug_f_start("gtk_register");

	gtk_widget_destroy(dialog);
	gtk_window_register();

}
