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

MainWindow::MainWindow(): table(9, 3, true), table_into(1, 3, true)
{

	// This Is Fuckin Sequential Programming

	is_connected();

	init_window();

	init_menu();
	init_menu_bar();
	layout.pack_start(menu_bar,PACK_SHRINK);

	init_statusbar();
	layout.pack_end(status_bar,PACK_SHRINK);

	init_toolbar();
	layout.pack_end(tool_bar,PACK_SHRINK);

	init_charbar();
	layout.pack_end(charbar,PACK_SHRINK);


	// for() to print Tweet

	init_scrolled_window();
	this->table.attach(this->scrolled_window, 0, 3, 0, 8);


	// TextArea + Scrollbar
	init_text_area();
	this->layout.pack_start(this->table);


	add(layout);

	this->show_all();

}

MainWindow::~MainWindow()
{
	/*for(int i=0;i<FILE_MENU_ITEMS;i++){
		file_menu_items[i].~MenuItem();
	}

	file_menu_root.~MenuItem();
	file_menu.~Menu();

	for(int i=0;i<HELP_MENU_ITEMS;i++){
		helps_menu_items[i].~MenuItem();
	}

	helps_menu_root.~MenuItem();
	helps_menu.~Menu();

	for(int i=0;i<NUM_BUTTON;i++){

		button[i].~ToolButton();
		icon_menu[i].~Image();

	}

	table.~Table();
	table_into.~Table();
	scrolled_window.~ScrolledWindow();
	scroll_text.~ScrolledWindow();
	text.~TextView();
	tweet_buffer.~RefPtr();
	layout.~VBox();
	menu_bar.~MenuBar();

	status_bar.~Statusbar();
	charbar.~Statusbar();
	tool_bar.~Toolbar();

	status_label.~basic_string();
	 */

}

void MainWindow::is_connected(){
	this->connected=!twitterStruct.twitter.getLocalUser().getScreenName().empty();
}
void MainWindow::init_scrolled_window(){
	this->scrolled_window.add(table_into);
	this->scrolled_window.set_policy(POLICY_NEVER, POLICY_ALWAYS);
}


void MainWindow::init_window(){
	this->set_title(PROG_NAME);
	this->set_icon_from_file(ICON_FAVICON);
	this->set_default_size(315, 650);
	this->set_size_request(315, 400);
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);
}

void MainWindow::init_menu_bar(){

	for(int i=0;i<FILE_MENU_ITEMS;i++){
		file_menu.append(file_menu_items[i]);
	}

	file_menu_root.set_label("File");
	file_menu_root.set_submenu(file_menu);
	menu_bar.append(file_menu_root);


	for(int i=0;i<HELP_MENU_ITEMS;i++){
		helps_menu.append(helps_menu_items[i]);
	}

	helps_menu_root.set_label("Help");
	helps_menu_root.set_submenu(helps_menu);
	menu_bar.append(helps_menu_root);

}


void MainWindow::init_menu(){


	if(this->connected){

		//m.setIcon(ICON_ADDUSER);
		file_menu_items[0].set_label("Log Out");
		file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::foo) );



	}else{
		if(twitterStruct.twitter.getConfig().is_registered()){
			//m.setIcon(ICON_ADDUSER);
			file_menu_items[0].set_label("Log In");
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::gtkConnect) );

		}else{
			//m.setIcon(ICON_ADDUSER);
			file_menu_items[0].set_label("Register");
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadRegWindow) );
		}

		//m.setName("Users");
		file_menu_items[1].set_label("Account");
		file_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowOptions) );
	}

	//m.setIcon(ICON_CLOSE);
	file_menu_items[2].set_label("Quit");
	file_menu_items[2].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::on_quit) );



	//menu_helps

	//m.setIcon(ICON_UPGRADE);
	helps_menu_items[0].set_label("Version");
	helps_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowVersion) );


	//m.setIcon(ICON_STAR);
	helps_menu_items[1].set_label("About");
	helps_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowCredits) );

}

