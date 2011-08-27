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

	this->set_title(PROG_NAME);
	this->set_icon_from_file(ICON_FAVICON);
	this->set_default_size(315, 650);
	this->set_size_request(315, 400);
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);


	file_menu_items[0].set_label("Log In");
	file_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::foo) );
	file_menu.append(file_menu_items[0]);


	//m.setIcon(ICON_ADDUSER);
	file_menu_items[1].set_label("Log Out");
	file_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::foo) );
	file_menu.append(file_menu_items[1]);


	//m.setIcon(ICON_CLOSE);
	file_menu_items[2].set_label("Quit");
	file_menu_items[2].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::on_quit) );
	file_menu.append(file_menu_items[2]);


	file_menu_root.set_label("File");
	file_menu_root.set_submenu(file_menu);
	menu_bar.append(file_menu_root);


	//menuOption
	//m.setName("Users");


	options_menu_items[0].set_label("Users");
	options_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowOptions) );
	options_menu.append(options_menu_items[0]);

	options_menu_root.set_label("Options");
	options_menu_root.set_submenu(options_menu);
	menu_bar.append(options_menu_root);


	//menu_helps
	//m.setIcon(ICON_UPGRADE);
	helps_menu_items[0].set_label("Version");
	helps_menu_items[0].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowVersion) );
	helps_menu.append(helps_menu_items[0]);

	//m.setIcon(ICON_STAR);
	helps_menu_items[1].set_label("Credits");
	helps_menu_items[1].signal_activate().connect(sigc::mem_fun(*this,&MainWindow::loadWindowCredits) );
	helps_menu.append(helps_menu_items[1]);

	helps_menu_root.set_label("Help");
	helps_menu_root.set_submenu(helps_menu);
	menu_bar.append(helps_menu_root);

	layout.pack_start(menu_bar,PACK_SHRINK);

	//StatusBar

	if(twitterStruct.twitter.getLocalUser().getScreenName().empty() &&
			twitterStruct.twitter.getLocalUser().getId().empty())
	{
		this->status_label="Disconnect..";

	}else{
		this->status_label="Connect..";

	}
	this->status_bar.push(this->status_label);

	layout.pack_end(status_bar,PACK_SHRINK);


	icon_menu[0].set(ICON_UPDATE);
	icon_menu[1].set(ICON_HOME);
	icon_menu[2].set(ICON_MENTION);
	icon_menu[3].set(ICON_DM);
	icon_menu[4].set(ICON_FAVORITES);
	icon_menu[5].set(ICON_LINK);
	icon_menu[6].set(ICON_PHOTO);


	tool_bar.set_toolbar_style(TOOLBAR_ICONS);
	tool_bar.set_icon_size(ICON_SIZE_SMALL_TOOLBAR);

	button[0].set_icon_widget(icon_menu[0]);
	button[0].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[0]);

	button[1].set_icon_widget(icon_menu[1]);
	button[1].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[1]);

	button[2].set_icon_widget(icon_menu[2]);
	button[2].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[2]);

	button[3].set_icon_widget(icon_menu[3]);
	button[3].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[3]);

	button[4].set_icon_widget(icon_menu[4]);
	button[4].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[4]);

	button[5].set_icon_widget(icon_menu[5]);
	button[5].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[5]);

	button[6].set_icon_widget(icon_menu[6]);
	button[6].signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::foo) );
	tool_bar.append(button[6]);

	layout.pack_end(tool_bar,PACK_SHRINK);

	statusbar_char.push("140"); // Now are Static !

	layout.pack_end(statusbar_char,PACK_SHRINK);


	// for() to print Tweet

	this->scrolled_window.add(table_into);
	this->scrolled_window.set_policy(POLICY_NEVER, POLICY_ALWAYS);

	this->table.attach(this->scrolled_window, 0, 3, 0, 8);


	// TextArea + Scrollbar

	this->text.set_editable(true);
	this->text.set_wrap_mode(WRAP_CHAR);

	tweet_buffer=TextBuffer::create();
	this->text.set_buffer(this->tweet_buffer);
	//this->text.signal_state_changed().connect(sigc::mem_fun(*this, &MainWindow::on_my_changed));;
	this->scroll_text.add(this->text);
	this->scroll_text.set_policy(POLICY_NEVER, POLICY_AUTOMATIC);
	this->table.attach(this->scroll_text,0, 3, 8, 9);

	this->layout.pack_start(this->table);
	add(layout);


	this->show_all();
}

MainWindow::~MainWindow()
{

}


void MainWindow::foo()
{

	cout<<"foo()"<<endl;

}




void MainWindow::gtkConnect()
{
	cout<<"gtkConnect()"<<endl;
}



void MainWindow::loadWindowCredits()
{

#define COMMENT "Basato su Gtkmm e semplicità!\n\nVersion: "


	cout<<"loadWindowCredits()"<<endl;

	Glib::RefPtr<Gdk::Pixbuf> logo;
	logo=Gdk::Pixbuf::create_from_file(ICON_ABOUT);

	AboutDialog about;

	about.set_name(PROG_NAME);
	about.set_copyright(COPYRIGHT);
	about.set_comments(COMMENT""TWC_VERSION""TWC_VERSION_STATUS);
	about.set_website(WEBSITE);
	about.set_license_type(LICENSE_GPL_3_0);
	about.set_license(Functions::readRawTextFile(PROG_DIR"/GPL3"));
	about.set_logo(logo);
	about.set_authors(Functions::readTextFileLinebyLine(PROG_DIR"/AUTHORS"));
	about.run();
}



void MainWindow::loadWindowVersion()
{
	cout<<"loadWindowVersion()"<<endl;

	string current_Version_MSG("Current Version: ");
	string last_Version_MSG("Last Version: ");

	string last_Version_Check(Functions::DownloadVersion());
	string current_Version_Check(TWC_VERSION""TWC_VERSION_STATUS);

	string info(current_Version_MSG+current_Version_Check+"\n"+last_Version_MSG+last_Version_Check);

	MessageDialog version(*this, info);
	version.set_title("Check Updates");
	version.set_border_width(0);
	version.set_position(WIN_POS_CENTER);
	version.set_default_icon_from_file(ICON_UPGRADE);

	version.run();

}



void MainWindow::loadWindowOptions()
{
	cout<<"loadWindowOptions()"<<endl;



	OptionWindow options;
}

void MainWindow::loadWindowAdduser()
{
	cout<<"loadWindowAdduser()"<<endl;


}



void MainWindow::on_quit()
{
	cout<<"on_quit()"<<endl;

	hide();
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
