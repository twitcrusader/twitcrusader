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

#include "include/RegWindow.h"

RegWindow::RegWindow() : table(9, 10, TRUE), cancel_button(Stock::CANCEL)
{
	this->set_default_size(70, 80);
	this->set_size_request(70,80);
	this->set_title("Register");
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);
	this->set_icon_from_file(ICON_ADDUSER);


	/* Attach twitter-login image */

	tw_login_img.set(ICON_SIGNIN);
	this->tw_login_event.set_image(tw_login_img);
	tw_login_event.signal_clicked().connect(sigc::mem_fun(*this, &RegWindow::browser_authorization) );
	table.attach(tw_login_event, 1, 9, 1, 2);

	label.set_text("Insert PIN");
	table.attach(label, 1, 9, 2, 3);

	pin.set_editable(true);
	table.attach(pin, 1, 9, 3, 4);

	button.set_label("Register Account");
	button.signal_clicked().connect(sigc::mem_fun(*this, &RegWindow::get_access_token));

	table.attach(button, 1, 9, 5, 6);


	cancel_button.signal_clicked().connect(sigc::mem_fun(*this, &RegWindow::quit));
	table.attach(cancel_button, 1, 9, 7, 8);

	add(table);

	show_all();
	Main::run();

}

RegWindow::~RegWindow() {
	// TODO Auto-generated destructor stub
}

void RegWindow::foo(){
	cout<<"RegWindow::foo()"<<endl;
}

void RegWindow::quit(){
	cout<<"RegWindow::quit()"<<endl;
	hide();
}

void RegWindow::browser_authorization(){
	twitterStruct.twitter.tokenTempBrowser();
}

void RegWindow::get_access_token(){
	pin_buffer=this->pin.get_buffer();
	string str=pin_buffer->get_text();
	if(!twitterStruct.twitter.tokenAccess(str)){
		MessageDialog error("Bad PIN",false,MESSAGE_ERROR ,BUTTONS_OK,false);
		error.run();
	}else{
		hide();
	}
}

