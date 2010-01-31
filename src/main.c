/**********************************************************************
*
*               Passcurse
*
*               V 0.1
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "file.h"
#include "fonction.h"
#include "ncurses.h"

/*  ELEMENT is the numbre of items in the Entry's structure */
#define ELEMENT 4
#define NB_ENTRY 256

int main (void)
{
    int selected = 0;
    /*  We get the home directory and stock it
     *  return it like /home/user/.passcurse/
     */
    char homedir[128] = {0};
    if( getHomeDir(homedir) == 1 )
    {   return EXIT_FAILURE;    }
    
    char passfilePath[256] = {0};
    if( getPassfilePath(homedir, passfilePath) == 1)
    {   return EXIT_FAILURE;    }
    
    /*  First, we go throught the file to know how many
     *  structure name/login/pass we've got.
     *  We count lines, and give "lines/ELEMENT" structures
     */
    int nbrOfLine = 0;
    nbrOfLine = countLine (passfilePath);


    /*  Very simple calcul to get the number of entry
     *  - 1 because the first entry is 0
     */
    int nbrOfEntry;
    nbrOfEntry = (nbrOfLine / ELEMENT) - 1;

    /*  Initialisation of the basic ncurses window
     */
    windowInit();

    /*  The nbrOfEntry can not be bigger than NB_ENTRY
     *  TODO find something if this happen
     */
    if( nbrOfEntry > NB_ENTRY )
    {
        printf("An unexpected error has occured, too many password found in the passfile");
        nbrOfEntry = NB_ENTRY;
    }


    /*  We take for each entry juste his name
     *  It's put in the entry.name structure
     */
    struct Entry entry[NB_ENTRY];
    /*getNameEntry(entry, passfilePath);*/
    getStructEntry(entry, passfilePath);
    
    while(1)
    {
        unsigned char c;
        /*windowBasic(entry, nbrOfEntry);*/
        if(getFonctionMenu (c, entry, nbrOfEntry, &selected) == 2)
        {
            return EXIT_SUCCESS;
        }
        c = getchar();
    }
    /*  !!  Debug fonction  !!      */
    int n;
    for (n = 0;n <= nbrOfEntry; n++)
    {
        printf("entry: %s\n", entry[n].name);
    }
    /*  !! END of Debug fonction !! */

    return EXIT_SUCCESS;
}
