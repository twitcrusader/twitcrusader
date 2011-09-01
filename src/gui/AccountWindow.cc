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

#include "include/AccountWindow.h"

namespace TwitCrusader {

AccountWindow::AccountWindow() : table(7, 10, TRUE)
{
	twitterStruct.twitter.readUserFile();

	this->set_default_size(210, 200);
	this->set_size_request(210, 200);
	this->set_title("Account");
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);
	this->set_icon_from_file(ICON_SETTINGS);

	label.set_label("Twitter's Account:");
	table.attach(label, 1, 9, 1, 2 );

	account.set_label(twitterStruct.twitter.getLocalUser().getScreenName());
	table.attach(account, 1, 9, 3, 4);

	button.set_label("Delete Account");
	button.signal_activate().connect(sigc::mem_fun(*this, &AccountWindow::delete_account));
	table.attach(button, 3, 7, 5, 6);

	this->get_vbox()->add(table);
	this->add_button(Stock::OK, Gtk::RESPONSE_OK);
	set_default_response(RESPONSE_OK) ;

}

AccountWindow::~AccountWindow() {
	// TODO Auto-generated destructor stub
}

void AccountWindow::delete_account(){

	Dialog confirm;
	Label conf;
	conf.set_label("Do you want delete the Profile?");
	confirm.get_vbox()->add(conf);
	confirm.add_button(Stock::OK,Gtk::RESPONSE_OK);
	confirm.add_button(Stock::CANCEL,Gtk::RESPONSE_CANCEL);
	set_default_response(RESPONSE_CANCEL);
	this->run();
	if(confirm.run()==Gtk::RESPONSE_OK){
		if(twitterStruct.twitter.getConfig().deleteConfigFile()){
			hide();
			this->label.set_label("");
			this->run();
		}
	}
}

} /* namespace TwitCrusader */
