//#pragma once

#ifndef PCLIST_H
#define PCLIST_H

#include "IdentityCardList.h"

class PCList {

    struct PCNode {
        char *postal_code;
        IdentityCardList *id_list;
        PCNode *next;
        PCNode *prev;

        PCNode(char *postal_code, PCNode *prev = NULL, PCNode *next = NULL);
        ~PCNode();
    };

    PCNode* start;
    PCNode* end;
    int size;

public:

    PCList();
    ~PCList();
    void insert(char *);
    bool exist(char *);
    void print();

    void insertVoterInPC(char *, char *);
    void deleteVoterFromPC(char *, char *);
    void vote(char *, char *);
    int votedpostcode(char *);
    void votedperpc();

};


#endif
