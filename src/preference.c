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

#include <logc/logc.h>

#include <twc/twc.h>
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

string_t
MakeAvatarName(string_t url, string_t screen_name, string_t dir)
{

  string_t avatarName = NULL;

  if (url)
    {

      debug("url: %s", url);
      string_t filename = fileNameFromUrl(url);

      if (filename)
        asprintf(&avatarName, "%s/%s_%s", dir, filename, screen_name);

    }

  return avatarName;
}

byte_t
_downloadAvatar(string_t url, string_t screen_name, string_t dir)
{

  string_t avatarName = MakeAvatarName(url, screen_name, dir);

  if (avatarName)
    {
      FILE *fp = fopen(avatarName, "r");
      if (!fp)
        getFileCURL(url, avatarName);

      if (fp)
        fclose(fp);

      return EXIT_SUCCESS;
    }

  return EXIT_FAILURE;
}

void
downloadAvatar(progData_t *progData)
{

  int i = 0;

  for (i = 0; i < MAX_NUM_TWEETS; i++)
    {

      if (progData->home_tl.statuses[i].user.profile_image_url
          && progData->home_tl.statuses[i].user.screen_name)
        _downloadAvatar(progData->home_tl.statuses[i].user.profile_image_url,
            progData->home_tl.statuses[i].user.screen_name,
            progData->pp->avatarDir);

      if (progData->mentions_tl.statuses[i].user.profile_image_url
          && progData->mentions_tl.statuses[i].user.screen_name)
        _downloadAvatar(
            progData->mentions_tl.statuses[i].user.profile_image_url,
            progData->mentions_tl.statuses[i].user.screen_name,
            progData->pp->avatarDir);

      if (progData->favorites_tl.statuses[i].user.profile_image_url
          && progData->favorites_tl.statuses[i].user.screen_name)
        _downloadAvatar(
            progData->favorites_tl.statuses[i].user.profile_image_url,
            progData->favorites_tl.statuses[i].user.screen_name,
            progData->pp->avatarDir);

    }

  for (i = 0; i < MAX_NUM_DM; i++)
    {

      if (progData->dm_rx.directMessage[i].sender.profile_image_url
          && progData->dm_rx.directMessage[i].sender.screen_name, progData->pp->avatarDir)
        _downloadAvatar(
            progData->dm_rx.directMessage[i].sender.profile_image_url,
            progData->dm_rx.directMessage[i].sender.screen_name,
            progData->pp->avatarDir);

      if (progData->dm_tx.directMessage[i].sender.profile_image_url
          && progData->dm_tx.directMessage[i].sender.screen_name)
        _downloadAvatar(
            progData->dm_tx.directMessage[i].sender.profile_image_url,
            progData->dm_tx.directMessage[i].sender.screen_name,
            progData->pp->avatarDir);
    }
}

void
initProgData(progData_t *progData)
{

  progData->pp = initProgPath(PROG_PATH, AVATAR_DIR, CONFIG_DIR, CONFIG_FILE,
      PREFERENCE_FILE);

  progData->twURLS = initURLS(OAUTH_URL_DEFAULT, API_URL_DEFAULT,
      SEARCH_URL_DEFAULT);

  progData->user = readUserFile(progData->pp->configFile);

}

void
updateProgData(progData_t *progData)
{

  if (!progData->pp)
    progData->pp = initProgPath(PROG_PATH, AVATAR_DIR, CONFIG_DIR, CONFIG_FILE,
        PREFERENCE_FILE);

  if (!progData->pp)
    progData->twURLS = initURLS(OAUTH_URL_DEFAULT, API_URL_DEFAULT,
        SEARCH_URL_DEFAULT);

  if (!progData->user)
    progData->user = readUserFile(progData->pp->configFile);

  if (progData->user)
    {

      uninitTimeline(&progData->favorites_tl);
      uninitTimeline(&progData->home_tl);
      uninitTimeline(&progData->mentions_tl);
      uninitDirectMessages(&progData->dm_rx);
      uninitDirectMessages(&progData->dm_tx);

      string_t raw = getRawTimeline(progData->twURLS, home_timeline,
          progData->user);
      progData->home_tl = readTimeLine(raw);
      if (raw)
        free(raw);

      raw = getRawFavorites(progData->twURLS, progData->user);
      progData->favorites_tl = readTimeLine(raw);
      if (raw)
        free(raw);

      raw = getRawTimeline(progData->twURLS, mentions, progData->user);
      progData->mentions_tl = readTimeLine(raw);
      if (raw)
        free(raw);

      raw = getRawDM(progData->twURLS, progData->user);
      progData->dm_rx = readDMs(raw);
      if (raw)
        free(raw);

      raw = getRawSentDM(progData->twURLS, progData->user);
      progData->dm_tx = readDMs(raw);
      if (raw)
        free(raw);

      downloadAvatar(progData);
    }
}

void
uninitProgData(progData_t *progData)
{

  uninitTimeline(&progData->favorites_tl);
  uninitTimeline(&progData->home_tl);
  uninitTimeline(&progData->mentions_tl);
  uninitDirectMessages(&progData->dm_rx);
  uninitDirectMessages(&progData->dm_tx);

  uninitProgPath(progData->pp);
  uninitURLS(progData->twURLS);
  uninitUser(progData->user);
}

#ifdef __cplusplus
}
#endif
