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

void windowBasic(struct Entry *entryName, int nbrOfEntry, int *selected, char c)
{
    int row = 0;
    int col = 0;

    getmaxyx(stdscr, row, col);

    int m;
    int startn;
    int endn;
    int y, x;
    x = 5; y = 2; startn = 0; endn = 0; m = 0;

    getHelpBar(row);
    /*  call of name:... description:...        */
    getHeaders();
    

    /*  if there is not enought row, the last displayed entry
     *  will be the row - 6
     */
    if((row - 5) <= nbrOfEntry)
    {
        endn = (row - 6);
    }
    else 
        endn = nbrOfEntry;

    if(*selected > (row - 6))
    {
        startn = *selected - (row - 5) + 1;
        endn = *selected;
    }

    for (m = startn; m <= endn; m++)
    {
        y++;
        move(y, x);
        char buffer1[32] = {0};
        char buffer2[521] = {0};

    /*  We take the width of the window, to make sure the descriptions
     *  dont go out of the window
     */
        
        strncpy (buffer1, entryName[m].name, 14*sizeof(char));
        strncpy (buffer2, entryName[m].description, sizeof(char)*(col - 22));
        if(m == *selected)
            attron(A_BOLD);
        printw("%s", buffer1);
        if(m == *selected)
            attroff(A_BOLD);
        move(y, x+15);
        if(m == *selected)
            attron(A_BOLD);
        printw("%s", buffer2);
        if(m == *selected)
            attroff(A_BOLD);
    }
    if (nbrOfEntry <= row)
        mvprintw(nbrOfEntry+4, 0,"                                                              ");
    
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
    mvwprintw (local_win, 4, 5, "j");
    mvwprintw (local_win, 4, 20, "Move down to the list");
    mvwprintw (local_win, 5, 5, "k");
    mvwprintw (local_win, 5, 20, "Move up to the list");
    mvwprintw (local_win, 6, 5, "space");
    mvwprintw (local_win, 6, 20, "Display full information and pass for an entry");
    mvwprintw (local_win, 8, 5, "a");
    mvwprintw (local_win, 8, 20, "Add a new entry");
    mvwprintw (local_win, 9, 5, "d");
    mvwprintw (local_win, 9, 20, "Delete an entry");
    mvwprintw (local_win, 11, 5, "?");
    mvwprintw (local_win, 11, 20, "Display this help menu");

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
    for(n = 0; n <= 30; n++)
    {
        mvwprintw (local_win, n, 1,"                                                                                                            ");
    }

    wrefresh (local_win);
    delwin (local_win);
}

void displayDetail(struct Entry entry)
{
    int leight = 10;
    int widht  = 70;
    int starty = 3;
    int startx = 5;

    WINDOW *display_window;
    display_window = create_displaywindow(leight, widht, starty, startx, entry);
    getchar();
    destroy_win(display_window);
}


WINDOW *create_displaywindow(int leight, int widht, int starty, int startx, struct Entry entry)
{
    WINDOW *local_win;
    local_win = newwin (leight, widht, starty, startx);
    box (local_win, 0, 0);
    
    mvwprintw (local_win, 2, 5, "name:");
    mvwprintw (local_win, 2, 20,  entry.name);
    mvwprintw (local_win, 3, 5, "description");
    mvwprintw (local_win, 3, 20, entry.description);
    mvwprintw (local_win, 4, 5, "login:");
    mvwprintw (local_win, 4, 20, entry.login);
    mvwprintw (local_win, 5, 5, "pass:");
    mvwprintw (local_win, 5, 20, entry.pass);

    wrefresh (local_win);
    return local_win;
}

void getHelpBar (int row)
{
    mvprintw(0, 0, "press ? for Help");
    /*mvprintw(row - 1, 30, "j: Down");
    mvprintw(row - 1, 40, "k: Up");
    mvprintw(row - 1, 50, "q: Quit");
    mvprintw(0, 35, "Space: Select");
    mvprintw(0, 55, "a: add");
    mvprintw(0, 65, "d: del");*/
    refresh();
}

int confirmationWindow(void)
{
    int locx, locy, locleight, locwidht;
    char ch = 0;
    getmaxyx(stdscr, locy, locx);

    locleight = 3;
    locwidht  = 50;
    locy = locy / 2 - 2;
    locx = locx / 2 - 25;

    WINDOW *local_win;
    local_win = newwin(locleight, locwidht, locy, locx);
    box (local_win, 0, 0);
    mvwprintw(local_win, 1, 5, "Are you sure to delete this entry ? (y/n)");
    wrefresh(local_win);
    ch = getchar();
    destroy_win(local_win);

    if(ch == 'y' || ch == 'Y')
            return 1;

    return 0;
}


WINDOW *create_addwindow (struct Entry *entry, int *nbrOfEntry)
{
    WINDOW *local_win;
    char buffer[512] = {0};

    /*TODO dynamique size of the window */

    local_win = newwin (15, 70, 2, 5);
    box (local_win, 0, 0);
    
    echo();
    curs_set(1);

    mvwprintw (local_win, 2, 5, "name:");
    mvwprintw (local_win, 3, 5, "description:");
    mvwprintw (local_win, 5, 5, "login:");
    mvwprintw (local_win, 6, 5, "pass:");
    mvwgetnstr (local_win, 2, 20,   buffer, 128);
    strncpy (entry[*nbrOfEntry+1].name, buffer, 128);
    strcat (entry[*nbrOfEntry+1].name, "\n");

    mvwgetnstr (local_win, 3, 20, buffer, 256);
    strncpy (entry[*nbrOfEntry+1].description, buffer, 256);
    strcat (entry[*nbrOfEntry+1].description, "\n");

    mvwgetnstr (local_win, 5, 20,  buffer, 32);
    strncpy (entry[*nbrOfEntry+1].login, buffer, 32);
    strcat (entry[*nbrOfEntry+1].login, "\n");

    mvwgetnstr (local_win, 6, 20, buffer, 32);
    strncpy (entry[*nbrOfEntry+1].pass, buffer, 32);
    strcat (entry[*nbrOfEntry+1].pass, "\n");

    noecho();
    curs_set(0);

    *nbrOfEntry = *nbrOfEntry +1;
    
    wrefresh (local_win);
    return (local_win);

}

