#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#define ELEMENT 3

int countLine(int nbrOfLine)
{
    nbrOfLine = 0;
    char buffer[256] = {0};

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

void getNameEntry (struct Entry *addrEntry[])
{
    FILE *passfile;
    passfile = fopen("/home/nicolas/pass.txt", "r");

    if(passfile != NULL)
    {
        int n = 0;
        int i = 0;
        char buffer[256];

        while(1)
        {
            fscanf(passfile, "%s", buffer);
            if(feof(passfile)) break;

            if( n % ELEMENT == 0)
            {
                strcpy(addrEntry[i] -> name, buffer);
                i++;
            }
        }
        fclose(passfile);
    }
}
