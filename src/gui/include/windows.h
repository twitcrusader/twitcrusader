/*
 * gtkfunction.h
 *
 *  Created on: 04/giu/2011
 *      Author: darkstar
 */

#ifndef GTKFUNCTION_H_
#define GTKFUNCTION_H_

#define _GNU_SOURCE
#include <stdio.h>

#include <gtk/gtk.h>
#include <glib.h>
#include <pthread.h>
#include <gdk/gdkkeysyms.h>

#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "gtkfunctions.h"

#include "../../core/include/functions.h"
#include "../../core/include/twitter.h"
#include "../../core/include/gethttp.h"

#define ICON_SETTINGS ICONS_DIR"/setting.png"
#define ICON_ABOUT ICONS_DIR"/tw_about.png"
#define ICON_STAR ICONS_DIR"/star.png"
#define ICON_ADDUSER ICONS_DIR"/add-user.png"
#define ICON_SIGNIN ICONS_DIR"/sign-in-with-twitter.png"
#define ICON_FAVICON ICONS_DIR"/favicon.png"
#define ICON_CLOSE ICONS_DIR"/close.png"
#define ICON_HOME ICONS_DIR"/home.png"
#define ICON_UPDATE ICONS_DIR"/update.png"
#define ICON_UPGRADE ICONS_DIR"/upgrade.png"
#define ICON_MENTION ICONS_DIR"/mention.png"
#define ICON_DM ICONS_DIR"/dm.png"
#define ICON_FAVORITES ICONS_DIR"/favorites.png"
#define ICON_LINK ICONS_DIR"/link.png"
#define ICON_PHOTO ICONS_DIR"/photo.png"

void windowError(char* error_msg);
void windowOption();
void windowUpgrade();
void windowCredits();
int windowAddUser();
int windowMain(int argc, char **argv);

#endif /* GTKFUNCTION_H_ */
