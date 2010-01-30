/*******************************************
*       ncurses.c
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "file.h"
#include "ncurses.h"

void windowInit(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    refresh();
}

void windowBasic(struct Entry *entryName, int nbrOfEntry)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);

    int n;
    int y, x;
    x = 5; y = 2;

    getHeaders();

    for (n = 0; n <= nbrOfEntry; n++)
    {   /* TODO make sure the description don't go out of 
         * the windows, with getmax calcul and %s
         */
        y++;
        move(y, x);
        char buffer1[32] = {0};
        char buffer2[521] = {0};
        
        strncpy (buffer1, entryName[n].name, 14*sizeof(char));
        strncpy (buffer2, entryName[n].description, sizeof(char)*(col - 22));
        printw("%s", buffer1);
        move(y, x+15);
        printw("%s", buffer2);
    }
    refresh();
}
/*  This display the headers,
 *  names: ... description: ...
 */

void getHeaders(void)
{
    move(1,5);
    printw("name:");
    move(1,20);
    printw("description:");
}

void windowHelp (void)
{

}
