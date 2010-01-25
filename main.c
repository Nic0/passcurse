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

#include "file.h"

/*  ELEMENT is the numbre of items in the Entry's structure */
#define ELEMENT 3
#define NB_ENTRY 10

int main (void)
{
    /*  First, we go throught the file to know how many
     *  structure name/login/pass we've got.
     *  We count lines, and give "lines/ELEMENT" structures
     */
    int nbrOfLine = 0;
    countLine (nbrOfLine);

    /*  Very simple calcul to get the number of entry
     */
    int nbrOfEntry;
    /*nbrOfEntry = nbrOfLine / ELEMENT;*/
    nbrOfEntry = 1; 

    /*  We take for each entry juste his name
     *  It's put in the entry.name structure
     */

    struct Entry entry[NB_ENTRY];

    getNameEntry(entry);

    /*  !!  Debug fonction  !!      */
    int n;
    for (n = 0;n <= nbrOfEntry; n++)
    {
        printf("entry: %s\n", entry[n].name);
    }
    /*  !! END of Debug fonction !! */


    /*FILE *passfile;
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
                strcpy(entry[i].name, buffer);
                printf("entry: %s\n", entry[i].name);
                i++;
            }
            n++;
        }
        fclose (passfile);
    }*/
    
    return EXIT_SUCCESS;
}
