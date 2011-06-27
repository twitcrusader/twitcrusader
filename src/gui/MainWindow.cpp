/*
 *	 TwitCrusader-GUI is part of TwitCrusader - Twitter Client For Linux Desktop
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

#include "include/MainWindow.h"

namespace std {

MainWindow::MainWindow() {

	Menu m=Menu();

	m.setName("Log In");
	m.setIcon(ICON_ADDUSER);
	m.setFunction(G_CALLBACK(&MainWindow::foo));
	m.setSeparator(false);
	menuFile.push_back(m);

	m.setName("Log Out");
	m.setIcon(ICON_ADDUSER);
	m.setFunction(G_CALLBACK(&MainWindow::foo));
	m.setSeparator(false);
	menuFile.push_back(m);

	m.setName("Esci");
	m.setIcon(ICON_CLOSE);
	m.setFunction(G_CALLBACK(gtk_main_quit));
	m.setSeparator(true);
	menuFile.push_back(m);

	//menuOption
	m.setName("Users");
	m.setIcon(ICON_SETTINGS);
	m.setFunction(G_CALLBACK(&MainWindow::loadWindowOptions));
	m.setSeparator(false);
	menuOptions.push_back(m);

	//menuHelps
	m.setName("Version");
	m.setIcon(ICON_UPGRADE);
	m.setFunction(G_CALLBACK(&MainWindow::loadWindowVersion));
	m.setSeparator(false);
	menuHelp.push_back(m);

	m.setName("Credits");
	m.setIcon(ICON_STAR);
	m.setFunction(G_CALLBACK(&MainWindow::loadWindowCredits));
	m.setSeparator(false);
	menuHelp.push_back(m);

	//menuToolbar
	Button b;
	b=Button();

	b.setIcon(ICON_UPDATE);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_HOME);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_MENTION);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_DM);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_FAVORITES);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_LINK);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	b.setIcon(ICON_PHOTO);
	b.setFunction(G_CALLBACK(&MainWindow::foo));
	menuToolbar.push_back(b);

	//MainWindowElemets
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	menuFileObj = gtk_menu_new();
	menuOptionsObj = gtk_menu_new();
	menuHelpObj = gtk_menu_new();
	menuBar = gtk_menu_bar_new();
	layout = gtk_vbox_new(0, 1);
	title=(gchar *)PROG_NAME;
	statusBar=StatusBar();
	toolbar = gtk_toolbar_new ();
	inputBar= gtk_statusbar_new ();
	table=gtk_table_new (9, 3, TRUE);
	internalTable= gtk_table_new (1, 3, TRUE);
	scrolledWindow=gtk_scrolled_window_new (NULL, NULL);

	twitterStruct.twitter=Twitter();

}

MainWindow::~MainWindow() {

}

gboolean MainWindow::destroyWindow()
{
	gtk_main_quit ();
	gtk_widget_destroy (GTK_WIDGET (window));

	return true;
}

gboolean MainWindow::ShowWindow()
{

	declaration();

	gtk_widget_show_all(window); //Mostra tutte le finistre

	return true;
}

gboolean MainWindow::UpdateWindow()
{
	return true;
}

gboolean MainWindow::declaration()
{

	initSkeleton();

	initMenu("File", menuFile, menuFileObj, fileMenuRoot);
	initMenu("Options", menuOptions, menuOptionsObj, optionMenuRoot);
	initMenu("Help", menuHelp, menuHelpObj, helpMenuRoot);

	if(twitterStruct.twitter.getLocalUser().getScreenName().empty() &&
			twitterStruct.twitter.getLocalUser().getId().empty()){
		statusBar.pushMessage("Disconnect..", 0);

	}else{
		statusBar.pushMessage("Connect..", 0);

	}

	gtk_box_pack_end (GTK_BOX (layout), statusBar.getStatus(), FALSE, FALSE, 0);

	initToolBar(menuToolbar);

	initInputBar();

	initScrolledWindow();

	gtk_container_add(GTK_CONTAINER(table), internalTable);
	gtk_container_add(GTK_CONTAINER(layout), table);
	gtk_container_add(GTK_CONTAINER(window), layout);

	/* CALLBACK: exit event */
	g_signal_connect (window, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);


	return true;
}

gboolean MainWindow::initSkeleton(){
	gtk_window_set_default_size (GTK_WINDOW(window), 295, 650);
	gtk_widget_set_size_request (window, 295, 400);
	gtk_window_set_title (GTK_WINDOW(window), title);
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), ICON_FAVICON, &error);
	return true;
}

gboolean MainWindow::initScrolledWindow(){
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledWindow),GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scrolledWindow), internalTable);
	gtk_table_attach (GTK_TABLE (table), scrolledWindow, 0, 3, 0, 8, GTK_FILL,GTK_FILL, 0, 0);

	return true;
}

