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

//Sum String
char *sum_string(char *parm1, char *parm2 ){
	
	
	char *parm = malloc(strlen(parm1) + strlen(parm2) + 1);
	if (parm != NULL )
	{
	 strcpy(parm, parm1);
	 strcat(parm, parm2);
	}
		
	return parm;
}
