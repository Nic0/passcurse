/*************************************************
*       
*       fonction.c
*
**************************************************/

/*  Fonction to get the home variable 
 *  stock in homedir 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "fonction.h"

 int getHomeDir (char *homedir)
 {
    char *buffer;
    homedir == NULL;
    if( (buffer = getenv ( "HOME" )) == NULL)
    {
        printf("Error getting the environment path\n");
        return 1;
    }
    if(!strcpy(homedir, buffer))
    {
        printf("Error getting the environment path\n");
        return 1;
    }
    return 0;
}