gboolean MainWindow::initMenu(string rootName, vector<Menu> menu, GtkWidget* menuObject, GtkWidget* menuRoot){

	GtkWidget *menuItems;

	for(unsigned int i=0;i<menu.size();i++){
		if(!menu[i].getSeparator()){
			menuItems = gtk_separator_menu_item_new();
			gtk_menu_shell_append(GTK_MENU_SHELL(menuObject), menuItems);
		}
		menuItems = gtk_image_menu_item_new_with_label(menu[i].getName().c_str());
		gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menuItems), gtk_image_new_from_file(menu[i].getIcon().c_str()));

		gdk_threads_enter ();
		g_signal_connect (G_OBJECT (menuItems), "activate", menu[i].getFunction() , NULL);
		gdk_threads_leave ();

		gtk_menu_shell_append(GTK_MENU_SHELL(menuObject), menuItems);

	}

	menuRoot = gtk_menu_item_new_with_label(rootName.c_str());
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (menuRoot), menuObject);

	gtk_box_pack_start(GTK_BOX(layout), menuBar, FALSE, FALSE, 0);
	gtk_menu_bar_append(GTK_MENU_BAR (menuBar), menuRoot);

	return true;
}

gboolean MainWindow::initToolBar(vector<Button> buttons){

	for(unsigned int i=0; i<buttons.size(); i++){
		GtkWidget* button;
		button=gtk_button_new();
		gtk_button_set_image(GTK_BUTTON(button),gtk_image_new_from_file(buttons[i].getIcon().c_str()));
		gtk_container_add (GTK_CONTAINER (toolbar), button);

		gdk_threads_enter ();
		gtk_signal_connect_object (GTK_OBJECT (button), "clicked", buttons[i].getFunction(), NULL);
		gdk_threads_leave ();

	}

	gtk_box_pack_end (GTK_BOX (layout), toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

	return true;
}

gboolean MainWindow::initInputBar(){

	GtkWidget* scroll;
	scroll = gtk_scrolled_window_new(NULL,NULL);
	gtk_table_attach(GTK_TABLE(table), scroll, 0, 3, 8, 9, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),(GtkAttachOptions) (GTK_FILL | GTK_EXPAND), 0, 0);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),GTK_POLICY_NEVER,GTK_POLICY_AUTOMATIC);
	text = gtk_text_view_new();
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text), TRUE);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(text), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(text), GTK_WRAP_WORD_CHAR);
	tweetBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text));
	gtk_text_buffer_set_text (tweetBuffer, "", -1);
	// g_signal_connect(tweetBuffer, "changed", G_CALLBACK("updateStatusBar"), inputBar);
	g_signal_connect(text, "key-press-event", G_CALLBACK("gtkSendTweet"), tweetBuffer);
	gtk_container_add(GTK_CONTAINER(scroll),text);

	gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(this->inputBar), FALSE);
	gtk_statusbar_push (GTK_STATUSBAR(inputBar), 0, "140");
	gtk_box_pack_end (GTK_BOX (layout), inputBar, FALSE, FALSE, 0);
	return true;
}

gboolean MainWindow::loadWindowCredits(){

	WindowCredits windowCredits=WindowCredits();
	windowCredits.ShowWindow();
	windowCredits.~WindowCredits();

	return true;
}

gboolean  MainWindow::loadWindowVersion(){
	WindowVersion windowVersion=WindowVersion();
	windowVersion.ShowWindow();
	windowVersion.~WindowVersion();
	return true;
}

gboolean MainWindow::loadWindowOptions(){
	WindowOptions windowOptions=WindowOptions();
	windowOptions.ShowWindow();
	windowOptions.~WindowOptions();
	return true;
}

gboolean MainWindow::loadWindowAdduser(){
	WindowAddUsers windowAddUsers=WindowAddUsers();
	windowAddUsers.ShowWindow();
	windowAddUsers.~WindowAddUsers();

	return true;
}

gboolean MainWindow::gtkSendTweet(GtkWidget *TextArea, GdkEventKey *pKey, GtkTextBuffer *tweetBuffer){

	GtkTextIter start,
	end;
	char *msg = NULL;

	/* Get start position of cursor and final position */
	gtk_text_buffer_get_start_iter (tweetBuffer, &start);
	gtk_text_buffer_get_end_iter (tweetBuffer, &end);

	/* Casting buffer to char */
	msg = gtk_text_buffer_get_text(tweetBuffer, &start, &end, TRUE);

	/* If user press ENTER on keyboard Send Tweet and clean TextArea*/
	if(pKey->keyval == GDK_Return){

		this->statusBar.pushMessage("Invio In Corso...",0);

		//SendTweet

		if(twitterStruct.twitter.SendTweet(msg)){
			this->statusBar.pushMessage("Tweet Inviato!",0);
			gtk_text_buffer_delete(tweetBuffer, &start, &end);

			return true;

		} else {
			this->statusBar.pushMessage("Tweet Non Inviato!",0);
		}
	}

	return false;

}

gboolean MainWindow::foo(){
	return true;
}


}
