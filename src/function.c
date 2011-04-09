/*
*	TwitCrusader - Twitter Client For Linux Desktop
*		Copyright (C) 2011  PTKDev, RoxShannon
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

#include "inc/function.h"

/*  
 * This function add string1 + string2 = string3
 * Exemple: "AL" + "EX" = "ALEX"
 * 
 */
char *sum_string(char *parm1, char *parm2 ){

	/* molloc function return a number of bytes of parm1 + parm2 */
	char *parm = malloc(strlen(parm1) + strlen(parm2) + 1);
	if (parm != NULL )
	{
		/* Add parm1 + parm2 for return sum of 2 variables */
		strcpy(parm, parm1);
		strcat(parm, parm2);
	}

	return parm;
}


/*  
 * This function split url-parameters with delimiter char
 * WARINING: use it with oauth_split_url_parameters() for variables rv
 * 
 * Exemple: 
 * param = oauth_token
 * rc = 1
 * rv = oauth=XXXXXXXXXX&token=ZZZZZZZZZ
 * Return = XXXXXXXXXX
 * 
 */
char* get_param(char** argv, int argc, const char* param)
{
	int i, 
		param_len;
	
	/* count lenght of input parameters */
	param_len = strlen(param);
	
	for (i = 0; i < argc; i++) {
		/* Split parameter after = */
		if (!strncmp(argv[i], param, param_len) && strlen(argv[i]) > param_len && argv[i][param_len] == '=')
		
			/* Return a parameters after delimiter = */
			return strdup(&argv[i][param_len + 1]);
	}

	return 0;
}

/*  
 * Debug Function
 * 
 */
void debug (int argc, char **argv)
{
	int count;

	/* return debug of 1 parameter */
	printf ("This program was called with \"%s\".\n",argv[0]);

	/* return debug of all parameters */
	if (argc > 1){
		for (count = 1; count < argc; count++)
		{
		  printf("argv[%d] = %s\n", count, argv[count]);
		}
	}else{
		printf("The command had no other arguments.\n");
	}

}
