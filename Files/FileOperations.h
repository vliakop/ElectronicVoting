#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "../Structures/Fenrir.h"

unsigned long countLines(char *);
void readRecords(char *, Fenrir *);
void readIDs(char *, Fenrir *);

#endif
