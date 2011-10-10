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
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */


#ifndef WINDOWS_REGISTER_H_
#define WINDOWS_REGISTER_H_


#include "icons.h"

#include "../../core/inc/externlibs.h"
#include "../../core/inc/lang.h"
#include "../../core/inc/debug.h"

#include "windows.main.h"
#include "windows.error.h"




typedef struct
{
GtkWidget *pin;
GtkWidget *window;

} AuthWidget;

AuthWidget *DataInput;


/* Define Function */
void gtk_window_register();
void gtkAccessToken();

#endif /* WINDOW_REGISTER_H_ */
