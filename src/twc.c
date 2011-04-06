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
#include <gdk/gdkkeysyms.h> 

//TwitCrusader Header File
#include "twc.h"

//Press Enter 
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

// Main
int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);
		
	// Variables
	
	const char *homeFile = getenv("HOME");
	
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
	
	puts(PACKAGE_PIXMAP_DIR);
	
	homeFile=strcat(homeFile, "/.twc");
	
	// Standard GTK Windows Declaration


	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 315, 650);
	gtk_widget_set_size_request (window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(window), "TwitCrusader");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), PACKAGE_PIXMAP_DIR"/favicon.png", &error);
	
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
    icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/add_user.png");
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_adduser), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_items = gtk_image_menu_item_new_with_label("Opzioni");   
    icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/setting.png");
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_setting), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_items = gtk_image_menu_item_new_with_label("Esci");
    icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/close.png");
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtk_main_quit), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_root = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (file_menu_root), file_menu_obj);
    
    // SubMenu: Help
    aiuto_menu_items = gtk_image_menu_item_new_with_label("Informazioni");
    icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/star.png");
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
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/home.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/update.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/mention.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/dm.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/favorites.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/link.png");
	gtk_button_set_image(GTK_BUTTON(new_button),icon_menu);
	gtk_container_add (GTK_CONTAINER (toolbar), new_button);
	
	new_button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(PACKAGE_PIXMAP_DIR"/photo.png");
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
