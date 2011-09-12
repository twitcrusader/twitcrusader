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

#ifndef ACCOUNTDIALOG_H_
#define ACCOUNTDIALOG_H_

#include <gtkmm.h>
#include <gtkmm/stock.h>

#include "Icons.h"
#include "lang.h"
#include "../../core/include/TwitterObject.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

namespace TwitCrusader {

class PropertiesDialog: public Dialog
{
private:
	Table table;
	Label label;
	Label account;
	Button button;

public:
	PropertiesDialog();
	virtual ~PropertiesDialog();
};

} /* namespace TwitCrusader */
#endif /* ACCOUNTDIALOG_H_ */
