#ifndef NCURSES_H_INCLUDED
#define NCURSES_H_INCLUDED

void windowInit(void);
void windowBasic(struct Entry *entryName, int nbrOfEntry);
void getHeaders(void);
void windowHelp(void);

WINDOW *create_helpwindow(int leight, int widht, int starty, int startx);
void destroy_win(WINDOW *local_win);

#endif
