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
MainWindow::MainWindow(): table(8, 3, true),table_into(50, 2, true), char_count("140")
{
	// This Is Fuckin Sequential Programming

	is_connected();

	init_window();

	this->declare();

	layout.pack_start(menu_bar,PACK_SHRINK);

	this->scrolled_window.set_policy(POLICY_NEVER, POLICY_ALWAYS);
	//this->scrolled_window.add(table_into);
	tweets.set_editable(false);
	scrolled_window.add(tweets);
	this->table.attach(this->scrolled_window, 0, 3, 0, 8);
	//this->table.attach(this->scroll_text,0, 3, 8, 9);


	layout.pack_end(status_bar,PACK_SHRINK);
	layout.pack_end(charbar,PACK_SHRINK);
	layout.pack_end(scroll_text,PACK_SHRINK);
	layout.pack_end(tool_bar,PACK_SHRINK);

	this->layout.pack_end(this->table);

	add(layout);

	this->signal_hide().connect(sigc::mem_fun(*this, &MainWindow::on_quit));

	this->show_all();

	//init_timer();
}

MainWindow::~MainWindow()
{

}

void MainWindow::declare(){
	counter=0;
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

	ustring tw=ustring();
	for(vector<Tweet>::iterator it =  twitter.getTimeLine().timeline.begin(); it!=twitter.getTimeLine().timeline.end(); it++){

		tw.append("@");
		tw.append(it.base()->user.screen_name);
		tw.append("\n\t");
		tw.append(it.base()->text);
		tw.append("\n");
		//avatar.set(twitter.getConfig().getAvatarDir()+it.base()->user.screen_name);
		//nick.set_label(it.base()->user.screen_name);

			//tweet->set_label("@"+it.base()->user.screen_name+"\n\t"+it.base()->text);
			//cout<<tweet->get_label()<<endl;

			//table_into.attach(avatar,0, 1, i, i+4);
			//table_into.attach(nick,1, 2,i, i+1);
		//	table_into.attach(*tweet, 1,2, i, i+1);


	}
	cout<<tw<<endl;
	tweets.get_buffer().operator ->()->set_text(tw);

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
	for(int i=0; i<FILE_MENU_ITEMS;i++){
		this->file_menu_items[i].remove();
	}

	if(this->connected){

		file_menu_items[0].add_pixlabel(ICON_ADDUSER, LOGOUT, 0, 0);
		file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::foo) );



	}else{
		if(twitter.getConfig().is_registered()){

			file_menu_items[0].add_pixlabel(ICON_ADDUSER, LOGIN, 0, 0);
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::gtkConnect) );

		}else{

			file_menu_items[0].add_pixlabel(ICON_ADDUSER, REGISTER, 0, 0);
			file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadRegWindow) );
		}


	}

	file_menu_items[1].add_pixlabel(ICON_SETTINGS, PROPERTIES, 0, 0);
	file_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowProperties) );

	file_menu_items[2].add_pixlabel(ICON_CLOSE, QUIT, 0, 0);
	file_menu_items[2].signal_activate().connect(sigc::mem_fun(*this,&Window::hide) );



	//menu_helps

	for(int i=0; i<2;i++){
		this->helps_menu_items[i].remove();
	}

	helps_menu_items[0].add_pixlabel(ICON_UPGRADE, VERSION, 0, 0);
	helps_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowVersion) );

	helps_menu_items[1].add_pixlabel(ICON_STAR, ABOUT, 0, 0);
	helps_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowCredits) );

}

void MainWindow::init_statusbar()
{

	clear_statusbar();

	//StatusBar
	if(this->connected){
		this->status_label=CONNECTED;
	}
	else{
		this->status_label=DISCONNECTED;
	}

	this->status_bar.push(this->status_label);

}

void MainWindow::clear_statusbar(){

	status_bar.pop(status_bar.get_context_id(CONNECTED));
	status_bar.pop(status_bar.get_context_id(DISCONNECTED));
	status_bar.pop(status_bar.get_context_id(NO_ONLINE));

}


void MainWindow::init_toolbar(){

	tool_bar.set_toolbar_style(TOOLBAR_ICONS);
	tool_bar.set_icon_size(ICON_SIZE_SMALL_TOOLBAR);

	icon_menu[0].set(ICON_UPDATE);
	button[0].set_icon_widget(icon_menu[0]);
	button[0].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::refresh_timeline) );
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

	refresh_timeline();

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



