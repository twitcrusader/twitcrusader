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

#include "../include/twc.h"

#include "../dependences/liblogc/logc.h"

#include "../include/preference.h"
#include "../include/ErrorWidget.h"
#include "../include/Registration.h"
#include "../include/MainWindow.h"
         
#include "../include/icons.h"
#include "../include/notify.h"
#include "../include/console.h"
#include "../dependences/libtwitc/twitc.h"

#include <gtk/gtk.h>
#include <glib/gi18n.h>

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static progData_t twc;

#ifdef __cplusplus
extern "C"
{
#endif

byte_t
main(int argc, char *argv[])
{
	initLog(FILE_VIDEO_LOG, DISABLED_LOG);

	byte_t shparam=shellParam(argc,argv);

	if (shparam == EXIT_FAILURE)
		return EXIT_FAILURE;

	if(shparam==2)
		initLog(FILE_VIDEO_LOG, FILE_VIDEO_LOG);

	debug ("PROG_DIR:\t%s", PROG_DIR);debug ("ICONS_DIR:\t%s", ICONS_DIR);debug ("PACKAGE_LOCALE_DIR:\t%s", PACKAGE_LOCALE_DIR);

	initProgData(&twc);

	if (twc.pp)
	{

		if (createDirectory(twc.pp->progDir))
		{
			createDirectory(twc.pp->avatarDir);
		}

		string_t fileLock = NULL;
		asprintf(&fileLock, "%s/%s.lock", twc.pp->progDir, PROG_NAME);

		string_t fileName = NULL;
		asprintf(&fileName, "%s/%s.log", twc.pp->progDir, PROG_NAME);

		checkFileSize(fileName, (1024 * 1000));
		openLogFile(fileName);

		notifyInit ();

		notifyMsg("\tStarted", 100);

		/* Init thread */
		g_thread_init(NULL );
		gdk_threads_init();

		if (gtk_init_check(NULL, NULL ))
		{

			debug (_("GTK initialized"));

			gdk_threads_enter();

			StartGUI(&twc);

			gtk_main();

			gdk_threads_leave();

		}
		else
			log(ERROR,_("GTK can't be initialized"));

		notifyMsg("\tStopped", 100);

		notifyUninit ();

	}

	return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
