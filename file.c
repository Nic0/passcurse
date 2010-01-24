#include <stdio.h>
#include <stdlib.h>

#include "file.h"

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
