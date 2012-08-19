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

#include <twitc/debug.h>
#include <twitc/stdredef.h>

#include <twc/preference.h>

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <libxml/xmlreader.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#ifdef __cplusplus
extern "C"
  {
#endif

ProgramPath_t *
initProgPath(const string_t programDir, const string_t avatarDir,
    const string_t configDir, const string_t configFile,
    const string_t preferenceFile)
{

  ProgramPath_t *pp = (ProgramPath_t *) malloc(sizeof(ProgramPath_t));

  if (pp)
    {

      uid_t uid = geteuid();
      passwd_t *p = getpwuid(uid);

      if (p != NULL )
        {
          asprintf(&pp->progDir, "%s/%s", p->pw_dir, programDir);
          asprintf(&pp->avatarDir, "%s/%s", pp->progDir, avatarDir);
          asprintf(&pp->configDir, "%s/%s", pp->progDir, configDir);
          asprintf(&pp->configFile, "%s/%s", pp->configDir, configFile);
          asprintf(&pp->preferenceFile, "%s/%s", pp->configDir, preferenceFile);

          debug ("avatarDir:\t%s", pp->avatarDir);debug ("configDir:\t%s", pp->configDir);debug ("configFile:\t%s", pp->configFile);debug ("preferenceFile:\t%s", pp->preferenceFile);debug ("progDir:\t%s", pp->progDir);

          return pp;
        }
    }

  warning("Returned value: (NULL)");
  return NULL ;
}

void
uninitProgPath(ProgramPath_t * pp)
{
  if (pp)
    {
      if (pp->avatarDir)
        free(pp->avatarDir);

      if (pp->configDir)
        free(pp->configDir);

      if (pp->configFile)
        free(pp->configFile);

      if (pp->preferenceFile)
        free(pp->preferenceFile);

      if (pp->progDir)
        free(pp->progDir);

      pp->avatarDir = NULL;
      pp->configDir = NULL;
      pp->configFile = NULL;
      pp->preferenceFile = NULL;
      pp->progDir = NULL;

      free(pp);

    }

  warning("ProgramPath_t uninitialized");
  pp = NULL;

}

#ifdef __cplusplus
}
#endif
