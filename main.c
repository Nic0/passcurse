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

/*  Main struct for each pass's entry   */
struct Entry {
    //char  name[];
    int   group;
    char *description;
    char *address;
    char *login;
    char *pass;
    char  name[];
};

int main (void)
{
    /*int row = 0;
    int col = 0;
    int ch  = 0;

    initscr();
    getmaxyx(stdsrc, row, col);

    cbreak();
    curs_set(0);
    keypad(strscr, TRUE);*/

    /*  We take the name list from the passes file
     */

    FILE *passfile;
    passfile = NULL;
    passfile = fopen ("/home/nicolas/pass.txt", "r");

    if(passfile != NULL)
    {
        struct Entry entry[5];
        int n = 0;
        /*for (n = 0;n <= 5; n++)
        {
            //entry[n].name = malloc (sizeof(entry[n].name)+100);
            //entry[n].name = malloc (256);
            //entry[n].name = malloc (strlen(entry[n].name)*sizeof(char *));
            //entry[n].name = NULL;
        }*/


        n=0;
        while(1)
        {
            fscanf(passfile, "%s", entry[n].name);     
            if (feof(passfile)) break;
            printf("entry: %s\n", entry[n].name);
            n++;
        }
        fclose (passfile);
    }
    
    return EXIT_SUCCESS;
}
