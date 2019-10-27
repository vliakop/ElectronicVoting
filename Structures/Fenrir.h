#ifndef FENRIR_H
#define FENRIR_H

#include "BloomFilter.h"
#include "RBTree.h"
#include "PCList.h"

class Fenrir {

private:

    BloomFilter *voters_bf;
    RBTree *rbTree;
    PCList *pcList;
    int size;
    int disabled;
    int voted;

public:

    Fenrir(unsigned long bf_size = 1024);
    ~Fenrir();

     bool insert(Voter *voter);
     bool lbf(char *);
     Voter* lrb(char *);
     Voter* findKey(char *);
     Voter* findKeyInPC(char *);
     bool delet(char *);
     int vote(char *);
     int voted_f();
     int votedpostcode(char *);
     void votedperpc();
};

#endif
