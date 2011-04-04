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
#define _GNU_SOURCE
#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oauth.h>

//TwitCrusader Header File
#include "twc.h"

//TwitCrusader - Twitter Key
char* twitter_key()
{
	return "df4eyJjVngL2HWtaS8GcQ";
}

//TwitCrusader - Twitter SecretKey
char* twitter_key_secret()
{
	return "svqV9Colm55tJwvh1RCvvIu2ZTBhs7eN9Y084y1qhbU";
}

//Parser Url
char* get_param(char** argv, int argc, const char* param)
{
	int i, param_len;

	param_len = strlen(param);
	for (i = 0; i < argc; i++) {
		if (!strncmp(argv[i], param, param_len) && strlen(argv[i]) > param_len && argv[i][param_len] == '=')
			return strdup(&argv[i][param_len + 1]);
	}

	return 0;
}

//Twitter Access Token: Authorize TwitCrusader
char* access_token(GtkButton *button, AuthWidget *DataInput)
{
	const char *req_url = NULL; 
	const char *pin = gtk_entry_get_text (GTK_ENTRY (DataInput->pin));
	char *access_token_url = "http://api.twitter.com/oauth/access_token";
	char *oauth_request = NULL;
	char *postarg = NULL;
	
	char buffer[256];
	FILE *fp;
	char* t_key =  NULL;
	char* t_key_secret =  NULL;
	char* c_key =  NULL;
	char* c_key_secret = NULL;
	
	fp = fopen ("tmp_token", "r");
	fgets(buffer, 250, fp);
	int rc;
	char **rv = NULL;
	rc = oauth_split_url_parameters(buffer, &rv);
	t_key = get_param(rv, rc, "oauth_token");
	t_key_secret = get_param(rv, rc, "oauth_token_secret");
	c_key = get_param(rv, rc, "c_key");
	c_key_secret = get_param(rv, rc, "c_key_secret");
	fclose (fp);
   
	asprintf(&access_token_url, "%s?oauth_verifier=%s", access_token_url, pin);
	req_url = oauth_sign_url2(access_token_url, &postarg, OA_HMAC, NULL, c_key, c_key_secret, t_key, t_key_secret);
	oauth_request = oauth_http_post(req_url,postarg);
	
	rc = oauth_split_url_parameters(oauth_request, &rv);
	char *user_token = get_param(rv, rc, "oauth_token");
	char *user_token_secret = get_param(rv, rc, "oauth_token_secret");
	char *user_id = get_param(rv, rc, "user_id");
	char *screen_name = get_param(rv, rc, "screen_name");
	
	fp=fopen("user", "w+");
	fprintf(fp, screen_name);
	fprintf(fp, "||");
	fprintf(fp, user_id);
	fprintf(fp, "||");
	fprintf(fp, c_key);
	fprintf(fp, "||");
	fprintf(fp, c_key_secret);
	fprintf(fp, "||");
	fprintf(fp, user_token);
	fprintf(fp, "||");
	fprintf(fp, user_token_secret);
	fclose(fp);
	
	remove("tmp_token");
	
	return oauth_request;
}

//Twitter Request Token: Generate URL For PIN
char* request_token(const char *c_key, const char *c_key_secret)
{
	char *postarg = NULL;
	const char *request_url = "https://api.twitter.com/oauth/request_token";
		
	const char *oauth_sign = oauth_sign_url2(request_url, NULL, OA_HMAC, NULL, c_key, c_key_secret, NULL, NULL);
	char *oauth_http_access = oauth_http_get(oauth_sign,postarg);
	
	return oauth_http_access;
}

//Twitter oAuth
int oauth_start()
{
	char *cmd;
	const char *authorize_url = "http://twitter.com/oauth/authorize";
	
	const char *c_key    = twitter_key();
	const char *c_key_secret = twitter_key_secret();

	int rc;
	char **rv = NULL;
	char *twitter_oauth = request_token(c_key, c_key_secret);
	rc = oauth_split_url_parameters(twitter_oauth, &rv);
	char* t_key = get_param(rv, rc, "oauth_token");
    
	asprintf(&cmd, "xdg-open \"%s?oauth_token=%s\"", authorize_url, t_key);
	system(cmd);
    
    asprintf(&twitter_oauth, "%s%s%s%s%s", twitter_oauth, "&c_key=", c_key, "&c_key_secret=", c_key_secret);
	FILE *fp;
	fp=fopen("tmp_token", "w+");
	fprintf(fp, twitter_oauth);
	fclose(fp);

	return 0;
}

// New User oAuth Request
void windows_adduser()
{
	// Variables
	GtkWidget *window, *table, *label, *button,*twitter_login,*tw_login_imgevent;
	GError *error = NULL;
	AuthWidget *DataInput;
	
	// allocate space for struct
	DataInput = g_slice_new (AuthWidget); 
	
	// Standard GTK Windows Declaration
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 240);
	gtk_widget_set_size_request (window, 310, 240);
	gtk_window_set_title (GTK_WINDOW(window), "Nuovo Utente");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	// GTK Windows Declaration: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "/usr/share/icons/twitcrusader/add_user.png", &error);

	// Table Content Input
	table = gtk_table_new (10, 10, TRUE);

	twitter_login = gtk_image_new_from_file ("/usr/share/icons/twitcrusader/sign-in-with-twitter.png");
	tw_login_imgevent = gtk_event_box_new ();
	gtk_container_add (GTK_CONTAINER (tw_login_imgevent), twitter_login);
	gtk_table_attach (GTK_TABLE (table), tw_login_imgevent, 2, 8,
					1, 3, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0); 
	g_signal_connect (G_OBJECT (tw_login_imgevent), "button_press_event", G_CALLBACK(oauth_start), NULL);
					 
	label = gtk_label_new ("Inserisci PIN");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	DataInput->pin = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (DataInput->pin), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					4, 5, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), DataInput->pin, 1, 9,
					5, 6, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	button = gtk_button_new_with_label ("Crea Account");
	gtk_table_attach (GTK_TABLE (table), button, 1, 9,
					7, 9, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_container_add (GTK_CONTAINER (window), table); 
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(access_token), DataInput);
	
	// CALLBACK: exit event
	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	
	// Widget Show
	gtk_widget_show_all (window);
}
