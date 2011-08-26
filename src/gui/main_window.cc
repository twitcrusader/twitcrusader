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

#include "include/main_window.h"

namespace std {

MainWindow::MainWindow(){

	// This Is Fuckin Sequential Programming

	this->set_title(PROG_NAME);
	this->set_icon_from_file(ICON_FAVICON);
	this->set_default_size(315, 650);
	this->set_size_request(315, 400);
	this->set_border_width(0);
	this->set_position(Gtk::WIN_POS_CENTER);



	file_menu_items[0].set_label("Log In");
	file_menu_items[0].signal_activate().connect(G_CALLBACK(&MainWindow::gtkConnect) );
	file_menu.append(file_menu_items[0]);


	//m.setIcon(ICON_ADDUSER);
	file_menu_items[1].set_label("Log Out");
	file_menu_items[1].signal_activate().connect(G_CALLBACK(&MainWindow::foo) );
	file_menu.append(file_menu_items[1]);


	//m.setIcon(ICON_CLOSE);
	file_menu_items[2].set_label("Quit");
	file_menu_items[2].signal_activate().connect(G_CALLBACK(&MainWindow::on_quit) );
	file_menu.append(file_menu_items[2]);


	file_menu_root.set_label("File");
	file_menu_root.set_submenu(file_menu);
	menu_bar.append(file_menu_root);


	//menuOption
	//m.setName("Users");


	options_menu_items[0].set_label("Users");
	options_menu_items[0].signal_activate().connect(G_CALLBACK(&MainWindow::foo) );
	options_menu.append(options_menu_items[0]);

	options_menu_root.set_label("Options");
	options_menu_root.set_submenu(options_menu);
	menu_bar.append(options_menu_root);


	//menu_helps
	//m.setIcon(ICON_UPGRADE);
	helps_menu_items[0].set_label("Version");
	helps_menu_items[0].signal_activate().connect(G_CALLBACK(&MainWindow::foo) );
	helps_menu.append(helps_menu_items[0]);

	//m.setIcon(ICON_STAR);
	helps_menu_items[1].set_label("Credits");
	helps_menu_items[1].signal_activate().connect(G_CALLBACK(&MainWindow::foo) );
	helps_menu.append(helps_menu_items[1]);

	helps_menu_root.set_label("Help");
	helps_menu_root.set_submenu(helps_menu);
	menu_bar.append(helps_menu_root);


	//StatusBar


	this->status_label="StatusBar..";
	this->status_bar.push(status_label);

	layout.pack_start(menu_bar,Gtk::PACK_SHRINK);
	layout.pack_end(status_bar,Gtk::PACK_SHRINK);



	icon_menu[0].set(ICON_UPDATE);
	icon_menu[1].set(ICON_HOME);
	icon_menu[2].set(ICON_MENTION);
	icon_menu[3].set(ICON_DM);
	icon_menu[4].set(ICON_FAVORITES);
	icon_menu[5].set(ICON_LINK);
	icon_menu[6].set(ICON_PHOTO);

	tool_bar.set_toolbar_style(Gtk::TOOLBAR_ICONS);

	button[0].set_icon_widget(icon_menu[0]);
	button[1].set_icon_widget(icon_menu[1]);
	button[2].set_icon_widget(icon_menu[2]);
	button[3].set_icon_widget(icon_menu[3]);
	button[4].set_icon_widget(icon_menu[4]);
	button[5].set_icon_widget(icon_menu[5]);
	button[6].set_icon_widget(icon_menu[6]);

	tool_bar.append(button[0]);
	tool_bar.append(button[1]);
	tool_bar.append(button[2]);
	tool_bar.append(button[3]);
	tool_bar.append(button[4]);
	tool_bar.append(button[5]);
	tool_bar.append(button[6]);

	layout.pack_end(tool_bar,Gtk::PACK_SHRINK);


	add(layout);


	this->show_all();
}

MainWindow::~MainWindow(){

}


void MainWindow::foo(){

	cout<<"foo()"<<endl;

}




void MainWindow::gtkConnect()
{
	cout<<"gtkConnect()"<<endl;
}



void MainWindow::loadWindowCredits()
{
	cout<<"loadWindowCredits()"<<endl;
}



void MainWindow::loadWindowVersion()
{
	cout<<"loadWindowVersion()"<<endl;
}



void MainWindow::loadWindowOptions()
{
	cout<<"loadWindowOptions()"<<endl;
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

}
/* namespace std */
