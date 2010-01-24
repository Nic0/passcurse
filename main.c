/**********************************************************************
*
*               Passcurse
*
*               V 0.01
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define ELEMENT

/*  Main struct for each pass's entry   */
struct Entry {
    char name[128];
    char login[32];
    char pass[32];
};

int main (void)
{
    int nbrOfLine = 0;
    char buffer[256];
    

    /*  First, we go throught the file to know how many
     *  structure name/login/pass we've got.
     *  We count lines, and give "lines/ELEMENT" structures
     */

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
    
    /*  We take for each entry juste his name
     *  It's put in the entry.name structure
     */

    passfile = fopen("/home/nicolas/pass.txt", "r");

    if(passfile != NULL)
    {
        int nbrOfEntry;
        nbrOfEntry = nbrOfLine / ELEMENT;
        struct Entry entry[nbrOfEntry];
        int n = 0;

        while(1)
        {
            fscanf(passfile, "%s", entry[n].name);     
            if (feof(passfile)) break;
            printf("entry: %s\n", entry[n].name);
            n++;
        }
        fclose (passfile);
    }
    
    return EXIT_SUCCESS;
}
