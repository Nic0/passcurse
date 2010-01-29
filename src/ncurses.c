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

    y = 2;
    x = 5;

    getHeaders();

    for (n = 0; n <= nbrOfEntry; n++)
    {
        y++;
        move(y, x);
        printw("%s", entryName[n].name);
    }
    refresh();
    getchar();
    endwin();
}
/*  This display the headers,
 *  names: ... description: ...
 */

void getHeaders(void)
{
    move(1,5);
    printw("name:");
    move(1,15);
    printw("description:");
}
