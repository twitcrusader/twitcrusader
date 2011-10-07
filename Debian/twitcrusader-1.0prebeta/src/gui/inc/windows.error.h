/*
 * windows.error.h
 *
 *  Created on: 17/set/2011
 *      Author: darkstar
 */

#ifndef WINDOWS_ERROR_H_
#define WINDOWS_ERROR_H_

/* CharSet */
#define MY_ENCODING "ISO-8859-1"

/* Fix: GCC Linux Compiler */
#define _GNU_SOURCE

/* Headers */
#include <gtk/gtk.h>

#include "icons.h"

#include "../../core/inc/debug.h"
#include "../../core/inc/lang.h"

/* Define Function */

void gtk_window_error(char* error_msg);

#endif /* WINDOWS_ERROR_H_ */
