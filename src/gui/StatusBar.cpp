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

#include "include/StatusBar.h"

namespace std {

StatusBar::StatusBar() {

	statusbar = gtk_statusbar_new ();
	message = GTK_STATUSBAR(statusbar);
}

StatusBar::~StatusBar(){

}

void StatusBar::pushMessage(string statusLabel, gint contextId){

	messageId=gtk_statusbar_push (GTK_STATUSBAR(this->message), contextId, statusLabel.c_str());
	gtk_statusbar_set_has_resize_grip (this->message, TRUE);
	this->contextId=contextId;

}

GtkWidget *StatusBar::getStatus()
{
	return statusbar;
}

void StatusBar::removeStatusBar(){
	gtk_statusbar_remove (message,contextId, messageId);
}

void StatusBar::clear(){
	this->message=NULL;
	this->statusbar=NULL;
	this->messageId=-1;
	this->contextId=-1;

	statusbar = gtk_statusbar_new ();
	message = GTK_STATUSBAR(statusbar);
}

}
