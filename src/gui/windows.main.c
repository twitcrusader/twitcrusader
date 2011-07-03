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

/* Headers */
#include "inc/windows.main.h"
#include "inc/windows.credits.h"
#include "inc/icons.h"

GtkWidget* GtkMenuItemCreate(GtkWidget* menu, const gchar const* title, const gchar const* imagePath)
{
	GtkWidget * item = gtk_image_menu_item_new_with_label(title);
	GtkWidget * image = gtk_image_new_from_file (imagePath);

	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item), image);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);

return item;
}


GtkWidget* GtkMenuCreate(GtkWidget* menuBar, const gchar const* name)
{
	GtkWidget *menu = gtk_menu_new();
	GtkWidget *item = gtk_menu_item_new_with_label(name);
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), item);

return menu;
}

GtkWidget* GtkMenuBarCreate()
{
	GtkWidget *menubar = gtk_menu_bar_new(),
			  *menu,
			  *item;

	menu = GtkMenuCreate(menubar, "File");
	
	item = GtkMenuItemCreate(menu, "Settings", ICON_SETTINGS);
	g_signal_connect (G_OBJECT (item), 
					  "activate",
					  G_CALLBACK(gtk_main_quit), 
					  NULL);
	
	item = GtkMenuItemCreate(menu, "Exit", ICON_CLOSE);
	g_signal_connect (G_OBJECT (item), 
					  "activate",
					  G_CALLBACK(gtk_main_quit), 
					  NULL);

	menu = GtkMenuCreate(menubar, "Help");
	item = GtkMenuItemCreate(menu, "Upgrade", ICON_UPGRADE);
	g_signal_connect (G_OBJECT (item), 
					  "activate",
					  G_CALLBACK(gtk_main_quit), 
					  NULL);
					  
	item = GtkMenuItemCreate(menu, "About", ICON_STAR);
	g_signal_connect (G_OBJECT (item), 
					  "activate",
					  G_CALLBACK(GtkCreditsDialogCreate),  
					  NULL);

return menubar;
}

GtkWidget* GtkStatusBarCreate()
{
	GtkWidget* statusbar = gtk_statusbar_new ();

	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), TRUE);
	gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "");

return statusbar;
}

GtkWidget* GtkCountTweetCreate()
{
	GtkWidget *statusbar = gtk_statusbar_new ();

	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), FALSE);
	gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "140");

return statusbar;
}

GtkWidget* GtkScrollingCreate()
{
	GtkWidget *scroll = gtk_scrolled_window_new(NULL,NULL),
		      *scrolltable = gtk_table_new (10, 10, FALSE);
		      
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),GTK_POLICY_NEVER,GTK_POLICY_ALWAYS);
	gtk_container_set_border_width (GTK_CONTAINER (scroll), 0); 
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(scroll), scrolltable); 	
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scroll),GTK_SHADOW_NONE);
	
return scroll;
}

GtkWidget* GtkTextAreaCreate()
{
	GtkWidget *textarea = gtk_text_view_new();
	gtk_text_view_set_editable(GTK_TEXT_VIEW(textarea), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(textarea), GTK_WRAP_WORD_CHAR);
	
return textarea;
}

GtkWidget* GtkTimeLineToolItemBarCreate(gchar *image){
	
	GtkWidget *button,
			  *icon_menu;
	button = gtk_button_new();
	icon_menu = gtk_image_new_from_file(image);
	gtk_button_set_image(GTK_BUTTON(button),icon_menu);
	
return button;
}

GtkWidget* GtkTimeLineToolBarCreate()
{
	GtkWidget *toolbar = gtk_toolbar_new ();
			  
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_HOME));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_UPDATE));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_MENTION));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_DM));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_FAVORITES));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_LINK));
	gtk_container_add (GTK_CONTAINER (toolbar), GtkTimeLineToolItemBarCreate(ICON_PHOTO));
	
return toolbar;
}
 
GtkWidget* GtkWindowMainCreate(){
	/* Variables */
	GtkWidget *window,
			  *container,
			  *menubar,
			  *scolling,
			  *counttweet,
			  *textarea,
			  *tltoolbar,
			  *statusbar;
	GError *error = NULL;
	
	/* Set Window Parameters */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 315, 650);
	gtk_widget_set_size_request (window, 315, 400);
	gtk_window_set_title (GTK_WINDOW(window), "TwitCrusader");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_FAVICON, &error);
	
	/* Create a Main Container*/
	container = gtk_vbox_new (FALSE, 0);
	
	menubar = GtkMenuBarCreate();
	scolling = GtkScrollingCreate();
	counttweet = GtkCountTweetCreate();
	textarea = GtkTextAreaCreate();
	tltoolbar = GtkTimeLineToolBarCreate();
	statusbar = GtkStatusBarCreate();
	
	/* Fix Size */
	gtk_widget_set_size_request(textarea, -1, 60);
	
	gtk_box_pack_start(GTK_BOX(container), menubar, FALSE, TRUE, 0);	
	gtk_box_pack_start(GTK_BOX(container), scolling, TRUE, TRUE, 0);	
	gtk_box_pack_start(GTK_BOX(container), counttweet, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(container), textarea, FALSE, TRUE, 0);	
	gtk_box_pack_start(GTK_BOX(container), tltoolbar, FALSE, TRUE, 0);	
	gtk_box_pack_end(GTK_BOX(container), statusbar, FALSE, TRUE, 0);
	
	
	/* Add Container to Window TopLevel */
	gtk_container_add (GTK_CONTAINER (window), container);
	
	/* Destroy WindowMain() */
	g_signal_connect_swapped(G_OBJECT(window), 
							 "destroy",
							 G_CALLBACK(gtk_main_quit), 
							 G_OBJECT(window));
	
return window;
}

int GtkWindowMain(){
 	g_thread_init (NULL);
	gdk_threads_init ();
	gtk_init (0, NULL);
	
	gtk_widget_show_all(GtkWindowMainCreate());
	
	gdk_threads_enter();
	gtk_main ();
	gdk_threads_leave ();
	
return 0;
}
