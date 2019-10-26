#include "IdentityCardList.h"
#include <cstring>
#include <iostream>

using namespace std;

IdentityCardList::IDNode::IDNode(char *identity_number, IDNode *prev, IDNode *next) {

    this->identity_number = new char[strlen(identity_number) + 1];
    strcpy(this->identity_number, identity_number);

    this->next = next;
    this->prev = prev;
    this->hasVoted = false;
}

IdentityCardList::IDNode::~IDNode() {

    delete []identity_number;
}

IdentityCardList::IdentityCardList() {

    start = NULL;
    end = NULL;
    size = 0;
    disabled = 0;
    voted = 0;
}

IdentityCardList::~IdentityCardList() {

    IdentityCardList::IDNode *node = start;
    while (node != NULL) {
        start = start->next;
        delete node;
        node = start;
    }
}

void IdentityCardList::insert(char *identity_number) {

    if (size > 0) {
        if (exist(identity_number) == true) {
            return;
        }
        end->next = new IDNode(identity_number, end);
        end = end->next;
    } else {
        start = new IDNode(identity_number);
        end = start;
    }
    size += 1;
}

bool IdentityCardList::exist(char *identity_number) {

    if (size > 0) {
        IDNode *node = start;
        while(node != NULL) {
            if (strcmp(node->identity_number, identity_number) == 0) {
                return true;
            }
            node = node->next;
        }
    }
    return false;
}

void IdentityCardList::print() {

    IDNode *node = start;
    while(node != NULL) {
        cout<<node->identity_number<<" ";
        if (node->hasVoted == true) {
            cout<<"has voted"<<endl;
        } else {
            cout<<"has not voted"<<endl;
        }
        node = node->next;
    }
}