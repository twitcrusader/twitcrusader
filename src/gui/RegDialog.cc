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
 *		Source: https://github.com/KernelMonkey/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/RegDialog.h"
namespace TwitCrusader {
RegDialog::RegDialog() : table(7, 10, TRUE)
{
	this->set_default_size(300, 210);
	this->set_size_request(300,210);
	this->set_title(REG_TITLE);
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);
	this->set_icon_from_file(ICON_ADDUSER);


	/* Attach twitter-login image */

	tw_login_img.set(ICON_SIGNIN);
	this->tw_login_event.set_image(tw_login_img);
	tw_login_event.signal_clicked().connect(sigc::mem_fun(*this, &RegDialog::browser_authorization) );
	table.attach(tw_login_event, 1, 9, 1, 2);

	label.set_text(LABEL_PIN);
	table.attach(label, 1, 9, 2, 3);

	pin.set_editable(true);
	table.attach(pin, 1, 9, 3, 4);

	//button.set_label(SUBMIT_REG_BUTTON);
	//button.signal_clicked().connect(sigc::mem_fun(*this, &RegDialog::get_access_token));

	//table.attach(button, 1, 9, 5, 6);

	this->add_button(SUBMIT_REG_BUTTON, Gtk::RESPONSE_OK);
	this->add_button(Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	this->get_vbox()->add(table);
	this ->set_default_response( Gtk::RESPONSE_CANCEL ) ;
	show_all();

}

RegDialog::~RegDialog() {
	// TODO Auto-generated destructor stub
}

void RegDialog::foo(){
	cout<<"RegDialog::foo()"<<endl;
}

void RegDialog::quit(){
	cout<<"RegDialog::quit()"<<endl;
	hide();

}

void RegDialog::browser_authorization(){
	twitter.tokenTempBrowser();
}

void RegDialog::get_access_token(){
	pin_buffer=this->pin.get_buffer();
	ustring str=pin_buffer->get_text();
	if(!twitter.tokenAccess(str)){
		MessageDialog error(REG_ERROR_LABEL,false,MESSAGE_ERROR ,BUTTONS_OK,false);
		error.run();
	}
}
}
