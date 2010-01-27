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

/*  We take the environment path with getenv fonction,
 *  into a buffer.
 *  return 0 if good, else return 1
 */
 int getHomeDir (char *homedir)
 {
    char *buffer;
    homedir == NULL;
    if( (buffer = getenv ( "HOME" )) != NULL)
    {
        if(strcat(buffer, "/.passcurse/"))
        {
            if(strcpy(homedir, buffer))
            {
                return 0;
            }
        }
    }
    printf("Error getting the environment path\n");
    return 1;
}

/*  We just add pass.txt to the homedir (attention
 *  homedir = /home/user/.passcurse/
 */
int getPassfilePath (char *homedir, char *passfilePath)
{
    char buffer[256] = {0};
    if(strcpy (buffer, homedir))
    {
        if(strcat (buffer, "pass.txt"))
        {
            if (strcpy(passfilePath, buffer))
            {
                return 0;
            }
        }
    }
    printf("Couldn't attributed passfile path\n");
    return 1;
}
