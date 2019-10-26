#ifndef IDENTITYCARDLIST_H
#define IDENTITYCARDLIST_H

#include <cstring>
class IdentityCardList {

    struct IDNode {
        char *identity_number;
        bool hasVoted;
        IDNode *next;
        IDNode *prev;

        IDNode(char *identity_number, IDNode *prev = NULL, IDNode *next = NULL);
        ~IDNode();
    };

    IDNode* start;
    IDNode* end;
    int size;
    int disabled; // How many have been deleted
    int voted; // How many have voted

public:

    IdentityCardList();
    ~IdentityCardList();
    void insert(char *);
    bool exist(char *);
    void vote(char *);
    void print();
};

#endif
