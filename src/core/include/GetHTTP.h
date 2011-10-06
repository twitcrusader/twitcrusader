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

#ifndef GETHTTP_H_
#define GETHTTP_H_

/*
 *
 */
#include <glibmm.h>
#include <curl/curl.h>
#include <pthread.h>

using  namespace std;
using  namespace Glib;

namespace TwitCrusader {

class GetHTTP {

public:

	static size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream);
	static void getSingleCURL(ustring url, ustring file);
	int getMultiCURL(char **url, char **file, int max_num_tid);
	static void pull_one_url(void *argv);

};
}

#endif /* GETHTTP_H_ */
