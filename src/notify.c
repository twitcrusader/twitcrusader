/*
 *	TwitCrusader - Twitter Client For Linux Desktop
 *	Copyright (C) 2012 - Patryk Rzucidlo <ptkdev@gmail.com>
 *	Orazio Briante <orazio.briante@hotmail.it>
 *
 *
 * This Program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *		WebSite: http://www.twitcrusader.org/
 * 		Development Guidelines: http://dev.twitcrusader.org/
 *
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 */

#include <logc/logc.h>

#include <twc/twc.h>

#include <twc/icons.h>
#include <twc/notify.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libnotify/notify.h>

#ifdef __cplusplus
extern "C"
  {
#endif

gboolean
notifyMsg(string_t message, int timeout)
{

  NotifyNotification *notify = notify_notification_new(PROG_NAME, message,
      ICONS_DIR "" ICON_FAVICON);

  notify_notification_set_timeout(notify, timeout);
  notify_notification_set_urgency(notify, NOTIFY_URGENCY_CRITICAL);

  GError *error = NULL;
  gboolean out = notify_notification_show(notify, &error);

  if (error)
    {
      log(ERROR,(string_t) error->message);
      g_error_free(error);
      error = NULL;
    }

  return out;
}

#ifdef __cplusplus
}
#endif
