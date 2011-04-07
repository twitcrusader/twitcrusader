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

// Setting Switch GTKNotebook
void switch_page (GtkButton *button, GtkNotebook *notebook)
{
	if (gtk_notebook_get_current_page (notebook) == 0)
	{
		gtk_notebook_set_current_page (notebook, 1);
	}else{
		gtk_notebook_set_current_page (notebook, 0);
	}
}

// Setting
void windows_setting()
{
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
	
	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), PACKAGE_PIXMAP_DIR"/setting.png", &error);
	
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