void MainWindow::init_statusbar()
{
	status_bar.pop(status_bar.get_context_id(CONNECTED));
	status_bar.pop(status_bar.get_context_id(DISCONNECTED));
	status_bar.pop(status_bar.get_context_id(NO_ONLINE));


	//StatusBar
	if(this->connected){
		this->status_label=CONNECTED;
	}
	else{
		this->status_label=DISCONNECTED;
	}

	this->status_bar.push(this->status_label);

}

void MainWindow::init_toolbar(){

	tool_bar.set_toolbar_style(TOOLBAR_ICONS);
	tool_bar.set_icon_size(ICON_SIZE_SMALL_TOOLBAR);

	icon_menu[0].set(ICON_UPDATE);
	button[0].set_icon_widget(icon_menu[0]);
	button[0].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[0]);

	icon_menu[1].set(ICON_HOME);
	button[1].set_icon_widget(icon_menu[1]);
	button[1].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[1]);

	icon_menu[2].set(ICON_MENTION);
	button[2].set_icon_widget(icon_menu[2]);
	button[2].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[2]);

	icon_menu[3].set(ICON_DM);
	button[3].set_icon_widget(icon_menu[3]);
	button[3].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[3]);

	icon_menu[4].set(ICON_FAVORITES);
	button[4].set_icon_widget(icon_menu[4]);
	button[4].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[4]);

	icon_menu[5].set(ICON_LINK);
	button[5].set_icon_widget(icon_menu[5]);
	button[5].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[5]);

	icon_menu[6].set(ICON_PHOTO);
	button[6].set_icon_widget(icon_menu[6]);
	button[6].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[6]);

}

void MainWindow::init_charbar(){

	charbar.push("140"); // Now are Static !

}

void MainWindow::init_text_area(){
	this->text.set_editable(true);
	this->text.set_wrap_mode(WRAP_CHAR);

	tweet_buffer=TextBuffer::create();
	this->text.set_buffer(this->tweet_buffer);
	//this->text.signal_state_changed().connect(sigc::mem_fun(*this, &MainWindow::on_my_changed));;
	this->scroll_text.add(this->text);
	this->scroll_text.set_policy(POLICY_NEVER, POLICY_AUTOMATIC);
	this->table.attach(this->scroll_text,0, 3, 8, 9);

}

void MainWindow::foo()
{
	cout<<"foo()"<<endl;

}


void MainWindow::gtkConnect()
{
	cout<<"gtkConnect()"<<endl;
	twitterStruct.twitter.readUserFile();
	this->is_connected();
	this->init_menu();
	this->timeline_mode=2;
	init_statusbar();
	refresh();

}



void MainWindow::loadWindowCredits()
{
	cout<<"loadWindowCredits()"<<endl;

	AboutWindow aboutWindow;
	aboutWindow.~AboutWindow();
}



void MainWindow::loadWindowVersion()
{
	cout<<"loadWindowVersion()"<<endl;

	WindowVersion windowVersion;
	windowVersion.~WindowVersion();

}



void MainWindow::loadWindowOptions()
{
	cout<<"loadWindowOptions()"<<endl;
	AccountWindow account_window;
	account_window.~AccountWindow();

	this->is_connected();
	this->init_menu();
	init_statusbar();
	refresh();
}

void MainWindow::loadRegWindow()
{
	cout<<"loadWindowAdduser()"<<endl;

	RegWindow regWindow;
	regWindow.~RegWindow();
	this->is_connected();
	refresh();
}



void MainWindow::on_quit()
{
	cout<<"on_quit()"<<endl;

	this->hide();
	Gtk::Main::quit();
}


void MainWindow::updateStatusBar(){
	cout<<"updateStatusBar()"<<endl;

}

void MainWindow::on_submit_text()
{
	cout<<"on_submit_text()"<<endl;
}

void MainWindow::on_writing()
{
	cout<<"on_writing()"<<endl;
}


void MainWindow::refresh_timeline(){
	bool error;

	error=twitterStruct.twitter.switchTimeLine(this->timeline_mode);

	if(error){

		//downloadsAvatars();

	}
}

void MainWindow::refresh(){

	while ( Gtk::Main::events_pending() )
		Gtk::Main::iteration() ;

	this->queue_draw();
}
