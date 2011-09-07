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

#include "include/PropertiesDialog.h"

namespace TwitCrusader {

PropertiesDialog::PropertiesDialog() : table(7, 10, TRUE)
{
	label.set_label("");
	twitter.readUserFile();

	this->set_default_size(260, 200);
	this->set_size_request(260, 200);
	this->set_title(PROPERTIES_TITLE);
	this->set_border_width(0);
	this->set_position(WIN_POS_CENTER);
	this->set_icon_from_file(ICON_SETTINGS);

	label.set_label(PROPERTIES_LABEL);
	table.attach(label, 1, 9, 1, 2 );

	account.set_label(twitter.getLocalUser().getScreenName());
	table.attach(account, 1, 9, 3, 4);

	this->get_vbox()->add(table);
	this->add_button(DELETE_ACCOUT_BUTTON, Gtk::RESPONSE_CANCEL);
	this->add_button(Stock::OK, Gtk::RESPONSE_OK);
	set_default_response(RESPONSE_OK) ;

}

PropertiesDialog::~PropertiesDialog() {
	// TODO Auto-generated destructor stub
}

} /* namespace TwitCrusader */
