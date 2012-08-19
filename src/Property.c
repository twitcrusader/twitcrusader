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

#include <twitc/twitc.h>

#include <twc/twc.h>
#include <twc/preference.h>
#include <twc/Property.h>
#include <twc/Registration.h>
#include <twc/MainWindow.h>
#include <twc/icons.h>

#include <gtk/gtk.h>

static GtkWidget *dialog = NULL;

void
deleteAccount()
{
  ProgramPath_t *pp = initProgPath(PROG_PATH, AVATAR_DIR, CONFIG_DIR,
      CONFIG_FILE, PREFERENCE_FILE);

  removeFile(pp->configFile);
  uninitProgPath(pp);

  gtk_widget_destroy(dialog);
  StartGUI();
}

void
startWindowProperties(user_t * user, GtkWidget * window)
{

  GtkWidget *table = gtk_table_new(7, 10, TRUE);
  GtkWidget *notebook = gtk_notebook_new();

  dialog = gtk_dialog_new();
  gtk_window_set_transient_for(GTK_WINDOW (dialog), GTK_WINDOW (window) );
  gtk_window_set_title(GTK_WINDOW (dialog), "Property");
  gtk_container_set_border_width(GTK_CONTAINER (dialog), 0);
  gtk_window_set_position(GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  GError *error = NULL;
  gtk_window_set_icon_from_file(GTK_WINDOW (dialog), ICONS_DIR "" ICON_SETTINGS,
      &error);
  if (error)
    {
      error((string_t) error->message);
      g_error_free(error);
      error = NULL;
    }
  gtk_notebook_set_tab_pos(GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

  /* Set all functions of Account TAB */
  table = gtk_table_new(6, 12, TRUE);
  GtkWidget *combo = gtk_combo_box_text_new();
  GtkWidget *settingMenu = gtk_label_new("Account");

  GtkWidget *label = gtk_label_new("Twitter's Account:");
  gtk_label_set_justify(GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  gtk_table_attach(GTK_TABLE (table), label, 1, 11, 0, 1, GTK_FILL | GTK_EXPAND,
      GTK_FILL | GTK_EXPAND, 0, 0);

  if (user)
    {
      gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT (combo),
          user->screenName);
      GtkWidget *button = gtk_button_new_with_label("Delete");
      gtk_table_attach(GTK_TABLE (table), button, 4, 8, 5, 6,
          GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 0, 0);
      g_signal_connect(G_OBJECT (button), "clicked", G_CALLBACK (deleteAccount),
          NULL);

    }

  gtk_table_attach(GTK_TABLE (table), combo, 2, 10, 1, 2, GTK_FILL | GTK_EXPAND,
      GTK_FILL | GTK_EXPAND, 0, 0);

  /* Set switch-TAB signal */
  gtk_notebook_append_page(GTK_NOTEBOOK (notebook), table, settingMenu);

  /* Attach tab-notebook at window container */
  gtk_dialog_add_action_widget(GTK_DIALOG (dialog), notebook,
      GTK_RESPONSE_APPLY);

  g_signal_connect_swapped(dialog, "response", G_CALLBACK (gtk_widget_destroy),
      dialog);

  gtk_widget_show_all(dialog);

  gtk_dialog_run(GTK_DIALOG (dialog) );

}
