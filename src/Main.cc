/*
 *	 TwitCrusader-GUI is part of TwitCrusader - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader Team
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
 *		WebSite: http://www.twitcrusader.org/
 * 		Development Guidelines: http://dev.twitcrusader.org/
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */
#include "Main.h"

using namespace std;

int main(int argc, char *argv[]){

	notify_init(PROG_NAME);

	cout<<"\n\n";
	cout<<"TwitCrusader - Twitter Client For Linux Desktop\n";
	cout<<"Copyright (C) 2011  TwitCrusader Team\n\n";

	if(Functions::shellParameters(argc,argv))return 0;

	Gtk::Main kit(argc, argv);

	MainWindow window;

	//Shows the window and returns when it is closed.
	Gtk::Main::run(window);

	notify_uninit();

	return 0;
}

