/* 
*	TwitCrusader - Twitter Client For Linux Desktop
*		Copyright (C) 2011  PTKDev
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
*		Author: Patryk Rzucidlo (PTKDev)
*		Twitter: @ptkdev / @twitcrusader_en
*		WebSite: http://www.twitcrusader.org
*/

#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

//TwitCrusader Header File
#include "twc.h"

char* twitter_key()
{
	return "df4eyJjVngL2HWtaS8GcQ";
}

char* twitter_key_secret()
{
	return "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU";
}

//Twitter Access Token: Authorize TwitCrusader
char* access_token(const gchar *pin)
{
        const char *req_url = NULL; 
        const char *c_key    = twitter_key();
        const char *c_secret = twitter_key_secret();
        char *access_token_uri = "http://api.twitter.com/oauth/access_token?";
		char *pin_parm = "oauth_verifier=";	
		char *url_pin= NULL;	
		char *pin_url = malloc(strlen(pin_parm) + strlen(pin) + 1);
		if (pin_url != NULL )
		{
		 strcpy(pin_url, pin_parm);
		 strcat(pin_url, pin);
		}

        req_url = oauth_sign_url2(access_token_uri, &pin_url, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
        printf(req_url);
        url_pin = oauth_http_post(req_url,pin_url);
		printf(url_pin);
		
        return url_pin;
}

//Twitter Request Token: Generate URL For PIN
char* request_token(const char* c_key, const char* c_secret)
{
        const char *req_url = NULL; 
        const char *postarg = NULL;
        char *reply = NULL;

        const char *request_token_uri = "https://api.twitter.com/oauth/request_token";

        req_url = oauth_sign_url2(request_token_uri, NULL, OA_HMAC, NULL, c_key, c_secret, NULL, NULL);
        reply = oauth_http_get(req_url,postarg);
        return reply;
}

//Twitter oAuth
int oauth_start()
{
        const char *c_key    = twitter_key();
        const char *c_secret = twitter_key_secret();

        const char *tw_url = "xdg-open http://twitter.com/oauth/authorize?";
        const char *token_url = request_token(c_key, c_secret);

		char *oauth_url = malloc(strlen(tw_url) + strlen(token_url) + 1);
		if (oauth_url != NULL )
		{
		 strcpy(oauth_url, tw_url);
		 strcat(oauth_url, token_url);
		}
        system(oauth_url);
        
        return 0;
}

// New User oAuth Request
void windows_adduser()
{
	// Variables
	GtkWidget *window, *table, *label, *entry_nick, *entry_api, *button;
	GError *error = NULL;
	
	// Standard GTK Windows Declaration
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 280);
	gtk_widget_set_size_request (window, 310, 280);
	gtk_window_set_title (GTK_WINDOW(window), "Nuovo Utente");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "../img/add_user.png", &error);

	// Table Content Input
	table = gtk_table_new (12, 10, TRUE);

	label = gtk_label_new ("UserName Twitter (Senza @):");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	entry_nick = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (entry_nick), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					1, 2, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
					2, 3, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);	 

	button = gtk_button_new_with_label ("Ottieni Autorizzazione (PIN)");
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(oauth_start), NULL);
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
					4, 5, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	label = gtk_label_new ("Inserisci PIN");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	entry_api = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (entry_api), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					6, 7, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
					7, 8, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	button = gtk_button_new_with_label ("Crea Account");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
					9, 11, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_container_add (GTK_CONTAINER (window), table); 
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(access_token), (gpointer)gtk_entry_get_text (GTK_ENTRY (entry_nick)));
	
	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	
	// Widget Show
	gtk_widget_show_all (window);
}
