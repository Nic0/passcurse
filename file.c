/**************************************
*           file.c
**************************************/   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#define ELEMENT 3

/*  this fonction open the passfile, go througt
 *  just to know how many line is in here, and
 *  return it.
 *  As the file containe only one word by line
 *  but has to be change to a proper line
 */

int countLine(int nbrOfLine)
{
    nbrOfLine = 0;
    char buffer[256];

    FILE *passfile = NULL;
    passfile = fopen("/home/nicolas/pass.txt", "r");

    if (passfile != NULL)
    {
        while(1)
        {
            fscanf(passfile, "%s", buffer);
            if (feof(passfile)) break;
            nbrOfLine++;
        }
        fclose(passfile);
    }
return nbrOfLine;
}

/*  this fonction go througt the passfile to return
 *  the name's string in the structure.
 *  It just list names
 */

void getNameEntry (struct Entry addrEntry[])
{
    char buffer[256] = {0};
    FILE *passfile = NULL;
    passfile = fopen("/home/nicolas/pass.txt", "r");

    if(passfile != NULL)
    {
        int n = 0;
        int i = 0;

        while(1)
        {
            fscanf(passfile, "%s", buffer);
            if(feof(passfile)) break;

            if( n % ELEMENT == 0)
            {
                strncpy(addrEntry[i].name, buffer, 120);
                i++;
            }
            n++;
        }
        fclose(passfile);
    }
}
