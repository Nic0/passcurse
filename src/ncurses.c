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

    y = 1;
    x = 5;

    getMenuBar();

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

void getMenuBar(void)
{
    move(0,5);
    printw("name:");
}
