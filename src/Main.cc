/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
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
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "Main.h"

int main(int argc, char *argv[]){

	notify_init(PROG_NAME);
	Functions::notifySystem("Started..");

	cout<<"\n\n";
	cout<<"TwitCrusader - Twitter Client For Linux Desktop\n";
	cout<<"Copyright (C) 2011  TwitCrusader Team\n\n";

	twitter=Twitter();


	if(Functions::shellParameters(argc,argv))return 0;

	//initialize to use threads
	Glib::thread_init() ;

	//initialize Gtk
	Gtk::Main kit(argc, argv);

	if(!twitter.config.is_registered()){
		RegDialog regDialog;
	}

	MainWindow window;

	//Shows the window and returns when it is closed.
	kit.run(window);

	notify_uninit();

	return 0;
}
