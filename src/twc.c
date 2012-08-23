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

#include <twc/twc.h>

#include <twc/preference.h>
#include <twc/ErrorWidget.h>
#include <twc/Registration.h>
#include <twc/MainWindow.h>

#include <twc/icons.h>
#include <twc/notify.h>

#include <twitc/twitc.h>

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

  byte_t
  main(int argc, char *argv[])
  {

    debug ("PROG_DIR:\t%s", PROG_DIR);debug ("ICONS_DIR:\t%s", ICONS_DIR);debug ("PACKAGE_LOCALE_DIR:\t%s", PACKAGE_LOCALE_DIR);

    fprintf(stdout, "\n\nTwitCrusader - Twitter Client For Linux Desktop\n");
    fprintf(stdout, "Copyright (C) 2012  TwitCrusader Team\n\n");

    ProgramPath_t *pp = initProgPath(PROG_PATH, AVATAR_DIR, CONFIG_DIR,
        CONFIG_FILE, PREFERENCE_FILE);

    if (pp)
      {

        if (createDirectory(pp->progDir))
          {
            createDirectory(pp->avatarDir);
          }

        string_t fileLock = NULL;
        asprintf(&fileLock, "%s/%s.lock", pp->progDir, PROG_NAME);

        string_t fileName = NULL;
        asprintf(&fileName, "%s/%s.log", pp->progDir, PROG_NAME);

        uninitProgPath(pp);

        initLog(fileName, (1024 * 1000));

        notifyInit ();

        notifyMsg("\tStarted", 100);

        if( !g_thread_supported() )
          {
            g_thread_init(NULL);
            gdk_threads_init();

            info("g_thread supported");
          }
        else
          {
            info("g_thread NOT supported");
          }

        if (gtk_init_check(&argc, &argv))
          {
            debug ("GTK initialized");

            startTrayIcon();

            StartGUI();

            gdk_threads_enter();
            gtk_main();
            gdk_threads_leave();
          }
        else
          error("GTK can't be initialized");

        notifyMsg("\tStopped", 100);

        notifyUninit ();

      }

    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
