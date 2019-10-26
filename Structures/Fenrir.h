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

public:

    Fenrir(unsigned long bf_size = 1024);
    ~Fenrir();

     bool insert(Voter *voter);
};

#endif
