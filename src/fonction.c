/*************************************************
*       
*       fonction.c
*
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "file.h"
#include "fonction.h"
#include "ncurses.h"

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

/*  We get the char and determinate what to do with it
 *  kind of menu, with:
 *  q == quit
 *  ? == help menu
 *  
 *  j == go down
 *  k == go up
 *
 *  space == display informations
 */

int getFonctionMenu (unsigned char c, struct Entry *entry, int *nbrOfEntry, int *selected, char *passfilePath)
{
    switch (c)
    {
        case 'q':
            endwin();
            return 2;
        
        case '?':
            windowHelp();
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        case ' ':
            displayDetail(entry[*selected], selected);
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        case 'j':
            if(*selected < *nbrOfEntry)
                *selected = *selected + 1;
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        case 'k':
            if(*selected >= 1)
                *selected = *selected - 1;
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        case 'd':
            if(confirmationWindow() == 1)
                deleteEntry(selected, entry, nbrOfEntry, passfilePath);
            int row; row = 0;
            int col; col = 0;
            getmaxyx(stdscr, row, col);
            
            if(*nbrOfEntry <= (row -5))
            {
                /* if the one deleted is the last one   */
                if(*selected >= *nbrOfEntry)
                    *selected = *nbrOfEntry;
            }
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        case 'a':
            addEntry(selected, entry, nbrOfEntry, passfilePath);
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;

        default:
            windowBasic(entry, *nbrOfEntry, selected, c);
            break;
    }
return 0;
}
