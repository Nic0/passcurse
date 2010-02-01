/**************************************
*           file.c
**************************************/   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


#include "file.h"
#include "ncurses.h"

#define ELEMENT 4 

/*  this fonction open the passfile, go througt
 *  just to know how many line is in here, and
 *  return it.
 *  As the file containe only one word by line
 *  but has to be change to a proper line
 */

int countLine(char *passfilePath)
{
    int nbrOfLine = 0;
    char ch = 0;

    FILE *passfile = NULL;
    passfile = fopen(passfilePath, "r");

    if (passfile != NULL)
    {
        while(1)
        {
            if(fscanf(passfile, "%c", &ch) == 0)
            {
                printf("error in countLine fonction\n");
                break;
            }
            if (feof(passfile)) break;
            if(ch == '\n')
                nbrOfLine++;
        }
        fclose(passfile);
    }
    else
    {   
        printf("Couldn't open the passfile or doesn't exist\n");
        /* TODO:
         * try to create the file
         */
    }

return nbrOfLine;
}

/*  this fonction go througt the passfile to return
 *  the name's string in the structure.
 *  It just list names
 */

void getNameEntry (struct Entry addrEntry[], char *passfilePath)
{
    char buffer[256] = {0};
    FILE *passfile = NULL;
    passfile = fopen(passfilePath, "r");

    if(passfile != NULL)
    {
        int n = 0;
        int i = 0;

        while(1)
        {
            if(fscanf(passfile, "%s", buffer) == 0)
            {
                printf("error in getNameEntry\n");
                break;
            }
            if(feof(passfile)) break;

            if( n % ELEMENT == 0)
            {
                if(strncpy(addrEntry[i].name, buffer, 120) == NULL)
                {
                    printf("error with struct while parsing %s", buffer);
                    break;
                }
                i++;
            }
            n++;
        }
        fclose(passfile);
    }
}

void getStructEntry (struct Entry *addrEntry, char *passfilePath)
{
    char buffer [512] = {0};
    FILE *passfile = NULL;
    passfile = fopen (passfilePath, "r");

    if(passfile != NULL)
    {
        int  tab = 0;
        int  i   = 0;

        while(1)
        {
            char c = 0;
            fscanf(passfile, "%c", &c);
            if(feof(passfile))
            {   break;}

            strncat (buffer, &c, 1);

            if(c == '\n')
            {   
                if(tab == 0)
                {
                    strncpy(addrEntry[i].name, buffer, 128);
                }
                if(tab == 1)
                {
                    strncpy(addrEntry[i].description, buffer, 256);
                }
                if(tab == 2)
                {
                    strncpy(addrEntry[i].login, buffer, 32);
                }
                if(tab == 3)
                {
                    strncpy(addrEntry[i].pass, buffer, 32);
                }

                tab++;
                if (tab == ELEMENT)
                {
                    tab = 0;
                    i++;
                }
                strcpy (buffer, "");
                
            }
        }
    }
    fclose(passfile);
}

int deleteEntry (int *selected, struct Entry *addrEntry, int *nbrOfEntry, char *passfilePath)
{

    /*  For delete, first we write in a tmp file the entries
     *  without the one deleted.
     */

    char passfileTmp[256] = {0};
    strcpy (passfileTmp, passfilePath);
    strcat (passfileTmp, ".tmp");

    FILE *tmppassfile;
    tmppassfile = fopen(passfileTmp, "w");

    if(tmppassfile != NULL)
    {
        int n;
        for (n = 0; n <= *nbrOfEntry; n++)
        {   
            if(n == *selected)
                n++;
            fprintf(tmppassfile, "%s", addrEntry[n].name);
            fprintf(tmppassfile, "%s", addrEntry[n].description);
            fprintf(tmppassfile, "%s", addrEntry[n].login);
            fprintf(tmppassfile, "%s", addrEntry[n].pass);
        }
        fclose(tmppassfile);
    }
    else
    {   return 1;}
    
    FILE *passfile;
    passfile = fopen(passfilePath, "w");

    if(passfile != NULL)
    {
        int n;
        for (n = 0; n <= *nbrOfEntry; n++)
        {   
            if(n == *selected)
                n++;
            fprintf(passfile, "%s", addrEntry[n].name);
            fprintf(passfile, "%s", addrEntry[n].description);
            fprintf(passfile, "%s", addrEntry[n].login);
            fprintf(passfile, "%s", addrEntry[n].pass);
        }
        fclose(passfile);
    }
    else
    {   return 1;}
    
    /*  TODO check md5sum of both file, and if match
     *  we delete the tmp file, and change the structure
     */

    *nbrOfEntry = *nbrOfEntry - 1;
    getStructEntry(addrEntry, passfilePath);

    return 0;
}

int addEntry (int *selected, struct Entry *entry, int *nbrOfEntry, char *passfilePath)
{
    WINDOW *addWindow;
    addWindow = create_addwindow (entry, nbrOfEntry);
    getchar();
    destroy_win(addWindow);


    char passfileTmp[256] = {0};
    strcpy (passfileTmp, passfilePath);
    strcat (passfileTmp, ".tmp");

    FILE *tmppassfile;
    tmppassfile = fopen(passfileTmp, "w");

    if(tmppassfile != NULL)
    {
        int n;
        for (n = 0; n <= *nbrOfEntry +1; n++)
        {   
            fprintf(tmppassfile, "%s", entry[n].name);
            fprintf(tmppassfile, "%s", entry[n].description);
            fprintf(tmppassfile, "%s", entry[n].login);
            fprintf(tmppassfile, "%s", entry[n].pass);
        }
        fclose(tmppassfile);
    }
    else
    {   return 1;}
    
    FILE *passfile;
    passfile = fopen(passfilePath, "w");

    if(passfile != NULL)
    {
        int n;
        for (n = 0; n <= *nbrOfEntry +1; n++)
        {   
            fprintf(passfile, "%s", entry[n].name);
            fprintf(passfile, "%s", entry[n].description);
            fprintf(passfile, "%s", entry[n].login);
            fprintf(passfile, "%s", entry[n].pass);
        }
        fclose(passfile);
    }
    else
    {   return 1;}

return 0;
}

