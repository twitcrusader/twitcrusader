/*
 *	 TwitCrusader - Twitter Client For Linux Desktop
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
#include "inc/notify.h"

    void notifySystem(char *message){

    	debug_f_start("notifySystem");

    	NotifyNotification *notify= NULL;
    	notify=notify_notification_new(TWC,message,ICON_FAVICON);

    	notify_notification_set_timeout(notify,3000);
    	notify_notification_set_urgency (notify,NOTIFY_URGENCY_CRITICAL);

    	GError *error=NULL;
    	notify_notification_show(notify,&error);

    }