void MainWindow::loadWindowProperties()
{
	cout<<"loadWindowOptions()"<<endl;
	PropertiesDialog propertiesDialog;
	propertiesDialog.set_transient_for( *this );
	propertiesDialog.show_all();
	if(propertiesDialog.run()==Gtk::RESPONSE_CANCEL){
		if(this->connected){
			Dialog confirm;
			Label conf;
			conf.set_label(DELETE_CONFIRM);
			confirm.get_vbox()->add(conf);
			confirm.add_button(Stock::OK,Gtk::RESPONSE_OK);
			confirm.add_button(Stock::CANCEL,Gtk::RESPONSE_CANCEL);
			confirm.set_default_response(RESPONSE_CANCEL);
			confirm.show_all_children();
			if(confirm.run()==Gtk::RESPONSE_OK){

				if(twitter.getConfig().deleteConfigFile()){
					confirm.hide();
					propertiesDialog.hide();
					propertiesDialog.run();
				}

			}
		}
		propertiesDialog.hide();
		propertiesDialog.~PropertiesDialog();

		this->is_connected();
		this->init_menu();
		init_statusbar();
		refresh_timeline();
	}
}

void MainWindow::loadRegWindow()
{
	cout<<"loadWindowAdduser()"<<endl;

	RegWindow regWindow;
	regWindow.~RegWindow();
	this->is_connected();
	refresh();
}

void MainWindow::init_timer()
{
	sigc::slot<bool> tslot = sigc::mem_fun(*this, &MainWindow::on_timeout);
	Glib::signal_timeout().connect(tslot, delayInMin);
	this->timeout=Glib::MainLoop::create(false);
	this->timeout.operator ->()->run();
}

bool MainWindow::on_timeout()
{
	++counter;

	if(counter>=delayInMin*60000){
		cout<<"Timeout"<<endl;
		counter=0;
		refresh_timeline();
	}

	return true;
}

void MainWindow::on_quit()
{
	cout<<"on_quit()"<<endl;

	if(Quit_Dialog()){
		timeout->quit();


		this->hide();
		Functions::notifySystem(QUIT);
	}else{
		show_all();
	}
}

bool MainWindow::Quit_Dialog()
{
	Gtk::MessageDialog quitDialog( *this, QUIT_MESSAGE, false, Gtk::MESSAGE_QUESTION,  Gtk::BUTTONS_NONE,true );


	quitDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	quitDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL );

	if (quitDialog.run() == Gtk::RESPONSE_CANCEL ) return false;

	return true;
}

void MainWindow::on_submit_text()
{
	cout<<"on_submit_text()"<<endl;

	clear_statusbar();
	status_bar.push(SENDING_MSG);
	this->queue_draw();

	ustring msg=tweet_buffer.operator ->()->get_text(false);

	if(twitter.SendTweet(msg)){
		Functions::notifySystem(MSG_SENT);
		status_bar.pop(status_bar.get_context_id(SENDING_MSG));
		status_bar.push(MSG_SENT);
	}else{
		Functions::notifySystem(MSG_NOT_SENT);
		status_bar.pop(status_bar.get_context_id(SENDING_MSG));
		status_bar.push(MSG_NOT_SENT);
	}


}

void MainWindow::on_writing()
{
	cout<<"on_writing()"<<endl;
	ustring buffer=tweet_buffer.operator ->()->get_text(true);
	int count=tweet_buffer.operator ->()->get_char_count();

	if(count<140 && count>0){
		ustring ch=buffer.substr(count-1,count);
		if(strstr(ch.c_str(),"\n")!=NULL){ //can't see endLine
			on_submit_text();
			this->tweet_buffer.operator ->()->set_text("");
			count=tweet_buffer.operator ->()->get_char_count();
		}
		cout<<"ch:\t"<<ch<<endl;
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

	refresh();
}

void MainWindow::refresh(){

	while ( Gtk::Main::events_pending() )
		Gtk::Main::iteration() ;

	init_menu();
	init_statusbar();
	init_scrolled_window();
	show_all();
	this->queue_draw();
}
}
