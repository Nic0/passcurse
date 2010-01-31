/*******************************************
*       ncurses.c
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "file.h"
#include "ncurses.h"

/*  This fonction call the basics parameters, to initialize
 *  the ncurses environment
 */

void windowInit(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    refresh();
}

/*  This is the MAIN window, kind of background window, with
 *  the list of name and description from each passes entry
 */

void windowBasic(struct Entry *entryName, int nbrOfEntry)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);

    int n;
    int y, x;
    x = 5; y = 2;
    /*  call of name:... description:...        */
    getHeaders();
    
    /*  We take the width of the window, to make sure the descriptions
     *  dont go out of the window
     */
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

/*  This display the headers on the basic window
 *  names: ... description: ...
 *  (and no more)
 */

void getHeaders(void)
{
    move(1,5);
    printw("name:");
    move(1,20);
    printw("description:");
}

/*  This fonction show a window with a help menu in it
 *  It call two other fonctions, to create and destroy
 *  the window, 
 *  This fonction dosn't realy containt the help menu
 *  Go to the create_helpwindow fonction to edit the menu
 */
void windowHelp (void)
{   
    int row = 0;
    int col = 0;
    getmaxyx(stdscr, row, col);

    int leight = 20;
    int widht  = 70;
    int starty = 3;
    int startx = 5; 

    /*if(row > 30)
    {
        leight = 30;
        starty = row / 2 - 16;
    }
    else
    {
        leight = row;
        starty = 0;
    }

    if(col > 50)
    {
        widht = 50;
        startx = col / 2 - 25;
    }
    else
        widht = col;
        startx = 0;
    }*/

    WINDOW *help_window;
    help_window = create_helpwindow(leight, widht, starty, startx);
    getchar();
    destroy_win(help_window);
}

/*  The menu help window call with the '?' key
 */

WINDOW *create_helpwindow(int leight, int widht, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin (leight, widht, starty, startx);
    box (local_win, 0, 0);
    
    mvwprintw (local_win, 2, 5,  "q");
    mvwprintw (local_win, 2, 20, "Quit");
    mvwprintw (local_win, 3, 5, "?");
    mvwprintw (local_win, 3, 20, "Display this help menu");
    mvwprintw (local_win, 5, 5, "a");
    mvwprintw (local_win, 5, 20, "Add a new entry");
    mvwprintw (local_win, 6, 5, "d");
    mvwprintw (local_win, 6, 20, "Delete an entry");

    wrefresh (local_win);
    return local_win;
}

/*  This fonction destroy any kind of pop-up windows
 */

void destroy_win(WINDOW *local_win)
{ 
    wborder (local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wprintw (local_win, "                                         ");
    
    int n;
    for(n = 2; n <= 10; n++)
    {
        mvwprintw (local_win, n, 1,"                                               ");
    }

    wrefresh (local_win);
    delwin (local_win);
}