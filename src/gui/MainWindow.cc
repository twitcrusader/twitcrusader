/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
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
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/MainWindow.h"
namespace TwitCrusader {
MainWindow::MainWindow(): table(9, 3, true),table_into(1, 3, true), char_count("140")
{

	// This Is Fuckin Sequential Programming

	is_connected();

	init_window();

	this->declare();

	layout.pack_start(menu_bar,PACK_SHRINK);

	this->scrolled_window.set_policy(POLICY_NEVER, POLICY_ALWAYS);
	this->scrolled_window.add(table_into);
	this->table.attach(this->scrolled_window, 0, 3, 0, 8);
	this->table.attach(this->scroll_text,0, 3, 8, 9);
	this->layout.pack_start(this->table);

	layout.pack_end(status_bar,PACK_SHRINK);
	layout.pack_end(tool_bar,PACK_SHRINK);
	layout.pack_end(charbar,PACK_SHRINK);


	add(layout);

	this->show_all();

}

MainWindow::~MainWindow()
{

}

void MainWindow::declare(){
	init_menu();
	init_menu_bar();
	init_statusbar();
	init_toolbar();
	init_charbar();
	init_scrolled_window();
	init_text_area();
}

void MainWindow::is_connected(){
	this->connected=!twitter.getLocalUser().getScreenName().empty();
}
void MainWindow::init_scrolled_window(){


	int i=0;
	for(vector<Tweet>::iterator it =  twitter.getTimeLine().timeline.begin(); it!=twitter.getTimeLine().timeline.end(); ++it){
		//avatar.set(twitter.getConfig().getAvatarDir()+it.base()->user.screen_name);
		nick.set_label(it.base()->user.screen_name);
		tweet.set_label(it.base()->text);
		//table_into.attach(avatar,0, 1, i, i+4);
		table_into.attach(nick,1, 10,i, i+1);
		table_into.attach(tweet, 1,10, i+1, i+4);
		i++;
	}


}


void MainWindow::init_window(){
	this->set_title(PROG_NAME);
	this->set_icon_from_file(ICON_FAVICON);
	this->set_default_size(320, 650);
	this->set_size_request(320, 400);
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
	for(int i=0; i<3;i++){
		this->file_menu_items[i].remove();
	}

	if(this->connected){

		file_menu_items[0].add_pixlabel(ICON_ADDUSER, "Log Out", 0, 0);
		file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::foo) );



	}else{
		if(twitter.getConfig().is_registered()){

			file_menu_items[0].add_pixlabel(ICON_ADDUSER, "Log In", 0, 0);
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::gtkConnect) );

		}else{

			file_menu_items[0].add_pixlabel(ICON_ADDUSER, "Register", 0, 0);
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadRegWindow) );
		}

		file_menu_items[1].add_pixlabel(ICON_SETTINGS, "Account", 0, 0);
		file_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowOptions) );
	}


	file_menu_items[2].add_pixlabel(ICON_CLOSE, "Quit", 0, 0);
	file_menu_items[2].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::on_quit) );



	//menu_helps

	for(int i=0; i<2;i++){
		this->helps_menu_items[i].remove();
	}

	helps_menu_items[0].add_pixlabel(ICON_UPGRADE, "Version", 0, 0);
	helps_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowVersion) );

	helps_menu_items[1].add_pixlabel(ICON_STAR, "About", 0, 0);
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

	charbar.push(char_count);

}

void MainWindow::init_text_area(){
	this->text.set_editable(true);
	this->text.set_wrap_mode(WRAP_CHAR);
	tweet_buffer=this->text.get_buffer();
	tweet_buffer.operator ->()->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_writing));
	this->scroll_text.add(this->text);
	this->scroll_text.set_policy(POLICY_NEVER, POLICY_AUTOMATIC);

}

void MainWindow::foo()
{
	cout<<"foo()"<<endl;

}


void MainWindow::gtkConnect()
{
	cout<<"gtkConnect()"<<endl;
	twitter.readUserFile();
	this->is_connected();
	this->timeline_mode=2;

	refresh();

}



void MainWindow::loadWindowCredits()
{
	cout<<"loadWindowCredits()"<<endl;

	AboutDialog aboutDialog;
	aboutDialog.~AboutDialog();
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
	AccountDialog accountDialog;
	accountDialog.set_transient_for( *this );
	accountDialog.show_all();
	if(accountDialog.run()==Gtk::RESPONSE_CANCEL){
		Dialog confirm;
		Label conf;
		conf.set_label("Do you want delete the Profile?");
		confirm.get_vbox()->add(conf);
		confirm.add_button(Stock::OK,Gtk::RESPONSE_OK);
		confirm.add_button(Stock::CANCEL,Gtk::RESPONSE_CANCEL);
		confirm.set_default_response(RESPONSE_CANCEL);
		confirm.show_all_children();
		if(confirm.run()==Gtk::RESPONSE_OK){
			if(twitter.getConfig().deleteConfigFile()){
				confirm.hide();
				accountDialog.hide();
				accountDialog.run();
			}
		}
	}
	accountDialog.hide();
	accountDialog.~AccountDialog();

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
	string buffer=tweet_buffer.operator ->()->get_text(true);
	int count=tweet_buffer.operator ->()->get_char_count();

	if(count<140){
		on_submit_text();
	}


	this->charbar.pop(this->charbar.get_context_id(char_count));

	count=140-count;
	std::stringstream out;
	out << count;
	char_count=out.str();
	init_charbar();
	this->queue_draw();
}


void MainWindow::refresh_timeline(){
	bool error;

	error=twitter.switchTimeLine(this->timeline_mode);

	if(error){

		//downloadsAvatars();

	}

	init_scrolled_window();
}

void MainWindow::refresh(){

	while ( Gtk::Main::events_pending() )
		Gtk::Main::iteration() ;

	init_menu();
	init_statusbar();

	refresh_timeline();

	this->queue_draw();
}
}
