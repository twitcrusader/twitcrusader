/*
 *	TwitCrusader - Twitter Client For Linux Desktop
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
 *
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */
#ifndef WINDOWS_PROPERTIES_H_
#define WINDOWS_PROPERTIES_H_



#include "icons.h"

#include "../../core/inc/externlibs.h"
#include "../../core/inc/lang.h"
#include "../../core/inc/debug.h"

#include "windows.register.h"
#include "windows.main.h"


GtkWidget *dialog,
*notebook,
*settingMenu,
*table,
*label,
*combo,
*button;
GList *itemsAccount;
GError *error;

/* Define Function */
void gtk_register();
void gtk_delete_account();
void gtk_window_properties();

#endif /* WINDOWS_PROPERTIES_H_ */
