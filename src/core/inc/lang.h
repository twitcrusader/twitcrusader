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


/*
 * To generate po layout: xgettext -a -o po/layout.txt --omit-header src/core/inc/lang.h
 */

/* Define */
#ifndef SYS_H
#define SYS_H

#include <glib/gi18n.h>

/* CharSet */ 
#define MY_ENCODING "ISO-8859-1"

/* Fix: GCC Linux Compiler */ 
#define _GNU_SOURCE	

/* System Variables */
#define COPYRIGHT_SIMBOL " (c) "
#define TWC "TwitCrusader"
#define TWC_TEAM "TwitCrusader Team"
#define TWC_VERSION "2011"
#define TWC_VERSION_STATUS "Nightly"
#define TWC_URL "http://www.twitcrusader.org/"

#define VERSION_MSG _("Version")
#define ABOUT_COMMENT _("Twitter Client For Linux Desktop")
#define START _("Start")
#define CONNECT _("Connect")
#define DISCONNECT _("Disconnect")
#define OPTIONS _("Options")
#define QUIT _("Exit")
#define UPDATES _("Updates")
#define ABOUT _("About")
#define ACCOUNT _("Account")
#define TWC_ACCOUNT_LABEL _("Twitter's Account:")
#define DELETE _("Delete")
#define NEW _("New")
#define NEW_USER _("New User")
#define INSERT_PIN _("Insert PIN")
#define MAKE_ACCOUNT _("Create Account")
#define BAD_INPUT _("ERROR: Bad Input")
#define LAST_VERSION _("Last Version")
#define CURRENT_VERSION _("Current Version")
#define FILE_MENU _("File")
#define HELP_MENU _("Help")
#define STBR_MSG _("Sending...")
#define NOT_SENT _("Tweet Not Sent")
#define SENT _("Tweet Sent")
#define PROFILE_DISCONNECTED _("Disconnected");
#define PROFILE_CONNECTED _("Connected");

#endif
