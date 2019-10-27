#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "../Structures/Fenrir.h"

unsigned long countLines(char *); // Counts lines of a file
void readRecords(char *, Fenrir *); // Reads voter-records from file and inserts them in the structures
void readIDs(char *, Fenrir *); // Reads voter IDs and applies "vote"

#endif
