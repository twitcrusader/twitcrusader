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

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

#include "../dependences/libtwitc/twitc.h"

#define		MY_ENCODING						"ISO-8859-1"

typedef struct
{
  string_t progDir;
  string_t avatarDir;
  string_t configDir;
  string_t configFile;
  string_t preferenceFile;
} ProgramPath_t;

typedef struct
{
  ProgramPath_t *pp;
  twitterURLS_t *twURLS;
  user_t *user;

  timeline_t home_tl;
  timeline_t mentions_tl;
  timeline_t favorites_tl;
  direct_messages_t dm_rx;
  direct_messages_t dm_tx;
} progData_t;

extern ProgramPath_t *
initProgPath(const string_t, const string_t, const string_t, const string_t,
    const string_t);
extern void
uninitProgPath(ProgramPath_t *);

extern string_t
MakeAvatarName(string_t, string_t, string_t);
extern void
downloadAvatar(progData_t *);
extern void
initProgData(progData_t *);
extern void
updateProgData(progData_t *);
extern void
uninitProgData(progData_t *);

#endif /* PREFERENCE_H_ */
