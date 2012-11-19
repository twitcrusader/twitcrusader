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


#include "../dependences/libtwitc/stdredef.h"
#include "../dependences/libtwitc/functions.h"

#include "../include/twc.h"

#include "../dependences/liblogc/logc.h"

#include "../include/icons.h"
#include "../include/Credits.h"

#include <gtk/gtk.h>
#include <glib/gi18n.h>

#ifdef __cplusplus
extern "C"
  {
#endif

/* gtk_credits_dialog_create() Function 
 *
 * Developer Guide (Italian): http://dev.it.twitcrusader.org/sourcecode-guide-gtk_credits_dialog_create-function/
 * 
 */
void
startCreditsDialog()
{

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_window_set_title(GTK_WINDOW (dialog), _("Credits"));
  gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG (dialog), PROG_NAME);
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG (dialog), "\0");

  GError *error = NULL;
  gtk_window_set_icon_from_file(GTK_WINDOW (dialog), ICONS_DIR "" ICON_FAVICON,
      &error);

  if (error)
    {
      log(ERROR,(string_t) error->message);
      g_error_free(error);
      error = NULL;
    }

  string_t version = readRawTextFile(PROG_DIR "VERSION");

  if (version)
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG (dialog), version);

  const string_t copyright = "(c) 2012 " PROG_NAME " Team";

  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG (dialog),
      g_markup_escape_text(copyright, strlen(copyright)));

  string_t license = readRawTextFile(PROG_DIR "COPYING");

  if (license)
    gtk_about_dialog_set_license(GTK_ABOUT_DIALOG (dialog), license);

  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG (dialog),
      _("Twitter Client For Linux Desktop"));
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG (dialog), TWC_URL);

  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(ICONS_DIR "" ICON_ABOUT, NULL );
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG (dialog), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;

  gtk_dialog_run(GTK_DIALOG (dialog) );
  gtk_widget_destroy(dialog);
}

#ifdef __cplusplus
}
#endif
