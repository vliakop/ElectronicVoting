#ifndef IDENTITYCARDLIST_H
#define IDENTITYCARDLIST_H

#include <cstring>
class IdentityCardList { // List of id_numbers with statuses: hasVoted, isActive

    struct IDNode {
        char *identity_number;
        bool hasVoted;
        bool isActive;
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
    void delet(char *);
    void vote(char *);
    void print();
    int getVoted();
    float statistics();
};

#endif
