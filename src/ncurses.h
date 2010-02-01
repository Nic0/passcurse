#ifndef NCURSES_H_INCLUDED
#define NCURSES_H_INCLUDED

void windowInit(void);
void windowBasic(struct Entry *entryName, int nbrOfEntry, int *selected, char c);
void getHeaders(void);
void getHelpBar(int row);
void windowHelp(void);
int confirmationWindow(void);

WINDOW *create_helpwindow(int leight, int widht, int starty, int startx);
WINDOW *create_displaywindow(int leight, int widht, int starty, int startx, struct Entry entry);
WINDOW *create_addwindow (struct Entry *entry, int *nbrOfEntry);

void destroy_win(WINDOW *local_win);
void diplayDetail(struct Entry entry);

#endif
