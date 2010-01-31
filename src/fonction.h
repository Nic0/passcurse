#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


int getHomeDir (char *homedir);
int getPassfilePath (char *homedir, char *passfilePath);
int getFonctionMenu (unsigned char c, struct Entry *entry, int *nbrOfEntry, int *selected, char *passfilePath);

#endif
