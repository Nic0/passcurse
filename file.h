#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

/*  Main structure for each pass's entry
 */

struct Entry {
    char name[128];
    char login[32];
    char pass[32];
};

/*  Fonction to count the number of line
 *  in the passfile, return of this number
 */
int countLine (int nbrOfLine);

/*  Get the name from each entry, return it
 *  in the structure
 */
void getNameEntry(struct Entry *addrEntry[]);


#endif
