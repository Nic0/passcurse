#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

/*  Main structure for each pass's entry
 */

struct Entry {
    char name[128];
    char description[512];
    char login[32];
    char pass[32];
};

/*  Fonction to count the number of line
 *  in the passfile, return of this number
 */
int countLine (char *passfilePath);

/*  Get the name from each entry, return it
 *  in the structure
 */
void getNameEntry(struct Entry addrEntry[], char *passfilePath);
void getStructEntry(struct Entry *addrEntry, char *passfilePath);

int deleteEntry(int *selected, struct Entry *addrEntry, int *nbrOfEntry, char *passfilePath);
int addEntry (int *selected, struct Entry *entry, int *nbrOfEntry, char *passfilePath);


#endif
