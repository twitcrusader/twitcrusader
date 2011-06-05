/*
 * gtk-thread.h
 *
 *  Created on: 03/giu/2011
 *      Author: darkstar


#ifndef GTK_THREAD_H_
#define GTK_THREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <pthread.h>

#define YES_IT_IS    (1)
#define NO_IT_IS_NOT (0)

typedef struct
{
  GtkWidget *label;
  int what;
} yes_or_no_args;

G_LOCK_DEFINE_STATIC (yes_or_no);
static volatile int yes_or_no = YES_IT_IS;

void destroy (GtkWidget *widget, gpointer data);
void *argument_thread (void *args);

#endif // GTK_THREAD_H_
*/
