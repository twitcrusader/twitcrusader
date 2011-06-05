/*-------------------------------------------------------------------------
 * Filename:      gtk-thread.c
 * Version:       0.99.1
 * Copyright:     Copyright (C) 1999, Erik Mouw
 * Author:        Erik Mouw <J.A.K.Mouwits.tudelft.nl>
 * Description:   GTK threads example. 
 * Created at:    Sun Oct 17 21:27:09 1999
 * Modified by:   Erik Mouw <J.A.K.Mouwits.tudelft.nl>
 * Modified at:   Sun Oct 24 17:21:41 1999
 *-----------------------------------------------------------------------*/
/*
 * Compile with:
 *
 * $ gcc -Wall -o gtk-thread gtk-thread.c `pkg-config --cflags --libs gtk+-2.0 gthread`
 *
 * Thanks to Sebastian Wilhelmi and Owen Taylor for pointing out some
 * bugs.
 *
*/

/*#include "gtk-thread.h"

void destroy (GtkWidget *widget, gpointer data){
  gtk_main_quit ();
}

void *argument_thread (void *args){
  yes_or_no_args *data = (yes_or_no_args *)args;
  gboolean say_something;

  for (;;)
    {
       sleep a while
      sleep(rand() / (RAND_MAX / 3) + 1);

       lock the yes_or_no_variable
      G_LOCK(yes_or_no);

       do we have to say something?
      say_something = (yes_or_no != data->what);

      if(say_something)
	{
	   set the variable
	  yes_or_no = data->what;
	}

       Unlock the yes_or_no variable
      G_UNLOCK (yes_or_no);

      if (say_something)
	{
	   get GTK thread lock
	  gdk_threads_enter ();

	   set label text
	  if(data->what == YES_IT_IS)
	    gtk_label_set_text (GTK_LABEL (data->label), "O yes, it is!");
	  else
	    gtk_label_set_text (GTK_LABEL (data->label), "O no, it isn't!");

	   release GTK thread lock
	  gdk_threads_leave ();
	}
    }

  return NULL;
}

int main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *label;
  yes_or_no_args yes_args, no_args;
  pthread_t no_tid, yes_tid;

   init threads
  g_thread_init (NULL);
  gdk_threads_init ();
  gdk_threads_enter ();

   init gtk
  gtk_init(&argc, &argv);

   init random number generator
  srand ((unsigned int) time (NULL));

   create a window
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_signal_connect (GTK_OBJECT (window), "destroy",
		      GTK_SIGNAL_FUNC (destroy), NULL);

  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

   create a label
  label = gtk_label_new ("And now for something completely different ...");
  gtk_container_add (GTK_CONTAINER (window), label);
  
   show everything
  gtk_widget_show (label);
  gtk_widget_show (window);

   create the threads
  yes_args.label = label;
  yes_args.what = YES_IT_IS;
  pthread_create (&yes_tid, NULL, argument_thread, &yes_args);

  no_args.label = label;
  no_args.what = NO_IT_IS_NOT;
  pthread_create (&no_tid, NULL, argument_thread, &no_args);

   enter the GTK main loop
  gtk_main ();
  gdk_threads_leave ();

  return 0;
}*/
